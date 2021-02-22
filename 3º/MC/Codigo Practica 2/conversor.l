/*/////////////////////////////////////////////////
///Práctica 2: Lex 
///Conversor Brainfuck/Ook!
///Por: Arturo Cortés Sánchez
/////////////////////////////////////////////////*/

%{
#include "stdio.h"
#include "string.h"

//Declaraciones de variables

FILE * codigo, * final;		//Archivos de entrada y de salida
char modo='b'; 				//Variable para controlar si trabajamos con Brainfuck ('b'), o trabajamos con Ook! ('o')
unsigned short opcion=0; 	//Variable para controlar el código que vamos a producir: C (0), C++ (1), Brainfuck (2), Ook! (3)
unsigned int n_bf=0; 		//Lleva la cuenta del numero de ordenes de Brainfuck que tiene el archivo de entrada 
unsigned int n_ook=0; 		//Lleva la cuenta del numero de ordenes de Ook! que tiene el archivo de entrada 
unsigned int tabulacion=1;  //Variable para llevar la cuenta de las tabulaciones

//Declaracion de funciones

//Funciones de uso variado
void tabular();
void modo_de_uso(char * n);
void escribir_operacion(const char * s1, const char * s2);
int cuenta_ook(char * s, int n);


//Funciones que generan codigo C
void escribir_cabecera_c(FILE * archivo);
void incrementar_puntero();
void incrementar_memoria();
void decrementar_puntero();
void decrementar_memoria();
void escribir_caracter();
void leer_caracter();
void abrir_bucle();
void cerrar_bucle();

//Funciones que generan codigo C++
void escribir_cabecera_cpp(FILE * archivo);
void incrementar_puntero_cpp();
void incrementar_memoria_cpp();
void decrementar_memoria_cpp();
void escribir_caracter_cpp();
void leer_caracter_cpp();
void abrir_bucle_cpp();

%}
/*Declaracion de los contextos*/


%s BF_A_C	
%s OOK_A_C	

%s BF_A_CPP	
%s OOK_A_CPP

%s BF_A_OOK	
%s OOK_A_BF	


/*Contextos y expresiones regulares*/
%%

<INITIAL>{	/*En esta primera sección se cuentan los token de cada lenguaje*/

	>	{n_bf++; }
	\<	{n_bf++;}
	\+	{n_bf++;}
	\-	{n_bf++;}
	\.	{n_bf++;}
	,	{n_bf++;}
	\[	{n_bf++;}
	\]	{n_bf++;}
	"Ook."(" "|\t|\n)*"Ook?"(" "|\t|\n)*	{n_ook++;}
	"Ook?"(" "|\t|\n)*"Ook."(" "|\t|\n)*	{n_ook++;}
	"Ook."(" "|\t|\n)*"Ook."(" "|\t|\n)*	{n_ook++;}
	"Ook!"(" "|\t|\n)*"Ook!"(" "|\t|\n)*	{n_ook++;}
	"Ook!"(" "|\t|\n)*"Ook."(" "|\t|\n)*	{n_ook++;}
	"Ook."(" "|\t|\n)*"Ook!"(" "|\t|\n)*	{n_ook++;}
	"Ook!"(" "|\t|\n)*"Ook?"(" "|\t|\n)*	{n_ook++;}
	"Ook?"(" "|\t|\n)*"Ook!"(" "|\t|\n)*	{n_ook++;}
	<<EOF>>		{/*En esta segunda sección se cambia de contexto en funcion de los tokens 
					contados anteriormente y de las opciones introducidas como argumento*/
		rewind(codigo);
		if(n_bf>=n_ook) { 
			printf("\tCódigo Brainfuck detectado.\n");
			modo='b';
			switch(opcion){
				case 0:
					BEGIN BF_A_C;
					break;
				case 1:
					BEGIN BF_A_CPP;
					break;
				case 2:
					printf("\tEl código ya es Brainfuck\n");
					break;
				case 3:
					BEGIN BF_A_OOK;
					break;
				default:
					printf("\tError comprobando lenguaje\n");
					break;				
			}
		}
		else if(n_bf<n_ook){
			printf("\tCódigo Ook! detectado.\n");
			modo='o';
			switch(opcion){
				case 0:
					BEGIN OOK_A_C;
					break;
				case 1:
					BEGIN OOK_A_CPP;
					break;
				case 2:
					BEGIN OOK_A_BF;
					break;
				case 3:
					printf("\tEl código ya es Ook!\n");
					break;
				default:
					printf("\tError de opción\n");
					break;				
			}
		} else printf("\tError comprobando lenguaje\n");
	}
	.|\n		{}
}

<BF_A_C>{

	>+	{incrementar_puntero();}
	\<+	{decrementar_puntero();}
	\++	{incrementar_memoria();}
	\-+	{decrementar_memoria();}
	\.	{escribir_caracter();}
	,	{leer_caracter();}
	\[	{abrir_bucle();}
	\]	{cerrar_bucle();}
	.|\n		{}
}

<OOK_A_C>{
	(" "|\t|\n)*
	("Ook."(" "|\t|\n)*"Ook?"(" "|\t|\n)*)+	{incrementar_puntero();}
	("Ook?"(" "|\t|\n)*"Ook."(" "|\t|\n)*)+	{decrementar_puntero();}
	("Ook."(" "|\t|\n)*"Ook."(" "|\t|\n)*)+	{incrementar_memoria();}
	("Ook!"(" "|\t|\n)*"Ook!"(" "|\t|\n)*)+	{decrementar_memoria();}
	"Ook!"(" "|\t|\n)*"Ook."(" "|\t|\n)*	{escribir_caracter();}
	"Ook."(" "|\t|\n)*"Ook!"(" "|\t|\n)*	{leer_caracter();}
	"Ook!"(" "|\t|\n)*"Ook?"(" "|\t|\n)*	{abrir_bucle();}
	"Ook?"(" "|\t|\n)*"Ook!"(" "|\t|\n)*	{cerrar_bucle();}
	.|\n		{}
}

<BF_A_CPP>{

	>+	{incrementar_puntero_cpp();}
	\<+	{decrementar_puntero();}
	\++	{incrementar_memoria_cpp();}
	\-+	{decrementar_memoria_cpp();}
	\.	{escribir_caracter_cpp();}
	,	{leer_caracter_cpp();}
	\[	{abrir_bucle_cpp();}
	\]	{cerrar_bucle();}
	.|\n		{}
}

<OOK_A_CPP>{

	("Ook."(" "|\t|\n)*"Ook?"(" "|\t|\n)*)+	{incrementar_puntero_cpp();}
	("Ook?"(" "|\t|\n)*"Ook."(" "|\t|\n)*)+	{decrementar_puntero();}
	("Ook."(" "|\t|\n)*"Ook."(" "|\t|\n)*)+	{incrementar_memoria_cpp();}
	("Ook!"(" "|\t|\n)*"Ook!"(" "|\t|\n)*)+	{decrementar_memoria_cpp();}
	"Ook!"(" "|\t|\n)*"Ook."(" "|\t|\n)*	{escribir_caracter_cpp();}
	"Ook."(" "|\t|\n)*"Ook!"(" "|\t|\n)*	{leer_caracter_cpp();}
	"Ook!"(" "|\t|\n)*"Ook?"(" "|\t|\n)*	{abrir_bucle_cpp();}
	"Ook?"(" "|\t|\n)*"Ook!"(" "|\t|\n)*	{cerrar_bucle();}
	.|\n		{}
}

<BF_A_OOK>{

	>	{fprintf(final, "Ook. Ook? ");}
	\<	{fprintf(final, "Ook? Ook. ");}
	\+	{fprintf(final, "Ook. Ook. ");}
	\-	{fprintf(final, "Ook! Ook! ");}
	\.	{fprintf(final, "Ook! Ook. ");}
	,	{fprintf(final, "Ook. Ook! ");}
	\[	{fprintf(final, "Ook! Ook? ");}
	\]	{fprintf(final, "Ook? Ook! ");}
	.|\n		{}
}

<OOK_A_BF>{

	"Ook."(" "|\t|\n)*"Ook?"(" "|\t|\n)*	{fprintf(final, ">");}
	"Ook?"(" "|\t|\n)*"Ook."(" "|\t|\n)*	{fprintf(final, "<");}
	"Ook."(" "|\t|\n)*"Ook."(" "|\t|\n)*	{fprintf(final, "+");}
	"Ook!"(" "|\t|\n)*"Ook!"(" "|\t|\n)*	{fprintf(final, "-");}
	"Ook!"(" "|\t|\n)*"Ook."(" "|\t|\n)*	{fprintf(final, ".");}
	"Ook."(" "|\t|\n)*"Ook!"(" "|\t|\n)*	{fprintf(final, ",");}
	"Ook!"(" "|\t|\n)*"Ook?"(" "|\t|\n)*	{fprintf(final, "[");}
	"Ook?"(" "|\t|\n)*"Ook!"(" "|\t|\n)*	{fprintf(final, "]");}
	.|\n		{}
}

%%

//Programa principal

int main (int argc, char *argv[]) {
	
	int tam_archivo; //Almacena el tamaño del archivo resultante

	printf("\n***************************************************\n");
	printf("*                                                 *\n");
	printf("*                 Práctica 2: Lex                 *\n");
	printf("*            Conversor Brainfuck/Ook!             *\n");
	printf("*                                                 *\n");
	printf("***************************************************\n\n");

	if (argc < 3) {
		modo_de_uso(argv[0]);
		exit(-1);
	}

	codigo = fopen (argv[1], "rt");

	if (codigo== NULL) { 		 //Verifica si el fichero existe
		printf ("\tEl fichero %s no se puede abrir\n\n", argv[1]);
		exit (-1);
	}

	final = fopen(argv[2],"w+"); //Crea el fichero de salida

	if(argc >=4){ 				 //Verifica el tercer argumento para decidir que conversión realizar
		if(!strcmp(argv[3],"-c") || !strcmp(argv[3],"-e")){
			opcion=0;
			escribir_cabecera_c(final);
		}else if(!strcmp(argv[3],"-cpp")){
			opcion=1;
			escribir_cabecera_cpp(final);
		}else if(!strcmp(argv[3],"-b")){
			opcion=2;
		}else if(!strcmp(argv[3],"-o")){
			opcion=3;
		}else{
			printf("\tTercer argumento argumento erróneo.\n");
			modo_de_uso(argv[0]);
			exit(-1);
		}
	}
	else{
		opcion=0;
		escribir_cabecera_c(final);
	}	

	yyin = codigo;
	yylex ();

	if(opcion<2) //En caso de ser una conversion a C o C++, cierra la llave del main()
		fprintf(final,"}");

	switch(opcion){
		case 0:
			printf("\tConvirtiendo a C.\n");
			break;
		case 1:
			printf("\tConvirtiendo a C++.\n");
			break;
		case 2:
			printf("\tConvirtiendo a Brainfuck.\n");
			break;
		case 3:
			printf("\tConvirtiendo a Ook!\n");
			break;
		default:
			printf("\tError de opción\n");
			exit(-1);
		break;				
	}

	//Comprueba el tamaño del archivo resultante para saber si todo ha ido bien
	rewind(final);
	fseek(final, 0L, SEEK_END);
	tam_archivo = ftell(final);

    if(tam_archivo!=0){
        printf("\tArchivo \"%s\" creado con éxito.\n", argv[2]);
	}else{
        printf("\tEl archivo \"%s\" no pudo ser convertido. \n", argv[1]);
        exit(-1);
    }

	fclose(final);
	fclose(codigo);	

    if( ( argc == 4 && !strcmp(argv[3],"-e" ) ) || ( argc == 5 && !strcmp(argv[4],"-e") ) ){
        if(opcion>=2){
            printf("No se puede compilar y ejecutar codigo en Brainfuck u Ook!,\n primero deber ser convertido a C o C++");
            exit(-1);
        }
        else{
            char* compilador = (opcion) ? "g++" : "gcc"; 
            char ejecutable[strlen(argv[2])+4];
			char compilar[27+3*strlen(argv[2])];

			printf("\tCompilando el archivo \"%s\".\n", argv[2]);
			strcpy(ejecutable, argv[2]);
			strcat(ejecutable,".bin");
			printf("\tSe creará y ejecutará el archivo \"%s\".\n", ejecutable);
            
            sprintf(compilar,"%s %s -o %s -O2 && ./%s",compilador,argv[2], ejecutable, ejecutable);
			printf("\t%s\n\n",compilar);
            system(compilar);
		}
    }
	printf("\n");
}


//Implementacion de funciones 

//Funciones variadas

void modo_de_uso(char * n){
	printf("\nModo de uso: %s <fichero de entrada en Ook! o Brainfuck> <fichero de salida> [Opciones] \n", n);
	printf("Opciones:\n");
	printf("\t-c : Convertir código Brainfuck o Ook! a código C \n");
	printf("\t-cpp : Convertir código Brainfuck o Ook! a código C++ \n");
	printf("\t-b : Convertir código Ook! a Brainfuck\n");
	printf("\t-o : Convertir código Brainfuck a Ook!\n");
    printf("\t-e : [Opcional] Compilar y ejecutar el codigo C o C++ generado (requiere gcc o g++)\n\n");
	printf("\tSi no se recibe ninguna opción, se usará -c por defecto\n\n");
	printf("\tEjemplo: Convertir a C++, compilar y ejecutar el archivo \"hello.b\":\n");
	printf("\t%s hello.b hello.cpp -cpp -e\n\n",n);
}

void tabular(){
	for(int i=0;i<tabulacion;i++)
		fprintf(final, "\t");
}

int cuenta_ook(char * s, int n){
	int ooks=0;
	for(int i=0;i<n;i++){
		if(s[i]=='O'&&s[i+1]=='o'&&s[i+2]=='k'){
			ooks++;
			i+=2;
		}
	}
	return ooks/2;
}

void escribir_operacion(const char * s1, const char * s2){
	int tam = modo == 'b' ? yyleng : cuenta_ook(yytext,yyleng);

	tabular();
	if(tam==1){
		fprintf(final, s1);
	}
	else{
		fprintf(final, s2, tam);
	}
}

//Funciones para generar codigo C

void escribir_cabecera_c(FILE * archivo){
	fprintf(archivo, "#include <stdio.h>\n");
	fprintf(archivo, "int main(){\n");
	fprintf(archivo, "\tunsigned char mem[30000]={0};\n");
	fprintf(archivo, "\tunsigned char*	 p=mem;\n\n");
	fprintf(archivo, "\t//------Transcripción------\n\n");
}

void incrementar_puntero(){
	escribir_operacion("++p;\n","p+=%d;\n");
}

void incrementar_memoria(){
	escribir_operacion("++*p;\n","*p+=%d;\n");
}

void decrementar_puntero(){
	escribir_operacion("--p;\n","p-=%d;\n");
}

void decrementar_memoria(){
	escribir_operacion("--*p;\n","*p-=%d;\n");
}

void escribir_caracter(){
	tabular();
	fprintf(final, "putchar(*p);\n");
}

void leer_caracter(){
	tabular();
	fprintf(final, "*p=getchar();\n");
}

void abrir_bucle(){
	tabular();
	fprintf(final, "while(*p){\n");
	tabulacion++;
}

void cerrar_bucle(){
	if(tabulacion>0) tabulacion--;
	tabular();
	fprintf(final, "}\n");
}

//Funciones para generar codigo C++

void escribir_cabecera_cpp(FILE * archivo){
	fprintf(archivo, "#include <iostream>\n");
	fprintf(archivo, "#include <vector>\n");
	fprintf(archivo, "using namespace std;\n\n");
	fprintf(archivo, "inline void inc_p(vector<unsigned char> &mem, unsigned long long &p ,int n) {\n");
	fprintf(archivo, "\tif (p + n >= mem.size()) {\n");
	fprintf(archivo, "\t\tmem.resize(mem.size() + n, 0);\n");
	fprintf(archivo, "\t\tp += n;\n");
	fprintf(archivo, "\t} else {\n");
	fprintf(archivo, "\t\tp += n;\n");
	fprintf(archivo, "\t}\n");
	fprintf(archivo, "}\n\n");
	fprintf(archivo, "int main(){\n");
	fprintf(archivo, "\tvector<unsigned char> mem;\n");
	fprintf(archivo, "\tunsigned long long p=0;\n");
	fprintf(archivo, "\tmem.push_back(0);\n\n");
	fprintf(archivo, "\t//------Transcripción------\n\n");
}
void incrementar_puntero_cpp(){
	tabular();
	if(modo=='b'){
		fprintf(final, "inc_p(mem,p,%i);\n",yyleng);
	}
	else{
		fprintf(final, "inc_p(mem,p,%i);\n",cuenta_ook(yytext,yyleng));
	}
}

void incrementar_memoria_cpp(){
	escribir_operacion("++mem[p];\n","mem[p]+=%d;\n");
}

void decrementar_memoria_cpp(){
	escribir_operacion("--mem[p];\n","mem[p]-=%d;\n");
}

void escribir_caracter_cpp(){
	tabular();
	fprintf(final, "cout << mem[p];\n");
}

void leer_caracter_cpp(){
	tabular();
	fprintf(final, "cin >> mem[p];\n");
}

void abrir_bucle_cpp(){
	tabular();
	fprintf(final, "while(mem[p]){\n");
	tabulacion++;
}
