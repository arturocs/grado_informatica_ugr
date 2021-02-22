/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "dns2.h"


void
dns2_1(char *host)
{
	CLIENT *clnt;
	void  *result_1;
	char *registrar_1_arg1;
	char *registrar_1_arg2;
	void  *result_2;
	char *borrar_1_arg1;
	char * *result_3;
	char *buscar_1_arg1;

#ifndef	DEBUG
	clnt = clnt_create (host, DNS2, DNSVER2, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	result_1 = registrar_1(registrar_1_arg1, registrar_1_arg2, clnt);
	if (result_1 == (void *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_2 = borrar_1(borrar_1_arg1, clnt);
	if (result_2 == (void *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_3 = buscar_1(buscar_1_arg1, clnt);
	if (result_3 == (char **) NULL) {
		clnt_perror (clnt, "call failed");
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	dns2_1 (host);
exit (0);
}
