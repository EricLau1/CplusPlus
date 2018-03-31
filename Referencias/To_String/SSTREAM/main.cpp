// metodo toString()
// usando a biblioteca "sstream"

#include <iostream>
#include <sstream>
using namespace std;

class ObjetoExemplo{
	
	private:
	int numero;
	string nome;
	
	public:
		ObjetoExemplo(int nu, string no){
			this->numero = nu;
			this->nome = no;
		}
		
		string toString(){
		    ostringstream obj;
		    
		    obj << "Objeto Exemplo={";
		    obj << "numero: " << this->numero << " | ";
		    obj << "nome: " << this->nome << " }" << endl;
		    
			return obj.str();
		} // fim metodo toString()
};

int main(){
	
	ObjetoExemplo objeto(1,"Primeiro");
	
	cout << objeto.toString() << endl;
	
	return 0;
}
