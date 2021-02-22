#include <iostream>
#include <set>
#include <ctime>
#include <cstdlib>

using namespace std;



// Calcula la unión de 2 set<int> que se les pasa como parámetros y devuelve el conjunto resultante
set<int> unir2conj( const set<int> & a, const set<int> & b )
{
	set<int> resultado( a );
	
	for( register set<int>::const_iterator iterador_de_b = b.begin(); iterador_de_b != b.end(); ++iterador_de_b )
	{
		resultado.insert( *iterador_de_b );
	}
	
	return resultado;
}



// Calcula la intersección de 2 set<int> que se les pasa como parámetros y devuelve el conjunto resultante
set<int> interseccion2conj( const set<int> & a, const set<int> & b )
{
	set<int> resultado;

	if( a.size() < b.size() )
	{
		for( register set<int>::const_iterator iterador_de_a = a.begin(); iterador_de_a != a.end(); ++iterador_de_a )
		{
			if( b.find( *iterador_de_a ) != b.end() )
			resultado.insert( *iterador_de_a );
		}
	}
	
	else
	{
		for( register set<int>::const_iterator iterador_de_b = b.begin(); iterador_de_b != b.end(); ++iterador_de_b )
		{
			if( a.find( *iterador_de_b ) != a.end() )
			{
				resultado.insert( *iterador_de_b );
			}
		}
	}
	
	return resultado;
	
	
	/*	También es correcto
	if( a.size() < b.size() )
	{
		set<int> resultado(a);
	
		for( register set<int>::const_iterator iterador_de_a = a.begin(); iterador_de_a != a.end(); ++iterador_de_a )
		{
			if( b.find( *iterador_de_a ) == b.end() )
			{
				resultado.erase( *iterador_de_a );
			}
		}
		
		return resultado;
	}
	
	else
	{
		set<int> resultado( b );
	
		for( register set<int>::const_iterator iterador_de_b = b.begin(); iterador_de_b != b.end(); ++iterador_de_b )
		{
			if( a.find( *iterador_de_b ) == a.end() )
			{
				resultado.erase( *iterador_de_b );
			}
		}
		
		return resultado;
	}
	*/
}



// Calcula la diferencia de 2 conjuntos que se le pasa como parámetros (el primero menos el segundo) 
// y devuelve el conjunto resultante
// A\B son los elementos que están en A y que no están en B
set<int> diferencia2conjuntos( const set<int> & a, const set<int> & b )
{
	set<int> resultado( a );
	
	for( register set<int>::const_iterator iterador_de_a = a.begin(); iterador_de_a != a.end(); ++iterador_de_a )
	{
		if( b.find( *iterador_de_a ) != b.end() )
		{
			resultado.erase( *iterador_de_a );
		}
	}
	
	return resultado;
}



// Calcula la unión de 3 set<int> que se les pasa como parámetros y devuelve el conjunto resultante
set<int> unir3conj( const set<int> & a, const set<int> & b, const set<int> & c )
{
	return unir2conj( unir2conj( a, b ), c );
}



// Calcular el conjunto resultante de la intersección disjunta de tres conjuntos A, B y C, que se le pasan como parámetros
// formada por los elementos de A y B que no están en C, unión con los de B y C que no están en A, unión con los de C y A 
// que no están en B
set<int> interseccionDisjunta3conj( const set<int> & a, const set<int> & b, const set<int> & c )
{
	return unir2conj( unir2conj( diferencia2conjuntos( interseccion2conj( a, b ), c ),
	       		  	     diferencia2conjuntos( interseccion2conj( a, c ), b ) ), 
	       	          diferencia2conjuntos( interseccion2conj( b, c ), a ) );
}



template <class T>
ostream & operator<<(ostream & s, const set<T> & c){

  typename set<T>::const_iterator i;
  
  for (i=c.begin(); i != c.end(); i++)
      s << (*i) << " ";
  
  return s;
}



int main()
{
	set<int> a;
	set<int> b;
	set<int> c;
	
	a.insert( 1 );
	a.insert( 2 );
	a.insert( 4 );
	a.insert( 5 );
	a.insert( 8 );
	
	b.insert( 4 );
	b.insert( 5 );
	b.insert( 6 );
	b.insert( 9 );
	
	c.insert( 3 );
	c.insert( 4 );
	c.insert( 7 );
	c.insert( 8 );
	c.insert( 9 );
	
	cout << endl << "La unión de set a, set b y set c es: " <<  unir3conj( a, b, c ) << endl << endl;
	
	cout << "La intersección disjunta de set a, set b y set c es: " <<  interseccionDisjunta3conj( a, b, c ) << endl << endl;
	
	return 0;
}





