#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *reservada[] = {"int", "float", "String", "light", "waterjet", "if", "else", "while", "for", "range", "funtion", "return", "writeLn", "scribe", "off", "on", "intensity", "useColor", "declareColor", "pressure", "angle", "Delay", "id"};
char *entero[] = {""};
char *flotante[]= {""};
char *cadena[]= {""};
char *luz[]= {""};
char *fuente[]= {""};
char *funcion[]= {""};

enum Testado{q0,q1,qe};

void Validar(char[]);

int main(){
	
	char linea[200] = "int";
	printf("Linea de codigo a complilar: %s\n\n", linea);
	
	Validar(linea);
	

	system("PAUSE");
}

void Validar(char palabra[]){
    int j = strlen(palabra);
	int estado = q0;
	int i = 0;
	
	while(i<j){
		switch(estado){
			case q0:
				if((palabra[i]>= 'a' && palabra[i]<='z')||(palabra[i]>= 'A' && palabra[i]<='Z')){
					estado = q1;
					break;
				}else{estado=qe;}
			case q1:
				if((palabra[i]>= 'a' && palabra[i]<='z')||(palabra[i]>= 'A' && palabra[i]<='Z')){
					estado = q1;
					break;
				}else{estado=qe;}
		}
		i++;
	}
	
	if(estado==qe){
		printf("Invalida\n\n");
	}else{
		int i;
		int res = 0;
		for(i=0; reservada[i]!='\0' && reservada == 0; i++){
			if(strcmp(palabra, reservada[i])){
				res = 1;
				break;
			}
		}
		if(res == 1){
			printf("reservada\n\n");
		}else{printf("variable\n\n");}
	}
}

