#include<stdlib.h>
#include<stdio.h>
#include <ctime>
void azar(int &numeroaleatorio);
void Pausa();
void Reglas();
bool MayMen(int Num,int NAleatorio,int &rango1,int &rango2);
main(){
	int Naleatorio, num_ingresado;
	int rango1=1,rango2=999;
	int intentoganador;
	bool Gano=false;
	
	azar(Naleatorio);
	printf("\t\t*********************************\n\t\t*****     Mayor y Menor     *****\n\t\t*********************************");
	Reglas();
	Pausa();
	for(int i=1;i<=10;i++){
		printf("Intento %d: ",i);
		scanf("%d",&num_ingresado);
		Gano=MayMen(num_ingresado,Naleatorio,rango1,rango2);
		if(Gano==true){
			intentoganador=i;
			printf("\n--------------------------------------");
			printf("\n  Acertaste!... Puntaje obtenido: %d",11-i);
			printf("\n--------------------------------------");
			i=11;
			printf("\n***El Numero secreto es: %d",Naleatorio);
		}
	}
	if(intentoganador>10){
		printf("\n----------------------------------------");
		printf("\n  Perdiste, El numero secreto era: %d",Naleatorio);
		printf("\n----------------------------------------");
	}
	printf("\n\nGracias por jugar. ");
	Pausa();
}
void azar(int &numeroaleatorio){
	int nro,N=1,nro_azar; 
  	srand(time(0));
	nro_azar=1+rand()%999;
	numeroaleatorio=nro_azar;
	printf("%d",numeroaleatorio);
}
void Pausa(){
	printf("\n\n");
	system("pause");
	system("cls");
}
void Reglas(){
	printf("\n\n\t   Este juego consiste en adivinar un numero que esta \n\tentre 1 y 999 denominado numero secreto, el cual elegire \n");
	printf("\t de manera aleatoria. En cada intento debes ingresar un \n\tnumero hasta adivinarlo, tienes 10 intentos, mucha suerte.\n");
}
bool MayMen(int Num,int NAleatorio,int &rango1,int &rango2){
	if(Num>NAleatorio){
		rango2=Num-1;
		printf("\nEl numero secreto es menor y se encuentra entre %d y %d\n",rango1,rango2);
		return false;
	}else 
		if(Num<NAleatorio){
			rango1=Num+1;
			printf("\nEl numero secreto es mayor y se encuentra entre %d y %d\n",rango1,rango2);
			return false;
		}else
			if(Num==NAleatorio){
				return true;
			}
}
