#include<stdlib.h>
#include<stdio.h>
#include <ctime>

//prototipos
void azar(int &numeroaleatorio);//devuelve un numero aleatorio
void Pausa();
void Reglas();
bool MayMen(int Num,int NAleatorio,int &rango1,int &rango2);//aqui se revisa si el numero ingresado es mayor o menor al numero aleatorio
void IntentosyFinal(int Naleatorio);//aqui se desarrolla el juego en si, los 10 intentos y el final

//funcion principal
main(){
	//variable donde se almacenara el numero aleatorio que creo la computadora
	int Naleatorio;
	azar(Naleatorio);
	Reglas();
	Pausa();
	IntentosyFinal(Naleatorio);
	printf("\n\nGracias por jugar. ");
	Pausa();
}

//funcion para un numero aleatorio
void azar(int &numeroaleatorio){
	int nro,N=1,nro_azar; 
  	srand(time(0));
	nro_azar=1+rand()%999;
	numeroaleatorio=nro_azar;
}

//pausa
void Pausa(){
	printf("\n\n");
	system("pause");
	system("cls");
}

//reglas del juego
void Reglas(){
	printf("\t\t*********************************\n\t\t*****     Mayor y Menor     *****\n\t\t*********************************");
	printf("\n\n\t   Este juego consiste en adivinar un numero que esta \n\tentre 1 y 999 denominado numero secreto, el cual elegire \n");
	printf("\t de manera aleatoria. En cada intento debes ingresar un \n\tnumero hasta adivinarlo, tienes 10 intentos, mucha suerte.\n");
}

//funcion donde se desarrollo el juego
bool MayMen(int Num,int NAleatorio,int &rango1,int &rango2){
	if(Num>NAleatorio){
		rango2=Num-1;
		system("cls");
		printf("-El numero secreto es menor y se encuentra entre %d y %d\n\n",rango1,rango2);
		return false;
	}else if(Num<NAleatorio){
		rango1=Num+1;
		system("cls");
		printf("-El numero secreto es mayor y se encuentra entre %d y %d\n\n",rango1,rango2);
		return false;
	}else if(Num==NAleatorio){
		return true;
	}
}

//funcion donde se almacena los intentos que van realizando. Muestra si ganaste o perdiste
void IntentosyFinal(int Naleatorio){
	int num_ingresado,i;
	int rango1=1,rango2=999;
	int intentoganador;
	bool Gano=false;
	
	for(int i=1;i<=10;i++){
		printf(">Intento %d: ",i);
		scanf("%d",&num_ingresado);
		Gano=MayMen(num_ingresado,Naleatorio,rango1,rango2);
		if(Gano==true){
			intentoganador=i;
			printf("\n--------------------------------------");
			printf("\n  Acertaste!... Puntaje obtenido: %d",11-i);
			printf("\n--------------------------------------");
			i=12;
			printf("\n***El Numero secreto es: %d",Naleatorio);
		}
	}
	if(Gano==false){
		printf("\n----------------------------------------");
		printf("\n  Perdiste, El numero secreto era: %d",Naleatorio);
		printf("\n----------------------------------------");
	}
}
