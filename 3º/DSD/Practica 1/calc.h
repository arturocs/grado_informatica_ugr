/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _CALC_H_RPCGEN
#define _CALC_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct suma_1_argument {
	double arg1;
	double arg2;
};
typedef struct suma_1_argument suma_1_argument;

struct resta_1_argument {
	double arg1;
	double arg2;
};
typedef struct resta_1_argument resta_1_argument;

struct mul_1_argument {
	double arg1;
	double arg2;
};
typedef struct mul_1_argument mul_1_argument;

struct div_1_argument {
	double arg1;
	double arg2;
};
typedef struct div_1_argument div_1_argument;

#define CALCPROG 0x20000001
#define CALCVER 1

#if defined(__STDC__) || defined(__cplusplus)
#define suma 1
extern  double * suma_1(double , double , CLIENT *);
extern  double * suma_1_svc(double , double , struct svc_req *);
#define resta 2
extern  double * resta_1(double , double , CLIENT *);
extern  double * resta_1_svc(double , double , struct svc_req *);
#define mul 3
extern  double * mul_1(double , double , CLIENT *);
extern  double * mul_1_svc(double , double , struct svc_req *);
#define div 4
extern  double * div_1(double , double , CLIENT *);
extern  double * div_1_svc(double , double , struct svc_req *);
extern int calcprog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define suma 1
extern  double * suma_1();
extern  double * suma_1_svc();
#define resta 2
extern  double * resta_1();
extern  double * resta_1_svc();
#define mul 3
extern  double * mul_1();
extern  double * mul_1_svc();
#define div 4
extern  double * div_1();
extern  double * div_1_svc();
extern int calcprog_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_suma_1_argument (XDR *, suma_1_argument*);
extern  bool_t xdr_resta_1_argument (XDR *, resta_1_argument*);
extern  bool_t xdr_mul_1_argument (XDR *, mul_1_argument*);
extern  bool_t xdr_div_1_argument (XDR *, div_1_argument*);

#else /* K&R C */
extern bool_t xdr_suma_1_argument ();
extern bool_t xdr_resta_1_argument ();
extern bool_t xdr_mul_1_argument ();
extern bool_t xdr_div_1_argument ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_CALC_H_RPCGEN */
