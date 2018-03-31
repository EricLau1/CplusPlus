#include <iostream>
#include <windows.h>
#include <winuser.h>

using namespace std;

int main(){
		char i;
	while(1){
		for(i = 0; i <= 190; i++){
			if(GetAsyncKeyState(i) == -32767){
				printf("%d\n", i);
			}
	    }//fim for
	}//fim while
	return 0;
}
