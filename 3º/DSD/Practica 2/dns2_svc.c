/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "dns2.h"
#include <stdio.h>
#include <stdlib.h>
#include <rpc/pmap_clnt.h>
#include <string.h>
#include <memory.h>
#include <sys/socket.h>
#include <netinet/in.h>

#ifndef SIG_PF
#define SIG_PF void(*)(int)
#endif

static void *
_registrar_1 (registrar_1_argument *argp, struct svc_req *rqstp)
{
	return (registrar_1_svc(argp->arg1, argp->arg2, rqstp));
}

static void *
_borrar_1 (char * *argp, struct svc_req *rqstp)
{
	return (borrar_1_svc(*argp, rqstp));
}

static char **
_buscar_1 (char * *argp, struct svc_req *rqstp)
{
	return (buscar_1_svc(*argp, rqstp));
}

static void
dns2_1(struct svc_req *rqstp, register SVCXPRT *transp)
{
	union {
		registrar_1_argument registrar_1_arg;
		char *borrar_1_arg;
		char *buscar_1_arg;
	} argument;
	char *result;
	xdrproc_t _xdr_argument, _xdr_result;
	char *(*local)(char *, struct svc_req *);

	switch (rqstp->rq_proc) {
	case NULLPROC:
		(void) svc_sendreply (transp, (xdrproc_t) xdr_void, (char *)NULL);
		return;

	case registrar:
		_xdr_argument = (xdrproc_t) xdr_registrar_1_argument;
		_xdr_result = (xdrproc_t) xdr_void;
		local = (char *(*)(char *, struct svc_req *)) _registrar_1;
		break;

	case borrar:
		_xdr_argument = (xdrproc_t) xdr_wrapstring;
		_xdr_result = (xdrproc_t) xdr_void;
		local = (char *(*)(char *, struct svc_req *)) _borrar_1;
		break;

	case buscar:
		_xdr_argument = (xdrproc_t) xdr_wrapstring;
		_xdr_result = (xdrproc_t) xdr_wrapstring;
		local = (char *(*)(char *, struct svc_req *)) _buscar_1;
		break;

	default:
		svcerr_noproc (transp);
		return;
	}
	memset ((char *)&argument, 0, sizeof (argument));
	if (!svc_getargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		svcerr_decode (transp);
		return;
	}
	result = (*local)((char *)&argument, rqstp);
	if (result != NULL && !svc_sendreply(transp, (xdrproc_t) _xdr_result, result)) {
		svcerr_systemerr (transp);
	}
	if (!svc_freeargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		fprintf (stderr, "%s", "unable to free arguments");
		exit (1);
	}
	return;
}

int
main (int argc, char **argv)
{
	register SVCXPRT *transp;

	pmap_unset (DNS2, DNSVER2);

	transp = svcudp_create(RPC_ANYSOCK);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create udp service.");
		exit(1);
	}
	if (!svc_register(transp, DNS2, DNSVER2, dns2_1, IPPROTO_UDP)) {
		fprintf (stderr, "%s", "unable to register (DNS2, DNSVER2, udp).");
		exit(1);
	}

	transp = svctcp_create(RPC_ANYSOCK, 0, 0);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create tcp service.");
		exit(1);
	}
	if (!svc_register(transp, DNS2, DNSVER2, dns2_1, IPPROTO_TCP)) {
		fprintf (stderr, "%s", "unable to register (DNS2, DNSVER2, tcp).");
		exit(1);
	}

	svc_run ();
	fprintf (stderr, "%s", "svc_run returned");
	exit (1);
	/* NOTREACHED */
}
