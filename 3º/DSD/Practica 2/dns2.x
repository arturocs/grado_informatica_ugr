
program DNS2 {
	version DNSVER2 {
		void registrar(string,string) = 1;
		void borrar(string) = 2;
		string buscar(string) = 3;
	} = 1;
} = 0x20000002;