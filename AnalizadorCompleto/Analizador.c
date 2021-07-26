#include "Files/variables.h"
#include "Files/metodos.h"
#include "Files/validaciones.h"
#include "Files/sintaxis.h"
#define color SetConsoleTextAttribute

bool sintaxisCorrecta(char[]);

//INICIO FUNCION MAIN
int main(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
    ciclos = 0;
    funciones = 0;
	bool compilacion = true;
	color(hConsole, 1);
    printf("ABRIENDO ARCHIVO\n");
    
	//Lectura de archivo
	FILE *f;
	f = fopen("programa.txt","r");

	if(f == NULL){
        color(hConsole, 4);
		printf("\nNo se pudo abrir el archivo.\n");
		system("PAUSE");
		exit(1);
	}
	
	color(hConsole, 2); printf("ARCHIVO ENCONTRADO\n");
	color(hConsole, 1); printf("COMPILACION POR LINEA\n\n");

	//LECTURA ARCHIVO LINEA A LINEA
	int numeroLinea = 1;
	while(!feof(f)){
		fgets(temp2,200,f);
		limpiar();
		int j = strlen(temp);
		if(j>1){
			int tempA = cuentaPalabra(temp);
			if(tempA != 1){
	            if(temp[j-1] == '\n'){temp[j-1] = '\0';}
				if(sintaxisCorrecta(temp)){
					color(hConsole, 6); printf("%s    ", temp);
					color(hConsole, 2); printf("|correcto|\n");
				}else{
	            	color(hConsole, 14); printf("%s    ", temp);
	            	color(hConsole, 4); printf("|error|\n");
	            	compilacion = false;
	           		break;
				}
			}
		}
        numeroLinea++;
	}
	
	color(hConsole, 3); printf("\n\n\nESTADO DE LA COMPILACION\n");
	
	if(compilacion == true){
		if(ciclos == 0 && funciones == 0){
			color(hConsole, 2); printf("COMPILACION EXITOSA\n\n");
		}else{
	        color(hConsole, 4); printf("COMPILACION FALLIDA\n");
	        printf("%d Ciclos sin cerrar\n", ciclos);
	        printf("%d Funciones sin cerrar\n\n", funciones);
		}
	}else{
        color(hConsole, 4); printf("COMPILACION FALLIDA\n");
	    printf("error en la linea %d : ", numeroLinea);
	    color(hConsole, 15); printf("(%s)",temp);
	    color(hConsole, 4); printf(" sintaxis invalida\n\n");
	}
	
	color(hConsole, 15);
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
		while(i<tam && (linea[i] == ' ' || linea[i] == '\t')){i++;}
		if(i<tam){cout++;}
		while(i<tam && linea[i] != ' ' && linea[i] != '.' && linea[i] != '('){
			aux[a] = linea[i];
			i++;
			a++;
		}
		if(aux[0] != '\0'){
			break;
		}
	}
	//fin obtiene primer palabra
	
	 //inicia validacion de typo de linea a evaluar
	if(esValida(aux)){
		if(esReservada(aux) == true  && linea[i] == ' '){
            if(strcmp(aux, "int") == 0 ||
				strcmp(aux, "float") == 0 ||
				strcmp(aux, "string") == 0||
				strcmp(aux, "waterjet") == 0 ||
				strcmp(aux, "led") == 0){q0 = instancia;}
				
			else if(strcmp(aux, "delay") == 0){q0 = delay;}
			
			else if(strcmp(aux, "return") == 0){q0 = retorno;}
			
			else if(strcmp(aux, "while") == 0
					|| strcmp(aux, "if") == 0){q0 = si;}
					
			else if(strcmp(aux, "function") == 0){q0 = funcion;}
			
			else if(strcmp(aux, "for") == 0){q0 = para;}
			
			else if(strcmp(aux, "writeLn") == 0){q0 = escribir;}
			
			else if(strcmp(aux, "scribe") == 0){q0 = obtener;}
			
			else if(strcmp(aux, "FIN") == 0){q0 = fin;}
		}else{q0 = var;}
	}else{q0 = qe;}
	//fin validacion de typo de linea a evaluar
	
	//inicio casos a evaluar
	switch(q0){
		case var:
			esCorrecta = sintaxisAsignacion(linea, i);
			break;
		case funcion:
            esCorrecta = sintaxisFuncion(linea);
            break;
		case para:
            esCorrecta = sintaxisFor(linea);
            break;
		case delay:
            esCorrecta = sintaxisDelay(linea);
            break;
		case instancia:
            esCorrecta = sintaxisInstancia(linea);
            break;
		case si:
            esCorrecta = sintaxisCiclo(linea);
            break;
		case escribir:
            printf("SINTAXIS PRINT\n");
            break;
		case obtener:
            printf("SINTAXIS CIN\n");
            break;
		case retorno:
            esCorrecta = sintaxisRetorno(linea);
            break;
        case fin:
            esCorrecta = sintaxisFin(linea);
            break;
		case qe:
			printf("SINTAXIS INVALIDA PARA INICIO DE LINEA\n");
            break;
	}
	//fin casos a evaluar
	
	return esCorrecta;
}
//FIN FUNCION PRINCIPAL PARA VALIDAR SI LA SINTAXIS DE UNA LINEA ES CORRECTA
