#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arrayDeNumeros[5]={5,4,2,8,16};

        for(int i=0;i<5;i++)
        {
            int buffer;
            buffer=arrayDeNumeros[i];
            arrayDeNumeros[i]=arrayDeNumeros[i+1];
            arrayDeNumeros[i+1]=buffer;
            printf("%d\n",arrayDeNumeros[i]);
        }
    return 0;
}
