#include <iostream>
#include <exception>
#include <string.h>

using namespace std;

class ExcecaoCustomizada : public exception {
	
	protected:
		char msg[100];
		
		public:
			ExcecaoCustomizada(const char* ex){
				strcpy(msg, ex);
			}
			
			virtual const char* what(){ // metodo sobrecarregado da classe exception
				return msg;
			}
	
};

int fatorial(int n){
	if (n < 0)
	   throw ExcecaoCustomizada("Numero negativo...");
	
	if(n == 0 || n == 1)
	   return 1;
	return n * fatorial(n - 1);
}

int main(int argc, char *argv[]){
	
	try{
		int n;
		cout << "Digite um numero:~~> ";
		cin >> n;
		cout << "Fatorial de !" << n << " = " << fatorial(n) << endl;
		
	}
	catch(ExcecaoCustomizada ex){
		cerr << ex.what() << endl;
	}
	catch(...){
		cerr << "Erro inesperado..." << endl;
	}
	
	
	return 0;
}
