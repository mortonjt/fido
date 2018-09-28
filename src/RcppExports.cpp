// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppEigen.h>
#include <Rcpp.h>

using namespace Rcpp;

// loglikMongrelCollapsed
double loglikMongrelCollapsed(const Eigen::ArrayXXd Y, const double upsilon, const Eigen::MatrixXd ThetaX, const Eigen::MatrixXd K, const Eigen::MatrixXd A, Eigen::MatrixXd eta);
RcppExport SEXP _mongrel_loglikMongrelCollapsed(SEXP YSEXP, SEXP upsilonSEXP, SEXP ThetaXSEXP, SEXP KSEXP, SEXP ASEXP, SEXP etaSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Eigen::ArrayXXd >::type Y(YSEXP);
    Rcpp::traits::input_parameter< const double >::type upsilon(upsilonSEXP);
    Rcpp::traits::input_parameter< const Eigen::MatrixXd >::type ThetaX(ThetaXSEXP);
    Rcpp::traits::input_parameter< const Eigen::MatrixXd >::type K(KSEXP);
    Rcpp::traits::input_parameter< const Eigen::MatrixXd >::type A(ASEXP);
    Rcpp::traits::input_parameter< Eigen::MatrixXd >::type eta(etaSEXP);
    rcpp_result_gen = Rcpp::wrap(loglikMongrelCollapsed(Y, upsilon, ThetaX, K, A, eta));
    return rcpp_result_gen;
END_RCPP
}
// gradMongrelCollapsed
Eigen::VectorXd gradMongrelCollapsed(const Eigen::ArrayXXd Y, const double upsilon, const Eigen::MatrixXd ThetaX, const Eigen::MatrixXd K, const Eigen::MatrixXd A, Eigen::MatrixXd eta);
RcppExport SEXP _mongrel_gradMongrelCollapsed(SEXP YSEXP, SEXP upsilonSEXP, SEXP ThetaXSEXP, SEXP KSEXP, SEXP ASEXP, SEXP etaSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Eigen::ArrayXXd >::type Y(YSEXP);
    Rcpp::traits::input_parameter< const double >::type upsilon(upsilonSEXP);
    Rcpp::traits::input_parameter< const Eigen::MatrixXd >::type ThetaX(ThetaXSEXP);
    Rcpp::traits::input_parameter< const Eigen::MatrixXd >::type K(KSEXP);
    Rcpp::traits::input_parameter< const Eigen::MatrixXd >::type A(ASEXP);
    Rcpp::traits::input_parameter< Eigen::MatrixXd >::type eta(etaSEXP);
    rcpp_result_gen = Rcpp::wrap(gradMongrelCollapsed(Y, upsilon, ThetaX, K, A, eta));
    return rcpp_result_gen;
END_RCPP
}
// hessMongrelCollapsed
Eigen::MatrixXd hessMongrelCollapsed(const Eigen::ArrayXXd Y, const double upsilon, const Eigen::MatrixXd ThetaX, const Eigen::MatrixXd K, const Eigen::MatrixXd A, Eigen::MatrixXd eta);
RcppExport SEXP _mongrel_hessMongrelCollapsed(SEXP YSEXP, SEXP upsilonSEXP, SEXP ThetaXSEXP, SEXP KSEXP, SEXP ASEXP, SEXP etaSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Eigen::ArrayXXd >::type Y(YSEXP);
    Rcpp::traits::input_parameter< const double >::type upsilon(upsilonSEXP);
    Rcpp::traits::input_parameter< const Eigen::MatrixXd >::type ThetaX(ThetaXSEXP);
    Rcpp::traits::input_parameter< const Eigen::MatrixXd >::type K(KSEXP);
    Rcpp::traits::input_parameter< const Eigen::MatrixXd >::type A(ASEXP);
    Rcpp::traits::input_parameter< Eigen::MatrixXd >::type eta(etaSEXP);
    rcpp_result_gen = Rcpp::wrap(hessMongrelCollapsed(Y, upsilon, ThetaX, K, A, eta));
    return rcpp_result_gen;
END_RCPP
}
// optimMongrelCollapsed
List optimMongrelCollapsed(const Eigen::ArrayXXd Y, const double upsilon, const Eigen::MatrixXd ThetaX, const Eigen::MatrixXd K, const Eigen::MatrixXd A, Eigen::MatrixXd init, int n_samples, bool calcGradHess, double b1, double b2, double step_size, double epsilon, double eps_f, double eps_g, int max_iter, bool verbose, int verbose_rate, String decomp_method, double eigvalthresh, bool no_error, double jitter, bool calcPartialHess);
RcppExport SEXP _mongrel_optimMongrelCollapsed(SEXP YSEXP, SEXP upsilonSEXP, SEXP ThetaXSEXP, SEXP KSEXP, SEXP ASEXP, SEXP initSEXP, SEXP n_samplesSEXP, SEXP calcGradHessSEXP, SEXP b1SEXP, SEXP b2SEXP, SEXP step_sizeSEXP, SEXP epsilonSEXP, SEXP eps_fSEXP, SEXP eps_gSEXP, SEXP max_iterSEXP, SEXP verboseSEXP, SEXP verbose_rateSEXP, SEXP decomp_methodSEXP, SEXP eigvalthreshSEXP, SEXP no_errorSEXP, SEXP jitterSEXP, SEXP calcPartialHessSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Eigen::ArrayXXd >::type Y(YSEXP);
    Rcpp::traits::input_parameter< const double >::type upsilon(upsilonSEXP);
    Rcpp::traits::input_parameter< const Eigen::MatrixXd >::type ThetaX(ThetaXSEXP);
    Rcpp::traits::input_parameter< const Eigen::MatrixXd >::type K(KSEXP);
    Rcpp::traits::input_parameter< const Eigen::MatrixXd >::type A(ASEXP);
    Rcpp::traits::input_parameter< Eigen::MatrixXd >::type init(initSEXP);
    Rcpp::traits::input_parameter< int >::type n_samples(n_samplesSEXP);
    Rcpp::traits::input_parameter< bool >::type calcGradHess(calcGradHessSEXP);
    Rcpp::traits::input_parameter< double >::type b1(b1SEXP);
    Rcpp::traits::input_parameter< double >::type b2(b2SEXP);
    Rcpp::traits::input_parameter< double >::type step_size(step_sizeSEXP);
    Rcpp::traits::input_parameter< double >::type epsilon(epsilonSEXP);
    Rcpp::traits::input_parameter< double >::type eps_f(eps_fSEXP);
    Rcpp::traits::input_parameter< double >::type eps_g(eps_gSEXP);
    Rcpp::traits::input_parameter< int >::type max_iter(max_iterSEXP);
    Rcpp::traits::input_parameter< bool >::type verbose(verboseSEXP);
    Rcpp::traits::input_parameter< int >::type verbose_rate(verbose_rateSEXP);
    Rcpp::traits::input_parameter< String >::type decomp_method(decomp_methodSEXP);
    Rcpp::traits::input_parameter< double >::type eigvalthresh(eigvalthreshSEXP);
    Rcpp::traits::input_parameter< bool >::type no_error(no_errorSEXP);
    Rcpp::traits::input_parameter< double >::type jitter(jitterSEXP);
    Rcpp::traits::input_parameter< bool >::type calcPartialHess(calcPartialHessSEXP);
    rcpp_result_gen = Rcpp::wrap(optimMongrelCollapsed(Y, upsilon, ThetaX, K, A, init, n_samples, calcGradHess, b1, b2, step_size, epsilon, eps_f, eps_g, max_iter, verbose, verbose_rate, decomp_method, eigvalthresh, no_error, jitter, calcPartialHess));
    return rcpp_result_gen;
END_RCPP
}
// uncollapseMongrelCollapsed
List uncollapseMongrelCollapsed(const Eigen::Map<Eigen::VectorXd> eta, const Eigen::Map<Eigen::MatrixXd> X, const Eigen::Map<Eigen::MatrixXd> Theta, const Eigen::Map<Eigen::MatrixXd> Gamma, const Eigen::Map<Eigen::MatrixXd> Xi, const double upsilon, bool ret_mean);
RcppExport SEXP _mongrel_uncollapseMongrelCollapsed(SEXP etaSEXP, SEXP XSEXP, SEXP ThetaSEXP, SEXP GammaSEXP, SEXP XiSEXP, SEXP upsilonSEXP, SEXP ret_meanSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Eigen::Map<Eigen::VectorXd> >::type eta(etaSEXP);
    Rcpp::traits::input_parameter< const Eigen::Map<Eigen::MatrixXd> >::type X(XSEXP);
    Rcpp::traits::input_parameter< const Eigen::Map<Eigen::MatrixXd> >::type Theta(ThetaSEXP);
    Rcpp::traits::input_parameter< const Eigen::Map<Eigen::MatrixXd> >::type Gamma(GammaSEXP);
    Rcpp::traits::input_parameter< const Eigen::Map<Eigen::MatrixXd> >::type Xi(XiSEXP);
    Rcpp::traits::input_parameter< const double >::type upsilon(upsilonSEXP);
    Rcpp::traits::input_parameter< bool >::type ret_mean(ret_meanSEXP);
    rcpp_result_gen = Rcpp::wrap(uncollapseMongrelCollapsed(eta, X, Theta, Gamma, Xi, upsilon, ret_mean));
    return rcpp_result_gen;
END_RCPP
}
// rMatNormalCholesky_test
Eigen::MatrixXd rMatNormalCholesky_test(Eigen::MatrixXd M, Eigen::MatrixXd LU, Eigen::MatrixXd LV);
RcppExport SEXP _mongrel_rMatNormalCholesky_test(SEXP MSEXP, SEXP LUSEXP, SEXP LVSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Eigen::MatrixXd >::type M(MSEXP);
    Rcpp::traits::input_parameter< Eigen::MatrixXd >::type LU(LUSEXP);
    Rcpp::traits::input_parameter< Eigen::MatrixXd >::type LV(LVSEXP);
    rcpp_result_gen = Rcpp::wrap(rMatNormalCholesky_test(M, LU, LV));
    return rcpp_result_gen;
END_RCPP
}
// rInvWishCholesky_test
Eigen::MatrixXd rInvWishCholesky_test(int v, Eigen::MatrixXd Psi);
RcppExport SEXP _mongrel_rInvWishCholesky_test(SEXP vSEXP, SEXP PsiSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type v(vSEXP);
    Rcpp::traits::input_parameter< Eigen::MatrixXd >::type Psi(PsiSEXP);
    rcpp_result_gen = Rcpp::wrap(rInvWishCholesky_test(v, Psi));
    return rcpp_result_gen;
END_RCPP
}
// rMatUnitNormal_test
Eigen::MatrixXd rMatUnitNormal_test(int n, int m);
RcppExport SEXP _mongrel_rMatUnitNormal_test(SEXP nSEXP, SEXP mSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    Rcpp::traits::input_parameter< int >::type m(mSEXP);
    rcpp_result_gen = Rcpp::wrap(rMatUnitNormal_test(n, m));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_mongrel_loglikMongrelCollapsed", (DL_FUNC) &_mongrel_loglikMongrelCollapsed, 6},
    {"_mongrel_gradMongrelCollapsed", (DL_FUNC) &_mongrel_gradMongrelCollapsed, 6},
    {"_mongrel_hessMongrelCollapsed", (DL_FUNC) &_mongrel_hessMongrelCollapsed, 6},
    {"_mongrel_optimMongrelCollapsed", (DL_FUNC) &_mongrel_optimMongrelCollapsed, 22},
    {"_mongrel_uncollapseMongrelCollapsed", (DL_FUNC) &_mongrel_uncollapseMongrelCollapsed, 7},
    {"_mongrel_rMatNormalCholesky_test", (DL_FUNC) &_mongrel_rMatNormalCholesky_test, 3},
    {"_mongrel_rInvWishCholesky_test", (DL_FUNC) &_mongrel_rInvWishCholesky_test, 2},
    {"_mongrel_rMatUnitNormal_test", (DL_FUNC) &_mongrel_rMatUnitNormal_test, 2},
    {NULL, NULL, 0}
};

RcppExport void R_init_mongrel(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
