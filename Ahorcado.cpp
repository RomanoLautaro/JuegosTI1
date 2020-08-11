#include<stdio.h>//prueba lautaro
#include<stdlib.h>
#include <ctype.h>
int Carga();//Cargar la palabra para adivinar
void PalabraAAdivinar();//muestra la palabra oculta y mmientras adivine va mostrando las letras
void Verificacion(int CaracteresAdivinados[25],char letraingresada,int &muneco);//Verifica si la letra ingresada coincide con la palabra a adivinar
void EstadoDelMuneco(int Muneco);
void Perdio();
void MostrarPalabra();

//variable global en la que guarda la plabra oculta que se ingreso para adivinar;
char Palabra[25];
//variable global que guarda la cantidad de letras que tiene la palabra
int cantletras;

main(){
	printf("AHORCADO\n========");
	cantletras=Carga();
	PalabraAAdivinar();
}

int Carga(){
	char b;
	int i=0,Bandera=1;
	printf("\nIngresar la palabra a adivinar letra por letra \"EN MAYUSCULA\", Al finalizar presione 0");
	while(Bandera!=48){//48 es el numerocero en codigo ascii
		
		printf("\nIngrese la %d letra: ",i+1);
		scanf("%c",&Palabra[i]);
		fflush(stdin);//para que no haya problemas al escanear datos tipo char
		
		//El siguiente codigo sirve para identeficar si un caracter ingresado es un numero o una letra
		//-----------------------------------------------------------
		if (isalpha(Palabra[i])) {
 		 } else {
 		 	if (Palabra[i]!=48){
   				printf("\nEROOR:Debe ingresar un caracter alfabetico, por favor intente nuevamente");
   				i--;
   			}
 		 }
		//--------------------------------------------------------------
		Bandera=Palabra[i];
		i++;
	}
	system("cls");
	return i-1;
}

void PalabraAAdivinar(){
	char i=0;
	int J=0;
	bool Gano=true;
	char LetraIngresada;
	int CantLetrasAdivinadas[25];//vector que indica con un 1 la posicion de el caracter adivinado
	int LetrasAdivinadas[25];//Aqui se guardan las letras que ya fueron adivinadas
	int muneco=0;
	printf("AHORCADO\n========\n\n");
	printf("Palabra a adivinar: ");
	for(int i=0;i<cantletras;i++){
		printf("_ ");
	}
	
	do{
		int Bandera=1;
		Gano=true;
		printf("\n-------------------------------------------\n");
		printf("Jugada #%d",J+1);
		printf("\nIngrese una letra: ");
		scanf("%c",&LetraIngresada);
		fflush(stdin);//para que no haya problemas al escanear datos tipo char
		
		//variable para verificar si la letra ingresada es un valor alfabetico
		char aux=LetraIngresada;
		
		//El siguiente codigo sirve para identeficar si un caracter ingresado es un numero o una letra
		//-----------------------------------------------------------
		if (isalpha(aux)){
 		 } else {
 		 	printf("\nERROR: El caracter ingresado no es albabetico, intente nuevamente\n");
 		 	J--;
 		 	
 		 	//si la bandera esta en 0 no debe contarse la jugada
 		 	Bandera=0;
 		 	Gano=false;
 		 }
		//--------------------------------------------------------------
		if(Bandera!=0){
			Verificacion(CantLetrasAdivinadas,LetraIngresada,muneco);
			printf("Resultado de la jugada #%d \nPalabra a adivinar: ",J+1);
			for(int i=0;i<cantletras;i++){
				if(CantLetrasAdivinadas[i]==1 || LetrasAdivinadas[i]==1){
					printf("%c ",Palabra[i]);
					LetrasAdivinadas[i]=1;
				}else{
					printf("_ ");
					Gano=false;
				}
			}
			EstadoDelMuneco(muneco);
			J++;
			//final perdedor
			if(muneco>=10){
				Perdio();
			}
		}
	}while(Gano==false);
	//final ganador
	int Puntos=50-(2*muneco);
	printf("\n\n=========================\nHAS GANADO LA PARTIDA!!\nEl puntaje obtenido es: %d Puntos.\n\n\n",Puntos);
	system("pause");
}

void Verificacion(int CaracteresAdivinados[25],char letraingresada,int &muneco){
	int B=0;
	for(int i=0;i<25;i++){
		if(Palabra[i]==letraingresada){
			CaracteresAdivinados[i]=1;
			B=1;
		}else CaracteresAdivinados[i]=0;
	}
	if(B==0){
		muneco++;
	}
}
void EstadoDelMuneco(int muneco){
	printf("\nEstado del muneco: ");
	if(muneco>=1){
		printf("cabeza, ");
	}
	if(muneco>=2){
		printf("tronco, ");
	}
	if(muneco>=3){
		printf("brazo izquierdo, ");
	}
	if(muneco>=4){
		printf("brazo derecho, ");
	}
	if(muneco>=5){
		printf("pierna izquierda, ");
	}
	if(muneco>=6){
		printf("pierna derecha, ");
	}
	if(muneco>=7){
		printf("mano izquierda, ");
	}
	if(muneco>=8){
		printf("mano derecha, ");
	}
	if(muneco>=9){
		printf("pie Izquierdo, ");
	}
	if(muneco>=10){
		printf("pie derecho. ");
	}
}
void Perdio(){
	printf("\n\n=========================\nHAS PERDIDO.\nPuntaje obtenido: 0\n\n\n");
	
	//se muestra la palabra que debia adivinarse
	MostrarPalabra();
	
	exit(0);
	system("pause");
}

//Funcion para ostrar la palabra que debia adivinarse
void MostrarPalabra(){
	printf("La palabra oculta era: ");
	for(int i=0;i<cantletras;i++){
		printf("%c",Palabra[i]);
	}
}
