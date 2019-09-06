/*
 ============================================================================
 Name        : Clase5Eclipe.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define QTY 5

int main()
{
    int edades[QTY]={50,2,35,15,8};
    /*initArrayInt(edades,QTY,22);
    int cantidadUsuario;
    getArrayInt(edades,QTY,"\nEdad?\n","\nERROR\n",0,200,2);*/
    ordenar(edades,QTY);
    printArrayInt(edades,QTY);
    sumaArrays(edades,QTY);
    intMaxMinProm(edades,QTY);
    return 0;
}
