#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Pantalla.h"
#include "Publicidad.h"
#include "SubMenuYMenu.h"
#define CANT_PAN 100
#define CANT_PUB 100

int main()
{
    Pantalla listPantalla[CANT_PAN];
    Publicidad listPublicidad[CANT_PUB];
    menu(listPantalla,CANT_PAN,listPublicidad,CANT_PUB);
    return 0;
}

