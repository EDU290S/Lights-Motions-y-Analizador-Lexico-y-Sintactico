//LIMPIAR
void limpiar(){
    int i = 0, j = 0;
	while(temp2[i] == ' ' || temp2[i] == '\t')
	    i++;
    while(temp2[i] != '\0'){
		temp[j] = temp2[i];
        i++;
        j++;
	}
	temp[j] = '\0';
}


//VACIA UNA ARREGLO DE CARACTERES
void vaciar(char str[]){
	int n, i = strlen(str);
	for(n=0; n<i;n++){
		str[n] = '\0';
	}
}

//EXTRAE UNA CADENA DESPUES DEL IGUAL
void extraerCadena(char linea[], char subLinea[], char n){
	int i = 0, j = 0;
	while(linea[i] != n)
	    i++;
	i++;
    while(linea[i] != '\0'){
		subLinea[j] = linea[i];
        i++;
        j++;
	}
	subLinea[j] = '\0';
}

//EXTRAE UNA CADENA DESPUES DEL PUNTO
void extraerPropiedad(char linea[], char subLinea[]){
	int i = 0, j = 0;
	while(linea[i] != '.')
	    i++;
	i++;
    while(linea[i] != '\0' && linea[i] != ' '){
		subLinea[j] = linea[i];
        i++;
        j++;
	}
	subLinea[j] = '\0';
}

//CUENTA CUANTAS CADENAS PALABRAS HAY EN UNA CADENA
int cuentaPalabra(char cadena[]){
    int i = 0, cout = 0, tam = strlen(cadena);
	while(i<tam){
		while(i<tam && cadena[i] == ' '){i++;}
		if(i<tam){cout++;}
		while(i<tam && cadena[i] != ' '){i++;}
	}

	return cout;
}

//OBTIENE Y GUARDA EN tempPalabra LA PALABRA n DE UNA CADENA
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


//VALIDA SI UNA CADENA TERMINA EN ) Y DEVUELVE LA POSICION DEL MISMO
int finCiclo(char cadena[]){
	int pos = 0;
	enum Testado{q0,q1,qe};
    int i = strlen(cadena)-1;
	int estado = q0;
	while(i>=0 && estado == q0){
		switch(estado){
			case q0:
				if(cadena[i] == ' '){estado = q0;}
				else if(cadena[i] == ')'){
					estado = q1;
					pos = i;
				}
				else{estado=qe;}
				break;
		}
		i--;
	}
	return pos;
}

//EXTRAE LA CADENA DENTRO DE UN PARENTESIS
void extraerCP(char linea[], char subLinea[], int n){
	vaciar(subLinea);
	int i = 0, j = 0;
	while(i<n && linea[i] != '(')
	    i++;
	if(linea[i]!='\0'){
        i++;
	    while(i<n){
			subLinea[j] = linea[i];
	        i++;
	        j++;
		}
		subLinea[j] = '\0';
	}else{subLinea="fail";}
}
