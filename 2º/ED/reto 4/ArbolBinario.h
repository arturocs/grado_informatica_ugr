/*____________________________________________________________ */
//               Fichero ArbolBinario.h
/*____________________________________________________________ */

#include <cassert>
#include <istream>

using namespace std;
/**
  * @file ArbolBinario.h
  * @brief Fichero cabecera del TDA Arbol Binario
  * 
  */
  
#ifndef __ArbolBinario_h__
#define __ArbolBinario_h__

/**
  * @brief T.D.A. ArbolBinario
  *
  * Una instancia @e a del tipo de dato abstracto ArbolBinario sobre un
  * dominio Tbase se puede construir como
  * 
  * - Un objeto vac�o (�rbol vac�o) si no contiene ning�n elemento. Lo
  * denotamos {}
  * - Un �rbol que contiene un elemento destacado, el nodo ra�z, con un 
  * valor @e e en el dominio Tbase (denominado @e etiqueta), y dos 
  * sub�rboles (T<sub>i</sub>:izquierdo y T<sub>d</sub> derecho) del T.D.A. 
  * ArbolBinario sobre Tbase. 
  * Se establece una relaci�n @e padre-hijo entre cada nodo y los nodos ra�z
  * de los sub�rboles (si los hubiera) que cuelgan de �l. Lo denotamos 
  * {@e e,{T<sub>i</sub>},{T<sub>d</sub>}}.
  * 
  * Para poder usar el TDA ArbolBinario se debe incluir el fichero
  *
  * <tt>\#include ArbolBinario.h</tt>
  * 
  * El espacio requerido para el almacenamiento es @e O(n). Donde @e n es el
  * n�mero de nodos del �rbol.
  * 
  * @author 
  * @date 
  *
  */     
template <class Tbase>
class ArbolBinario {
/**
  * @page repConjunto Rep del TDA ArbolBinario
  *
  * @section invConjunto Invariante de la representaci�n
  *
  * Sea @e T, un �rbol binario sobre el tipo @e Tbase. Entonces el invariante 
  * de la representaci�n es
  *
  * Si @e T es vac�o, entonces T.laraiz = 0, y si no:
  *
  * T.laraiz->padre = 0 y
  *
  * \f$\forall n\f$ nodo de \e T, 
  *  n\f$\rightarrow\f$izqda \f$\neq\f$ n\f$\rightarrow\f$drcha y
  *
  * \f$\forall n,m\f$ nodos de \e T, si n\f$\rightarrow\f$izqda=m
  * � n\f$\rightarrow\f$drcha=m, entonces m\f$\rightarrow\f$padre= n
  *
  * @section faConjunto Funci�n de abstracci�n
  *
  * Sea @e T un �rbol binario sobre el tipo @e Tbase, entonces si lo denotamos 
  * tambi�n �rbol(T.laraiz), es decir, como el �rbol que cuelga de su ra�z, 
  * entonces �ste �rbol del conjunto de valores en la representaci�n se aplica 
  * al �rbol
  *
  * \f[
  * T.laraiz \rightarrow etiqueta,
  * \{Arbol(T.laraiz \rightarrow izqda)\},
  * \{Arbol(T.laraiz \rightarrow drcha)\},
  *    \f]
  * donde {0} es el �rbol vac�o.
  *
  */

  private:
    /** @brief En cada  estructura nodo se almacena una etiqueta del �rbol, que 
      * se implementa como un conjunto de nodos enlazados seg�n la relaci�n 
      * padre-hijo.
      */

    struct nodo {

      /** @brief Elemento almacenado. En este campo se almacena la etiqueta que 
        * corresponde a este nodo.
        */
      Tbase etiqueta;
        
      /** @brief Puntero al hijo izquierda. En este campo se almacena un puntero 
        * al nodo ra�z del sub�rbol izquierdo, o el valor 0 si no tiene. 
        */
      struct nodo *izqda;
        
      /**@brief Puntero al hijo derecho. En este campo se almacena un puntero al
        * nodo ra�z del sub�rbol derecho,  o el valor 0 si no tiene. 
        */
      struct nodo *drcha;
      
      /**@brief Puntero al padre. En este campo se almacena un puntero al nodo 
        * padre, o el valor 0 si es la ra�z. 
        */
      struct nodo *padre;
    };
    
    
    /**
      * @brief Destruye el sub�rbol.
      * @param n Nodo a destruir, junto con sus descendientes.
      *
      * Libera los recursos que ocupan @e n y sus descendientes.
      */
    void destruir(nodo * n);
    
    /**
      * @brief Copia un sub�rbol.
      * @param dest Referencia al puntero del que cuelga la copia.
      * @param orig Puntero a la ra�z del sub�rbol a copiar.
      *
      * Hace una copia de todo el sub�rbol que cuelga de @e orig en
	  * el puntero @e dest. Es importante ver que en @e dest->padre
	  * (si existe) no se asigna ning�n valor, pues no se conoce.
      */
    void copiar(nodo * & dest, nodo * orig);
      
    /**
      * @brief Cuenta el n�mero de nodos
      * @param n Nodo del que cuelga el sub�rbol de nodos a contabilizar
      *
      * Cuenta cu�ntos nodos cuelgan de @e n, incluido �ste
      */
    int contar(nodo * n);
      
    /**
      * @brief Comprueba igualdad de dos sub�rboles
      * @param n1 Primer sub�rbol a comparar
      * @param n2 Segundo sub�rbol a comparar
      *
	  * Comprueba si son iguales los sub�rboles que cuelgan de @e n1 y @e n2. 
	  * Para ello deber�n tener los mismos nodos en las mismas posiciones y 
	  * con las mismas etiquetas.
      */
    bool soniguales(nodo * n1, nodo * n2);
      
    /**
      * @brief Escribe un sub�rbol
      * @param out Stream de salida donde escribir
	  * @param nod Nodo del que cuelga el sub�rbol a escribir
	  *
	  * Escribe en la salida todos los nodos del sub�rbol que cuelga del nodo 
	  * @e nod siguiendo un recorrido en preorden. La forma de impresi�n de 
	  * cada nodo es:
	  *	- Si el nodo es nulo, imprime el car�cter 'x'.
      *	- Si el nodo no es nulo, imprime el car�cter 'n' seguido de un 
	  * 	 espacio, al que sigue la impresi�n de la etiqueta.
      */
    void escribe_arbol(std::ostream& out, nodo * nod) const;
      
    /**
      * @brief Lee un sub�rbol
      * @param in Stream de entrada desde el que leer
      * @param nod Referencia al nodo que contendr� el sub�rbol le�do
      * @see escribe_arbol
      *
	  * Lee de la entrada @e in los elementos de un �rbol seg�n el formato 
	  * que se presenta en la funci�n de escritura.
	  * 
      */
    void lee_arbol(std::istream& in, nodo *& nod);
      

  
  private: 
    /** @brief Puntero a la ra�z. Este miembro es un puntero al primer nodo, 
      * que corresponde a la ra�z del �rbol. Vale 0 si el �rbol es vac�o
      */
    struct nodo *laraiz;

  public:
    /**
      * @brief Tipo Nodo
      *
      * Este tipo nos permite manejar cada uno de los nodos del �rbol. Los 
	  * valores que tomar� ser�n tantos como nodos en el �rbol (para poder 
	  * referirse a cada uno de ellos) y adem�s un valor destacado 
	  * @e nulo (0), que indica que no se refiere a ninguno de ellos.
	  *
	  * Una variable @e n de este tipo se declara
	  *
	  * <tt> ArbolBinario::Nodo n; </tt>
	  *
	  * Las operaciones v�lidas sobre el tipo nodo son:
      * - Operador de Asignaci�n (=)
	  * - Operador de comprobaci�n de igualdad (==)
	  * - Operador de comprobaci�n de desigualdad (!=)
	  */
    typedef struct nodo * Nodo;
      

    /** @brief Constructor por defecto
      *
      * Reserva los recursos e inicializa el �rbol a vac�o {}. La operaci�n se 
	  * realiza en tiempo O(1).
      *
      */
    ArbolBinario();
    
    /**
      * @brief Constructor de ra�z
      *
      * @param e Etiqueta de la ra�z
      *
      * Reserva los recursos e inicializa el �rbol con un �nico nodo ra�z que 
      * tiene la etiqueta @e e, es decir, el �rbol {e,{},{}}. La operaci�n se 
      * realiza en tiempo O(1).
      */
      ArbolBinario(const Tbase& e);
      
    /**
      * @brief Constructor de copias
      * @param v ArbolBinario a copiar
      * 
      * Construye el �rbol duplicando el contenido de @e v en el �rbol
      * receptor. La operaci�n se realiza en tiempo O(n), donde n es el 
      * n�mero de elementos de @e v.
      */
      ArbolBinario(const ArbolBinario<Tbase>& v);
      
    /**
      * @brief Destructor
      *
      * Libera los recursos ocupados por el �rbol receptor. La operaci�n se 
      * realiza en tiempo O(n), donde n es el n�mero de elementos del �rbol 
      * receptor.
      */
    ~ArbolBinario();
    
    /**
      * @brief Operador de asignaci�n
      * @param v ArbolBinario a copiar
      * @return Referencia al �rbol receptor.
      *
      * Asigna el valor del �rbol duplicando el contenido de @e v en el �rbol 
      * receptor. La operaci�n se realiza en tiempo O(n), donde n es el n�mero
      * de elementos de @e v.
      */
    ArbolBinario<Tbase> & operator = (const ArbolBinario<Tbase> & v);
      
    /**
      * @brief Asignar nodo ra�z
      * @param e Etiqueta a asignar al nodo ra�z
      *
      * Vac�a el �rbol receptor y le asigna como valor el �rbol de un �nico 
      * nodo cuya etiqueta es @e e.
      */
    void AsignaRaiz(const Tbase & e);
      
    /**
      * @brief Ra�z del �rbol
      * @return Nodo ra�z del �rbol receptor.
      *
      * Devuelve el nodo ra�z, que es el nodo nulo si el �rbol est� vac�o. 
      * La operaci�n se realiza en tiempo O(1).     
      */
    Nodo raiz() const;
      
    /**
      * @brief Hijo izquierda
      * @param n Nodo del que se quiere obtener el hijo a la izquierda
      * @pre @e n no es nulo.
      * @return Nodo hijo a la izquierda.
      *
      * Devuelve el nodo hijo a la izquierda de @e n, que ser� el nodo nulo si 
      * no tiene hijo a la izquierda. La operaci�n se realiza en tiempo O(1).
      */
    Nodo izquierda(const Nodo n) const;
    
    /**
      * @brief Hijo derecha
      * @param n Nodo del que se quiere obtener el hijo a la derecha
      * @pre @e n no es nulo.
      * @return Nodo hijo a la derecha.
      *
      * Devuelve el nodo hijo a la derecha de @e n, que ser� el nodo nulo si 
      * no tiene hijo a la derecha. La operaci�n se realiza en tiempo O(1).
      */
    Nodo derecha(const Nodo n) const;
    
    /**
      * @brief Nodo padre
      * @param n Nodo del que se quiere obtener el padre
      * @pre @e n no es nulo
      * @return Nodo padre.
      *
      * Devuelve el nodo padre de @e n, que ser� el nodo nulo si es la ra�z. 
      * La operaci�n se realiza en tiempo O(1).
      */
    Nodo padre(const Nodo n) const;
    
    /**
      * @brief Etiqueta de un nodo
      * @param n Nodo en el que se encuentra el elemento.
      * @pre @e n no es nulo
      * @return Referencia al elemento del nodo @e n.
      *
      * Devuelve una referencia al elemento del nodo @e n y por tanto se puede 
      * modificiar o usar el valor. La operaci�n se realiza en tiempo O(1).     
      */
    Tbase& etiqueta(const Nodo n);
      
    /**
      * @brief Etiqueta de un nodo
      * @param n Nodo en el que se encuentra el elemento.
      * @pre @e n no es nulo
      * @return Referencia constante al elemento del nodo @e n.
      *
      * Devuelve una referencia al elemento del nodo @e n. Es constante y 
      * por tanto no se puede modificiar el valor. La operaci�n se realiza en 
      * tiempo O(1).
      */
    const Tbase& etiqueta(const Nodo n) const;
    
    /**
      * @brief Copia sub�rbol
      * @param orig �rbol desde el que se va a copiar una rama
      * @param nod Nodo ra�z del sub�rbol que se copia. Es un nodo del �rbol 
      * @e orig y no es nulo
      *
      * El �rbol receptor acaba con un valor copia del sub�rbol que cuelga del 
      * nodo @e nod en el �rbol @e orig. La operaci�n se realiza en tiempo 
      * O(n), donde @e n es el n�mero de nodos del sub�rbol copiado.
      */
    void asignar_subarbol(const ArbolBinario<Tbase>& orig, const Nodo nod);

    /**
      * @brief Podar sub�rbol izquierda
      * @param n Nodo al que se le podar� la rama hijo izquierda.
      * @param dest �rbol que recibe la rama cortada
      * @pre @e n no es nulo y es un nodo v�lido del �rbol receptor.
      *
      * Asigna un nuevo valor al �rbol @e dest, con todos los elementos del 
      * sub�rbol izquierdo del nodo @e n en el �rbol receptor. �ste se queda 
      * sin dichos nodos. La operaci�n se realiza en tiempo O(1).
      */
    void podar_izquierda(Nodo n, ArbolBinario<Tbase>& dest);
    
    /**
      * @brief Podar sub�rbol derecha
      * @param n Nodo al que se le podar� la rama hijo derecha.
      * @param dest �rbol que recibe la rama cortada
      * @pre @e n no es nulo y es un nodo v�lido del �rbol receptor.
      *
      * Asigna un nuevo valor al �rbol @e dest, con todos los elementos del 
      * sub�rbol derecho del nodo @e n en el �rbol receptor. �ste se queda 
      * sin dichos nodos. La operaci�n se realiza en tiempo O(1).
      */
    void podar_derecha(Nodo n, ArbolBinario<Tbase>& dest);

    /**
      * @brief Insertar sub�rbol izquierda
      * @param n Nodo al que se insertar� el �rbol @e rama como hijo izquierdo.
      * @param rama �rbol que se insertar� como hijo izquierdo.
      * @pre @e n no es nulo y es un nodo v�lido del �rbol receptor.
      *
      * El �rbol @e rama se inserta como hijo izquierda del nodo @e n del �rbol
      * receptor. El �rbol @e rama queda vac�o y los nodos que estaban en el 
      * sub�rbol izquierdo de @e n se eliminan.
      */
    void insertar_izquierda(Nodo n, ArbolBinario<Tbase>& rama);

    /**
      * @brief Insertar sub�rbol derecha
      * @param n Nodo al que se insertar� el �rbol @e rama como hijo derecho.
      * @param rama �rbol que se insertar� como hijo derecho.
      * @pre @e n no es nulo y es un nodo v�lido del �rbol receptor.
      *
      * El �rbol @e rama se inserta como hijo derecho del nodo @e n del �rbol
      * receptor. El �rbol @e rama queda vac�o y los nodos que estaban en el 
      * sub�rbol derecho de @e n se eliminan.
      */
    void insertar_derecha(Nodo n, ArbolBinario<Tbase>& rama);

    /**
      * @brief Borra todos los elementos
      *
      * Borra todos los elementos del �rbol receptor. Cuando termina, el �rbol 
      * est� vac�a. La operaci�n se realiza en tiempo O(n), donde n es el
      * n�mero de elementos del �rbol receptor.
      */
    void clear();
    
    /**
      * @brief N�mero de elementos
      * @return  El n�mero de elementos del �rbol receptor.
      *
      * La operaci�n se realiza en tiempo O(n).
      * @see contar
      */
    int size() const;
    
    /**
      * @brief Vac�o
      * @return Devuelve @e true si el n�mero de elementos del �rbol receptor 
      * es cero, @e false en otro caso.
      *
      * La operaci�n se realiza en tiempo O(1).
      */
    bool empty() const;
    
    /**
      * @brief Operador de comparaci�n (igualdad)
      * @param v ArbolBinario con el que se desea comparar
      * @return Devuelve @e true si el �rbol receptor tiene los mismos
      * elementos y en el mismo orden, y @e false en caso contrario.
      *
      * La operaci�n se realiza en tiempo O(n).
      * @see soniguales       
      */
    bool operator == (const ArbolBinario<Tbase>& v) const;
    
    /**
      * @brief Operador de comparaci�n (diferencia)
      * @param v ArbolBinario con el que se desea comparar
      * @return Devuelve @e true si el �rbol receptor no tiene los mismos
      * elementos y en el mismo orden, y @e false en caso contrario.
      *
      * La operaci�n se realiza en tiempo O(n).
      */
    bool operator != (const ArbolBinario<Tbase>& v) const;

      
    /**
      * @brief Operador de extracci�n de flujo
      * @param in Stream de entrada
      * @param v �rbol que leer 
      * @return Referencia al stream de entrada.
      *
      * Lee de @e in un �rbol y lo almacena en @e v. El formato aceptado para 
      * la lectura se puede consultar en la funci�n de salida.
      * @see lee_arbol 
      */
    template <class T>
    friend std::istream& operator >> (std::istream& in, ArbolBinario<T>& v);
    
    /**
      * @brief Operador de inserci�n de flujo
      * @param out Stream de salida
      * @param v �rbol que escribir
      * @return Referencia al stream de salida.
      *
      * Escribe en la salida todos los nodos del �rbol @e v siguiendo un 
      * recorrido en preorden. La forma de impresi�n de cada nodo es:
      * - Si el nodo es nulo, imprime el car�cter 'x'.
      * - Si el nodo no es nulo, imprime el car�cter 'n' seguido de 
      *   un espacio, al que sigue la impresi�n de la etiqueta.
      *
      * @see escribe_arbol
      */
    template <class T>
    friend std::ostream& operator << (std::ostream& out, 
                                      const ArbolBinario <T> & v);
};




/*____________________________________________________________ */
/*____________________________________________________________ */
//               FUNCIONES PRIVADAS
/*____________________________________________________________ */
/*____________________________________________________________ */

template <class Tbase>
void ArbolBinario <Tbase> :: destruir (nodo * n){
  if (n!=0){             //Si no es un nodo nulo,
    destruir(n->izqda);  //destruimos recursivamente su hijo izquierda y
    destruir(n->drcha);  //destruimos recursivamente su hijo derecha
    delete n;            //Una vez borrados los descendientes, borramos el nodo
  }
}

/*____________________________________________________________ */

template <class Tbase>
void ArbolBinario<Tbase>::copiar(nodo * & dest, nodo * orig){
  if (orig == 0)                      //Si el nodo origen es nulo,
    dest = 0;
  else{                               //Si no es el nodo nulo,
    dest = new nodo;                  //Reservamos el nodo destino
    dest->etiqueta = orig->etiqueta;  //Copiamos la etiqueta
    copiar(dest->izqda, orig->izqda); //Copiamos recursivamente el hijo izqda
    copiar(dest->drcha, orig->drcha); //Copiamos recursivamente el hijo drcha
    if (dest->izqda != 0)             //Si hay hijo izquierda,
      dest->izqda->padre = dest;      //actualizamos su padre
    if (dest->drcha != 0)             //Si hay hijo derecha,
      dest->drcha->padre = dest;      //actualizamos su padre
  }
}

/*____________________________________________________________ */

template <class Tbase>
int ArbolBinario<Tbase>::contar(nodo * n){
  if (n==0)      //Si es el nodo nulo,
    return 0;    //devuelve 0
  else 
    return 1+contar(n->izqda)+contar(n->drcha); //Caso general (recursivo)
}

/*____________________________________________________________ */

template <class Tbase>
bool ArbolBinario<Tbase>::soniguales(nodo * n1, nodo * n2){
  if (n1==0 && n2==0)                        //Si los dos nodos son nulos,
    return true;                             //devolvemos true
  else if (n1==0 || n2==0)                   //Si uno es nulo y el otro no
    return false;                            //devolvemos false
  else if (n1->etiqueta!=n2->etiqueta)       //Si sus etiquetas son distintas
    return false;                            //devolvemos false
  else if (!soniguales(n1->izqda,n2->izqda)) //Si los hijos izquierda no son =
    return false;                            //devolvemos false
  else if (!soniguales(n1->drcha,n2->drcha)) //Si los hijos derecha no son =
    return false;                            //devolemos false
  else                                       //En otro caso
    return true;                             //devolvemos true
}

/*____________________________________________________________ */

template <class Tbase>
void ArbolBinario <Tbase>::lee_arbol(std::istream& in, nodo * & nod){
  char c;
  in >> c;                     //Lectura de un car�cter
  if (c=='n'){                 //Si es 'n'
    nod= new nodo;             //Reservamos un nuevo nodo
    in >> nod->etiqueta;       //Leemos la etiqueta
    lee_arbol(in,nod->izqda);  //Leemos recursivamente el hijo izquierda
    lee_arbol(in,nod->drcha);  //Leemos recursivamente el hijo derecha
    if (nod->izqda!=0)         //Si hay hijo izquierda,
      nod->izqda->padre=nod;   //actualizamos su padre
    if (nod->drcha!=0)         //Si hay hijo derecha,
      nod->drcha->padre=nod;   //actualizamos su padre
  }
  else nod= 0;                 //Si no es 'n' hay un error en la entrada
                               //o no hay m�s caracteres que leer,
                               //y devolvemos un �rbol nulo
}

/*____________________________________________________________ */

template <class Tbase>
void ArbolBinario<Tbase>::escribe_arbol(std::ostream& out, nodo * nod) const{
  if (nod==0)                            //Si el nodo es nulo
    out << "x ";                         //escribimos 'x'
  else {                                 //Si el nodo no es nulo
    out << "n "<< nod->etiqueta << " ";  //escribimos su etiqueta
    escribe_arbol(out,nod->izqda);    //Escribimos el hijo izqda recursivamente
    escribe_arbol(out,nod->drcha);    //Escribimos el hijo drcha recursivamente
  }
}

/*____________________________________________________________ */
/*____________________________________________________________ */
//               FUNCIONES PUBLICAS
/*____________________________________________________________ */
/*____________________________________________________________ */


template <class Tbase>
inline ArbolBinario<Tbase>::ArbolBinario(){
  laraiz = 0;  //El constructor por defecto crea un �rbol vac�o
}

/*____________________________________________________________ */

template <class Tbase>
ArbolBinario<Tbase>::ArbolBinario(const Tbase& e){
  laraiz = new nodo;      //Crea el nodo ra�z
  laraiz->padre =         //No tiene padre,
  laraiz->izqda =         //hijo izquierda
  laraiz->drcha = 0;      //ni hijo derecha.
  laraiz->etiqueta = e;   //Asignamos valor a la etiqueta de la ra�z
}

/*____________________________________________________________ */

template <class Tbase>
ArbolBinario<Tbase>::ArbolBinario (const ArbolBinario<Tbase>& v){
  copiar (laraiz,v.laraiz); //Llamamos a copiar desde la ra�z
  if (laraiz!=0)            //Si no es el �rbol vac�o
    laraiz->padre= 0;       //actualizamos el padre
}

/*____________________________________________________________ */

template <class Tbase>
inline ArbolBinario<Tbase>::~ArbolBinario(){
  destruir(laraiz);  //Destruye llamando a destruir desde la ra�z 
}

/*____________________________________________________________ */

template <class Tbase>
ArbolBinario<Tbase> & 
ArbolBinario<Tbase>::operator = (const ArbolBinario<Tbase>&v){
  if (this!=&v){              //Comprobaci�n de rigor. Si no es el mismo objeto
    destruir(laraiz);         //destruimos el objeto *this
    copiar (laraiz,v.laraiz); //Llamamos a copiar desde la ra�z
    if (laraiz!=0)            //Si no es el �rbol vac�o
      laraiz->padre= 0;       //actualizamos el padre
  }
  return *this; //Devolvemos *this para permitir encadenamientos (a=b=c)
}

/*____________________________________________________________ */

template <class Tbase>
void ArbolBinario<Tbase>::AsignaRaiz(const Tbase& e){
  destruir(laraiz);     //Destruye el �rbol actual
  laraiz = new nodo;    //Reservamos el nodo ra�z
  laraiz->padre =       //No tiene padre,
  laraiz->izqda =       //ni hijo izquierda,
  laraiz->drcha = 0;    //ni hijo derecha.
  laraiz->etiqueta= e;  //Damos valor a la etiqueta de la ra�z
}

/*____________________________________________________________ */

template <class Tbase>
inline typename ArbolBinario<Tbase>::Nodo 
                ArbolBinario<Tbase>::raiz() const{
  return laraiz;
}

/*____________________________________________________________ */

template <class Tbase>
inline typename ArbolBinario<Tbase>::Nodo 
                ArbolBinario<Tbase>::izquierda(const Nodo p) const{
  assert(p!=0);       //El nodo no debe ser nulo
  return (p->izqda);
}

/*____________________________________________________________ */

template <class Tbase>
typename ArbolBinario<Tbase>::Nodo ArbolBinario<Tbase>::derecha(const Nodo p) const{
  assert(p!=0);       //El nodo no debe ser nulo
  return (p->drcha);
}

/*____________________________________________________________ */

template <class Tbase>
typename ArbolBinario<Tbase>::Nodo ArbolBinario<Tbase>::padre(const Nodo p) const{
  assert(p!=0);       //El nodo no debe ser nulo
  return (p->padre);
}

/*____________________________________________________________ */

template <class Tbase>
Tbase& ArbolBinario<Tbase>::etiqueta(const Nodo p){
  assert(p!=0);          //El nodo no debe ser nulo
  return (p->etiqueta);
}

/*____________________________________________________________ */

template <class Tbase>
const Tbase& ArbolBinario<Tbase>::etiqueta(const Nodo p) const{
  assert(p!=0);          //El nodo no debe ser nulo
  return (p->etiqueta);
}

/*____________________________________________________________ */

template <class Tbase>
void ArbolBinario<Tbase>::asignar_subarbol(const ArbolBinario<Tbase>& orig, 
                                           const Nodo nod){
  destruir(laraiz);    //Destruye el �rbol actual
  copiar(laraiz,nod);  //Copiamos el sub�rbol que cuelga de nod en la ra�z
  if (laraiz!=0)       //Si el sub�rbol copiado no es vac�o,
    laraiz->padre=0;   //actualizamos el padre
}


/*____________________________________________________________ */

template <class Tbase>
void ArbolBinario<Tbase>::podar_izquierda(Nodo n, ArbolBinario<Tbase>& dest){
  assert(n!=0);             //El nodo no debe ser nulo
  destruir(dest.laraiz);    //Destruimos el �rbol destino
  dest.laraiz=n->izqda;     //Copia el hijo izquierda de n en la ra�z de dest
  if (dest.laraiz!=0) {     //Si el sub�rbol copiado no es vac�o,
    dest.laraiz->padre=0;   //actualizamos el padre
    n->izqda=0;             //y actualizamos el hijo a la izquierda
  }
}


/*____________________________________________________________ */

template <class Tbase>
void ArbolBinario<Tbase>::podar_derecha(Nodo n, ArbolBinario<Tbase>& dest){
  assert(n!=0);             //El nodo no debe ser nulo
  destruir(dest.laraiz);    //Destruimos el �rbol destino
  dest.laraiz=n->drcha;     //Copia el hijo derecha de n en la ra�z de dest
  if (dest.laraiz!=0) {     //Si el sub�rbol copiado no es vac�o,
    dest.laraiz->padre=0;   //actualizamos el padre
    n->drcha=0;             //y actualizamos el hijo a la derecha
  }
}

/*____________________________________________________________ */

template <class Tbase>
void ArbolBinario<Tbase>::insertar_izquierda(Nodo n, ArbolBinario<Tbase>& rama){
  assert(n!=0);             //El nodo no debe ser nulo
  destruir(n->izqda);       //Destruimos el hijo izquierda
  n->izqda=rama.laraiz;     //Copia la rama en el hijo izquierda
  if (n->izqda!=0) {        //Si la rama copiada no es vac�a,
    n->izqda->padre= n;     //actualizamos el padre
    rama.laraiz=0;          //y actualizamos la ra�z en rama
  }
}

/*____________________________________________________________ */

template <class Tbase>
void ArbolBinario<Tbase>::insertar_derecha(Nodo n, ArbolBinario<Tbase>& rama){
  assert(n!=0);             //El nodo no debe ser nulo
  destruir(n->drcha);       //Destruimos el hijo izquierda
  n->drcha=rama.laraiz;     //Copia la rama en el hijo derecha
  if (n->drcha!=0) {        //Si la rama copiada no es vac�a,
    n->drcha->padre= n;     //actualizamos el padre
    rama.laraiz=0;          //y actualizamos la ra�z en rama
  }
}

/*____________________________________________________________ */

template <class Tbase>
void ArbolBinario<Tbase>::clear(){
  destruir(laraiz);    //Destruimos el �rbol recursivamente desde la ra�z
  laraiz= 0;           //Actualizamos la ra�z del �rbol
}

/*____________________________________________________________ */

template <class Tbase>
inline int ArbolBinario<Tbase>::size() const{
  return contar(laraiz);  //Contamos los nodos recursivamente desde la ra�z
}

/*____________________________________________________________ */

template <class Tbase>
inline bool ArbolBinario<Tbase>::empty() const{
  return (laraiz==0);
}

/*____________________________________________________________ */

template <class Tbase>
inline bool ArbolBinario<Tbase>::operator==(const ArbolBinario<Tbase>& v) const{
  return soniguales(laraiz,v.laraiz); //Comparamos los �rboles desde la ra�z
}

/*____________________________________________________________ */

template <class Tbase>
inline bool ArbolBinario<Tbase>::operator!=(const ArbolBinario<Tbase>& v) const{
  return !(*this==v); //Comparamos los �rboles desde la ra�z
}

/*____________________________________________________________ */

template <class Tbase>
inline istream& operator>> (istream& in, ArbolBinario<Tbase>& v){
  v.lee_arbol(in,v.laraiz); //Lee el �rbol
  return in;                //Devuelve in para permitir encadenamientos
}

/*____________________________________________________________ */

template <class Tbase>
inline ostream& operator<< (ostream& out, const ArbolBinario<Tbase>& v){
  v.escribe_arbol(out,v.laraiz); //Escribe el �rbol
  return out;                    //Devuelve out para permitir encadenamientos
}

/*____________________________________________________________ */


#endif
