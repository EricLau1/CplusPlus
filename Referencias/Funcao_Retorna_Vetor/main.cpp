#include <iostream>
#include <stdlib.h> // função malloc

using namespace std;

int* getVetor(int vetor[5]) {
	// ponteiro que aloca memoria para o tamanho do vetor
	int* v = (int*)malloc(sizeof(vetor));
	
	cout << "Vetor criado dentro dentro da funcao: " << endl; 
	for(int i = 0; i < 5; i++) {
		
		*(v + i) = vetor[i] + i;
		
		printf("v[%d] => %d\n", i, v[i]);
		
	}
	return v;	
}


int main() {
	
	int vetor[5] = {999, 999, 999, 999, 999};
	
	int * v = getVetor(vetor);
	
	cout << "\nVetor retornado da funcao: " << endl;
	
	for(int i = 0; i < 5; i++) {
		printf("v[%d] => %d\n", i, v[i]);
	}
	
	
	return 0;
}
