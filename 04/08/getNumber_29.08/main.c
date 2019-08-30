#include <stdio.h>
#include <stdlib.h>
#include "biblioteca_practica.h"

#define CANT_REIT 3



int main()
{
    int numero;
    if(getNumberInt(&numero,"\nIngrese un numero entre 0 a 100: ","\nERROR",100,0,CANT_REIT) == 0)
    {
        printf("\nNumero Ingresado es: %d\n",numero);
    }
    else
    {
        printf("\nSE TERMINARON LOS REINTENTOS\n");
    }

    return 0;
}

