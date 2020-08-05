#include<stdio.h>
#include<stdlib.h>
#include <ctime>
//repositorios
int Monedas();
int Inicia();//para saber si inicia jugando la computadora o el jugador
void Comienzo(int inicia,int cantmonedas);//Empieza el juego
int CantMonedasQueRetiraLaPc();
void Reglas();

//variables globales 
int min,max;

main(){
	Reglas();
	printf("WARCOIN\n=========\n");
	int CMonedas,PlayerOPc;
	printf("Ingrese la cantidad minima de monedas que se pueden retirar: ");
	scanf("%d",&min);
	printf("\nIngrese la cantidad maxima de monedas que se pueden retirar: ");
	scanf("%d",&max);
	system("cls");
	printf("WARCOIN\n=========\n");
	CMonedas=Monedas();
	PlayerOPc=Inicia();
	printf("\n**La cantidad inicial de monedas en la pila es: %d**\n",CMonedas);
	Comienzo(PlayerOPc,CMonedas);
	
	
}
int Monedas(){
	int nro_azar; 
  	srand(time(0));
	nro_azar=10+rand()%41;
	return nro_azar;
}
int Inicia(){
	int nro_azar; 
  	srand(time(0));
	nro_azar=1+rand()%2;
	return nro_azar;
}
void Comienzo(int juega,int cantmonedas){
	if(juega==1){
		printf("\nInicia el usuario");
	}else printf("\nInicia la computadora");
	
	while(cantmonedas>=min){
		int retiraJugador;
		int retiraPC;
		if(juega==1){
			printf("\ningrese la cantidad de monedas que desea eliminar: ");
			scanf("%d",&retiraJugador);
			if(retiraJugador>=min && retiraJugador <= max){
				cantmonedas=cantmonedas-retiraJugador;
				printf("Quedan %d monedas\n",cantmonedas);
				juega=2;
			}else {
				printf("\nERROR: Se deben desapilar entre %d y %d monedas de la pila",min,max);
			}
		}else{
			retiraPC=CantMonedasQueRetiraLaPc();
			printf("\nLa computadora saco %d monedas de la pila",retiraPC);
			cantmonedas=cantmonedas-retiraPC;
			printf("\nQuedan %d monedas en la pila\n",cantmonedas);
			juega=1;
		}
	}
	if(juega==1){
		printf("\n\n");
		system("pause");
		system("cls");
		printf("WARCOIN\n=========\n");
		printf("\nLA COMPUTADORA GANO!! puntaje obtenido es: 0");
	}else{
		printf("\n\n");
		system("pause");
		system("cls");
		printf("WARCOIN\n=========\n");
		printf("\nGANASTE!! puntaje obtenido: 5");
	}
	printf("\nGracias por jugar ");
	system("pause");
}

int CantMonedasQueRetiraLaPc(){
	int nro_azar; 
  	srand(time(0));
	nro_azar=min+rand()%(max-min+1);
	return nro_azar;
}
void Reglas(){//Consiste en una pila de monedas, de la cual el jugador y la computadora van sacando monedas hasta que ya no quedan más en la pila. El que vacía la pila de monedas es quien gana el juego
	printf("WARCOIN\n=========\n");
	printf("\nEl juego Consiste en una pila de monedas, de la cual el jugador y la computadora");
	printf("\n\tvan sacando monedas hasta que ya no quedan más en la pila.");
	printf("\n\t El que vacía la pila de monedas es quien gana el juego.\n\n");
	system("pause");
	system("cls");
}
