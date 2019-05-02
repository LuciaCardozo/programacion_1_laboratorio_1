#include <stdio.h>

int utn_getNumber(int* pNumber,int max, int min, char* msg, char* msgError, int retries)
{
    int number;
    int retorno=-1;

    while(retries>0)
    {
        printf("%s",msg);
        scanf("%d",&number);
        if(number>min && number<max)
        {
            (*pNumber)=number;
            retorno=0;
            break;
        }
        else
        {
            printf("%s",msgError);
        }
        retries--;
    }
    return retorno;
}
