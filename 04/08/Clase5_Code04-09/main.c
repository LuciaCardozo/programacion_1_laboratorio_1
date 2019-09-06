#include <stdio.h>
#include <stdlib.h>
#include "funciones2.h"
#define QTY 5

int main()
{
    int edades[QTY]={50,2,35,15,8};
    /*initArrayInt(edades,QTY,22);
    int cantidadUsuario;
    getArrayInt(edades,QTY,"\nEdad?\n","\nERROR\n",0,200,2);*/
    swapBubble(edades,QTY);
    printArrayInt(edades,QTY);
    printSumaArrays(edades,QTY);
    printSacarPromedio(edades,QTY);
    printMaxMinInt(edades,QTY);

    return 0;
}


