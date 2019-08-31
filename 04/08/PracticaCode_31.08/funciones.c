#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	/*int ret;*/
	*resultadoDiv = numeroA/numeroB;
	/*if(numeroB!=0)
	{
		ret = 0;
	}
	else
	{
		ret = -1;
	}

	return ret;*/
	return *resultadoDiv;
}

int pedirNumero()
{
    int number;
    printf("\nIngrese un numero: ");
    scanf("%d",&number);
    return number;
}

int mostrarOpciones()
{
    int numero;
    printf("\n1.Ingresar numero uno");
    printf("\n2.Ingresar numero Dos");
    printf("\n3.Calcular");
    printf("\n4.Mostrar Calculos");
    printf("\n5.Salir\n");
    fflush(stdin);
    scanf("%d",&numero);
    return numero;
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
	do{
        opcion = mostrarOpciones();
        if((opcion!=1 && opcion==2))
        {
            printf("Error, falta cargar numeros");
            continue;
        }
        else if((opcion!=1 && opcion==3) || opcion==4 )
        {
            printf("Error");
            continue;
        }
        switch(opcion)
        {
            case 1:
            numeroUno=pedirNumero();
            case 2:
            numeroDos=pedirNumero();
            case 3:
            sumarDosNumeros(&resultadoSuma,numeroUno,numeroDos);
            restarDosNumeros(&resultadoResta,numeroUno,numeroDos);
            multiplicacionDosNumeros(&resultadoMult,numeroUno,numeroDos);
            dividirDosNumeros(&resultadoDiv,numeroUno,numeroDos);
            case 4:
            printf("\nEl resultado de SUMA es: %.2f",resultadoSuma);
            printf("\nEl resultado de RESTA es: %.2f",resultadoResta);
            printf("\nEl resultado de MULTIPLICACION es: %.2f",resultadoMult);
            if(numeroDos==0)
            {
                printf("\nEl resultado de DIVISION es: Error no se puede dividir con el numero cero(0)\n");
            }
            else
            {
                printf("\nEl resultado de DIVISION es: %.2f\n",resultadoDiv);
            }
            break;
            case 5:
            printf("Good bye\n");
            break;
            default:
            printf("No es una opcion");
            break;
        }
	}while(opcion!=5);
	return 0;
}
