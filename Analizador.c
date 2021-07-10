#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *reservada[] = {"int", "float", "String", "light", "waterjet", "if", "else", "while", "for", "range", "funtion", "return", "writeLn", "scribe", "off", "on", "intensity", "useColor", "declareColor", "pressure", "angle", "Delay", "id"};
char *entero[] = {""};
char *flotante[]= {""};
char *cadena[]= {""};
char *luz[]= {""};
char *fuente= {""};
char *funcion[]= {""};

int main(){
	
	FILE *archivo = fopen("programa.txt", "r");
	if(archivo == NULL){
		printf("Archivo no leido\n");
	}

	char aux;
	while(feof(archivo)==0){
		fscanf(archivo, "%c", aux);
		printf("%c", aux);
	}

	fclose(archivo);

	system("PAUSE");
}
