#include <iostream>
using namespace std;

int main(){
   char min_izda, max_izda, min_dcha, max_dcha,char_izda, char_dcha;
   
	cout << "Introduzca min_izda "<< endl;
   	cin >> min_izda;
   	cout << "Introduzca max_dcha "<< endl;
   	cin >> max_dcha;
   	cout << "Introduzca min_dcha "<< endl;
   	cin >> min_dcha;   
  	cout << "Introduzca max_izda "<< endl;
   	cin >> max_izda;
   
	for (char_izda = min_izda;char_izda <= max_izda;char_izda++){	
	  for (char_dcha = min_dcha; char_dcha <= max_dcha; char_dcha++){
		cout <<char_izda << char_dcha << " ";
  }
		cout << "\n"; 
		
   }
   

}

