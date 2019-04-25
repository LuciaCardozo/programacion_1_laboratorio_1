#include <stdio.h>
#include <stdlib.h>
#include "pantalla.h"
#include "utn.h"
#define CANTIDAD 50

int main()
{
    int opcion;
    Pantalla listPantalla[CANTIDAD];
    utn_menuDeOpciones();
    do
    {
        utn_getValidInt("Ingrese opcion","Error",&opcion,1,4,1);
        switch(opcion)
            {
            case 1:
            pan_alta(listPantalla,CANTIDAD);
            break;
            case 2:

            break;
            case 3:

            break;
            case 4:

            break;
            }
    }while(opcion!=4);


    return 0;
}
