#ifndef COMPORTAMIENTOJUGADOR_H
#define COMPORTAMIENTOJUGADOR_H
#include <list>
#include "comportamientos/comportamiento.hpp"
#include <string>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm> 
#include <iostream>

using namespace std;

    struct estado{
      int fila;
      int columna;
      int orientacion;
    };

    struct estadoP{
      estado e;
      list<Action> p;
      int peso=0;
      bool operator<(const estadoP& a) const{
        return (a.peso < peso);
      }
    };




class ComportamientoJugador : public Comportamiento{

  public:
    ComportamientoJugador(unsigned int size) : Comportamiento(size){

    }

    ComportamientoJugador(const ComportamientoJugador & comport) : Comportamiento(comport){}
    ~ComportamientoJugador(){}

    Action think(Sensores sensores);

    int interact(Action accion, int valor);


    ComportamientoJugador * clone(){return new ComportamientoJugador(*this);}

  private:
  
     int fila = 100;
    int columna =100;
    int orientacion =0; //orientacion%4 = 0 n, 1 e, 2 s, 3 o
    bool estoyorientado=false;
    bool girar=false;
    bool girado=false;
    int camino_memoria[200][200]={{0}};
    int camino_mapaRes[100][100]={{0}};

    //objetos 
    bool hueso=false;//0
    bool bikini=false;//1
    bool zapatillas=false;//2
    bool llave=false;//3
    bool regalo=false;//4

    unsigned char memoria[200][200];
    unsigned char mapaSuperficieTemp[200][200];
    unsigned char mapaSuperficie[100][100];
    int tiempo=0;
    bool inaccesible=false;
    int umbral=150;
    unsigned int veces_inaccesible=0;

    Action ultimaaccion=actIDLE;

    // Para el plan
    bool estoy_ejecutando_plan=false;
    bool error_plan=false;
    list <Action> plan;



    struct doblePair{
      pair< int, int> regalo;
      pair< int, int> agente;
    };

    struct ordenadoblePair {
      bool operator()(const doblePair &a, const doblePair &b) {
        return (abs(a.regalo.first-a.agente.first)+abs(a.regalo.second-a.agente.second))
         < (abs(b.regalo.first-b.agente.first)+abs(b.regalo.second-b.agente.second));
      }
    };

    void Rellenar(vector<vector< unsigned char> > & mapaResultado){
      int n_A, n_B, n_D, n_P, n_S, n_T, n_K, n_M, n_interr, mayor=-1, interr_total=0, interr_total_anterior=0 ;
      char relleno='T';

      do{
        interr_total=0;
        for (int i=0; i<mapaResultado.size();i++){
          for (int j=0; j<mapaResultado.size(); j++){
            if(mapaResultado[i][j]=='?'){
              interr_total++;
              n_A=0; n_B=0; n_D=0; n_P=0; n_S=0; n_T=0; n_K=0; n_M=0; n_interr=0;
              switch(mapaResultado[i-1][j]){
                case 'A': n_A++; break; case 'B': n_B++; break; case 'D': n_D++; break;
                case 'P': n_P++; break; case 'S': n_S++; break; case 'T': n_T++; break;
                case 'K': n_K++; break; case 'M': n_M++; break; case '?': n_interr++; break;
              }
              switch(mapaResultado[i-2][j]){
                case 'A': n_A++; break; case 'B': n_B++; break; case 'D': n_D++; break;
                case 'P': n_P++; break; case 'S': n_S++; break; case 'T': n_T++; break;
                case 'K': n_K++; break; case 'M': n_M++; break; case '?': n_interr++; break;
              }
              switch(mapaResultado[i+1][j]){
                case 'A': n_A++; break; case 'B': n_B++; break; case 'D': n_D++; break;
                case 'P': n_P++; break; case 'S': n_S++; break; case 'T': n_T++; break;
                case 'K': n_K++; break; case 'M': n_M++; break; case '?': n_interr++; break;
              }
              switch(mapaResultado[i+2][j]){
                case 'A': n_A++; break; case 'B': n_B++; break; case 'D': n_D++; break;
                case 'P': n_P++; break; case 'S': n_S++; break; case 'T': n_T++; break;
                case 'K': n_K++; break; case 'M': n_M++; break; case '?': n_interr++; break;
              }
              switch(mapaResultado[i][j-1]){
                case 'A': n_A++; break; case 'B': n_B++; break; case 'D': n_D++; break;
                case 'P': n_P++; break; case 'S': n_S++; break; case 'T': n_T++; break;
                case 'K': n_K++; break; case 'M': n_M++; break; case '?': n_interr++; break;
              }
              switch(mapaResultado[i][j-2]){
                case 'A': n_A++; break; case 'B': n_B++; break; case 'D': n_D++; break;
                case 'P': n_P++; break; case 'S': n_S++; break; case 'T': n_T++; break;
                case 'K': n_K++; break; case 'M': n_M++; break; case '?': n_interr++; break;
              }
              switch(mapaResultado[i][j+1]){
                case 'A': n_A++; break; case 'B': n_B++; break; case 'D': n_D++; break;
                case 'P': n_P++; break; case 'S': n_S++; break; case 'T': n_T++; break;
                case 'K': n_K++; break; case 'M': n_M++; break; case '?': n_interr++; break;
              }
              switch(mapaResultado[i][j+2]){
                case 'A': n_A++; break; case 'B': n_B++; break; case 'D': n_D++; break;
                case 'P': n_P++; break; case 'S': n_S++; break; case 'T': n_T++; break;
                case 'K': n_K++; break; case 'M': n_M++; break; case '?': n_interr++; break;
              }
              mayor = max(max(max(max(max(max(max(max(n_A,n_B),n_D),n_P),n_S),n_T),n_K),n_M),n_interr); 
            
              if(mayor==n_A){relleno='A';} else if(mayor==n_B){relleno='B';}
              else if(mayor==n_D){relleno='?';} else if(mayor==n_P){relleno='?';}
              else if(mayor==n_S){relleno='S';} else if(mayor==n_T){relleno='T';}
              else if(mayor==n_K){relleno='?';} else if(mayor==n_M){relleno='M';}
              else{relleno='?';}
              mapaResultado[i][j]=relleno;
            }
          }
        }

        if(interr_total==interr_total_anterior){
          interr_total=0;
        }

      interr_total_anterior=interr_total;
      }while(interr_total!=0);  
    }

    int pisable(int fil, int col){
      int salida;
    	switch(mapaResultado[fil][col]){
    		case 'S':
    		case 'T':
    		case 'K':
    		case '?': salida= 1;
    			break;  
    		default: salida= 0;
    	}
      if(mapaSuperficie[fil][col]!='_')
        salida=0;

      return salida;
    }

    estadoP operadorIz( const estadoP & nodo){
      estadoP k=nodo;
      k.e.orientacion = (k.e.orientacion+3)%4;
      k.p=nodo.p;
      k.p.push_back(actTURN_L);
      return k;
    }

    estadoP operadorDer(const estadoP & nodo){
      estadoP k=nodo;
      k.e.orientacion = (k.e.orientacion+1)%4;
      k.p=nodo.p;
      k.p.push_back(actTURN_R);
      return k;
    } 

    estadoP operadorAvanza(const estadoP & nodo){
      estadoP k=nodo;
      switch(k.e.orientacion){
        case 0: k.e.fila--; break;
        case 1: k.e.columna++; break;
        case 2: k.e.fila++; break;
        case 3: k.e.columna--; break;
      }
      k.p=nodo.p;
      k.p.push_back(actFORWARD);
      return k;
    }

    void aplicaOperadores(estadoP base, estadoP & iz, estadoP & der, estadoP & av){
      iz = operadorIz(base);
      der = operadorDer(base);
      av = operadorAvanza(base);
    }

    int distanciaManhattan(int fil, int col){
      return abs(fila-fil)+abs(columna-col);
    }

    bool buscarRey(int fil, int col, estado & reycercano){
      int filrey1=-1,colrey1=-1,filrey2=-1,colrey2=-1;

      for(int i=99;i>fil;i--)
        for(int j=99;j>col;j--)
          if(mapaSuperficie[i][j]=='r'){
            filrey1=i;
            colrey1=j;
          }  
      
      for(int i=0;i<fil;i++)
        for(int j=0;j<col;j++)
          if(mapaSuperficie[i][j]=='r'){
            filrey2=i;
            colrey2=j;
          }

      if (filrey1==-1&&filrey2==-1){
        return false;
      }
      else{ 
        if(filrey1==-1&&filrey2!=-1){
          reycercano.fila=filrey2;
          reycercano.columna=colrey2;
          reycercano.orientacion=0;
        }  
        else{ 
          if(filrey1!=-1&&filrey2==-1){
            reycercano.fila=filrey1;
            reycercano.columna=colrey1;
            reycercano.orientacion=0;
          }
          else{
            if(distanciaManhattan(filrey1,colrey1)<distanciaManhattan(filrey2,colrey2)){
              reycercano.fila=filrey1;
              reycercano.columna=colrey1;
              reycercano.orientacion=0;
            }
            else{
              reycercano.fila=filrey2;
              reycercano.columna=colrey2;
              reycercano.orientacion=0;
            }
          }
        }
        return true;
      }      
    }
    

    int distancia(estado a, estado b){
      return ( abs(a.fila-b.fila)+abs(a.columna-b.columna));
    }
    
    Action Reactivo(Sensores sensores);
    Action Deliberativo(Sensores sensores);

    vector<pair< int, int> > ordenaRegalos(const vector<pair< int, int> > & regalos, int fil, int col){
      doblePair t;
      vector<doblePair> v;
      vector<pair< int, int> > salida;

      for(int i=0;i<regalos.size();i++){
          t.regalo=regalos[i];
          t.agente.first=fil;
          t.agente.second=col;
          v.push_back(t);
      }

      sort(v.begin(),v.end(), ordenadoblePair());

      for (int i = 0; i < v.size(); i++){
        salida.push_back(v[i].regalo);
      }
      return salida;
    }  

    Action avanza(){
      Action a = actTURN_R;
      if(estoyorientado){
        switch (orientacion){
          case 0:
            if(camino_mapaRes[fila-1][columna] <= camino_mapaRes[fila][columna+1] &&
               camino_mapaRes[fila-1][columna] <= camino_mapaRes[fila][columna-1] ){
              a =  actFORWARD;
            } 
            else if(camino_mapaRes[fila][columna+1] <= camino_mapaRes[fila-1][columna] &&
                    camino_mapaRes[fila][columna+1] <= camino_mapaRes[fila][columna-1]){
                    a =  actTURN_R;
            }               
            else if(camino_mapaRes[fila][columna-1] <= camino_mapaRes[fila-1][columna] &&
                    camino_mapaRes[fila][columna-1] <= camino_mapaRes[fila][columna+1]){
                  a =  actTURN_L;
            }
            break;
          case 1:
            if(camino_mapaRes[fila][columna+1] <= camino_mapaRes[fila-1][columna] &&
               camino_mapaRes[fila][columna+1] <= camino_mapaRes[fila+1][columna] ){
              a =  actFORWARD;
            } 
            else if(camino_mapaRes[fila+1][columna] <= camino_mapaRes[fila][columna+1] &&
                    camino_mapaRes[fila+1][columna] <= camino_mapaRes[fila-1][columna]){
                  a =  actTURN_R;
            }               
            else if(camino_mapaRes[fila-1][columna] <= camino_mapaRes[fila+1][columna] &&
                    camino_mapaRes[fila-1][columna] <= camino_mapaRes[fila][columna+1]){
                  a =  actTURN_L;
            }  
            break;
          case 2:
            if (camino_mapaRes[fila+1][columna] <= camino_mapaRes[fila][columna+1] &&
                camino_mapaRes[fila+1][columna] <= camino_mapaRes[fila][columna-1] ){
              a =  actFORWARD;
            } 
            else if(camino_mapaRes[fila][columna-1] <= camino_mapaRes[fila+1][columna] &&
                    camino_mapaRes[fila][columna-1] <= camino_mapaRes[fila][columna+1]){
                  a =  actTURN_R;
            }               
            else if(camino_mapaRes[fila][columna+1] <= camino_mapaRes[fila-1][columna] &&
                    camino_mapaRes[fila][columna+1] <= camino_mapaRes[fila][columna+1]){
                  a =  actTURN_L;
            }
            break;  
          case 3:
            if (camino_mapaRes[fila][columna-1] <= camino_mapaRes[fila-1][columna] &&
                camino_mapaRes[fila][columna-1] <= camino_mapaRes[fila+1][columna] ){
              a =  actFORWARD;
            } 
            else if(camino_mapaRes[fila-1][columna] <= camino_mapaRes[fila][columna-1] &&
                    camino_mapaRes[fila-1][columna] <= camino_mapaRes[fila+1][columna]){
                  a =  actTURN_R;
            }               
            else if(camino_mapaRes[fila+1][columna] <= camino_mapaRes[fila-1][columna] &&
                    camino_mapaRes[fila+1][columna] <= camino_mapaRes[fila][columna-1]){
                  a =  actTURN_L;
            }
          }  
      }
      else{
          switch (orientacion){
          case 0:
            if(camino_memoria[fila-1][columna] <= camino_memoria[fila][columna+1] &&
               camino_memoria[fila-1][columna] <= camino_memoria[fila][columna-1] ){
              a =  actFORWARD;
            } 
            else if(camino_memoria[fila][columna+1] <= camino_memoria[fila-1][columna] &&
                    camino_memoria[fila][columna+1] <= camino_memoria[fila][columna-1]){
                  a =  actTURN_R;
            }               
            else if(camino_memoria[fila][columna-1] <= camino_memoria[fila-1][columna] &&
                    camino_memoria[fila][columna-1] <= camino_memoria[fila][columna+1]){
                  a =  actTURN_L;
            }
            break;
          case 1:
            if(camino_memoria[fila][columna+1] <= camino_memoria[fila-1][columna] &&
               camino_memoria[fila][columna+1] <= camino_memoria[fila+1][columna] ){
              a =  actFORWARD;
            } 
            else if(camino_memoria[fila+1][columna] <= camino_memoria[fila][columna+1] &&
                    camino_memoria[fila+1][columna] <= camino_memoria[fila-1][columna]){
                  a =  actTURN_R;
            }               
            else if(camino_memoria[fila-1][columna] <= camino_memoria[fila+1][columna] &&
                    camino_memoria[fila-1][columna] <= camino_memoria[fila][columna+1]){
                  a =  actTURN_L;
            }  
            break;
          case 2:
            if (camino_memoria[fila+1][columna] <= camino_memoria[fila][columna+1] &&
                camino_memoria[fila+1][columna] <= camino_memoria[fila][columna-1] ){
              a =  actFORWARD;
            } 
            else if(camino_memoria[fila][columna-1] <= camino_memoria[fila+1][columna] &&
                    camino_memoria[fila][columna-1] <= camino_memoria[fila][columna+1]){
                  a =  actTURN_R;
            }               
            else if(camino_memoria[fila][columna+1] <= camino_memoria[fila-1][columna] &&
                    camino_memoria[fila][columna+1] <= camino_memoria[fila][columna+1]){
                  a =  actTURN_L;
            }
            break;  
          case 3:
            if (camino_memoria[fila][columna-1] <= camino_memoria[fila-1][columna] &&
                camino_memoria[fila][columna-1] <= camino_memoria[fila+1][columna] ){
              a =  actFORWARD;
            } 
            else if(camino_memoria[fila-1][columna] <= camino_memoria[fila][columna-1] &&
                    camino_memoria[fila-1][columna] <= camino_memoria[fila+1][columna]){
                 a =  actTURN_R;
            }               
            else if(camino_memoria[fila+1][columna] <= camino_memoria[fila-1][columna] &&
                    camino_memoria[fila+1][columna] <= camino_memoria[fila][columna-1]){
                 a =  actTURN_L;
            }
          } 
      }
      switch(a){
        case actFORWARD:
          break;
        case actTURN_L:
          orientacion = (orientacion+3)%4;
          girado=true;
          break;
        case actTURN_R:
          orientacion = (orientacion+1)%4;

          girado=true;
          break;     
      }
      return a;
    }

    void bloquear(){
      if(estoyorientado){
        switch (orientacion) {
          case 0:
            camino_mapaRes[fila-1][columna]+=3;
            break;

          case 1:
            camino_mapaRes[fila][columna+1]+=3;
            break;

          case 2:
            camino_mapaRes[fila+1][columna]+=3;
            break;

          case 3:
            camino_mapaRes[fila][columna-1]+=3;
            break;
        }
      }  
      else{
        switch (orientacion) {
          case 0:
            camino_memoria[fila-1][columna]+=3;
            break;

          case 1:
            camino_memoria[fila][columna+1]+=3;
            break;

          case 2:
            camino_memoria[fila+1][columna]+=3;
            break;

          case 3:
            camino_memoria[fila][columna-1]+=3;
            break;

        }
      }
    }

    Action gira(){
      if(estoyorientado){
        switch (orientacion) {
          case 0:
            if(camino_mapaRes[fila][columna-1] < camino_mapaRes[fila][columna+1]){
              orientacion = (orientacion+3)%4;
              girar=false;
              return actTURN_L;
            }
            else if(camino_mapaRes[fila][columna-1] > camino_mapaRes[fila][columna+1]){
              orientacion = (orientacion+1)%4;
              girar=false;
              return actTURN_R;
            }
            else{
              if (rand()%2){
                orientacion = (orientacion+3)%4;                
                girar=false;
                return actTURN_L;   
              }
              else{
                orientacion = (orientacion+1)%4;
                girar=false;
                return actTURN_R;
              }
            }
            break;
          case 1:
            if(camino_mapaRes[fila-1][columna] < camino_mapaRes[fila+1][columna]){
              orientacion = (orientacion+3)%4;
              girar=false;
              return actTURN_L;
            }
            else if(camino_mapaRes[fila-1][columna] > camino_mapaRes[fila+1][columna]){
              orientacion = (orientacion+1)%4;
              girar=false;
              return actTURN_R;
            }
            else{
              if (rand()%2){
                orientacion = (orientacion+3)%4;                
                girar=false;
                return actTURN_L;   
              }
              else{
                orientacion = (orientacion+1)%4;
                girar=false;
                return actTURN_R;
              }
            }
            break;
          case 2:
            if(camino_mapaRes[fila][columna-1] < camino_mapaRes[fila][columna+1]){
              orientacion = (orientacion+1)%4;
              girar=false;
              return actTURN_R;
            }
            else if(camino_mapaRes[fila][columna-1] > camino_mapaRes[fila][columna+1]){
              orientacion = (orientacion+3)%4;
              girar=false;
              return actTURN_L;
            }
            else{
              if (rand()%2){
                orientacion = (orientacion+3)%4;                
                girar=false;
                return actTURN_L;   
              }
              else{
                orientacion = (orientacion+1)%4;
                girar=false;
                return actTURN_R;
              }
            }
            break;  
          case 3:
            if(camino_mapaRes[fila-1][columna] < camino_mapaRes[fila+1][columna]){
              orientacion = (orientacion+1)%4;
              girar=false;
              return actTURN_R;
            }
            else if(camino_mapaRes[fila-1][columna] > camino_mapaRes[fila+1][columna]){
              orientacion = (orientacion+3)%4;
              girar=false;
              return actTURN_L;
            }
            else{
              if (rand()%2){
                orientacion = (orientacion+3)%4;                
                girar=false;
                return actTURN_L;   
              }
              else{
                orientacion = (orientacion+1)%4;
                girar=false;
                return actTURN_R;
              }
            }
            break;
        } 
      }
      else{
        switch (orientacion) {
          case 0:
            if(camino_memoria[fila][columna-1] < camino_memoria[fila][columna+1]){
              orientacion = (orientacion+3)%4;
              girar=false;
              return actTURN_L;
            }
            else if(camino_memoria[fila][columna-1] > camino_memoria[fila][columna+1]){
              orientacion = (orientacion+1)%4;
              girar=false;
              return actTURN_R;
            }
            else{
              if (rand()%2){
                orientacion = (orientacion+3)%4;                
                girar=false;
                return actTURN_L;   
              }
              else{
                orientacion = (orientacion+1)%4;
                girar=false;
                return actTURN_R;
              }
            }
            break;
          case 1:
            if(camino_memoria[fila-1][columna] < camino_memoria[fila+1][columna]){
              orientacion = (orientacion+3)%4;
              girar=false;
              return actTURN_L;
            }
            else if(camino_memoria[fila-1][columna] > camino_memoria[fila+1][columna]){
              orientacion = (orientacion+1)%4;
              girar=false;
              return actTURN_R;
            }
            else{
              if (rand()%2){
                orientacion = (orientacion+3)%4;                
                girar=false;
                return actTURN_L;   
              }
              else{
                orientacion = (orientacion+1)%4;
                girar=false;
                return actTURN_R;
              }
            }
            break;
          case 2:
            if(camino_memoria[fila][columna-1] < camino_memoria[fila][columna+1]){
              orientacion = (orientacion+1)%4;
              girar=false;
              return actTURN_R;
            } 
            else if(camino_memoria[fila][columna-1] > camino_memoria[fila][columna+1]){
              orientacion = (orientacion+3)%4;
              girar=false;
              return actTURN_L;
            }
            else{
              if (rand()%2){
                orientacion = (orientacion+3)%4;                
                girar=false;
                return actTURN_L;   
              }
              else{
                orientacion = (orientacion+1)%4;
                girar=false;
                return actTURN_R;
              }
            }
            break;  
          case 3:
           if(camino_memoria[fila-1][columna] < camino_memoria[fila+1][columna]){
              orientacion = (orientacion+1)%4;
              girar=false;
              return actTURN_R;
            }
            else if(camino_memoria[fila-1][columna] > camino_memoria[fila+1][columna]){
              orientacion = (orientacion+3)%4;
              girar=false;
              return actTURN_L;
            }
            else{
              if (rand()%2){
                orientacion = (orientacion+3)%4;                
                girar=false;
                return actTURN_L;   
              }
              else{
                orientacion = (orientacion+1)%4;
                girar=false;
                return actTURN_R;
              }
            }
            break;
          }
        }
    } 


    void ver(vector <unsigned char> terreno, vector<vector< unsigned char> > & mapaResultado ){
      switch (orientacion) {
        case 0: //norte
          if(estoyorientado){
            for(int i=9;i<=15;i++){
              if(columna+i-12<100 && fila-3 <100)
              mapaResultado[fila-3][columna+(i-12)]=terreno[i];
            }
            for(int i=4;i<=8;i++){
               if(columna+i-6<100 && fila -2 < 100)         
              mapaResultado[fila-2][columna+(i-6)]=terreno[i];
            }
            for(int i=1;i<=3;i++){ 
              if(columna+i-2<100 && fila-1 <100)                     
              mapaResultado[fila-1][columna+(i-2)]=terreno[i]; 
            }      
            if(columna<100 && fila<100){             
            mapaResultado[fila][columna]=terreno[0];
            camino_mapaRes[fila][columna]++;
            }
          } 
          else{
            for(int i=9;i<=15;i++){
              if(columna+i-12<200 && fila-3 <200)
              memoria[fila-3][columna+(i-12)]=terreno[i];
            }
            for(int i=4;i<=8;i++){
               if(columna+i-6<200 && fila -2 < 200) 
              memoria[fila-2][columna+(i-6)]=terreno[i];
            }
            for(int i=1;i<=3;i++){
             if(columna+i-2<200 && fila-1 <200)              
             memoria[fila-1][columna+(i-2)]=terreno[i]; 
            }
            if(columna<200 && fila<200){           
            memoria[fila][columna]=terreno[0];
            camino_memoria[fila][columna]++;
            }
          }
            break;

        case 1: //este
          if(estoyorientado){
            for(int i=9;i<=15;i++){
              if(fila+i-12<100 && columna+3 < 100)         
              mapaResultado[fila+(i-12)][columna+3]=terreno[i];
            }
            for(int i=4;i<=8;i++){
              if(fila+i-6<100 && columna+2 < 100)             
              mapaResultado[fila+(i-6)][columna+2]=terreno[i];
            }
            for(int i=1;i<=3;i++){
              if(fila+i-2<100 && columna+1 < 100)             
              mapaResultado[fila+(i-2)][columna+1]=terreno[i]; 
            }
            if(fila<100 && columna<100){                 
            mapaResultado[fila][columna]=terreno[0];
            camino_mapaRes[fila][columna]++;
            }
          }
          else{
            for(int i=9;i<=15;i++){
              if(fila+i-12<200 && columna+3 < 200)  
              memoria[fila+(i-12)][columna+3]=terreno[i];
            }
            for(int i=4;i<=8;i++){ 
               if(fila+i-6<200 && columna+2 < 200)                   
              memoria[fila+(i-6)][columna+2]=terreno[i];
            }
            for(int i=1;i<=3;i++){ 
              if(fila+i-2<200 && columna+1 < 200)                     
              memoria[fila+(i-2)][columna+1]=terreno[i]; 
            }
            if(fila<200 && columna< 200) {            
            memoria[fila][columna]=terreno[0];
            camino_memoria[fila][columna]++;
            }
          }
          break;

        case 2: //sur
          if(estoyorientado){
            for(int i=9;i<=15;i++){
              if(fila+3<100 && columna-i-12 < 100)             
              mapaResultado[fila+3][columna-(i-12)]=terreno[i];
            }
            for(int i=4;i<=8;i++){
              if(fila+2<100 && columna-i-6 < 100)                  
              mapaResultado[fila+2][columna-(i-6)]=terreno[i];
            }
            for(int i=1;i<=3;i++){
              if(fila+1<100 && columna-i-2 < 100)         
              mapaResultado[fila+1][columna-(i-2)]=terreno[i];
            }
             if(fila<100 && columna<100){  
            mapaResultado[fila][columna]=terreno[0];
            camino_mapaRes[fila][columna]++;
            }
          }
          else{
            for(int i=9;i<=15;i++){ 
              if(fila+3<200 && columna-i-12 < 200)         
              memoria[fila+3][columna-(i-12)]=terreno[i];
            }
            for(int i=4;i<=8;i++){
              if(fila+2<200 && columna-i-6 < 200)        
              memoria[fila+2][columna-(i-6)]=terreno[i];
            }
            for(int i=1;i<=3;i++){ 
              if(fila+1<200 && columna-i-2 < 200)  
              memoria[fila+1][columna-(i-2)]=terreno[i];
            }
             if(fila<200 && columna < 200){  
            memoria[fila][columna]=terreno[0];
            camino_memoria[fila][columna]++;
            }
          }
          break;

        case 3: //oeste
          if(estoyorientado){
            for(int i=9;i<=15;i++){
              if(fila-i-12<100 && columna-3 < 100) 
              mapaResultado[fila-(i-12)][columna-3]=terreno[i];
            }
            for(int i=4;i<=8;i++){
              if(fila-i-6<100 && columna-2 < 100) 
              mapaResultado[fila-(i-6)][columna-2]=terreno[i];
            }    
            for(int i=1;i<=3;i++){
              if(fila-i-2<100 && columna-1 < 100) 
              mapaResultado[fila-(i-2)][columna-1]=terreno[i];
            }    
            if(fila<100 && columna < 100){ 
            mapaResultado[fila][columna]=terreno[0];
            camino_mapaRes[fila][columna]++;
            }
          }
          else{
            for(int i=9;i<=15;i++){
              if(fila-i-12<200 && columna-3 < 200) 
              memoria[fila-(i-12)][columna-3]=terreno[i];
            }
            for(int i=4;i<=8;i++){        
              if(fila-i-6<200 && columna-2 < 200)  
              memoria[fila-(i-6)][columna-2]=terreno[i];
            } 
            //cout << endl;
            for(int i=1;i<=3;i++){
              if(fila-i-2<200 && columna-1 < 200)         
              memoria[fila-(i-2)][columna-1]=terreno[i];
            }
            if(fila<200 && columna < 200){ 
            memoria[fila][columna]=terreno[0];
            camino_memoria[fila][columna]++;
            }
          } 
          break;
      }
    }
    
    void verSuperficie(vector <unsigned char> superficie){
      switch (orientacion) {
        case 0: //norte
          if(estoyorientado){
            for(int i=9;i<=15;i++){
              if(columna+i-12<100 && fila-3 <100)
              mapaSuperficie[fila-3][columna+(i-12)]=superficie[i];
            }
            for(int i=4;i<=8;i++){
              if(columna+i-6<100 && fila -2 < 100)         
              mapaSuperficie[fila-2][columna+(i-6)]=superficie[i];
            }
            for(int i=1;i<=3;i++){ 
              if(columna+i-2<100 && fila-1 <100)                     
              mapaSuperficie[fila-1][columna+(i-2)]=superficie[i]; 
            }      
          } 
          else{
            for(int i=9;i<=15;i++){
              if(columna+i-12<200 && fila-3 <200)
              mapaSuperficieTemp[fila-3][columna+(i-12)]=superficie[i];
            }
            for(int i=4;i<=8;i++){
               if(columna+i-6<200 && fila -2 < 200) 
              mapaSuperficieTemp[fila-2][columna+(i-6)]=superficie[i];
            }
            for(int i=1;i<=3;i++){
             if(columna+i-2<200 && fila-1 <200)              
             mapaSuperficieTemp[fila-1][columna+(i-2)]=superficie[i]; 
            }
          }
            break;

        case 1: //este
          if(estoyorientado){
            for(int i=9;i<=15;i++){
              if(fila+i-12<100 && columna+3 < 100)         
              mapaSuperficie[fila+(i-12)][columna+3]=superficie[i];
            }
            for(int i=4;i<=8;i++){
              if(fila+i-6<100 && columna+2 < 100)             
              mapaSuperficie[fila+(i-6)][columna+2]=superficie[i];
            }
            for(int i=1;i<=3;i++){
              if(fila+i-2<100 && columna+1 < 100)             
              mapaSuperficie[fila+(i-2)][columna+1]=superficie[i]; 
            }
          }
          else{
            for(int i=9;i<=15;i++){
              if(fila+i-12<200 && columna+3 < 200)  
              mapaSuperficieTemp[fila+(i-12)][columna+3]=superficie[i];
            }
            for(int i=4;i<=8;i++){ 
               if(fila+i-6<200 && columna+2 < 200)                   
              mapaSuperficieTemp[fila+(i-6)][columna+2]=superficie[i];
            }
            for(int i=1;i<=3;i++){ 
              if(fila+i-2<200 && columna+1 < 200)                     
              mapaSuperficieTemp[fila+(i-2)][columna+1]=superficie[i]; 
            }
          }
          break;

        case 2: //sur
          if(estoyorientado){
            for(int i=9;i<=15;i++){
              if(fila+3<100 && columna-i-12 < 100)             
              mapaSuperficie[fila+3][columna-(i-12)]=superficie[i];
            }
            for(int i=4;i<=8;i++){
              if(fila+2<100 && columna-i-6 < 100)                  
              mapaSuperficie[fila+2][columna-(i-6)]=superficie[i];
            }
            for(int i=1;i<=3;i++){
              if(fila+1<100 && columna-i-2 < 100)         
              mapaSuperficie[fila+1][columna-(i-2)]=superficie[i];
            }
  
          }
          else{
            for(int i=9;i<=15;i++){ 
              if(fila+3<200 && columna-i-12 < 200)         
              mapaSuperficieTemp[fila+3][columna-(i-12)]=superficie[i];
            }
            for(int i=4;i<=8;i++){
              if(fila+2<200 && columna-i-6 < 200)        
              mapaSuperficieTemp[fila+2][columna-(i-6)]=superficie[i];
            }
            for(int i=1;i<=3;i++){ 
              if(fila+1<200 && columna-i-2 < 200)  
              mapaSuperficieTemp[fila+1][columna-(i-2)]=superficie[i];
            }
          }
          break;

        case 3: //oeste
          if(estoyorientado){
            for(int i=9;i<=15;i++){
              if(fila-i-12<100 && columna-3 < 100) 
             mapaSuperficie[fila-(i-12)][columna-3]=superficie[i];
            }
            for(int i=4;i<=8;i++){
              if(fila-i-6<100 && columna-2 < 100) 
              mapaSuperficie[fila-(i-6)][columna-2]=superficie[i];
            }    
            for(int i=1;i<=3;i++){
              if(fila-i-2<100 && columna-1 < 100) 
             mapaSuperficie[fila-(i-2)][columna-1]=superficie[i];
            }    
          }
          else{
            for(int i=9;i<=15;i++){
              if(fila-i-12<200 && columna-3 < 200) 
              mapaSuperficieTemp[fila-(i-12)][columna-3]=superficie[i];
            }
            for(int i=4;i<=8;i++){        
              if(fila-i-6<200 && columna-2 < 200)  
              mapaSuperficieTemp[fila-(i-6)][columna-2]=superficie[i];
            } 
            for(int i=1;i<=3;i++){
              if(fila-i-2<200 && columna-1 < 200)         
              mapaSuperficieTemp[fila-(i-2)][columna-1]=superficie[i];
            }
          } 
          break;
      }
    }

  Action sacar_objeto(unsigned char objetoActivo){
      if(ultimaaccion==actPUSH)
        return actPOP;
      else
        return actPUSH;
  }
    void Reiniciar();
    bool pathFinding(const estado &origen, const estado &destino, list<Action> &plan);


};


#endif
