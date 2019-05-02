#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
int main()
{
    int num;
    if(utn_getNumber(&num,100,0,"Ingrese un numero:\n","Error.\n",5)==0)
    {
        printf("el numero ingresado es: %d\n",num);
    }
    else
    {
        printf("sos un pelotudo fallaste 5 veces");
    }
    return 0;
}
