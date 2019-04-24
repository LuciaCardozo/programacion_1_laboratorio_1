#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char letras;
    if(isChar(&letras,"Ingrese una letras\n")==0)
    {
        printf("NO ES UNA EDAD");
    }
    else
    {
        printf("El numero es: %c\n",letras);
    }
    return 0;
}
