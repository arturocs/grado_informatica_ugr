#ifndef hash_abierto_hpp
#define hash_abierto_hpp

#include <cassert>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

class CeldaLista{
private:
  int clave;
  int ptr;
public:
  CeldaLista():clave(-1),ptr(-1){};
  CeldaLista(int c, int p):clave(c),ptr(p){};
  ~CeldaLista(){};
  int & Clave(){
    return clave;
  }
  
  int & Datos(){
    return ptr;
  }
  
};

class TablaHash{
private:
  vector<list<CeldaLista> > tabla;
  int fhash(int clave);
  list<CeldaLista>::iterator EstaEnFila(int clave, int pos);
public:
  TablaHash(int tam);
  bool Existe(int clave);
  bool Insertar(int clave, int ptrdatos);
  bool Borrar(int clave);
  bool Cambiar(int clave, int ptrdatos);
  int Obtener(int clave);
  void imprimir();
};


TablaHash::TablaHash(int tam){
  assert(tam>0);
  tabla.resize(tam);
}

int TablaHash::fhash(int clave){
  return clave%tabla.size();
}

list<CeldaLista>::iterator TablaHash::EstaEnFila(int clave, int pos){
  list<CeldaLista>::iterator it;
  for(it=tabla[pos].begin(); it!=tabla[pos].end(); it++)
    if(it->Clave() == clave)
      return it;
  return it;
}

bool TablaHash::Existe(int clave){
  int pos = fhash(clave);
  return (EstaEnFila(clave, pos)!=tabla[pos].end());
}

bool TablaHash::Insertar(int clave, int ptrdatos){
  bool exito = false;
  int pos = fhash(clave);
  if (EstaEnFila(clave, pos) == tabla[pos].end()){
    tabla[pos].push_back(CeldaLista(clave,ptrdatos));
    exito = true;
  }
  return exito;
}

bool TablaHash::Cambiar(int clave, int ptrdatos){
  bool exito = false;
  int pos = fhash(clave);
  list<CeldaLista>::iterator donde = EstaEnFila(clave, pos);
  
  if (donde != tabla[pos].end()){
    donde->Datos() = ptrdatos;
    exito = true;
  }
  return exito;
}

int TablaHash::Obtener(int clave){
  int pos = fhash(clave);
  list<CeldaLista>::iterator donde = EstaEnFila(clave, pos);
  
  return(donde!=tabla[pos].end() ? donde->Datos(): -1);
}

bool TablaHash::Borrar(int clave){
  bool exito = false;
  int pos = fhash(clave);
  list<CeldaLista>::iterator donde = EstaEnFila(clave, pos);
  
  if (donde!=tabla[pos].end()){
    tabla[pos].erase(donde);
    exito = true;
  }
  return exito;
}

void TablaHash::imprimir(){
  list<CeldaLista>::iterator it;
  for(int i=0; i<tabla.size(); i++){
    cout << "Fila " << i << ": ";
    for(it=tabla[i].begin(); it!=tabla[i].end(); it++)
      cout << "(" << it->Clave() << "." << it->Datos() << ")";
    cout << endl;
  }
}




#endif /* hash_abierto_hpp */
