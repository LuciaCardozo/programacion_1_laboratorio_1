#include <stdio.h>
#include <stdlib.h>

int getNumberInt(int *numero,char *msg,char *msgError,int maxInt,int minInt,int reintentos)
{
    int i;
    int ret = -1;
    for(i=0;i<reintentos;i++)
    {
        printf("%s",msg);
        fflush(stdin);
        scanf("%d",numero);
        if(*numero <= maxInt && *numero >= minInt)
        {
            ret = 0;
            break;
        }
        else
        {
            printf("%s",msgError);
        }
    }
    return ret;
}

int getNumberFloat(float *numero,char *msg, float max,float min,int reintentos)
{
    int i;
    int ret = -1;
    for(i=0;i<reintentos;i++)
    {
        printf(msg);
        fflush(stdin);
        scanf("%f",numero);
        if(*numero <= max && *numero >= min)
        {
            ret = 0;
            break;
        }
        else
        {
            printf("\nError\n");
        }
    }
    return ret;
}
