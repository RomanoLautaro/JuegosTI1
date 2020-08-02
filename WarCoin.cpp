#include<stdio.h>
#include<stdlib.h>
#include <ctime>
int Monedas();
int Inicia();//para saber si inicia jugando la computadora o el jugador
void Comienzo(int inicia,int cantmonedas);//Empieza el juego

int min,max;
main(){
	int CMonedas,PlayerOPc;
	printf("Ingrese la cantidad minima de monedas que se pueden retirar: ");
	scanf("%d",&min);
	printf("\nIngrese la cantidad maxima de monedas que se pueden retirar: ");
	scanf("%d",&max);
	CMonedas=Monedas();
	PlayerOPc=Inicia();
	printf("\nLa cantidad inicial de monedas en la pila es: %d",CMonedas);
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
		printf("\nInicia el jugador");
	}else printf("\nInicia la computadora");
	
	while(cantmonedas>=min){
		int retiraJugador;
		int retiraPC;
		if(juega==1){
			printf("\ningrese la cantidad de monedas que decea eliminar: ");
			scanf("%d",&retiraJugador);
			if(retiraJugador>=min && retiraJugador <= max){
				cantmonedas=cantmonedas-retiraJugador;
				printf("\nQuedan %d monedas ",cantmonedas);
				juega=2;	
			}else {
				printf("\nERROR: Se deben desapilar entre %d y %d monedas de la pila",min,max);
			}
		}else{
			retiraPC=CantMonedasQueRetiraLaPc();
			printf("\nLa computadora saco %d monedas de la pila",retiraPC);
			cantmonedas=cantmonedas-retiraPC;
			printf("\nQuedan %d monedas en la pila",cantmonedas);
			juega=1;
		}
	}
}
