#include <iostream>
#include <string>
using namespace std;

// limpando o buffer do teclado

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	string nome1;
	char nome2[100];
	string nome3;
	
	cout << "Digite um nome: ";
	cin >> nome1; // caso uma string com espa�os seja digitada cin ir� capturar apenas a palavra antes do espa�o
	
	//Se a string acima for uma frase com espa�os, a funcao gets ou getline ir� capturar string at� encontrar um \n
	
	fflush(stdin); // limpa o buffer, mas esta funcao nao e recomendada usar, pois e indefinida 
	
	//Agora a funcao gets n�o ir� capturar o resto de string deixada pelo cin 
	
	cout << "Digite um nome: ";
	gets(nome2); // le a string at� encontrar um \n ou enter
	
	cout << "Digite um nome: ";
	cin >> nome1;
	
	setbuf(stdin,NULL); // limpa o buffer, resolve na maioria dos casos
	
	cout << "Digite um nome: ";
	getline(cin,nome3); // le a string at� encontrar um \n ou enter
	
	cout << "\nPrimeiro nome: " << nome1 << endl;
	cout << "\nSegundo nome: " << nome2 << endl;
	cout << "\nTerceiro nome: " << nome3 << endl;
	
	int num;
	cout << "\nDigite um numero: ";
	cin >> num;
	
	// quando o enter for apertado um \n ficara no teclado e ser� capturado pela fun��o getline 
	
	cin.ignore(); // limpa o \n
	
	// Agora a funcao getline pode ler um novo nome
	
	cout << "Digite um novo nome: ";
	getline(cin,nome1);
	
	cout << "Novo nome: " << nome1 << endl;
		
	return 0;
}
