
program DNS1 {
	version DNSVER1 {
		void registrar(string,string) = 1;
		void borrar(string) = 2;
		string buscar(string) = 3;
		string cliente(string) = 4;
	} = 1;
} = 0x20000001;