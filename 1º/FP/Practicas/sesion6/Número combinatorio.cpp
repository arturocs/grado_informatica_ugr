#include <iostream> 
using namespace std;  
   
int main(){    
	int n, m;
	long long factorial_n, factorial_m, factorial_diferencia, combinatorio;

	cout << "\n\nIntroduzca n: ";
	cin >> n;
	cout << "\nIntroduzca m: ";
	cin >> m;
	
	factorial_n = 1;
	for (int i = 2; i <= n; i++)
		factorial_n = factorial_n * i;
		
	factorial_m = 1;
	for (int i = 2; i <= m; i++)
		factorial_m = factorial_m * i;

	factorial_diferencia = 1;
	for (int i = 2; i <= n - m; i++)
		factorial_diferencia = factorial_diferencia * i;

	combinatorio = factorial_n / (factorial_m * factorial_diferencia);
	cout << " El resultado es: " << combinatorio;
}
