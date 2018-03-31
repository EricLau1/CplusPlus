#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ifstream leia("mensagem.txt");
	string texto;
	while(leia.good()){
		char caracter = leia.get(); // pega o caracter escrito no arquivo
		//cout << caracter;
		texto.push_back(caracter); // pega o valor da variavel e coloca no final da string 
	}
	leia.close();
	
	cout << texto << endl;
	
	return 0;
}
