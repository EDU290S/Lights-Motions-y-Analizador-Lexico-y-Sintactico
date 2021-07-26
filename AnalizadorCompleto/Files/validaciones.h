
//VALIDA SI UNA CADENA ES VALIDA
bool esValida(char cadena[]){
    enum Testado{q0,q1,qe};
    int j = strlen(cadena);
	int estado = q0;
	int i = 0;

	while(i<j){
		switch(estado){
			case q0:
				if((cadena[i]>= 'a' && cadena[i]<='z')||(cadena[i]>= 'A' && cadena[i]<='Z')){estado = q1;}
				else{estado=qe;}
				break;
			case q1:
				if((cadena[i]>= 'a' && cadena[i]<='z')||(cadena[i]>= 'A' && cadena[i]<='Z')){estado = q1;}
				else{estado=qe;}
				break;
		}
		i++;
	}
	if(estado == q1){
		return true;
	}else{return false;}
}

//VALIDA SI UNA CADENA ES UNA OPERACION ARIRMETICA
bool esAritmetica(char line[]){
	bool sintaxis = false;
	enum estados{qf, qp, qc, qd, q0, qs, qe};
	int e = q0, tam = strlen(line), i = 0;
	while(i<tam){
		switch(e){
			case q0:
				if(line[i] == ' '){e=q0;}
				else if(line[i] >= '0' && line[i] <= '9'){e=qd;}
				else if(line[i] >= 'a' && line[i] <= 'z'){e=qc;}
				else if(line[i] >= 'A' && line[i] <= 'Z'){e=qc;}
				else{e=qf;}
				break;
			case qc:
                if(line[i] >= 'a' && line[i] <= 'z'){e=qc;}
				else if(line[i] >= 'A' && line[i] <= 'Z'){e=qc;}
				else if(line[i]=='*' || line[i]=='+' || line[i]=='/' || line[i]=='-'){e=qs;}
				else if(line[i] == ' '){e=qe;}
				else{e=qf;}
				break;
			case qd:
                if(line[i] >= '0' && line[i] <= '9'){e=qd;}
				else if(line[i]=='*' || line[i]=='+' || line[i]=='/' || line[i]=='-'){e=qs;}
				else if(line[i]=='.'){e=qp;}
				else if(line[i] == ' '){e=qe;}
				else{e=qf;}
				break;
			case qp:
                if(line[i] >= '0' && line[i] <= '9'){e=qp;}
				else if(line[i]=='*' || line[i]=='+' || line[i]=='/' || line[i]=='-'){e=qs;}
				else if(line[i] == ' '){e=qe;}
				else{e=qf;}
				break;
			case qe:
				if(line[i] == ' '){e=qe;}
				else if(line[i]=='*' || line[i]=='+' || line[i]=='/' || line[i]=='-'){e=qs;}
				else{e=qf;}
				break;
			case qs:
                if(line[i] == ' '){e = qs;}
				else if(line[i] >= '0' && line[i] <= '9'){e=qd;}
				else if(line[i] >= 'a' && line[i] <= 'z'){e=qc;}
				else if(line[i] >= 'A' && line[i] <= 'Z'){e=qc;}
				else{e=qf;}
				break;
		}
		i++;
	}

	if(e == qc || e==qd || e==qp || e==qe || e==q0){
		sintaxis = true;
	}else{sintaxis = false;}

	return sintaxis;
}

//VALIDA SI UNA CADENA ES UNA OPERACION ARIRMETICA SIN ESPACIOS 
bool esAritmeticaNumeros(char line[]){
	bool sintaxis = false;
	enum estados{qf, qp, qc, qd, q0, qs};
	int e = q0, tam = strlen(line), i = 0;
	while(i<tam){
		switch(e){
			case q0:
				if(line[i] >= '0' && line[i] <= '9'){e=qd;}
				else if(line[i] >= 'a' && line[i] <= 'z'){e=qc;}
				else if(line[i] >= 'A' && line[i] <= 'Z'){e=qc;}
				else if(line[i] == '-'){e=qd;}
				else{e=qf;}
				break;
			case qc:
                if(line[i] >= 'a' && line[i] <= 'z'){e=qc;}
				else if(line[i] >= 'A' && line[i] <= 'Z'){e=qc;}
				else if(line[i]=='*' || line[i]=='+' || line[i]=='/' || line[i]=='-'){e=qs;}
				else{e=qf;}
				break;
			case qd:
                if(line[i] >= '0' && line[i] <= '9'){e=qd;}
				else if(line[i]=='*' || line[i]=='+' || line[i]=='/' || line[i]=='-'){e=qs;}
				else if(line[i]=='.'){e=qp;}
				else{e=qf;}
				break;
			case qp:
                if(line[i] >= '0' && line[i] <= '9'){e=qp;}
				else if(line[i]=='*' || line[i]=='+' || line[i]=='/' || line[i]=='-'){e=qs;}
				else{e=qf;}
				break;
			case qs:
				if(line[i] >= '0' && line[i] <= '9'){e=qd;}
				else if(line[i] >= 'a' && line[i] <= 'z'){e=qc;}
				else if(line[i] >= 'A' && line[i] <= 'Z'){e=qc;}
				else{e=qf;}
				break;
		}
		i++;
	}

	if(e == qc || e==qd || e==qp){
		sintaxis = true;
	}else{sintaxis = false;}

	return sintaxis;
}

//VALIDA SI UNA CADENA ES RESERVADA
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

//VALIDA SI UNA CADENA ES FLOTANTE
bool esFlotante(char cadena[]){
    enum Testado{q0,q1,q2,q3,qe};
    int j = strlen(cadena);
	int estado = q0;
	int i = 0;

	while(i<j){
		switch(estado){
			case q0:
				if((cadena[i]>= '0' && cadena[i]<='9')){estado = q1;}
				else{estado = qe;}
				break;
			case q1:
				if((cadena[i]>= '0' && cadena[i]<='9')){estado = q1;}
				else if(cadena[i]=='.'){estado = q2;}
				else{estado = qe;}
				break;
			case q2:
				if(cadena[i]>='0' && cadena[i]<='9'){estado = q3;}
				else{estado = qe;}
				break;
            case q3:
				if((cadena[i]>= '0' && cadena[i]<='9')){estado = q3;}
				else{estado = qe;}
				break;
		}
		i++;
	}
	if(estado == q3){
		return true;
	}else{return false;}
}

//VALIDA SI UNA CADENA ES ENTERO
bool esEntero(char cadena[]){
    enum Testado{q0,q1,qe};
    int j = strlen(cadena);
	int estado = q0;
	int i = 0;

	while(i<j){
		switch(estado){
			case q0:
				if((cadena[i]>= '0' && cadena[i]<='9')){estado = q1;}
				else{estado = qe;}
				break;
			case q1:
				if((cadena[i]>= '0' && cadena[i]<='9')){estado = q1;}
				else{estado = qe;}
				break;
		}
		i++;
	}
	if(estado == q1){
		return true;
	}else{return false;}
}

//VALIDA SI LA CADENA TERMINA EN PUNTO Y COMA
int finalizaCon(char cadena[]){
	int pos = 0;
	enum Testado{q0,q1,qe};
    int i = strlen(cadena)-1;
	int estado = q0;
	while(i>=0 && estado == q0){
		switch(estado){
			case q0:
				if(cadena[i]== ' '){estado = q0;}
				else if(cadena[i]== ')'){
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

//DETERMINA SI UNA CADENA CORRESPONDE A UN COLOR
bool esColor(char color[]){
    bool sintaxis = false;
	int i, tam = sizeof(colores)/sizeof(char*);
	for(i=0; i<tam && sintaxis == false; i++){
		if(strcmp(color, colores[i]) == 0){
			sintaxis = true;
		}
	}
	
	enum e {qe, q0, q1};
	int size = strlen(color), estado = q0;
	if(size==9){
		int i = 0;
		while(i<size){
			switch(estado){
				case q0:
					if(color[i]=='#'){estado = q1;}
					else{estado = qe;}
					break;
				case q1:
                    if(color[i]>='A' && color[i]<='F'){estado = q1;}
                    else if(color[i]>='a' && color[i]<='f'){estado = q1;}
                    else if(color[i]>='0' && color[i]<='9'){estado = q1;}
					else{estado = qe;}
			}
			i++;
		}
		if(estado == q1){sintaxis = true;}
	}
	
	return sintaxis;
}

//VALIDA SI ES OPERADOR
bool esOperador(char linea[]){
	bool sintaxis = false;
	if(strcmp(linea, "==") == 0 ||
			strcmp(linea, "!=") == 0 ||
			strcmp(linea, "<=") == 0 ||
			strcmp(linea, ">=") == 0 ||
			strcmp(linea, "<") == 0 ||
			strcmp(linea, ">") == 0){sintaxis = true;}
	
	return sintaxis;
}

//VALIDA SI ES CONECTOR
bool esConector(char linea[]){
	bool sintaxis = false;
	if(strcmp(linea, "AND") == 0 ||
			strcmp(linea, "OR") == 0){sintaxis = true;}

	return sintaxis;
}

//VALIDA SI ES INSTANCIA DE VARIABLE
bool esInstancia(char linea[]){
	bool sintaxis = false;
	if(strcmp(linea, "int") == 0 ||
		strcmp(linea, "float") == 0 ||
		strcmp(linea, "string") == 0||
		strcmp(linea, "waterjet") == 0 ||
		strcmp(linea, "led") == 0){sintaxis = true;}

	return sintaxis;
}

//VALIDA SI ES UNA VARIABLE
bool esVariable(char linea[]){
	bool sintaxis = false;
	if(esValida(linea) && esReservada(linea) == false){sintaxis = true;}
	return sintaxis;
}
