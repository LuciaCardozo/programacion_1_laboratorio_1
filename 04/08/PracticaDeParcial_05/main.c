#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Orquesta.h"
#include "Musico.h"
#include "Instrumento.h"
#include "subMenu.h"
#define CANT_ORQUESTA 50
#define CANT_MUSICO 1000
#define CANT_INSTRUMENTO 20

int main()
{
    Orquesta listOrquesta[CANT_ORQUESTA];
    Musico listMusico[CANT_MUSICO];
    Instrumento listInstrumento[CANT_INSTRUMENTO];
    int opciones;
    do
    {
        if(utn_getValidInt("\n1-Orquestas\n2-Musicos\n3-Instrumentos\n4-Salir\nIngrese opcion: ","\nERROR, no es una sector.",&opciones,1,4,2)==0)
        {
            switch(opciones)
            {
                case 1:
                    menuOrquesta(listOrquesta,CANT_ORQUESTA);
                    break;
                case 2:
                    menuMusico(listMusico,CANT_MUSICO);
                    break;
                case 3:
                    menuInstrumento(listInstrumento,CANT_INSTRUMENTO);
                    break;
                case 4:
                break;
                default:
                    printf("\nOpcion Incorrecta");
                    break;
            }
        }
    }while(opciones!=4);

    return 0;
}
