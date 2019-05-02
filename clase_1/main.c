#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD_REP 3

int pedirSumaMostrar();
int pedirAcumuladorMostrar();

int main()
{
    if (!pedirSumaMostrar())
        {
            printf("\nATR");
        }
    pedirAcumuladorMostrar();

  return 0;
}
int pedirSumaMostrar()
{
    float numeroUno;
    float numeroDos;
    float resultado;
    printf("Ingrese un numero: ");
    scanf("%f",&numeroUno);
    printf("Ingrese otro numero: ");
    scanf("%f",&numeroDos);
    resultado=numeroUno+numeroDos;
    printf("El resultado es:%.2f",resultado);
    return 0;
}
int pedirAcumuladorMostrar()
{
    int numeroIngresado;
    int acumulador=0;
    int i;
    for(i=0;i<CANTIDAD_REP;i++)
    {
        printf("\nIngrese un numero %d:",i+1);
        scanf("%d",&numeroIngresado);
        acumulador=acumulador+numeroIngresado;
    }
    printf("El promedio es:%.2f",(float)acumulador/CANTIDAD_REP);
    return 0;
}

