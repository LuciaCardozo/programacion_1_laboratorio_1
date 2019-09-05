#include <stdio.h>
#include <stdlib.h>
#include "funciones2.h"
#define QTY 5

int main()
{
    int edades[QTY] = {100,200,300,400,500};
    /*initArrayInt(edades,QTY,22);
    int cantidadUsuario;
    cantidadUsuario=getArrayInt(edades,QTY,"\nEdad?\n","\nERROR\n",0,200,2);*/
    printArrayInt(edades,QTY);
    intMaxMinProm(edades,QTY);

    return 0;
}


