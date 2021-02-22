/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "dns1.h"

#include <map>
#include <iostream>

using namespace std;

map<string,string>dns;
//CLIENT *clnt;

void *
registrar_1_svc(char *arg1, char *arg2,  struct svc_req *rqstp)
{
	static char * result;

	string a=arg1, b=arg2;
	dns[a]=b;

	return (void *) &result;
}

void *
borrar_1_svc(char *arg1,  struct svc_req *rqstp)
{
	static char * result;

	string a=arg1;
	map<string,string>::iterator it;
	it=dns.find(a);
	dns.erase(it);

	return (void *) &result;
}

char **
buscar_1_svc(char *arg1,  struct svc_req *rqstp)
{
	static char * result;
	CLIENT *clnt;
	result="";
	string a=arg1;
	result=dns[a].c_str();
	if (result==""){
		//result=cliente_1_svc(arg1,  (struct svc_req) *clnt);
		char * host = "localhost";

		#ifndef	DEBUG
			clnt = clnt_create (host, DNS2, DNSVER2, "udp");
			if (clnt == NULL) {
				clnt_pcreateerror (host);
				exit (1);
			}
		#endif	/* DEBUG */

			
			result = *buscar_1(arg1, clnt);
			//auto a = buscar_1(arg1, clnt);
			#ifndef	DEBUG
				clnt_destroy (clnt);
			#endif	 /* DEBUG */

	}

	return &result;
}
