/*
 ============================================================================
 Name        : eclipse.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funcionesDePrueba.h"
#define QTY 5

int main(void)
{
    int edades[QTY] = {100,200,300,400,500};
    /*initArrayInt(edades,QTY,22);
    getArrayInt(edades,QTY,"\nEdad?\n","\nERROR\n",0,200,2);*/
    printArrayInt(edades,QTY);
    intMaxMinProm(edades,QTY);

    return EXIT_SUCCESS;
}
