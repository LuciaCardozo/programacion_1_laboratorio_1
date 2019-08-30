#include <stdio.h>
#include <stdlib.h>
#define CANT_ITERA 5

int sumarDosEnteros(float numeroUno, float numeroDos,float *resultado);
int sacarNumeroMaxMin(int *pFlag,float numero,float*numMax,float *numMin);

int main()
{
	float numeroA;
	float numMax=0;
	float numMin=0;
	int flag=0;
	float acumSuma=0;
	float promTotal;
	int i;
	/*printf("Ingrese la cantidad de numero que quiere ingresar: ");
	fflush(stdin);
	scanf("%d",&cantidad);*/
	for(i=0;i<CANT_ITERA;i++)
	{
		printf("Ingrese numero: ");
		fflush(stdin);
		scanf("%f",&numeroA);
		sacarNumeroMaxMin(&flag,numeroA,&numMax,&numMin);
		acumSuma = acumSuma + numeroA;
	}
	    printf("Suma de los numeros ingresados: %.2f",acumSuma);
	    printf("\nNumero Minimo: %.2f",numMin);
	    printf("\nNumero Maximo: %.2f",numMax);
	    promTotal=acumSuma/CANT_ITERA;
	    printf("\nPromedio de Numeros Sumados: %.2f",promTotal);

	return 0;
}

int sumarDosEnteros(float numeroUno, float numeroDos,float *resultado)
{
	*resultado = numeroUno+numeroDos;
	return 0;
}

int sacarNumeroMaxMin(int *pFlag,float numero,float*numMax,float *numMin)
{
    float max = *numMax;
    float min = *numMin;
    int flag = *pFlag;

    if(flag==0)
    {
        max = numero;
        min = numero;
        *pFlag = 1;
    }
    if(numero>max)
    {
        max=numero;
    }
    *numMax = max;

    if(numero<min)
    {
        min=numero;
    }
    *numMin = numero;

    return 0;
}



/*if(numeroA<numMin)
		{
            numMin=numeroA;
		}
		else if(numeroA>numMax)
		{
            numMax=numeroA;
		}
		*/
