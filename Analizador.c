#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//TABLA DE SIMBOLOS
char *reservada[] = {"int", "float", "String", "led", "waterjet", "if", "else", "while", "for", "range", "funtion", "return", "writeLn", "scribe", "off", "on", "intensity", "useColor", "declareColor", "pressure", "angle", "delay", "id"};

bool sintaxisCorrecta(char[]);

bool esValida(char[]);
bool esReservada(char[]);
bool esEntero(char[]);
bool esFlotante(char[]);
bool esValor(char[]);
bool esAsignador(char[]);

void vaciar(char[]);
void obtPalabra(char[], int);
int cuentaPalabra(char[]);

bool sintaxisInstancia(char[]);
bool sintaxisAsignacion(char[]);
bool sintaxisFor(char[]);
bool sintaxisFuncion(char[]);

enum type {var, funcion, para, delay, instancia, si, escribir, obtener, retorno, qe};

char tempPalabra[50];

char aux[100];

//INICIO FUNCION MAIN
int main(){

	char linea[200] = "funtion int hola int waterjet return 0";
	
	if(sintaxisCorrecta(linea) == true){
		printf("\n\nexito \n\n");
	}else{printf("\n\nfail \n\n");}
	
	
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
		while(i<tam && linea[i] != ' '){
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
			esCorrecta = sintaxisAsignacion(linea);
			break;
		case funcion:
            printf("SINTAXIS FUNCION\n");
            esCorrecta = sintaxisFuncion(linea);
            break;   
		case para:
            printf("SINTAXIS FOR\n");
            break;
		case delay:
            printf("SINTAXIS RETRASO\n");
            break;
		case instancia:
            printf("SINTAXIS DEFINICION\n");
            esCorrecta = sintaxisInstancia(linea);
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
void obtPalabra(char linea[], int n){
    char aux[100] = "";
	vaciar(tempPalabra);
	int i = 0, a = 0, cout = 0, tam = strlen(linea);
	while(i<tam && cout < n){
        a = 0;
		vaciar(aux);
		while(i<tam && linea[i] == ' '){i++;}
		if(i<tam){cout++;}
		while(i<tam && linea[i] != ' '){
			aux[a] = linea[i];
			i++;
			a++;
		}
	}
	strcpy(tempPalabra, aux);
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

//determina si es valor valido
bool esValor(char valor[]){
	bool esV = false;
    if((esValida(valor) == true && esReservada(valor) == false) || esEntero(valor) || esFlotante(valor)){
		esV = true;
	}
	return esV;
}

//determina es asignador
bool esAsignador(char as[]){
    bool esA = false;
    if(strcmp(as, "=") == 0 ||
        strcmp(as, "intensity") == 0 ||
        strcmp(as, "pressure") == 0 ||
        strcmp(as, "angle") == 0 ||
        strcmp(as, "id") == 0
	){
		esA = true;
	}
	return esA;
}

//INICION METODOS PRUEBA DE SINTAXIS
//definicion de variables
bool sintaxisInstancia(char linea[]){
	bool sintaxis = false;
	int tam = cuentaPalabra(linea);
	if(tam == 2){
		obtPalabra(linea, 2);
		if(esValida(tempPalabra) == true && esReservada(tempPalabra) == false){
			sintaxis = true;
		}
	}
	return sintaxis;
}

//asignacion a variables
bool sintaxisAsignacion(char linea[]){
	bool sintaxis = false;
	int tam = cuentaPalabra(linea);
	if(tam == 3){
		obtPalabra(linea, 2);
		if(esAsignador(tempPalabra)){
			obtPalabra(linea, 3);
			if(esValor(tempPalabra)){
				sintaxis = true;
			}
		}
	}
	
	return sintaxis;
}

//sintaxis de funcion
bool sintaxisFuncion(char linea[]){
		bool sintaxis = false;
		int tam = cuentaPalabra(linea);
				if(tam == 7){
					obtPalabra(linea, 2);
						if(esReservada(tempPalabra)){
							obtPalabra(linea, 3);
							if(esValor(tempPalabra)){
								obtPalabra(linea, 4);
								if(esReservada(tempPalabra)){
									obtPalabra(linea, 5);
									if(esReservada(tempPalabra)){
										obtPalabra(linea, 6);
										if(esReservada(tempPalabra)){
											obtPalabra(linea, 7);
											if(esValor(tempPalabra)){
											sintaxis = true;
											}	
											}	
										}	
									}	
								}	
							}	
					
				}else if(tam == 6){
					obtPalabra(linea, 1);
					if(esReservada(tempPalabra)){
						obtPalabra(linea, 2);
						if(esReservada(tempPalabra)){
							obtPalabra(linea, 3);
							if(esAsignador(tempPalabra)){
								obtPalabra(linea, 4);
								if(esReservada(tempPalabra)){
									obtPalabra(linea, 5);
									if(esReservada(tempPalabra)){
										obtPalabra(linea, 6);
										if(esValor(tempPalabra)){
										sintaxis = true;}	
										}	
									}	
								}	
							}	
						}	
					}	
			return sintaxis;				
}

/* 

Ciclo for (sólo es un borrador)

int validar_ num(char numero [6]) // Inicia Función
int i=0, sw=0, j;
j=strlen(numero);

while (i<j&& sw==0){
	if(isdigit(numero[i])!0){
	i++;
	}
	else{
		sw=1;
	}
}

return sw;

int validar_ num(char numero [6]) // Inicia Función
int i=0, sw=0, j;
j=strlen(cadena);

while (i<j&& sw==0){
	if(isalpha(cadena[i])!0){
	i++;
	}
	else{
		sw=1;
	}
}

return sw;

*/
