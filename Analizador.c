#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//TABLA DE SIMBOLOS
char *reservada[] = {"int", "float", "String", "led", "waterjet", "if", "else", "while", "for", "range", "funtion", "return", "writeLn", "scribe", "off", "on", "intensity", "useColor", "declareColor", "pressure", "angle", "delay", "id"};

bool esValida(char[]);
bool esReservada(char[]);
bool esEntero(char[]);
bool esFlotante(char[]);
bool sintaxisCorrecta(char[]);

void vaciar(char[]);
void obtPalabra(char[], char[], int);
int cuentaPalabra(char[]);

enum type {var, funcion, para, delay, instancia, si, escribir, obtener, retorno, qe};

char aux[100];

//INICIO FUNCION MAIN
int main(){

	char linea[200] = "  elias.asi si me gusta a yo";
	sintaxisCorrecta(linea);
	printf("%d\n", cuentaPalabra(linea));
	system("PAUSE");
}
//FIN FUNCION MAIN

//INICIO FUNCION PRINCIPAL PARA VALIDAR SI LA SINTAXIS DE UNA LINEA ES CORRECTA
bool sintaxisCorrecta(char linea[]){
	bool esCorrecta = false;
	char aux[200] = "";
	int q0;
	//inicio obtiene primer palabra
	int i = 0, a = 0, cout = 0, tam = strlen(linea);
	while(i<tam){
		while(i<tam && linea[i] == ' '){i++;}
		if(i<tam){cout++;}
		while(i<tam && linea[i] != ' ' &&  linea[i] != '.' && linea[i] != '('){
			aux[a] = linea[i];
			i++;
			a++;
		}
		if(aux[0] != '\0'){
			break;
		}
	}
	//fin obtiene primer palabra
	printf("Primera Palabra: .%s.\n", aux);
	 //inicia validacion de typo de linea a evaluar
	if(esValida(aux) == true && esReservada(aux)==false){q0 = var;}
	if(esValida(aux)){
		if(esReservada(aux) == true){
            if(strcmp(aux, "int") == 0 ||
				strcmp(aux, "float") == 0 ||
				strcmp(aux, "string") == 0||
				strcmp(aux, "waterjet") == 0 ||
				strcmp(aux, "led") == 0){q0 = instancia;}
				
			else if(strcmp(aux, "delay") == 0){q0 = delay;}
			
			else if(strcmp(aux, "return") == 0){q0 = retorno;}
			
			else if(strcmp(aux, "while") == 0
					|| strcmp(aux, "if") == 0){q0 = si;}
					
			else if(strcmp(aux, "funtion") == 0){q0 = funcion;}
			
			else if(strcmp(aux, "for") == 0){q0 = para;}
			
			else if(strcmp(aux, "writeLn") == 0){q0 = escribir;}
			
			else if(strcmp(aux, "scribe") == 0){q0 = obtener;}
		}
	}else{q0 = qe;}
	//fin validacion de typo de linea a evaluar
	
	//inicio casos a evaluar
	switch(q0){
		case var:
            printf("SINTAXIS VARIABLE\n");
			break;
		case funcion:
            printf("SINTAXIS FUNCION\n");
            break;
		case para:
            printf("SINTAXIS FOR\n");
            break;
		case delay:
            printf("SINTAXIS RETRASO\n");
            break;
		case instancia:
            printf("SINTAXIS DEFINICION\n");
            break;
		case si:
            printf("SINTAXIS IF O WHILE\n");
            break;
		case escribir:
            printf("SINTAXIS PRINT\n");
            break;
		case obtener:
            printf("SINTAXIS CIN\n");
            break;
		case retorno:
            printf("SINTAXIS RETURN\n");
            break;
		case qe:
			printf("SINTAXIS INVALIDA PARA INICIO DE LINEA\n");
            break;
	}
	//fin casos a evaluar
	
	return esCorrecta;
}
//FIN FUNCION PRINCIPAL PARA VALIDAR SI LA SINTAXIS DE UNA LINEA ES CORRECTA


//Vacia una cadena de caracteres
void vaciar(char str[]){
	int n, i = strlen(str);
	for(n=0; n<i;n++){
		str[n] = '\0';
	}
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

//obtiene la palabra n de una cadena linea
void obtPalabra(char linea[], char aux[], int n){
    char aux2[100];
	vaciar(aux);
	int i = 0, a = 0, cout = 0, tam = strlen(linea);
	while(i<tam && cout < n){
        a = 0;
		vaciar(aux2);
		while(i<tam && linea[i] == ' '){i++;}
		if(i<tam){cout++;}
		while(i<tam && linea[i] != ' '){
			aux2[a] = linea[i];
			i++;
			a++;
		}
	}
	strcpy(aux, aux2);
}

//Cuenta las palabra en una cadena
int cuentaPalabra(char cadena[]){
    int i = 0, cout = 0, tam = strlen(cadena);
	while(i<tam){
		while(i<tam && cadena[i] == ' '){i++;}
		if(i<tam){cout++;}
		while(i<tam && cadena[i] != ' '){i++;}
	}
	
	return cout;
}
