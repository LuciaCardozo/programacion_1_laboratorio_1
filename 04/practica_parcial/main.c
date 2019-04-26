#include <stdio.h>
#include <stdlib.h>
#include "pantalla.h"
#include "utn.h"
#define CANTIDAD 5


int main()
{
    int opcion;
    Pantalla listPantalla[CANTIDAD];
    pan_initArray(listPantalla,CANTIDAD);
    do
    {
        utn_menuDeOpciones();
        utn_getValidInt("Ingrese opcion: ","Error\n",&opcion,1,4,5);
        switch(opcion)
            {
            case 1:
            pan_alta(listPantalla,CANTIDAD);
            break;
            case 2:
            pan_printArray(listPantalla,CANTIDAD);
            break;
            case 3:
            pan_modificarId(listPantalla,CANTIDAD);
            break;
            case 4:

            break;
            }
    }while(opcion!=4);


    return 0;
}
