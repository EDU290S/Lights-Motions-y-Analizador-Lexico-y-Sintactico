#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>

//TABLA DE SIMBOLOS
char *reservada[] = {"int", "float", "String", "led", "waterjet", "if", "else", "while",
					"for", "range", "function", "return", "writeLn", "scribe", "off", "on",
					"intensity", "useColor", "pressure", "angle", "delay", "id", "FIN"};

//TABLA DE COLORES
char *colores[] = {"#rojo", "#verde", "#azul", "#blanco", "#negro", "#gris", "#cian", "#morado",
					"#cafe", "#amarillo", "#rosado", "#limon", "#naranja"};

int auxTam;
int posP, p;
char tempPalabra[100];
char campos[] = "";
char aux[100];
enum type {var, funcion, para, delay, instancia, si, escribir, obtener, retorno, fin, qe};
int ciclos;
int funciones;
char temp[2000];
char temp2[2000];


