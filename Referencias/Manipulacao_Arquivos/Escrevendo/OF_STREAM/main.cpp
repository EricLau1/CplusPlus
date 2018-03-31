#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ofstream escreva("mensagem.txt");
	
	escreva << "Ola mundo!" << endl;
	
	escreva.close();
	return 0;
}
