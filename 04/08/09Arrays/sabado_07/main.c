#include <stdio.h>
#include <stdlib.h>
#include "funcionesSabado.h"
#define CANTIDAD 3

int main()
{
    int miArray[CANTIDAD];
    int maximo,minimo;
    int indiceMaximo,indiceMinimo;
    cargarUnArraySecuencial(miArray,CANTIDAD,"\nIngrese edad: ");
    getMax(miArray,CANTIDAD,&maximo);
    getMin(miArray,CANTIDAD,&minimo);
    printf("\nMaximo: %d",maximo);
    printf("\nMinimo: %d",minimo);
    getMaxInd(miArray,CANTIDAD,&indiceMaximo);
    getMinInd(miArray,CANTIDAD,&indiceMinimo);
    printf("\nIndiceMax: %d",indiceMaximo);
    printf("\nIndiceMin: %d",indiceMinimo);

    return 0;
}
