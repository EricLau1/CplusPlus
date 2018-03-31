#include <iostream>

// raiz quadrada usando a formula de newton

using namespace std;

double my_Sqrt(double x){
	double raiz, num_anterior, y;
	raiz = x / 2;
	for(double i = 1; i > 0.0001; i = y){
		num_anterior = raiz;
		raiz = (raiz * raiz + x) / (2 * raiz);
		y = raiz - num_anterior;
		if(y < 0){
			y = y * -1; // y tem que ser absoluto
		}
	}
	return raiz;
}

int main(){
	double numero;
	cout << "Informe um numero: ";
	cin >> numero;
	cout << "raiz quadrada: " << my_Sqrt(numero) << endl;
	return 0;
}
