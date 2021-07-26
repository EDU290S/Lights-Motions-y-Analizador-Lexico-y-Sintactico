
//VALIDA LA SINTAXIS PARA DEFINIR UNA VARIABLE
bool sintaxisInstancia(char linea[]){
	bool sintaxis = false;
	int tam = cuentaPalabra(linea);
	if(tam == 2){
		obtPalabra(linea, 2);
		if(esVariable(tempPalabra)){
			sintaxis = true;
		}
	}
	return sintaxis;
}


//VALIDA SINTAXIS LLAMAR FUNCION
bool sintaxisLlamar(char linea[]){
	bool sintaxis = false;
	char aux[200] = "";
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

	if(esVariable(aux) && aux[i] == '('){
        posP = finCiclo(linea);
        if(posP > 0){
            extraerCP(linea, campos,posP);
            if(strlen(campos)==0)
                sintaxis = true;
			else{
                auxTam = cuentaPalabra(campos);
                if(auxTam == 0){
					sintaxis = true;
				}else if(auxTam%2 == 1){
	                p = 1;
	                sintaxis = true;
					while(p <= auxTam){
						if(p%2 == 1){
							obtPalabra(campos, p);
							if(esAritmeticaNumeros(tempPalabra) == false){sintaxis = false;}
						}
						if(p%2 == 0){
	                        obtPalabra(campos, p);
	                        if(strcmp(tempPalabra, ",") == 1){sintaxis = false;}
						}
						p++;
					}
				}
			}
		}
	}

	return sintaxis;
}



//VALIDA LA SINTAXIS PARA LA EDICION DE VALORES PARA VARIABLES
bool sintaxisAsignacion(char linea[], int pos){
	bool sintaxis = false;
	char valor[] = "";
	int tam = cuentaPalabra(linea);
	if(linea[pos] == ' '){
		if(tam > 2){
			obtPalabra(linea, 2);
			if(strcmp(tempPalabra, "=")==0){
                extraerCadena(linea, valor, '=');
                if(esAritmetica(valor) || sintaxisLlamar(valor))
					sintaxis = true;
			}
		}
	}else if(linea[pos] == '.'){
        if(tam == 1){
            extraerPropiedad(linea, valor);
            if(strcmp(valor, "on")==0 || strcmp(valor, "off")==0)
                sintaxis = true;
		}else if(tam>2){
            auxTam = tam;
            extraerPropiedad(linea, valor);
            if(strcmp(valor, "intensity") == 0 || strcmp(valor, "pressure") == 0 || strcmp(valor, "angle") == 0 || strcmp(valor, "id") == 0){
                obtPalabra(linea, 2);
				if(strcmp(tempPalabra, "=")==0){
                	extraerCadena(linea, valor, '=');
                	if(esAritmetica(valor) || sintaxisLlamar(valor))
						sintaxis = true;
				}
			}else if(strcmp(valor, "useColor") == 0 && auxTam ==3){
                obtPalabra(linea, 2);
				if(strcmp(tempPalabra, "=")==0){
                    obtPalabra(linea, 3);
					if(esColor(tempPalabra))
					    sintaxis = true;
				}
			}
		}
	}else if(linea[pos] == '('){
        posP = finCiclo(linea);
        if(posP > 0){
            extraerCP(linea, campos,posP);
            if(strlen(campos)==0)
                sintaxis = true;
			else{
                auxTam = cuentaPalabra(campos);
                if(auxTam == 0){
					sintaxis = true;
				}else if(auxTam%2 == 1){
	                p = 1;
	                sintaxis = true;
					while(p <= auxTam){
						if(p%2 == 1){
							obtPalabra(campos, p);
							if(esAritmeticaNumeros(tempPalabra) == false){sintaxis = false;}
						}
						if(p%2 == 0){
	                        obtPalabra(campos, p);
	                        if(strcmp(tempPalabra, ",") == 1){sintaxis = false;}
						}
						p++;
					}
				}
			}
		}
	}

	return sintaxis;
}

//VALIDA SI CUMPLE LA SINTAXIS PARA FOR
bool sintaxisFor(char linea[]){
	bool sintaxis = false;
	int tam = cuentaPalabra(linea);
	if(tam == 5){
		obtPalabra(linea, 2);
		if(esValida(tempPalabra) == true && esReservada(tempPalabra) == false){
            obtPalabra(linea, 3);
            if(strcmp(tempPalabra, "in")==0){
                obtPalabra(linea, 4);
                if(strcmp(tempPalabra, "range")==0){
                    obtPalabra(linea, 5);
                    if(esVariable(tempPalabra) || esEntero(tempPalabra)){sintaxis = true;}
				}
			}
		}
	}
	
	if(sintaxis == true){ciclos++;}
	
	return sintaxis;
}

//VALIDA SI UN RETRADO ES CORRECTO
bool sintaxisDelay(char linea[]){
	bool sintaxis = false;
	int tam = cuentaPalabra(linea);
	if(tam==2){
        obtPalabra(linea, 2);
        if((esVariable(tempPalabra)) || esEntero(tempPalabra)){sintaxis = true;}
	}
	return sintaxis;
}

//VALIDA LA SINTAXIS DE UNA LINEA DE RETORNO
bool sintaxisRetorno(char linea[]){
	bool sintaxis = false;
	int tam = cuentaPalabra(linea);
	if(tam>1){
        extraerCadena(linea, tempPalabra, ' ');
        if(esAritmeticaNumeros(tempPalabra) && funciones>0){sintaxis = true;}
	}
	return sintaxis;
}

//VALIDA LA SINTAXIS PARA UN WHILE O UN IF
bool sintaxisCiclo(char linea[]){
	bool sintaxis = true;
	posP = finCiclo(linea);
	obtPalabra(linea, 2);
	if(tempPalabra[0] == '('){
		if(posP>1){
			extraerCP(linea, campos,posP);
			if(strlen(campos)>0){
				auxTam = cuentaPalabra(campos);
				if(auxTam%4 == 3){
					p = 1;
					while(p<=auxTam){
						if(p%2 == 1){
							obtPalabra(campos, p);
							if(esAritmeticaNumeros(tempPalabra) == false){sintaxis = false;}
						}
						if(p%4==2){
	                        obtPalabra(campos, p);
	                        if(esOperador(tempPalabra) == false){sintaxis = false;}
						}
						if(p%4 == 0){
	                        obtPalabra(campos, p);
	                        if(esConector(tempPalabra) == false ){sintaxis = false;}
						}
						p++;
					}
				}
			}
		}
	}else{sintaxis = false;}
	
	if(sintaxis == true){ciclos++;}
	
	return sintaxis;
}


//VALIDA LA SINTAXIS PARA DEFINICION DE UNA FUNCION
bool sintaxisFuncionA(char linea[]){
	bool sintaxis = false;
	posP = finCiclo(linea);
	if(posP > 0){
        int aux = cuentaPalabra(linea);
        if(aux > 3){
            obtPalabra(linea, 2);
			if(strcmp(tempPalabra, "int") == 0 ||
				strcmp(tempPalabra, "float") == 0 ||
				strcmp(tempPalabra, "string") == 0||
				strcmp(tempPalabra, "waterjet") == 0 ||
				strcmp(tempPalabra, "led") == 0){
					obtPalabra(linea, 3);
					if(esValida(tempPalabra) && esReservada(tempPalabra) == false){
						sintaxis = true;
					}
			}
		}
	}
	return sintaxis;
}


//VALIDA LA SINTAXIS PARA DEFINICION DE UNA FUNCION SIN ESPECIFICAR RETORNO
bool sintaxisFuncion(char linea[]){
	bool sintaxis = false;
	posP = finCiclo(linea);
	if(posP > 0){
        int aux = cuentaPalabra(linea);
        if(aux > 2){
            obtPalabra(linea, 2);
			if(esVariable(tempPalabra)){
                obtPalabra(linea, 3);
				if(tempPalabra[0] == '('){
					extraerCP(linea, campos,posP);
					if(strlen(campos)==0){
						sintaxis = true;
					}else{
	                    auxTam = cuentaPalabra(campos);
	                    if(auxTam == 0){
							sintaxis = true;
						}else if(auxTam%3 == 2){
	                        p = 1;
	                        sintaxis = true;
							while(p <= auxTam){
								if(p%3 == 1){
									obtPalabra(campos, p);
									if(esInstancia(tempPalabra) == false){sintaxis = false;}
								}
								if(p%3==2){
	                        		obtPalabra(campos, p);
	                        		if(esVariable(tempPalabra) == false){sintaxis = false;}
								}
								if(p%3 == 0){
	                        		obtPalabra(campos, p);
	                        		if(strcmp(tempPalabra, ",") == 1){sintaxis = false;}
								}
								p++;
							}
						}
					}
				}
			}
		}
	}
	
	if(sintaxis == true){funciones++;}
	
	return sintaxis;
}


//VALIDA LA SINTAXIS DE UN FIN
bool sintaxisFin(char linea[]){
	bool sintaxis = false;
	int auxT = cuentaPalabra(linea);
	if(auxT == 2){
        obtPalabra(linea, 2);
		if(strcmp(tempPalabra, "function") == 0){
			if(funciones>0){
                sintaxis = true;
                funciones--;
			}
		}else if(strcmp(tempPalabra, "ciclo") == 0){
            if(ciclos>0){
                sintaxis = true;
                ciclos--;
			}
		}
	}
	return sintaxis;
}

