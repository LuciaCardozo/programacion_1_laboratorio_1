#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int getAge(int* age, char* message)
{
    int sePudo=0;
    int aux;
    printf(message);
    sePudo=scanf("%d",&aux);
    if(sePudo==1)
    {
        *age=aux;
    }
    return sePudo;
}
int getAgeTwo(int* age, char* message)
{
    int sePudo=1;
    char cadenaCargada[20];
    printf(message);
    scanf("%s",cadenaCargada);
    if(sePudo==1)
    {
        *age=atoi(cadenaCargada);
    }
    return sePudo;
}
int isInt(int* number, char* message)
{
    int sePudo=1;
    int i;
    char cadenaCargada[20];
    printf(message);
    fflush(stdin);
    scanf("%s",cadenaCargada);

    for(i=0;i<strlen(cadenaCargada);i++)
    {
        if((cadenaCargada[i]<'0' || cadenaCargada[i]=='\0') || cadenaCargada[i]>'9')
        {
            sePudo=0;
            break;
        }
    }
    if(sePudo==1)
    {
        *number=atoi(cadenaCargada);
    }
    return sePudo;

}
int isFloat(float* number, char* message)
{
    int sePudo=1;
    int i;
    char cadenaCargada[20];
    printf(message);
    fflush(stdin);
    scanf("%s",cadenaCargada);

    for(i=0;i<strlen(cadenaCargada);i++)
    {
        if((cadenaCargada[i]<'0' && cadenaCargada[i]!='.') || cadenaCargada[i]>'9'|| cadenaCargada[i]=='\0')
        {
            sePudo=0;
            break;
        }
    }
    if(sePudo==1)
    {
        *number=atof(cadenaCargada);
    }
    return sePudo;

}
int isChar(char* letters, char* message)
{
    int sePudo=0;
    int i;
    char cadenaCargada[20];
    printf(message);
    fflush(stdin);
    scanf("%s",cadenaCargada);

    for(i=0;i<strlen(cadenaCargada);i++)
    {
        if(cadenaCargada[i]>='a' && cadenaCargada[i]<='z')
        {
            *letters=cadenaCargada[i];
            sePudo=1;
            break;
        }
    }
    return sePudo;
}

