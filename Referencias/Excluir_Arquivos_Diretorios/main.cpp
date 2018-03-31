#include <iostream>
#include <fstream>
#include <dirent.h>
using namespace std;

int main(){
	
	ofstream arq;
	
	const char *dir = "New";
	mkdir(dir);
	arq.open("New/arquivo.txt");
	arq << "arquivo criado com sucesso!" << endl;
	arq.close();
	
	char c;
	cout << "Apagar arquivo? (S/n) ~:> ";
	cin >> c;
	if(c == 'S' || c == 's'){
	   remove("New/arquivo.txt");
	   cout << "Apagar Diretorio? (S/n) ~:> ";
	   cin >> c;
	   if(c == 'S' || c == 's'){
	   		rmdir(dir);
	   }	
	} 
	
	
	return 0;
}
