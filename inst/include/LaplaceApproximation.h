#ifndef MONGREL_LAPAPPROX_H
#define MONGREL_LAPAPPROX_H

#include <RcppEigen.h>
#include <MatDist.h>
using namespace Rcpp;
using Eigen::Map;
using Eigen::MatrixXd;
using Eigen::ArrayXXd;
using Eigen::ArrayXd;
using Eigen::VectorXd;
using Eigen::Ref;

namespace lapap{

  struct lappars
  {
    double eigvalthresh;
  };

  inline lappars init_lappars(double eigvalthresh){
    lappars lap;
    lap.eigvalthresh=eigvalthresh;
    return lap;
  }

  template <typename T1, typename T2, typename T3> 
  // @param z is object derived from class MatrixBase to overwrite with sample
  // @param m MAP estimate
  // @param S the hessian of the NEGATIVE log-likelihood evaluated at m
  // @param pars structure of type pars
  // @return int 0 success, 1 failure
  inline int eigen_lap(Eigen::MatrixBase<T1>& z, Eigen::MatrixBase<T2>& m, 
                Eigen::MatrixBase<T3>& S,  
                            lappars &pars){
    int p=S.rows();
    int nc=z.cols();
    Eigen::SelfAdjointEigenSolver<MatrixXd> eh(-S); // negative hessian
    VectorXd evalinv(eh.eigenvalues().array().inverse().matrix());
    
    int excess=0;
    for (int i=0; i<p; i++){
      if (evalinv(i) < pars.eigvalthresh) {
        excess++;
      }
    }
    if (excess > 0){
      Rcpp::warning("Some eigenvalues are below eigvalthresh");
      Rcout << "Eigenvalues" << evalinv.transpose() << std::endl;
      return 1;
    }
    int pos = 0;
    for (int i=0; i<p; i++){
      if (evalinv(pos) > 0)
        pos++;
    }
    if (pos < p) {
      Rcpp::warning("Some small negative eigenvalues are being chopped");
      Rcout << p-pos << " out of " << p <<
        " passed eigenvalue threshold" << std::endl;
    }
    
    MatrixXd invhesssqrt(p, pos);
    invhesssqrt = eh.eigenvectors().rightCols(pos)*
      evalinv.tail(pos).cwiseSqrt().asDiagonal(); //V*D^{-1/2}
    typename T1::PlainObject samp(pos, nc);
    fillUnitNormal(samp);
    z.template noalias() = invhesssqrt*samp;
    z.template colwise() += m;
    return 0;
  }
  
  template <typename T1, typename T2, typename T3> 
  // @param z is object derived from class MatrixBase to overwrite with sample
  // @param m MAP estimate
  // @param S the hessian of the NEGATIVE log-likelihood evaluated at m
  // @param pars structure of type pars
  // @return int 0 success, 1 failure
  inline int cholesky_lap(Eigen::MatrixBase<T1>& z, Eigen::MatrixBase<T2>& m, 
                   Eigen::MatrixBase<T3>& S,  
                   lappars &pars){
    // int nc=z.cols();
    // int nr=z.rows();
    Eigen::LLT<MatrixXd> hesssqrt;
    hesssqrt.compute(-S);
    if (hesssqrt.info() == Eigen::NumericalIssue){
        Rcpp::warning("Cholesky of Hessian failed with status status Eigen::NumericalIssue");
        return 1;
    }
    //typename T1::PlainObject samp(nr, nc);
    fillUnitNormal(z);
    hesssqrt.matrixU().solveInPlace(z);
    z.template colwise() += m;
    return 0;
  }
  
  template <typename T1, typename T2, typename T3> 
  // chooses which laplace function to call based on parameter decomp_method
  // @param decomp_method "eigen" or "cholesky"
  inline int lap_picker(Eigen::MatrixBase<T1>& z, Eigen::MatrixBase<T2>& m, 
                 Eigen::MatrixBase<T3>& S, 
                 lappars &pars, String decomp_method){
    if (decomp_method=="eigen"){
      return eigen_lap(z, m, S, pars);
    } else if (decomp_method=="cholesky"){
      return cholesky_lap(z, m, S, pars);
    }
    return 1;
  }
  
  
  
  template <typename T1, typename T2, typename T3>
  // @param z an object derived from class MatrixBase to overwrite with samples
  // @param m MAP estimate (as a vector)
  // @param S the hessian of the NEGATIVE log-likelihood evaluated at m 
  //    block forms should be given as blocks row bound together, blocks 
  //    must be square and of the same size!
  // @param decomp_method  "eigen" or "cholesky"
  // @param eigvalthresh for eigen decomposition, threshold for negative 
  //    eigenvalues dictates clipping vs. stopping behavior
  // @param jitter amount of jitter to add to diagonal
  // @return MatrixXd columns are samples 
  inline int LaplaceApproximation(Eigen::MatrixBase<T1>& z, Eigen::MatrixBase<T2>& m, 
                           Eigen::MatrixBase<T3>& S,
                           String decomp_method, 
                           double eigvalthresh, 
                           double jitter){
    lappars pars = init_lappars(eigvalthresh);
    int nr = S.rows();
    int nc = S.cols();
    int n_samples=z.cols();
    bool partial=false;
    int status; 
    if (nr != nc){
      //Rcout << "Detected Block Digonal" << std::endl;
      if ( (nr % nc) != 0 ) {
        Rcpp::stop("Rectangular Hessian of wrong dimension passed"); 
      }
      else {
        partial=true;
      }
    }
 
    if (partial){
      int q = nr/nc;
      int pos=0;
      MatrixXd zl = MatrixXd::Zero(nc, n_samples);
      VectorXd ml = VectorXd::Zero(nc);
      MatrixXd Sl = MatrixXd::Zero(nc, nc);
      for (int i=0; i < q; i++){
        pos = nc*i;
        ml = m.segment(pos,nc);
        Sl = S.middleRows(pos, nc);
        if (jitter > 0)
          Sl.diagonal().array() += jitter;
        status = lap_picker(zl, ml, Sl, pars, decomp_method);
        z.middleRows(pos,nc) = zl.eval();
        if (status == 1) { return status; } // stop early if failure
      }
    } else {
      if (jitter > 0)
        S.diagonal().array() += jitter; 
      status = lap_picker(z, m, S, pars, decomp_method);
    }
    return status;
  }

}

#endif