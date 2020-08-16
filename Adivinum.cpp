#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void separarNumero(int n, int &a1, int &a2, int &a3, int &a4);

main(){
    int n,aleatorio,numIngresado,numMismaPos=0, numIgual=0;
    int i=1,a1=0,a2=0,a3=0,a4=0;
    int n1=0, n2=0,n3=0,n4=0;
    int puntuacion=10;
    srand(time(NULL));
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\n\tBienvenido Adivinum\n");
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\n____________________________________________\n");
    printf("\nPresione una tecla para empezar a jugar\n");
    printf("\n____________________________________________\n");
    system("Pause");
    system ("cls");
    do{
        aleatorio=(rand()%9000)+1000;
        separarNumero(aleatorio,a1,a2,a3,a4);
    }while(a1==a2 || a1==a3 || a1==a4 || a2==a3 || a2==a4 || a3==a4||
    a1==0 || a2==0 || a3==0 || a4==0);

    for(int i=1; i<11; i++){
        printf("\n\nIntento numero *%d*: ", i);
        scanf("%d",&numIngresado);
        if(numIngresado>=1000 && numIngresado<10000){ //1000^9999
            separarNumero(numIngresado,n1,n2,n3,n4);
            if(a1==n1){
                numMismaPos++;
            }
            if(a2==n2){
                numMismaPos++;
            }
            if(a3==n3){
                numMismaPos++;
            }
            if(a4==n4){
                numMismaPos++;
            }

            if(a1==n1 || a2==n1 || a3==n1 || a4==n1){
                numIgual++;
            }
            if(a1==n2 || a2==n2 || a3==n2 || a4==n2){
                numIgual++;
            }
            if(a1==n3 || a2==n3 || a3==n3 || a4==n3){
                numIgual++;
            }
            if(a1==n4 || a2==n4 || a3==n4 || a4==n4){
                numIgual++;
            }
        printf("\nNumeros ingresados iguales con la misma posicion: %d",numMismaPos);
        printf("\nNumeros ingresados iguales %d",numIgual);
        if(numMismaPos==4){
            printf("\nGano la partida\nSu puntuacion es:%d",puntuacion);
            i=11;
        }
        else{
            puntuacion--;
        }
        if(puntuacion==0){
            printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
            printf("\nPerdiste\n");
            printf("\n\nEl numero es: %d", aleatorio);
            printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
        }
        numIgual=0;
        numMismaPos=0;
        }
        else{
            printf("\nEl numero ingresado no es de 4 cifras.");
            i--;
        }
    }
}

void separarNumero(int n, int &a1, int &a2, int &a3, int &a4){
	a1=n/1000;
	a2=(n-a1*1000)/100;
	a3=(n-(a1*1000+a2*100))/10;
	a4=(n-(a1*1000+a2*100+a3*10));
}

