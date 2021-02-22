#ifndef COMPORTAMIENTOJUGADOR_H
#define COMPORTAMIENTOJUGADOR_H

#include "comportamientos/comportamiento.hpp"
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

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
  	//movimiento
  	int fila = 100;
    int columna =100; 
    int orientacion =0; //orientacion%4 = 0 n, 1 e, 2 s, 3 o
    bool estoyorientado=false;
    bool girar=false;
    bool girado=false;
    bool siguiendo_k=false;
    int camino_memoria[200][200]={{0}};
    int camino_mapaRes[100][100]={{0}};
    

    //objetos 
    bool hueso=false;//0
    bool bikini=false;//1
    bool zapatillas=false;//2
    bool llave=false;//3

    //auxiliares
    int n_muertes=0;
    unsigned char memoria[200][200];
    bool llenar=false;
    bool inimem=false;
    int tiempo=0;

    Action ultimaaccion=actIDLE;

    Action avanza(){
      Action a = actFORWARD;

      if(estoyorientado){
        switch (orientacion%4<0 ? (orientacion%4)+4 : orientacion%4){
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
          switch (orientacion%4<0 ? (orientacion%4)+4 : orientacion%4){
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
          orientacion--;
          girado=true;
          break;
        case actTURN_R:
          orientacion++;
          girado=true;
          break;     
      }
      return a;
    }

    void bloquear(){
      if(estoyorientado){
        switch (orientacion%4<0 ? (orientacion%4)+4 : orientacion%4) {
          case 0:
            camino_mapaRes[fila-1][columna]++;
            break;

          case 1:
            camino_mapaRes[fila][columna+1]++;
            break;

          case 2:
            camino_mapaRes[fila+1][columna]++;
            break;

          case 3:
            camino_mapaRes[fila][columna-1]++;
            break;
        }
      }  
      else{
        switch (orientacion%4<0 ? (orientacion%4)+4 : orientacion%4) {
          case 0:
            camino_memoria[fila-1][columna]++;
            break;

          case 1:
            camino_memoria[fila][columna+1]++;
            break;

          case 2:
            camino_memoria[fila+1][columna]++;
            break;

          case 3:
            camino_memoria[fila][columna-1]++;
            break;

        }
      }
    }

    Action gira(){
      if(estoyorientado){
        switch (orientacion%4<0 ? (orientacion%4)+4 : orientacion%4) {
          case 0:
            if(camino_mapaRes[fila][columna-1] < camino_mapaRes[fila][columna+1]){
              orientacion--;
              girar=false;
              return actTURN_L;
            }
            else if(camino_mapaRes[fila][columna-1] > camino_mapaRes[fila][columna+1]){
              orientacion++;
              girar=false;
              return actTURN_R;
            }
            else{
                orientacion--;                
                girar=false;
                return actTURN_L;   
              }
              else{
                orientacion++;
                girar=false;
                return actTURN_R;
              }
            }
            break;
          case 1:
            if(camino_mapaRes[fila-1][columna] < camino_mapaRes[fila+1][columna]){
              orientacion--;
              girar=false;
              return actTURN_L;
            }
            else if(camino_mapaRes[fila-1][columna] > camino_mapaRes[fila+1][columna]){
              orientacion++;
              girar=false;
              return actTURN_R;
            }
            else{
              if (rand()%2){
                orientacion--;                
                girar=false;
                return actTURN_L;   
              }
              else{
                orientacion++;
                girar=false;
                return actTURN_R;
              }
            }
            break;
          case 2:
            if(camino_mapaRes[fila][columna-1] < camino_mapaRes[fila][columna+1]){
              orientacion++;
              girar=false;
              return actTURN_R;
            }
            else if(camino_mapaRes[fila][columna-1] > camino_mapaRes[fila][columna+1]){
              orientacion--;
              girar=false;
              return actTURN_L;
            }
            else{
              if (rand()%2){
                orientacion--;                
                girar=false;
                return actTURN_L;   
              }
              else{
                orientacion++;
                girar=false;
                return actTURN_R;
              }
            }
            break;  
          case 3:
            if(camino_mapaRes[fila-1][columna] < camino_mapaRes[fila+1][columna]){
              orientacion++;
              girar=false;
              return actTURN_R;
            }
            else if(camino_mapaRes[fila-1][columna] > camino_mapaRes[fila+1][columna]){
              orientacion--;
              girar=false;
              return actTURN_L;
            }
            else{
              if (rand()%2){
                orientacion--;                
                girar=false;
                return actTURN_L;   
              }
              else{
                orientacion++;
                girar=false;
                return actTURN_R;
              }
            }
            break;
        } 
      }
      else{
        switch (orientacion%4<0 ? (orientacion%4)+4 : orientacion%4) {
          case 0:
            if(camino_memoria[fila][columna-1] < camino_memoria[fila][columna+1]){
              orientacion--;
              girar=false;
              return actTURN_L;
            }
            else if(camino_memoria[fila][columna-1] > camino_memoria[fila][columna+1]){
              orientacion++;
              girar=false;
              return actTURN_R;
            }
            else{
              if (rand()%2){
                orientacion--;                
                girar=false;
                return actTURN_L;   
              }
              else{
                orientacion++;
                girar=false;
                return actTURN_R;
              }
            }
            break;
          case 1:
            if(camino_memoria[fila-1][columna] < camino_memoria[fila+1][columna]){
              orientacion--;
              girar=false;
              return actTURN_L;
            }
            else if(camino_memoria[fila-1][columna] > camino_memoria[fila+1][columna]){
              orientacion++;
              girar=false;
              return actTURN_R;
            }
            else{
              if (rand()%2){
                orientacion--;                
                girar=false;
                return actTURN_L;   
              }
              else{
                orientacion++;
                girar=false;
                return actTURN_R;
              }
            }
            break;
          case 2:
            if(camino_memoria[fila][columna-1] < camino_memoria[fila][columna+1]){
              orientacion++;
              girar=false;
              return actTURN_R;
            } 
            else if(camino_memoria[fila][columna-1] > camino_memoria[fila][columna+1]){
              orientacion--;
              girar=false;
              return actTURN_L;
            }
            else{
              if (rand()%2){
                orientacion--;                
                girar=false;
                return actTURN_L;   
              }
              else{
                orientacion++;
                girar=false;
                return actTURN_R;
              }
            }
            break;  
          case 3:
           if(camino_memoria[fila-1][columna] < camino_memoria[fila+1][columna]){
              orientacion++;
              girar=false;
              return actTURN_R;
            }
            else if(camino_memoria[fila-1][columna] > camino_memoria[fila+1][columna]){
              orientacion--;
              girar=false;
              return actTURN_L;
            }
            else{
              if (rand()%2){
                orientacion--;                
                girar=false;
                return actTURN_L;   
              }
              else{
                orientacion++;
                girar=false;
                return actTURN_R;
              }
            }
            break;
          }
        }
    }        

    void ver(vector <unsigned char> terreno, vector<vector< unsigned char> > & mapaResultado){
      switch (orientacion%4<0 ? (orientacion%4)+4 : orientacion%4) {
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
            mapaResultado[fila][columna]=terreno[0];
            camino_mapaRes[fila][columna]++;
          } 
          else{
            for(int i=9;i<=15;i++){
              memoria[fila-3][columna+(i-12)]=terreno[i];
            }
            for(int i=4;i<=8;i++){
              memoria[fila-2][columna+(i-6)]=terreno[i];
            }
            for(int i=1;i<=3;i++){          
             memoria[fila-1][columna+(i-2)]=terreno[i]; 
            }

            memoria[fila][columna]=terreno[0];
            camino_memoria[fila][columna]++;
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
            mapaResultado[fila][columna]=terreno[0];
            camino_mapaRes[fila][columna]++;
          }
          else{
            for(int i=9;i<=15;i++){
              memoria[fila+(i-12)][columna+3]=terreno[i];
            }
            for(int i=4;i<=8;i++){         
              memoria[fila+(i-6)][columna+2]=terreno[i];
            }
            for(int i=1;i<=3;i++){         
              memoria[fila+(i-2)][columna+1]=terreno[i]; 
            }
            memoria[fila][columna]=terreno[0];
            camino_memoria[fila][columna]++;
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
            mapaResultado[fila][columna]=terreno[0];
            camino_mapaRes[fila][columna]++;
          }
          else{
            for(int i=9;i<=15;i++){
              memoria[fila+3][columna-(i-12)]=terreno[i];
            }
            for(int i=4;i<=8;i++){       
              memoria[fila+2][columna-(i-6)]=terreno[i];
            }
            for(int i=1;i<=3;i++){        
              memoria[fila+1][columna-(i-2)]=terreno[i];
            }
            memoria[fila][columna]=terreno[0];
            camino_memoria[fila][columna]++;
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
            mapaResultado[fila][columna]=terreno[0];
            camino_mapaRes[fila][columna]++;
          }
          else{
            for(int i=9;i<=15;i++){
              memoria[fila-(i-12)][columna-3]=terreno[i];
            }
            for(int i=4;i<=8;i++){       
              memoria[fila-(i-6)][columna-2]=terreno[i];
            } 
            for(int i=1;i<=3;i++){         
              memoria[fila-(i-2)][columna-1]=terreno[i];
            }
            memoria[fila][columna]=terreno[0];
            camino_memoria[fila][columna]++;
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

    bool visto(char a, vector <unsigned char> terreno){
      bool v=false;
      for(int i=0; i<15; i++)
        if(terreno[i]==a){
        	v = true;
       	}	

      return v;   
    }

};

#endif