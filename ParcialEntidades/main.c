#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "autor.h"  //cambiar por nombre entidad
#include "libro.h"
#include "autor.h"
#include "prestamos.h"

#define QTY_TIPO 5

int main()
{


    int opcion;
    int contadorIdAutor=0;                   //cambiar

    Autor arrayAutor[QTY_TIPO];                   //cambiar
    autor_Inicializar(arrayAutor,QTY_TIPO);                   //cambiar

    strncpy(arrayAutor[1].nombre,"lucia",20);
    strncpy(arrayAutor[1].apellido,"cardozo",20);
    //arrayAutor[1].sexo='F';
    arrayAutor[1].idAutor=generadorId();
    arrayAutor[1].isEmpty=-1;
    strncpy(arrayAutor[2].nombre,"jonathan",20);
    strncpy(arrayAutor[2].apellido,"Haedo",20);
    arrayAutor[2].idAutor=generadorId();
    arrayAutor[2].isEmpty=-1;
    strncpy(arrayAutor[3].nombre,"matias",20);
    strncpy(arrayAutor[3].apellido,"murray",20);
    arrayAutor[3].idAutor=generadorId();
    arrayAutor[3].isEmpty=-1;


    do
    {
        utn_getUnsignedInt("\n\n1) Alta \n2) Modificar \n3) Baja \n4) Listar \n5) Ordenar \n6) Salir\n",                   //cambiar
                           "\nError",1,sizeof(int),1,11,1,&opcion);
        switch(opcion)
        {
        case 1: //Alta
            autor_alta(arrayAutor,QTY_TIPO,&contadorIdAutor);                   //cambiar
            break;

        case 2: //Modificar
            autor_modificar(arrayAutor,QTY_TIPO);                   //cambiar
            break;

        case 3: //Baja
            autor_baja(arrayAutor,QTY_TIPO);                   //cambiar
            break;

        case 4://Listar
            autor_listar(arrayAutor,QTY_TIPO);                   //cambiar
            break;

        case 5://Ordenar
            autor_ordenarPorString(arrayAutor,QTY_TIPO);                   //cambiar
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
