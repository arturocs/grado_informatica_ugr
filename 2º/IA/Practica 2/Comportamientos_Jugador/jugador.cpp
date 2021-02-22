#include "../Comportamientos_Jugador/jugador.hpp"
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;


bool essolucion(const estado &a, const estado &b){
	return (a.fila == b.fila and a.columna == b.columna);
}

struct CompararEstado{
	bool operator()(const estado &a, const estado &b){
		if (a.fila < b.fila) return true;
		else if (a.fila == b.fila and a.columna < b.columna) return true;
		else if (a.fila == b.fila and a.columna == b.columna and a.orientacion < b.orientacion) return true;
		else return false;
	}
};


bool ComportamientoJugador::pathFinding(const estado &origen, const estado &destino, list<Action> &plan){
  plan.clear();
  unsigned int t=0;
  priority_queue <estadoP> abiertos;
  set <estado, CompararEstado> cerrados;
  estadoP iz, der, av, aux, origenP;
  origenP.e=origen;
  origenP.p.clear();
  origenP.peso=origenP.p.size() + distancia(origenP.e, destino);

  abiertos.push(origenP);

    while(!abiertos.empty() and !essolucion(abiertos.top().e,destino) && t<5000){

    	aux=abiertos.top(); 
    	abiertos.pop();

    	cerrados.insert(aux.e);
    	aplicaOperadores(aux, iz, der, av);

    	iz.peso=iz.p.size() + distancia(iz.e, destino);
    	der.peso=der.p.size() + distancia (der.e, destino);
    	av.peso=av.p.size() + distancia(av.e, destino);

    	if (cerrados.find(iz.e) == cerrados.end()){
	    	abiertos.push(iz);
		}

    	if (cerrados.find(der.e) == cerrados.end()){
    		abiertos.push(der);
		}

    	if (cerrados.find(av.e) == cerrados.end()){
    		if(pisable(av.e.fila, av.e.columna)==1 or essolucion(av.e, destino)){
    			abiertos.push(av);
    		}
    	}	
    	t++;			
	}

	if(t>=5000){
		inaccesible=true;
		return false;
	}
	else{
		inaccesible=false;
		if (abiertos.size()>0){
			plan = abiertos.top().p;
			return true;
		}
		else return false;
	}
}

void ComportamientoJugador::Reiniciar(){
	ultimaaccion = actIDLE;
	regalo=false;
	inaccesible=false;
	estoy_ejecutando_plan =false;
	error_plan =false;
	estoyorientado=false;
	hueso=false;
	bikini=false;
	zapatillas=false;
	llave=false;
	fila=100;
	columna=100;
	orientacion=0;
	girar=false;
   	girado=false;
	for(int i=0;i<200;i++)
		for(int j=0;j<200;j++){
			memoria[i][j]='_';
			camino_memoria[i][j]=0;	
			mapaSuperficieTemp[i][j]='_';
		}
}

bool hayObstaculoDelante(const vector<unsigned char> & terreno, const vector<unsigned char> & superficie){
	if ( (terreno[2]=='T' or terreno[2]=='S' or terreno[2]=='K') and
				superficie[2]=='_'){
					return false;
	}
	else{
	 return true;
 }
}

Action ComportamientoJugador::Deliberativo(Sensores sensores){
	Action accion=actIDLE;
	if (estoy_ejecutando_plan and !error_plan){
		if(plan.size() > 0){
			accion = plan.front();
		    switch(accion){
	        	case actFORWARD: camino_mapaRes[fila][columna]++; break;
	        	case actTURN_R:  orientacion = (orientacion+1)%4; girado=true; break;
	    	    case actTURN_L: orientacion = (orientacion+3)%4; girado=true; break;
	    	}
			plan.pop_front();
		}
		else{
			estoy_ejecutando_plan = false;
		}
	}
	else{
		estado n, orig;
		orig.columna=columna;
		orig.orientacion=orientacion;
		orig.fila=fila;

		if(regalo){	
			if(buscarRey(fila, columna, n)){
				estoy_ejecutando_plan=pathFinding(orig,n,plan);


		error_plan=false;

			}
			else{
				accion=Reactivo(sensores);
			}	
		}
		else{
			vector<pair<int, int>>r=ordenaRegalos(sensores.regalos,fila, columna);
			int i=0;
			do{
				n.fila=r[i].first;
				n.columna=r[i].second;
				n.orientacion=0;
				i++;		
			}while(!(estoy_ejecutando_plan=pathFinding(orig,n,plan)) && i<r.size());
			error_plan=false;
			
			if(i>=r.size()){
				//error_plan=true;
				inaccesible=true;
				//accion=Reactivo(sensores);
			}


		}	


	}
	return accion;
}

Action ComportamientoJugador::Reactivo(Sensores sensores){
	Action accion=actIDLE;	

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
					girar=true;//accion = gira();
					bloquear();	
				}			
				break;

			case 'A': //Agua
				if(bikini){
					if(sensores.terreno[0]=='B'){
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

			case 'D':
						bloquear(); 
						girar=true;//accion = gira();
				break;
		
			case 'P': //Precipicio
				bloquear();
				girar=true;//accion = gira();
				break;
			
			case 'M': //Muro
				bloquear();
				girar=true;//accion = gira();
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
				girar=true;//girar=true();
				bloquear();
		}
		if(sensores.superficie[1]=='a'||sensores.superficie[3]=='a'||sensores.superficie[4]=='a'||sensores.superficie[5]=='a'
		|| sensores.superficie[6]=='a' || sensores.superficie[7]=='a' || sensores.superficie[8]=='a' && !girado){
			girar=true;//girar=true();
			bloquear();
		}
		
		//Objetos
		if(sensores.superficie[2]!='_' && !girar && !girado){
			switch (sensores.superficie[2]) {
				case '0': //hueso
						girar=true;//girar=true();
						bloquear();
	  				break;
				case '1': //bikini
					if(bikini){
	  					girar=true;//girar=true();
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
						girar=true;//girar=true();
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
	  					girar=true;//girar=true();
	  					bloquear();
					break;
				case '4':
					if(regalo){
						girar=true;//girar=true();
						bloquear();					
					}
					else{
						if(sensores.objetoActivo=='_'){
	  						accion=actPICKUP; 
	  						regalo=true;
	  					}
	  					else accion=actPUSH;
					}	
					
				case 'a':
					girar=true;//accion = gira();
					bloquear();
					break;
				case 'l':
					girar=true; //accion = gira();
					break;
				case 'r':
					if(regalo){
						if(sensores.objetoActivo=='4'){
							accion=actGIVE;
							regalo=false;
						}
						else{
							if(sensores.objetoActivo=='_')
								accion=actPOP;
							else
								accion=actPUSH;
						}
					}	
					else{
						girar=true;
						bloquear();
					}	
					break;
				default:
					bloquear();
					girar=true;
					break;
			}	
	}

	if(girar && !girado && accion!=actPICKUP){
		accion=gira();
	}
	girado=false;

	return accion;
}


Action ComportamientoJugador::think(Sensores sensores){

	Action accion = actFORWARD;
	if (sensores.reset ){
		Reiniciar();
	}

	if (!tiempo){		
		for (int i=0; i<mapaResultado.size();i++)
			for (int j=0; j<mapaResultado.size(); j++)
				if(i<3||i>=(mapaResultado.size()-3)){
					mapaResultado[i][j]='P';
					camino_mapaRes[i][j]=20000;
				}
				else if(j<3||j>=(mapaResultado.size()-3)){ 
					mapaResultado[i][j]='P';
					camino_mapaRes[i][j]=20000;
				}				
	}

	if(tiempo==19999){
		Rellenar(mapaResultado);
	}

	if (!tiempo){
		for (int i=0; i<200;i++)
			for (int j=0; j<200; j++){	
				memoria[i][j]='_';
				mapaSuperficieTemp[i][j]='#';
			}	
		for (int i=0; i<100;i++)
			for (int j=0; j<100; j++)
			mapaSuperficie[i][j]='_';	
	}


	orientacion=orientacion%4<0 ? (orientacion%4)+4 : orientacion%4;

	//Controlar coordenadas
	if(ultimaaccion==actFORWARD && !sensores.colision){
		switch (orientacion) {
			case 0: //norte
 				if(estoyorientado){
 					if(fila>0)
 						fila--;
 				}
 				else{
 					if(fila>0)
 						fila--;
 				}	
  				break;
			case 1: //este
			if(estoyorientado){
 					if(columna<100)
 						columna++;
 				}
 				else{
 					if(columna<200)
 						columna++;
 				}  					
				break;
			case 2: //sur
				if(estoyorientado){
 					if(fila<100)
 						fila++;
 				}
 				else{
 					if(fila<200)
 						fila++;
 				}  				
				break; 
			case 3: //oeste	
  				if(estoyorientado){
 					if(columna>0)
 						columna--;
 				}
 				else{
 					if(columna>0)
 						columna--;
 				}
				break;
		}	
	}

	if(sensores.terreno[0]=='K' && !estoyorientado){//GPS
		int desp_f=fila-sensores.mensajeF;
		int desp_c=columna-sensores.mensajeC;
		for(int j=0; j<100;j++)
			for (int i = 0; i < 100; i++){
				if(camino_memoria[desp_f+j][desp_c+i]!=0)
					camino_mapaRes[j][i]=camino_memoria[desp_f+j][desp_c+i];
				if(mapaSuperficieTemp[desp_f+j][desp_c+i]!='#')
					mapaSuperficie[j][i]=mapaSuperficieTemp[desp_f+j][desp_c+i];
				if(memoria[desp_f+j][desp_c+i]!='_'){
					mapaResultado[j][i]=memoria[desp_f+j][desp_c+i];
				
				}
			}
		fila=sensores.mensajeF;
		columna=sensores.mensajeC;
		estoyorientado=true;
	}	

	if (error_plan){
		estoy_ejecutando_plan = false;
	}
	if (estoy_ejecutando_plan and plan.front() == actFORWARD and hayObstaculoDelante(sensores.terreno, sensores.superficie)){

		switch(sensores.superficie[2]){
			case 'a':
			case 'l':	
				plan.push_front(actIDLE);
				error_plan = false;
				break;
			case 'r':	
				if(regalo){
					if(sensores.objetoActivo=='4'){
						plan.push_front(actGIVE);
						error_plan = false;
						regalo=false;
					}
					else{
						if(sensores.objetoActivo=='_')
							plan.push_front(actPOP);
						else
							plan.push_front(actPUSH);
					}
				}
				else{
					error_plan=true;
				}
				break;
			case '4':
				if(!regalo){
					if(sensores.objetoActivo=='_'){
						plan.push_front(actPICKUP);
						error_plan = false;
						regalo=true;
					}
					else{
						plan.push_front(actPUSH);
						error_plan = false;
					}
				}
				else{
					error_plan=true;
				}
				break;
			case '1':
				if(bikini){
					error_plan=true;
				}
				else{
					if(sensores.objetoActivo=='_'){
						plan.push_front(actPICKUP);
						error_plan = false;
						bikini=true;
					}
					else{
						plan.push_front(actPUSH);
						error_plan = false;
					}
				}
				break;
			case '2':
				if(zapatillas){
					error_plan=true;
				}
				else{
					if(sensores.objetoActivo=='_'){
						plan.push_front(actPICKUP);
						error_plan = false;
						zapatillas=true;
					}
					else{
						plan.push_front(actPUSH);
						error_plan = false;
					}
				}
				break;
			default:
				error_plan=true;
				break;			
		}
	}
	else {
		error_plan = false;
	}

	tiempo++;

	ver(sensores.terreno,mapaResultado);
	verSuperficie(sensores.superficie);

	if(inaccesible){
		veces_inaccesible++;
		umbral=tiempo+log(tiempo)*10;
		inaccesible=false;
	}


	if(tiempo <umbral || !estoyorientado ){
		accion=Reactivo(sensores);
	}
	else{

		if(pisable(fila,columna)){
			accion=Deliberativo(sensores);
		}
		else{
			accion=Reactivo(sensores);
		}
	}

	ultimaaccion = accion;
	return accion;
}

int ComportamientoJugador::interact(Action accion, int valor){
  return false;
}
