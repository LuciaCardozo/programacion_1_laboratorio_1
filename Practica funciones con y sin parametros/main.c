#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int main()
{
    float numberOne;
    float numberTwo;
    float resultado;

    printf("Ingrese un numero");
    scanf("%f",&numberOne);
    printf("Ingrese otro numero");
    scanf("%f",&numberTwo);

    sumarDosNumeros(numberOne,numberTwo,&resultado);

    printf("Resultado: %.2f",resultado);

    return 0;
}
