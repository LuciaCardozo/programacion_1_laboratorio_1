#include <stdio.h>
#include <stdlib.h>

void initArray(int *pArray,int len,int valor)
{
    int i;
    for(i=0;i<len;i++)
    {
        pArray[i]=valor;
    }
}

void printArray(int *pArray,int len)
{
    int i;
    for(i=0;i<len;i++)
    {
        printf("\nnumero: %d",pArray[i]);
    }
}

void cargarUnArraySecuencial(int *pArray,int len,char *msg)
{
    int i=0;
    for(i=0;i<len;i++)
    {
        printf(msg);
        scanf("%d",&pArray[i]);
    }
}

int getMax(int *pArray,int len,int *numMax)
{
    int i;
    int maximo;
    for(i=0;i<len;i++)
    {
        if(i==0 || pArray[i]>maximo)
        {
            maximo=pArray[i];
        }
    }
    *numMax=maximo;
    return maximo;
}

int getMaxInd(int *pArray,int len,int *indiceMax)
{
    int i;
    int indiceMaximo;
    int maximo;
    getMax(pArray,len,&maximo);
    for(i=0;i<len;i++)
    {
        if(pArray[i]==maximo)
        {
            indiceMaximo=i;
        }
    }
    *indiceMax=indiceMaximo;
    return indiceMaximo;
}

int getMin(int *pArray,int len,int *numMin)
{
    int i;
    int minimo;
    for(i=0;i<len;i++)
    {
        if(i==0 || pArray[i]<minimo)
        {
            minimo=pArray[i];
        }
    }
    *numMin=minimo;
    return minimo;
}

int getMinInd(int *pArray,int len,int *indiceMin)
{
    int i;
    int indiceMinimo;
    int minimo;
    getMax(pArray,len,&minimo);
    for(i=0;i<len;i++)
    {
        if(pArray[i]==minimo)
        {
            indiceMinimo=i;
        }
    }
    *indiceMin=indiceMinimo;
    return indiceMinimo;
}

int swapBubble(int *pArray,int len)
{
    int ret = -1;
    int i,j,aux;
    if(pArray!=NULL && len>0)
    {
        for(i=0;i<len-1;i++)
        {
            for(j=i+1;j<len;j++)
            {
                aux=pArray[i];
                pArray[i]=pArray[j];
                pArray[j]=aux;
            }
        }
        ret = 0;
    }
    return ret;
}

int bubbleSort(int *pArray,int len)
{
    int i,aux;
    int flagNoEstaOrdenado = 1;
    while(flagNoEstaOrdenado==1)
    {
        flagNoEstaOrdenado=0;
        for(i=0;i<len-1;i++)
        {
            if(pArray[i]>pArray[i+1])
            {
                    aux=pArray[i];
                    pArray[i]=pArray[i+1];
                    pArray[i+1]=aux;
                    flagNoEstaOrdenado=1;
            }
        }
    }
    return 0;
}
