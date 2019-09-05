/*
 * funciones.c
 *
 *  Created on: 31 ago. 2019
 *      Author: alumno
 */
#include <stdio.h>
#include <stdlib.h>

float sumarDosNumeros(float *resultadoSuma,float numeroA,float numeroB)
{
    *resultadoSuma = numeroA + numeroB;
    return *resultadoSuma;
}

float restarDosNumeros(float *resultadoResta,float numeroA,float numeroB)
{
    *resultadoResta = numeroA - numeroB;
    return *resultadoResta;
}

float multiplicacionDosNumeros(float* resultadoMult,float numeroA,float numeroB)
{
    *resultadoMult = numeroA * numeroB;
    return *resultadoMult;
}

int dividirDosNumeros(float *resultadoDiv, float numeroA,float numeroB)
{
	int ret;
	*resultadoDiv = numeroA/numeroB;
	if(numeroA!=0 || numeroB!=0)
	{
		ret = 0;
	}
	else
	{
		ret = -1;
	}

	return ret;
}

int pedirNumero()
{
    int number;
    printf("Ingrese un numero: ");
    scanf("%d",&number);
    return number;
}

int mostrarOpciones()
{
    int numeroUno;
    int numeroDos;
    printf("1.Ingrese numero uno: ");
    fflush(stdin);
    scanf("%d",&numeroUno);
    printf("2.Ingrese numero Dos: ");
    fflush(stdin);
    scanf("%d",&numeroDos);
    printf("3.Calcular: ");
    printf("2.Mostrar Calculos: ");
    return 0;
}

int menuOpciones()
{
	float numeroUno;
	float numeroDos;
	float resultadoSuma;
	float resultadoResta;
	float resultadoMult;
	float resultadoDiv;
	int opcion;
	printf("Estoy fuera");
	do{
        opcion = mostrarOpciones();
		switch(opcion)
		{
			if(opcion==2 && opcion!=1)
			{
				printf("\nError, falta un operando.");
				break;
			}
			else if(opcion==3 && opcion==4)
			{
				printf("\nNo se cargaron numeros.");
				break;
			}
			else
			{

                case 1:
                printf("Ingrese un numero: ");
                fflush(stdin);
                scanf("%f",&numeroUno);
                break;
                case 2:
                printf("Ingrese un numero: ");
                fflush(stdin);
                scanf("%f",&numeroDos);
                break;
                case 3:
                sumarDosNumeros(&resultadoSuma,numeroUno,numeroDos);
                restarDosNumeros(&resultadoResta,numeroUno,numeroDos);
                multiplicacionDosNumeros(&resultadoMult,numeroUno,numeroDos);
                dividirDosNumeros(&resultadoDiv,numeroUno,numeroDos);
                break;
                case 4:

                break;
			}
		}
	}while(opcion!=5);
	return 0;
}


