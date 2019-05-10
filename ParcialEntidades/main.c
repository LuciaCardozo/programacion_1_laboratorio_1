#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "socios.h"  //cambiar por nombre entidad
#include "libro.h"
#include "autor.h"
#include "prestamos.h"
#include "menu.h"

#define QTY_TIPO 5

int main()
{


    int opcion;
    int contadorIdAutor=0;                   //cambiar

    Autor arrayList[QTY_TIPO];

    do
    {
        utn_getUnsignedInt("\n\n1) Autor \n2) Libro \n3) Socios \n4) Prestamos \n5) Salir\n",                   //cambiar
                           "\nError",1,sizeof(int),1,11,1,&opcion);
        switch(opcion)
        {
        case 1: //Alta
            menuAutor(arrayList,QTY_TIPO,&contadorIdAutor);
            //autor_alta(arrayAutor,QTY_TIPO,&contadorIdAutor);                   //cambiar
            break;

        case 2: //Modificar
            //autor_modificar(arrayAutor,QTY_TIPO);                   //cambiar
            break;

        case 3: //Baja
            //autor_baja(arrayAutor,QTY_TIPO);                   //cambiar
            break;

        case 4://Listar
           // autor_listar(arrayAutor,QTY_TIPO);                   //cambiar
            break;

        case 5://Ordenar
            //autor_ordenarPorString(arrayAutor,QTY_TIPO);                   //cambiar
            break;

        case 6://Salir
            break;
        default:
            printf("\nOpcion no valida");
        }
    }
    while(opcion!=5);
    return 0;
}
