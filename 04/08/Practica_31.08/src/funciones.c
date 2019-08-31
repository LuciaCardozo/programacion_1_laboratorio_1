/*
 * funciones.c
 *
 *  Created on: 31 ago. 2019
 *      Author: alumno
 */
#include <stdio.h>
#include <stdlib.h>

void saludar()
{
    printf("\nBienvenidos");
}

void sumarDosNumeros(int numeroA,int numeroB)
{
    int suma;
    suma = numeroA + numeroB;
    printf("\nEl resultado es: %d",suma);
}

void sumar(int numeroA,int numeroB)
{
    numeroA = numeroA + numeroB;
    printf("\nEl resultado es: %d",numeroA);
}

float sumarDosNumeros(float* resultado,float numeroA,float numeroB)
{
    *resultado = numeroA + numeroB;
    printf("\nEl resultado es: %.2f",resultado);
    return resultado;
}

float restarDosNumeros(float* resultado,float numeroA,float numeroB)
{
    *resultado = numeroA - numeroB;
    printf("\nEl resultado es: %.2f",resultado);
    return resultado;
}

float multiplicacionDosNumeros(float* resultado,float numeroA,float numeroB)
{
    *resultado = numeroA * numeroB;
    printf("\nEl resultado es: %.2f",resultado);
    return resultado;
}

int dividirDosNumeros(float *resultado, float *numeroA,float *numeroB)
{
	int ret = -1;
	*resultado = numeroA / numeroB;
	if(numeroA!=0 || numeroB!=0)
	{
		printf("\nEl resultado es: %.2f",resultado);
		ret = 0;
	}
	else
	{
		printf("Error");
	}

	return ret;
}

int calcular(float *resultado,float numberOne,float numberTwo)
{
	sumarDosNumeros(&resultado,numberOne,numberTwo);
	restarDosNumeros(&resultado,numberOne,numberTwo);
	multiplicacionDosNumeros(&resultado,numberOne,numberTwo);
	dividirDosNumeros(&resultado, numberOne,numberTwo);
	return 0;
}

int menuOpciones()
{
	int ret=-1;
	float numeroUno;
	float numeroDos;
	float resultado;
	int opcion;
	do{
		switch(opcion)
		{
			if(opcion==2 && opcion!=1)
			{
				printf("\nError, falta un operando.");
			}
			else if(opcion==3 && opcion==4)
			{
				printf("\nNo se cargaron numeros.")
			}
			case 1:
			printf("Ingrese un numero: ");
			fflush(stdin);
			scanf("%.2f",numeroUno);
			break;
			case 2:
			printf("Ingrese un numero: ");
			fflush(stdin);
			scanf("%.2f",numeroDos);
			break;
			case 3:
			calcular(&resultado,numeroUno,numeroDos);
			break;
			case 4:
			break;


		}
	}while(opcion!=5)
	return ret;
}

