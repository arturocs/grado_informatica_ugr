#include <iostream>
using namespace std;

int main(){
	short segundosentrada;
	short minutosentrada;
	short horasentrada;
	short diassalida;
	short segundossalida;
	short minutossalida;
	short horassalida;
	

	cout << "\nIntroduzca los segundos: ";
	cin >> segundosentrada;
	cout << "\nIntroduzca los minutos: ";
	cin >> minutosentrada;
	cout << "\nIntroduzca las horas: ";
	cin >> horasentrada;
/*
segundossalida=segundosentrada%60;
minutossalida=(minutosentrada%60+segundosentrada/60)/60;
horassalida=horasentrada%24+minutosentrada/60;
diassalida=horasentrada/24;
*/
segundossalida=segundosentrada%60;
minutossalida=(minutosentrada%60+segundosentrada/60)%60;
horassalida=(horasentrada%24+minutosentrada/60+(minutosentrada%60+segundosentrada/60)/60)%24;
diassalida=(horasentrada%24+minutosentrada/60+(minutosentrada%60+segundosentrada/60)/60)/24;


	cout << "\n" << segundossalida << " segundos ";
	cout << "\n" << minutossalida << " minutos ";
	cout << "\n" << horassalida << " horas ";
	cout << "\n" << diassalida << " dias ";

	system("pause");
}
