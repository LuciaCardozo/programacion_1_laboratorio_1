/*
 * funcionesDePrueba.c
 *
 *  Created on: 4 sep. 2019
 *      Author: alumno
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

int getNumberInt(int *numero,char *msg,char *msgError,int minInt,int maxInt,int reintentos)
{
    int i;
    int ret = -1;
    for(i=0; i<reintentos; i++)
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

int initArrayInt(int *pArray,int limite,int valor)
{
    int ret = -1;
    int i;
    if(pArray!=NULL && limite>0)
    {
        for(i=0; i<limite; i++)
        {
            pArray[i]=valor;
        }
        ret = 0;
    }
    return ret;
}

int printArrayInt(int *pArray,int limite)
{
    int ret = -1;
    int i;
    printf("\nDEBUG");
    if(pArray!=NULL && limite>0)
    {
        for(i=0; i<limite; i++)
        {
            printf("\n\t%d",pArray[i]);
        }
        ret = 0;
    }
    return ret;
}

int getArrayInt(int *pArray,int limite,char *msg,char *msgError,int minInt,int maxInt,int reintentos)
{
    int ret = -1;
    int buffer;
    char respuesta;
    int i=0;
    printf("\nDEBUG");
    if(pArray!=NULL && limite>0)
    {
        do
        {
            if(getNumberInt(&buffer,msg,msgError,minInt,maxInt,reintentos)==0)
            {
                pArray[i] = buffer;
                i++;
                if(i == limite)
                {
                    break;
                }
            }
            printf("\nContinuar (s/n)?\n");
            __fpurge(stdin);
            scanf("%c",&respuesta);
        }
        while(respuesta != 'n');
        ret = 0;
    }
    return ret;
}

int sumaDeNumerosIngresado(int *pNumero,int limite)
{
    int ret = -1;
    int i;
    for(i=0; i<limite; i++)
    {
        pNumero=pNumero+i;
        ret = 0;
    }
    return ret;
}

int sacarNumeroMaxMin(int *pFlag,float numero,float*numMax,float *numMin)
{
    float max = *numMax;
    float min = *numMin;
    int flag = *pFlag;

    if(flag==0)
    {
        max = numero;
        min = numero;
        *pFlag = 1;
    }
    if(numero>max)
    {
        max=numero;
    }
    *numMax = max;

    if(numero<min)
    {
        min=numero;
    }
    *numMin = min;

    return 0;
}

int intMaxMinProm(int *pArray,int limite)
{
    int sum=0;
    float max=0;
    float min=0;
    float promedio;
    int i=0;
    int flag=0;
    if(pArray!=NULL && limite>0)
    {
        for(i=0; i<limite; i++)
        {
            sum=sum+pArray[i];
            sacarNumeroMaxMin(&flag,pArray[i],&max,&min);
            if(i == limite)
            {
                break;
            }
        }

    }
    promedio=sum/i;
    printf("\nSuma: %d",sum);
    printf("\nPromedio: %.2f",promedio);
    printf("\nNumero Minimo: %.2f",min);
    printf("\nNumero Maximo: %.2f",max);
    return 0;
}


