#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int respuestaSeguir()
{
    char respuesta[25];

    printf("ingrese si para continuar\n");
    scanf("%s",respuesta);

    while(strcmp("si",respuesta)==0)
    {




        printf("ingrese si para continuar\n");
        scanf("%s",respuesta);
    }
    return 0;
}
//hacer una funcion que muestre un menu
/*
1.-Hola todo bien?
2.-Hola como estas?
3.-Hola tenes novio?
4.-Hola te caiste?
5.-Hola ya fue suficiente.
*/
int mostrarMenu()
{
    int menu;
    printf("1.-Hola todo bien?\n");
    printf("2.-Hola como estas?\n");
    printf("3.-Hola tenes novio?\n");
    printf("4.-Hola te caiste?\n");
    printf("5.-Hola ya fue suficiente.\n");
    scanf("%d",&menu);
    return 0;
}

int pedirSumaMostrar()
{
    float numeroUno;
    float numeroDos;
    float resultado;
    printf("Ingrese un numero 1:\n");
    scanf("%f",&numeroUno);
    printf("Ingrese un numero 2:\n");
    scanf("%f",&numeroDos);
    resultado=numeroUno+numeroDos;
    printf("El resultado es:%.2f",resultado);
    return 0;
}
int pedirNumeroMostrar()
{
    float numero[2];
    int contador=0;
    while (contador<2)
    {
        printf("Ingrese un numero\n");
        scanf("%f",&numero[contador]);
        contador++;
    }
    printf("Los numeros son:%.2f y %.2f\n",numero[0],numero[1]);
    return 0;
}
int pedirNumerosEnteros()
{
    int numero[5];
    int contador=0;
    while(contador<5)
    {
        printf("Ingrese un numero\n");
        scanf("%d",&numero[contador]);
        contador++;
    }
    printf("Los numeros son:%d, %d, %d, %d y %d\n",numero[0],numero[1],numero[2],numero[3],numero[4]);
    return 0;
}
float sumarDosNumeros( float numeroUno, float numeroDos, float* Presultado)
{
    *Presultado=numeroUno+numeroDos;
    return 0;

}
float restaDosNumeros(float numeroUno, float numeroDos)
{
    float resultado=numeroUno-numeroDos;
    return resultado;
}
float multiplicacionDosNumeros(float numeroUno, float numeroDos)
{
    float resultado=numeroUno*numeroDos;
    return resultado;
}
float divisionDosNumeros(float numeroUno, float numeroDos)
{
    float resultado=numeroUno/numeroDos;
    return resultado;
}
//hacer una funcion que le pida al usuario si quiere continuar o no. "seguir" para continuar


//hacer una funcion que pida dos numero y los sume

//hacer una funcion que pida dos numeros al usuario y los muestre en pantalla, retorna 0 si esta bien.

//hacer una funcion que reciba por parametro dos numeros y los sume


