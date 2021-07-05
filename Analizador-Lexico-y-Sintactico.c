TEstado Estado;

int  Simbolo;

int i;
int longitud;

i= longitud=0;
Estado= q0;

longitud= Cadena.size();

while (longitud > i and Estado !=qe){
	Simbolo = Cadena[i];

	switch (Estado){
		case q0:
			if (Simbolo >= 'a' && Simbolo <='z' || Simbolo >= 'A' && Simbolo <='Z'){
				Estado=q1;
			}else
			if(Simbolo >= '0' && Simbolo <= '9'){
				Estado = q3;
			}


			break;

			case q1:
				if(Simbolo >= 'a' && Simbolo <='z'|| Simbolo >= 'A' && Simbolo <='Z'){
					Estado = q1;
				}
				else{
					Estado = qe;
				}
				break;

			  case q2:
            //si es un digito
            if(Simbolo >= '0' && Simbolo <= '9'){
                Estado= q3;
            }
            break;
        case q3:
            //si es un digito
            if(Simbolo >= '0' && Simbolo <= '9'){
                Estado= q3;
            }
            else{
			if(Simbolo == '.'){
                    Estado= q4;


                }
            }
            break;
        case q4:
            //si es un digito
            if(Simbolo >= '0' && Simbolo <= '9' ){


                Estado= q5;
				}

            break;

	}
	i++;



}

int conta=0;
 for(i=0; i<longitud; i++){
  for(int j=0; j<longitud; j++){
 if (Cadena[i]==Cadena[j*1]){
 if(Cadena[i]=='-'){

      conta++;
         if(conta>2){

         Estado=qe;

         break;
           }
         }
       }
    }
 }




if(Estado==q1){
	cout <<"\n ["<<Cadena<< "] es: Cadena aceptada";

	int j;
	int TamanioArreglo=sizeof TablaSimbolos/ sizeof TablaSimbolos[0];
	for(j=0; j< TamanioArreglo; j++){
		if(Cadena.compare(TablaSimbolos[j])==0){
			cout<<" y Palabra reservada" ;
			break;

		}

	}
}

else if(Estado== q5){


	cout <<"\n ["<<Cadena<< "] es: Numero Racional";

}else{

	cout << "\n Existe un error en: "<<Cadena;
	cout << " Programa detenido ";
	break;

}

if(Cadena=="fin"){

		cout << "\n\n Fin del programa";

    break;


     }
  }
}