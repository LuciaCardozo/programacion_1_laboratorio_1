#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define CANT_CLIENTE 4
#define MSG_INGRESONOM "Ingrese un nombre: "
#define MSG_INGRESOAP "Ingrese un apellido: "

int main()
{

    int i;
    char arrayNombre[CANT_CLIENTE][50];
    char arrayApellido[CANT_CLIENTE][50];
    char auxNombre[50];
    char auxApellido[50];
    for(i=0;i<CANT_CLIENTE;i++)
    {
        utn_getString(MSG_INGRESONOM,auxNombre);
        strcpy(arrayNombre[i],auxNombre);
    }
    utn_printString(arrayNombre,CANT_CLIENTE);

    for(i=0;i<CANT_CLIENTE;i++)
    {
        utn_getString(MSG_INGRESOAP,auxApellido);
        strncpy(arrayApellido[i],auxApellido,50);
    }
    utn_printString(arrayApellido,CANT_CLIENTE);

    for(i=0;i<CANT_CLIENTE;i++)
    {
        printf("\n %s - %s - %d",arrayNombre[i],arrayApellido[i],i);
    }

    /*int legajo[CANT];
    char sexo[CANT];
    int edad[CANT];
    int notaUno[CANT];
    int notaDos[CANT];
    float promedio;
    cargarSetDatos(legajo,sexo,edad,notaUno,notaDos,&promedio,CANT);*/
    return 0;
}
