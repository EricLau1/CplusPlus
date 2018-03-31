#include <iostream>
#include <string>
using namespace std;

// ler uma string que capture frases com espaços

int main(){
	setlocale(LC_ALL,"Portuguese");
	
	string nome;

	cout << "Informe nome completo: ";
	getline(cin,nome); // percorre a string até encontrar \n
	cout << "Nome digitado: "<< nome << endl;
		
	return 0;
}
