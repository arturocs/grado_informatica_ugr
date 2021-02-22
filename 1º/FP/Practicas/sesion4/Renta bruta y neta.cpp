#include <iostream>

using namespace std;

int main(){

bool trabajador;
bool pensionista;
bool casado;
double Renta_bruta;
double Retencion_fiscal;
double Retencion_fiscal_final;
double Renta_neta;

	// Entrada de datos
	cout << "\nIntroduzca si es trabajador: ";
	cin >> trabajador;
	cout << "\nIntroduzca si es pensionista: ";
	cin >> pensionista;
	cout << "\nIntroduzca si esta casado: ";
	cin >> casado;
	cout << "\nIntroduzca la renta bruta: ";
	cin >> Renta_bruta;
	cout << "\nIntroduzca la retencion fiscal: ";
	cin >> Retencion_fiscal;


if (trabajador)
Retencion_fiscal_final=Retencion_fiscal-3;
else{
  
  if (pensionista)
		Retencion_fiscal_final=Retencion_fiscal+1;
  else{
  	Retencion_fiscal_final=Retencion_fiscal+2;
  	
  	if (Renta_bruta<20000)
  		Retencion_fiscal_final=Retencion_fiscal_final+2;
  	else{
  		if (Renta_bruta<20000&&casado)
  		Retencion_fiscal_final=Retencion_fiscal_final+2.5;
  		if (Renta_bruta<20000&&!casado)
  		Retencion_fiscal_final=Retencion_fiscal_final+3;
  		
  		}
  	
  }
  
}
 
 Renta_neta = Renta_bruta - Renta_bruta * Retencion_fiscal_final / 100;
  cout << "\nLa renta neta es: " << Renta_neta ;
  
}
