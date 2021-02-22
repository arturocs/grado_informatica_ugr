#include <iostream>
using namespace std;

int main(){

short horainicial;
short horafinal;
short minutoinicial;
short minutofinal;
short segundoinicial;
short segundofinal;
short diferenciadesegundos;

	// Entrada de datos
	cout << "\nIntroduzca la hora inicial: ";
	cin >> horainicial;
	cout << "\nIntroduzca el minuto inicial: ";
	cin >> minutoinicial;
	cout << "\nIntroduzca el segundo inicial: ";
	cin >> segundoinicial;
	cout << "\nIntroduzca la hora final: ";
	cin >> horafinal;
	cout << "\nIntroduzca el minuto final: ";
	cin >> minutofinal;
	cout << "\nIntroduzca el segundo final: ";
	cin >> segundofinal;

	// Cómputos
	diferenciadesegundos = (horafinal*3600+minutofinal*60+segundofinal)-(horainicial*3600+minutoinicial*60+segundoinicial);

	// Salida
	cout << "\nLa diferencia de segundos es: " << diferenciadesegundos ;

}
