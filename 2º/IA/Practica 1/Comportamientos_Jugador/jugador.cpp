#include "../Comportamientos_Jugador/jugador.hpp"
#include <iostream>
#include <cstdlib>
using namespace std;

Action ComportamientoJugador::think(Sensores sensores){

	Action accion=actFORWARD;
	
	/cout << "Terreno: ";
	for (int i=0; i<sensores.terreno.size(); i++)
		cout << sensores.terreno[i];
	cout << endl;
	cout << "Superficie: ";
	for (int i=0; i<sensores.superficie.size(); i++)
		cout << sensores.superficie[i];
	cout << endl;

	cout << "Colisión: " << sensores.colision << endl;
	cout << "Mochila: " << sensores.mochila << endl;
	cout << "Reset: " << sensores.reset << endl;
	cout << "Vida: " << sensores.vida << endl;
	cout << "objetoActivo: " << sensores.objetoActivo << endl;
	cout << endl;
	
	if (!llenar){ //Pone precipicios en los bordes		

		for (int i=0; i<mapaResultado.size();i++)
			for (int j=0; j<mapaResultado.size(); j++)
				if(i<3||i>=(mapaResultado.size()-3))
					mapaResultado[i][j]='P';
				else if(j<3||j>=(mapaResultado.size()-3)) 
					mapaResultado[i][j]='P';		


		llenar = true;	
	}

	if(tiempo==19999){ //Quita las interrogaciones antes de acabar
		
		for (int i=0; i<mapaResultado.size();i++)
			for (int j=0; j<mapaResultado.size(); j++)
				if(mapaResultado[i][j]=='?')
						mapaResultado[i][j]=mapaResultado[i-1][j];
	}

	if (!inimem){ //inicializa la matriz memoria
		for (int i=0; i<200;i++)
			for (int j=0; j<200; j++)	
				memoria[i][j]='_';

		inimem = true;	
	}

	//Controlar coordenadas
	if(ultimaaccion==actFORWARD && !sensores.colision){
		switch (orientacion%4<0 ? (orientacion%4)+4 : orientacion%4) {
			case 0: //norte
 					fila--;
  				break;
			case 1: //este
  					columna++;
				break;
			case 2: //sur
  					fila++;
				break; 
			case 3: //oeste
  					columna--;
				break;
		}	
	}

	if (sensores.reset){ //Control de la muerte
		n_muertes++;
		estoyorientado=false;
		hueso=false;
		bikini=false;
		zapatillas=false;
		llave=false;
		siguiendo_k=false;
		fila=100;
		columna=100;
		orientacion=0;
		girar=false;
   		girado=false;
		for(int i=0;i<200;i++)
			for(int j=0;j<200;j++)
				memoria[i][j]='_';

		for(int i=0;i<200;i++)
			for(int j=0;j<200;j++)
				camino_memoria[i][j]=0;	
	}

	if(sensores.terreno[0]=='K' && !estoyorientado){//GPS
		int desp_f=fila-sensores.mensajeF;
		int desp_c=columna-sensores.mensajeC;
		for(int j=0; j<100;j++)
			for (int i = 0; i < 100; i++){
				camino_mapaRes[j][i]=camino_memoria[desp_f+j][desp_c+i];	
				if(memoria[desp_f+j][desp_c+i]!='_')
					mapaResultado[j][i]=memoria[desp_f+j][desp_c+i];
			}

		fila=sensores.mensajeF;
		columna=sensores.mensajeC;
		estoyorientado=true;
	}	

	//Tiempo
	tiempo++;

	//Vision
	ver(sensores.terreno,mapaResultado);


	//Desplazamiento
	switch(sensores.terreno[2]){   
		case 'B': //Bosque
			if(zapatillas){
				if(sensores.terreno[0]=='A'){
					bloquear();
					girar=true;
				}
				else{
					if(sensores.objetoActivo=='2')
						accion=actFORWARD;
					else{
						if(sensores.objetoActivo=='_')
							accion=actPOP;
						else{
							accion=sacar_objeto(sensores.objetoActivo);
						}
					}
				}
			}
			else {
				girar=true;
				bloquear();	
			}			
			break;

		case 'A': //Agua
			if(bikini){
				if(sensores.terreno[0]=='A'){
					bloquear();
					girar=true;
				}
				else{
					if(sensores.objetoActivo=='1')
						accion=actFORWARD;
					else{
						if(sensores.objetoActivo=='_')
							accion=actPOP;
						else{
							accion=sacar_objeto(sensores.objetoActivo);
						}
					}
				}
			}
			else {
				girar=true;
				bloquear();
			}	
			break;

		case 'D'://Puerta
			if(llave){
				if(sensores.objetoActivo=='3'){
					accion=actGIVE;
					if(ultimaaccion==actGIVE)
						accion=actFORWARD;
				}	
				else{
					if(sensores.objetoActivo=='_')
						accion=actPOP;
					else{
						accion=sacar_objeto(sensores.objetoActivo);
					}
				}					
			}
			else{
				if(ultimaaccion==actGIVE){
					accion=actFORWARD;
				}
				else{
					bloquear(); 
					girar=true;
				}	
			}	
			break;
	
		case 'P': //Precipicio
			bloquear();
			girar=true;
			break;
		
		case 'M': //Muro
			bloquear();
			girar=true;
			break;
		case 'K' : //GPS	
			accion=actFORWARD;
			break;

		default:		
			accion=avanza();
			break;
	}

	if(sensores.superficie[1]=='l'||sensores.superficie[3]=='l'||sensores.superficie[4]=='l'||sensores.superficie[5]=='l' 
	|| sensores.superficie[6]=='l' || sensores.superficie[7]=='l' || sensores.superficie[8]=='l' && !girado){ 
			girar=true;
			bloquear();
	}
	if(sensores.superficie[1]=='a'||sensores.superficie[3]=='a'||sensores.superficie[4]=='a'||sensores.superficie[5]=='a'
	|| sensores.superficie[6]=='a' || sensores.superficie[7]=='a' || sensores.superficie[8]=='a' && !girado){
		girar=true;
		bloquear();
	}
	
	//Objetos
	if(sensores.superficie[2]!='_' && !girar && !girado){
		switch (sensores.superficie[2]) {
			case '0': //hueso
				if (hueso){
					girar=true;
					bloquear();
				}
				else{
 					if(sensores.objetoActivo=='_'){
 						accion=actPICKUP;
 						hueso=true;
 					}
 					else accion=actPUSH;
 				}	
  				break;
			case '1': //bikini
				if(bikini){
  					girar=true;
  					bloquear();
  				}
  				else{
  					if(sensores.objetoActivo=='_'){ 
  						accion=actPICKUP; 
  						bikini=true;
  					}
  					else accion=actPUSH;
  				}
				break;
			case '2': //zapatillas
				if(zapatillas){
					girar=true;
					bloquear();
				}
				else{
  					if(sensores.objetoActivo=='_'){
  						accion=actPICKUP; 
  						zapatillas=true;
  					}
  					else accion=actPUSH;
  				}
				break; 
			case '3': //llave
  				if(llave){
  					girar=true;
  					bloquear();
  				}
  				else{
  					if(sensores.objetoActivo=='_'){
  						accion=actPICKUP; 
  						llave=true;
  					}
  					else accion=actPUSH;
  				}
				break;
			case 'a': //Aldeano
				girar=true;
				break;
			case 'l': //Lobo
				girar=true;
			break;
		}	
	}

	if(sensores.objetoActivo=='0' && !girar){
		accion=actTHROW;
		hueso=false;
	}

	if(girar && !girado && accion!=actPICKUP){accion=gira(); }
	else if(girado){girado=false;}


	girado=false;
	ultimaaccion=accion;	
	return accion;
}

int ComportamientoJugador::interact(Action accion, int valor){
  return false;
}
