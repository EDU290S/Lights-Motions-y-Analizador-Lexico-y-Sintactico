#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char *reservada[] = {"int", "float", "String", "light", "waterjet", "if", "else", "while", "for", "range", "funtion", "return", "writeLn", "scribe", "off", "on", "intensity", "useColor", "declareColor", "pressure", "angle", "Delay", "id"};
char *entero[] = {""};
char *flotante[]= {""};
char *cadena[]= {""};
char *luz[]= {""};
char *fuente[]= {""};
char *funcion[]= {""};

bool esValida(char[]);
bool esReservada(char[]);
bool esEntero(char[]);
bool esFlotante(char[]);


int main(){
	
	char linea[200] = "23";
	printf("Linea de codigo a complilar: %s\n\n", linea);
	
	if(esValida(linea)){
		if(esReservada(linea)){
			printf("Es reservada\n");
		}else{printf("Es variable\n");}
	}else if(esEntero(linea)){
        printf("Es entero\n");
	}else if(esFlotante(linea)){
        printf("Es flotante\n");
	}else{printf("Es invalida\n");}
	

	system("PAUSE");
}


//Valida si una cadena es validad
bool esValida(char cadena[]){
    enum Testado{q0,q1,qe};
    int j = strlen(cadena);
	int estado = q0;
	int i = 0;
	
	while(i<j){
		switch(estado){
			case q0:
				if((cadena[i]>= 'a' && cadena[i]<='z')||(cadena[i]>= 'A' && cadena[i]<='Z')){
					estado = q1;
					break;
				}else{estado=qe;}
			case q1:
				if((cadena[i]>= 'a' && cadena[i]<='z')||(cadena[i]>= 'A' && cadena[i]<='Z')){
					estado = q1;
					break;
				}else{estado=qe;}
		}
		i++;
	}
	if(estado == q1){
		return true;
	}else{return false;}
}

//Valida si es palabra reservada una cadena
bool esReservada(char cadena[]){
	bool esRes = false;
	int i, tam = sizeof(reservada)/sizeof(char*);
	for(i=0; i<tam && esRes == false; i++){
		if(strcmp(cadena, reservada[i]) == 0){
			esRes = true;
		}
	}
	return esRes;
}

//Valida si es flotante
bool esFlotante(char cadena[]){
    enum Testado{q0,q1,q2,q3,qe};
    int j = strlen(cadena);
	int estado = q0;
	int i = 0;

	while(i<j){
		switch(estado){
			case q0:
				if((cadena[i]>= '0' && cadena[i]<='9')){
					estado = q1;
					break;
				}else{estado = qe;}
			case q1:
				if((cadena[i]>= '0' && cadena[i]<='9')){
					estado = q1;
					break;
				}else if(cadena[i]=='.'){
					estado = q2;
					break;
				}else{estado = qe;}
			case q2:
				if(cadena[i]>='0' && cadena[i]<='9'){
					estado = q3;
					break;
				}else{estado = qe;}
            case q3:
				if((cadena[i]>= '0' && cadena[i]<='9')){
					estado = q3;
					break;
				}else{estado = qe;}
		}
		i++;
	}
	if(estado == q3){
		return true;
	}else{return false;}
}

//Valida si es Entero
bool esEntero(char cadena[]){
    enum Testado{q0,q1,qe};
    int j = strlen(cadena);
	int estado = q0;
	int i = 0;

	while(i<j){
		switch(estado){
			case q0:
				if((cadena[i]>= '0' && cadena[i]<='9')){
					estado = q1;
					break;
				}else{estado = qe;}
			case q1:
				if((cadena[i]>= '0' && cadena[i]<='9')){
					estado = q1;
					break;
				}else{estado = qe;}
		}
		i++;
	}
	if(estado == q1){
		return true;
	}else{return false;}
}

