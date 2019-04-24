#include <string.h>
#include <stdio.h>
/*
int utn_getFloat(char* msg)
{
    float aux;
    printf(msg);
    scanf("%f",aux);
    return aux;
}

int utn_getInt(char* msg)
{
    int aux;
    printf(msg);
    scanf("%d",aux);
    return aux;
}

char utn_getChar(char* msg)
{
    char aux;
    printf(msg);
    fflush(stdin);
    scanf("%c",aux);
    return aux;

}

int utn_isNumberFloat(char str[])
{
   int i=0;
   int cantidadPuntos=0;
   while(str[i] != '\0')
   {
       if (i == 0 && str[i] == '-')
       {
           i++;
           continue;
       }
       if (str[i] == '.' && cantidadPuntos == 0)
       {
           cantidadPuntos++;
           i++;
           continue;
       }
       if(str[i] < '0' || str[i] > '9')
       {
            return 0;
       }
       i++;
   }
   return 1;
}

int isNumber(char* str)
{
    int i=0;
    while(str[i] != '\0')
    {
        if(i == 0 && str[i] == '-')
        {
            i++;
            continue;
        }
        if(str[i]<'0' || str[i]>'9')
        {
            return 0;
        }
        i++;
    }
    return 1;
}

int isLyrics(char* str)
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
        {
            return 0;
        }
        i++;
    }
    return 1;
}

void getString(char* msg,char* pInput)
{
    printf(msg);
    fflush(stdin);
    scanf("%[^\n]s",pInput);
}

int getStringLyrics(char* msg,char* pInput)
{
    char aux[256];

}*/
