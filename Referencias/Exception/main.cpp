#include <iostream>
using namespace std;

int div(int n1, int n2){
	if(n2 == 0)
		throw "Divisao por 0";
	return n1/n2;
}

int main(int argc, char *argv[]){
	
	try{
		int n1, n2;
		cout << "Digite um numero:~~> ";
		cin >> n1;
		cout << "Digite outro numero:~~> ";
        cin >> n2;		
		int num = div(n1, n2);
		cout << num << endl;
	}
	catch(const char* ex){ // variavel ex captura a mensagem do throw
		cerr << ex << endl;
	}
	catch(...){ // pega qualquer tipo de erro que não ainda foi tratado
		cerr << "Erro inesperado..." << endl;
	}
	
	return 0;
}
