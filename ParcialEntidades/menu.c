#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "socios.h"  //cambiar por nombre entidad
#include "libro.h"
#include "autor.h"
#include "prestamos.h"

int menuAutor(Autor* arrayAux, int len, int* idAux)
{

    int opcion;

    //Autor arrayAux[len];
    autor_Inicializar(arrayAux,len);                   //cambiar
    cargarDatos(arrayAux);



    do
    {
        utn_getUnsignedInt("\n\n1) Alta \n2) Modificar \n3) Baja \n4) Listar \n5) Ordenar \n6) Salir\n",                   //cambiar
                           "\nError",1,sizeof(int),1,11,1,&opcion);
        switch(opcion)
        {
        case 1: //Alta

            autor_alta(arrayAux,len,idAux);                   //cambiar
            break;

        case 2: //Modificar
            autor_modificar(arrayAux,len);                   //cambiar
            break;

        case 3: //Baja
            autor_baja(arrayAux,len);                   //cambiar
            break;

        case 4://Listar
            autor_listar(arrayAux,len);                   //cambiar
            break;

        case 5://Ordenar
            autor_ordenarPorString(arrayAux,len);
                //cambiar
            break;

        case 6://Salir
            break;
        default:
            printf("\nOpcion no valida");
        }
    }
    while(opcion!=6);
    return 0;
}

int menuLibro(Libro* arrayAux, int len, int* idAux)
{

    int opcion;

    //Autor arrayAux[len];
    libro_Inicializar(arrayAux,len);                   //cambiar
    cargarDatosLibro(arrayAux,&idAux);


    do
    {
        utn_getUnsignedInt("\n\n1) Alta \n2) Modificar \n3) Baja \n4) Listar \n5) Ordenar \n6) Salir\n",                   //cambiar
                           "\nError",1,sizeof(int),1,11,1,&opcion);
        switch(opcion)
        {
        case 1: //Alta

            libro_alta(arrayAux,len,idAux);                   //cambiar
            break;

        case 2: //Modificar
            libro_modificar(arrayAux,len);                   //cambiar
            break;

        case 3: //Baja
            libro_baja(arrayAux,len);                   //cambiar
            break;

        case 4://Listar
            libro_listar(arrayAux,len);                   //cambiar
            break;

        case 5://Ordenar
            libro_ordenarPorString(arrayAux,len);
                //cambiar
            break;

        case 6://Salir
            break;
        default:
            printf("\nOpcion no valida");
        }
    }
    while(opcion!=6);
    return 0;
}

