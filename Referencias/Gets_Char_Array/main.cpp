#include <iostream>
using namespace std;

// ler um vetor de char que capture nomes com espa�os

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	char nome[100];
    cout << "Informe o nome completo: ";
    gets(nome); // aceita nomes com espa�os
    cout << "Nome digitado: " << nome << endl;
   
	return 0;
}
