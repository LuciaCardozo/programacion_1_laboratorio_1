#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pantalla.h"
#include "utn.h"
#define LEN_LIST 5

int main()
{
    Pantalla listaDePantalla[LEN_LIST];
    pan_initArray(listaDePantalla,LEN_LIST);

    Pantalla auxList[LEN_LIST];
    pan_initArray(auxList,LEN_LIST);


    strncpy(listaDePantalla[1].nombre,"lucia",51);
    strncpy(listaDePantalla[1].direccion,"hornos",51);
    listaDePantalla[1].precio=55;
    listaDePantalla[1].tipo=2;
    listaDePantalla[1].idPantalla=generadorId();
    listaDePantalla[1].isEmpty=1;
    strncpy(listaDePantalla[2].nombre,"jonathan",51);
    strncpy(listaDePantalla[2].direccion,"marco avellaneda",51);
    listaDePantalla[2].precio=55;
    listaDePantalla[2].tipo=1;
    listaDePantalla[2].idPantalla=generadorId();
    listaDePantalla[2].isEmpty=1;
     strncpy(listaDePantalla[3].nombre,"jonathan",51);
    strncpy(listaDePantalla[3].direccion,"marco avellaneda",51);
    listaDePantalla[3].precio=55;
    listaDePantalla[3].tipo=1;
    listaDePantalla[3].idPantalla=generadorId();
    listaDePantalla[3].isEmpty=1;

    int opciones;
    do
    {
        opciones=utn_menuDeOpciones();
        switch(opciones)
        {
            case 1:
            pan_altaPantalla(listaDePantalla,LEN_LIST);
            break;
            case 2:
            pan_printPantalla(listaDePantalla,LEN_LIST);
            break;
            case 4:
            pan_bajaPantalla(listaDePantalla,LEN_LIST);

            break;
        }
    }while(opciones!=5);
    return 0;
}
