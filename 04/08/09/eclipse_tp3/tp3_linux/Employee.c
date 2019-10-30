#include <string.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

static int generarId(void);

Employee* employee_new()
{
    return (Employee*) malloc(sizeof(Employee));
}

Employee* employee_newParametros(char* nombre,char* apellido,char* edad)
{
	Employee* emp=employee_new();
    if(emp!=NULL)
    {
    	employee_setNombre(emp,nombre);
    	employee_sethorasTrabajadas(emp,horasTrabajadas);
    	employee_setSueldo(emp,sueldo);
    }

    return emp;
}

int employee_delete(Employee* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

int employee_setId(Employee* this, int value)
{
    int retorno = -1;
    if(this != NULL && value >= 0)
    {
        this->id = value;
        retorno = 0;
    }
    return retorno;
}

int employee_setNombre(Employee* this, char* value)
{
    int retorno = -1;
    if(this != NULL && isLetter(value))
    {
        strncpy(this->nombre,value,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int employee_sethorasTrabajadas(Employee* this, int value)
{
    int retorno = -1;
    if(this != NULL && value >= 0)
    {
        this->horasTrabajadas = value;
        retorno = 0;
    }
    return retorno;
}

int employee_setSueldo(Employee* this, int value)
{
    int retorno = -1;
    if(this != NULL && value >= 0)
    {
        this->sueldo = value;
        retorno = 0;
    }
    return retorno;
}

int employee_getId(Employee* this, int* value)
{
    int retorno = -1;
    if(this != NULL)
    {
        *value = this->id;
        retorno = 0;
    }
    return retorno;
}

int employee_getNombre(Employee* this, char* value)
{
    int retorno = -1;
    if(this != NULL)
    {
        strncpy(value,this->nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int employee_gethorasTrabajadas(Employee* this, int* value)
{
    int retorno = -1;
    if(this != NULL)
    {
        *value = this->horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}

int employee_getSueldo(Employee* this, int* value)
{
    int retorno = -1;
    if(this != NULL)
    {
        *value = this->sueldo;
        retorno = 0;
    }
    return retorno;
}

int abrirArchivos()
{

}

