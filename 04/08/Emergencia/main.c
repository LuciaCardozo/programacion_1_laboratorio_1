#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Asociados.h"
#include "Llamadas.h"
#include "utn.h"
#define CANT_ASOC 100
#define CANT_LLAM 100

int main()
{
    Asociados listAsoc[CANT_ASOC];
    Llamada listLlam[CANT_LLAM];
    menu(listAsoc,CANT_ASOC,listLlam,CANT_LLAM);
    return 0;
}
