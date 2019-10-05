#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Orquesta.h"
#include "Musico.h"
#include "Instrumento.h"

int menuOrquesta(Orquesta *listOrquesta,int lenOrquesta)
{
    initOrquesta(listOrquesta,lenOrquesta);
    int opciones;
    int ret=-1;
    int auxId;
    int auxPos;
    int flag;
    do
    {
        if(utn_getValidInt("\n1-Alta Orquesta\n2-Baja de Orquesta\n3-Imprimir Orquesta\n4-Salir\nIngrese opcion: ",
        "\nOpcion incorrecta\n",&opciones,1,4,2)==0)
        {
            switch(opciones)
            {
                case 1:
                    printf("\n---------------------------\n");
                    if(registerAnOrquesta(listOrquesta,lenOrquesta)==0)
                    {
                        printf("\n---------------------------\n");
                        printf("\nAlta Exitosa\n");
                        printf("\n---------------------------\n");
                        flag=1;
                    }
                    else
                    {
                        printf("\nError\n");
                    }
                    break;
                case 2:
                    if(flag)
                    {
                        printOrquestas(listOrquesta,lenOrquesta);
                        if(utn_getValidInt("\nIngrese Id : ","\nERROR, id no existe.",&auxId,1,99999,2)==0)
                        {
                            if(findOrquestaById(listOrquesta,lenOrquesta,auxId,&auxPos)!=-1)
                            {
                                if(removeOrquesta(listOrquesta,lenOrquesta,auxId)!=-1)
                                {
                                    printf("\n---------------------------\n");
                                    printf("\nBaja Exitosa\n");
                                    printf("\n---------------------------\n");

                                }
                            }
                        }
                    }
                    else
                    {
                        printf("\nNo hay orquestas\n");
                    }
                    break;
                case 3:
                    if(flag)
                    {
                        printf("\n---------------------------\n");
                        printOrquestas(listOrquesta,lenOrquesta);
                        printf("\n---------------------------\n");
                    }
                    else
                    {
                        printf("\nNo hay orquestas\n");
                    }
                    break;
                case 4:
                    break;
                default:
                    printf("\nOpcion incorrecta\n");
                    break;
            }
        }
        ret=0;
    }while(opciones!=4);
    return ret;
}

int menuMusico(Musico *listMusico,int lenMusico)
{
    initMusicos(listMusico,lenMusico);
    int opciones;
    int ret=-1;
    int auxId;
    int auxPos;
    int flag;
    do
    {
        if(utn_getValidInt("\n1-Alta Musico\n2-Modificar Musico\n3-Baja de Musico\n4-Imprimir Orquesta\n5-Salir\nIngrese opcion: ",
            "\nOpcion incorrecta\n",&opciones,1,5,2)==0)
        {
            switch(opciones)
            {
                case 1:
                    printf("\n---------------------------\n");
                    if(registerAnMusico(listMusico,lenMusico)==0)
                    {
                        printf("\n---------------------------\n");
                        printf("\nAlta Exitosa\n");
                        printf("\n---------------------------\n");
                        flag=1;
                    }
                    else
                    {
                        printf("\nError");
                    }
                    break;
                case 2:
                    if(flag)
                    {
                        printMusicos(listMusico,lenMusico);
                        if(modifyAnMusico(listMusico,lenMusico)!=-1)
                        {
                            printf("\n---------------------------\n");
                            printf("\nModificacion Exitosa\n");
                            printf("\n---------------------------\n");
                        }
                    }
                    else
                    {
                        printf("\nNo hay Musicos\n");
                    }
                    break;
                case 3:
                    if(flag)
                    {
                        printMusicos(listMusico,lenMusico);
                        if(utn_getValidInt("\nIngrese Id : ","\nERROR, id no existe.",&auxId,1,99999,2)==0)
                        {
                            if(findMusicoById(listMusico,lenMusico,auxId,&auxPos)!=-1)
                            {
                                if(removeMusico(listMusico,lenMusico,auxId)!=-1)
                                {
                                    printf("\n---------------------------\n");
                                    printf("\nBaja Exitosa\n");
                                    printf("\n---------------------------\n");
                                }
                            }
                        }
                    }
                    else
                    {
                        printf("\nNo hay Musicos\n");
                    }
                    break;
                case 4:
                    if(flag)
                    {
                        printf("\n---------------------------\n");
                        printMusicos(listMusico,lenMusico);
                        printf("\n---------------------------\n");
                    }
                    else
                    {
                        printf("\nNo hay Musicos\n");
                    }
                    break;
                case 5:
                    break;
                default:
                    printf("\nOpcion incorrecta\n");
                    break;
            }
        }
        ret=0;
    }while(opciones!=5);
    return ret;
}

int menuInstrumento(Instrumento *listInstrumento,int lenInstrumento)
{
    initInstrumentos(listInstrumento,lenInstrumento);
    int opciones;
    int ret=-1;
    int flag;
    do
    {
        if(utn_getValidInt("\n1-Alta Instrumento\n2-Imprimir Instrumento\n3-Salir\nIngrese opcion: ","\nOpcion incorrecta\n",&opciones,1,3,2)==0)
        {
            switch(opciones)
            {
                case 1:
                    printf("\n---------------------------\n");
                    if(registerAnInstrumento(listInstrumento,lenInstrumento)==0)
                    {
                        printf("\n---------------------------\n");
                        printf("\nAlta Exitosa\n");
                        printf("\n---------------------------\n");
                        flag=1;
                    }
                    else
                    {
                        printf("\nError");
                    }
                    break;
                case 2:
                    if(flag)
                    {
                        printf("\n---------------------------\n");
                        printInstrumentos(listInstrumento,lenInstrumento);
                        printf("\n---------------------------\n");
                    }
                     else
                    {
                        printf("\nNo hay Instrumentos\n");
                    }
                    break;
                case 3:
                    break;
                default:
                    printf("\nOpcion incorrecta\n");
                    break;
            }
        }
        ret=0;
    }while(opciones!=3);
    return ret;
}
