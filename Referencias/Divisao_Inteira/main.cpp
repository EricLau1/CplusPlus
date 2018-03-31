#include <iostream>
using namespace std;

 // Algoritmo que faz Divisão inteira apenas com soma e subtração

int main(int argc,char *argv[]){
	int num, den, resultado;
	
	cout << "Informe o numerador: ";
	cin >> num;
	cout << "Informe o denominador: ";
	cin >> den;
	
	if(den == 0){
		cout << "Divisao por 0" << endl;
		exit(1); // encerra o programa
	}else{
		resultado = 0;
		while(num > den){
			num = num - den;
			resultado++;
		}
		
		cout << "Resultado da divisao: " << resultado << endl; 
	}

	return 0;
}
