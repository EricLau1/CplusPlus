#include <iostream>
#include <ctime>
using namespace std;

int main(){
	time_t now;
	
	struct tm nowLocal;
	
	now = time(NULL); // pega a hora do sistema operacional
	
	nowLocal = *localtime(&now);

	cout << "Data do sistema: " << nowLocal.tm_mday<< " / " <<  nowLocal.tm_mon+1 << " / " << nowLocal.tm_year+1900<<endl;
	
	cout << "Hora do sistema: " << nowLocal.tm_hour << ":" << nowLocal.tm_min << ":" << nowLocal.tm_sec <<endl;
	
	return 0;
 }
