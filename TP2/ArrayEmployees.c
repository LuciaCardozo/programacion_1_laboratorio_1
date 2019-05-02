#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utn.h"
#include "ArrayEmployees.h"
#define OCUPADO 1
#define LIBRE 0

int proximoId(void)
{
    static int idMax=0;
    return idMax++;
}
int emp_buscarLugarLibre(Employee* employees,int limite)
{
    int retorno=-1;//-1 devuelve si no hay lugar libre
    int i;
    for(i=0;i<limite;i++)
    {
        if(employees[i].isEmpty==LIBRE)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}

int emp_initEmployees(Employee* list, int len)
{
    int retorno;
    int i;
    for(i=0;i<len;i++)
    {
        list[i].isEmpty=LIBRE;
        retorno=0;
    }
    return retorno;
}


int emp_addEployees(Employee* list,int len)
{
    int retorno=-1;
    char auxName[51];
    char auxLastName[51];
    float auxSalary;
    int auxSector;
    int posLibre;

    if( (utn_getValidName(auxName)==0) &&
        (utn_getValidLastName(auxLastName)==0) &&
        (utn_getValidFloat("Ingrese sueldo: ","Error, la repuesta no es valida\n",&auxSalary,0,999999,3)==0) &&
        (utn_getValidInt("Ingrese sector: ","Error, la repuesta no es valida\n",&auxSector,0,999999,3)==0) )
    {
        posLibre=emp_buscarLugarLibre(list,len);
        if(posLibre!=-1)//si encuentra lugar Guardamos al empleado
        {
            strncpy(list[posLibre].name,auxName,51);
            strncpy(list[posLibre].lastName,auxLastName,51);
            list[posLibre].salary=auxSalary;
            list[posLibre].sector=auxSector;
            list[posLibre].isEmpty=OCUPADO;
            list[posLibre].idEmployee=proximoId();
        }
    }
    return retorno;
}

int emp_printEmployees(Employee* list, int len)
{
    int retorno=-1;
    int i;
    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty==OCUPADO)
        {
            retorno=0;
            printf("Empleado en la posicion %d\n",i);
            printf("%s %s\nSalario: %f\nSector: %d\n\n",list[i].name, list[i].lastName,list[i].salary, list[i].sector);
        }

    }
    return retorno;
}

