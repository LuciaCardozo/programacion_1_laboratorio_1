/*
 ============================================================================
 Name        : 1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD 5

int sumarDosEnteros(float numeroUno, float numeroDos,float *resultado);
int sacarNumeroMaxMin(float numero,float*numMax,float *numMin);

int main()
{
	float numeroA;
	float numMax;
	float numMin;
	float acumSuma=0;
	float promTotal;
	int cantidad;
	int i;
	printf("Ingrese la cantidad de numero que quiere ingresar: ");
	fflush(stdin);
	scanf("%d",&cantidad);
	for(i=0;i<cantidad;i++)
	{
		printf("Ingrese numero: ");
		fflush(stdin);
		scanf("%f",&numeroA);
		sacarNumeroMaxMin(numeroA,&numMax,&numMin);
		acumSuma = acumSuma + numeroA;
	}
	    printf("Suma de los numeros ingresados: %.2f",acumSuma);
	    printf("\nNumero Minimo: %.2f",numMin);
	    printf("\nNumero Maximo: %.2f",numMax);
	    promTotal=acumSuma/cantidad;
	    printf("\nPromedio de Numeros Sumados: %.2f",promTotal);

	return 0;
}

int sumarDosEnteros(float numeroUno, float numeroDos,float *resultado)
{
	*resultado = numeroUno+numeroDos;
	return 0;
}

int sacarNumeroMaxMin(float numero,float*numMax,float *numMin)
{
    if(numero>*numMax)
    {
        *numMax=numero;
    }
    if(numero<*numMin)
    {
        *numMin=numero;
    }
    return 0;
}
