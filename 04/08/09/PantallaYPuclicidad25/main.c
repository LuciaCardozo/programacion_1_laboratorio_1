#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Pantalla.h"
#define CANT 100

int main()
{
    Pantalla listPersonas[CANT];
    menu(listPersonas,CANT);
    return 0;
}
