#include <iostream>
using namespace std;

int main(){
	char letra;

	cout << "\nIntroduzca una letra en mayuscula: ";
	cin >> letra;
	
	letra=letra+32;

	cout <<  letra << "\n";


	system("pause");
}
