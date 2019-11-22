#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "ventas.h"

Venta* venta_new()
{
	Venta* pVen = (Venta*)malloc( sizeof(Venta));

	if(pVen != NULL){
	   strcpy(pVen->cuit, "");
	   pVen->fecha_venta.dia = 0;
	   pVen->fecha_venta.mes = 0;
	   pVen->fecha_venta.anio = 0;
	   pVen->tipo = 0;
	   pVen->cantidad = 0;
	   pVen->precio = 0;
	}
	return pVen;
}

/*Venta* venta_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr)
{
	Ventas* pVen = venta_new();
	int auxId;
	int auxHoras;
	auxId = atoi(idStr);
	auxHoras = atoi(horasTrabajadasStr);
	if(pEmp != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL)
    {
    	employee_setId(pEmp,auxId);
    	employee_setNombre(pEmp,nombreStr);
        employee_setHorasTrabajadas(pEmp,auxHoras);
    }
    else
    {
        employee_delete(pEmp);
    }
    return pEmp;
}*/

int venta_delete(Venta* this)
{
    int ret = -1;
    if(this != NULL)
    {
        free(this);
        ret = 0;
    }
    return ret;
}

int venta_setId(Venta* this,int id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}

int venta_setCuit(Venta* this,char* cuit)
{
    int retorno = -1;
    if(this != NULL && cuit!=NULL)
    {
        strncpy(this->cuit,cuit,sizeof(this->cuit));
        retorno = 0;
    }
    return retorno;
}

int venta_setFecha(Venta* this,int dia,int mes,int anio)
{
    int retorno = -1;
    if(this != NULL && dia > 0 && mes > 0 && anio > 0)
    {
        this->fecha_venta.dia = dia;
        this->fecha_venta.mes = mes;
        this->fecha_venta.anio  = anio;
        retorno = 0;
    }
    return retorno;
}

int venta_setCantidad(Venta* this,int cantidad)
{
    int retorno = -1;
    if(this != NULL && cantidad > 0)
    {
        this->cantidad = cantidad;
        retorno = 0;
    }
    return retorno;
}

int venta_setPrecio(Venta* this,float precio)
{
    int retorno = -1;
    if(this != NULL && precio > 0)
    {
        this->precio = precio;
        retorno = 0;
    }
    return retorno;
}

int venta_setTipo(Venta* this,char* tipo)
{
    int retorno = -1;
    if(this != NULL && tipo!=NULL)
    {
        strncpy(this->tipo,tipo,sizeof(this->tipo));
        retorno = 0;
    }
    return retorno;
}

int venta_getId(Empleado* this,int* id)
{
    int retorno = -1;
    if(this != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}

int venta_getCuit(Empleado* this,char* cuit)
{
    int retorno = -1;
    if(this != NULL)
    {
        strncpy(nombre,this->nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int venta_getFecha(Venta* this,int* dia,int* mes,int* anio)
{
    int retorno = -1;
    if(this != NULL && dia > 0 && mes > 0 && anio > 0)
    {
        *dia = this->fecha_venta.dia;
        *mes = this->fecha_venta.mes;
        *anio = this->fecha_venta.anio;
        retorno = 0;
    }
    return retorno;
}

int venta_getCantidad(Empleado* this,int* cantidad)
{
    int retorno = -1;
    if(this != NULL)
    {
        *cantidad = this->cantidad;
        retorno = 0;
    }
    return retorno;
}

int venta_getCantidad(Empleado* this,float* precio)
{
    int retorno = -1;
    if(this != NULL)
    {
        *precio = this->precio;
        retorno = 0;
    }
    return retorno;
}

int venta_getTipo(Empleado* this,int* tipo)
{
    int retorno = -1;
    if(this != NULL)
    {
        *tipo = this->tipo;
        retorno = 0;
    }
    return retorno;
}
