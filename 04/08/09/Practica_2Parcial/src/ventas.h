/*
 * ventas.h
 *
 *  Created on: 20 nov. 2019
 *      Author: alumno
 */

#ifndef VENTAS_H_
#define VENTAS_H_

typedef struct
{
	int dia;
	int mes;
	int anio;
}Fecha;

typedef struct
{
	int id;
	char cuit[20];
	Fecha fecha_venta;
	int tipo;
	int cantidad;
	float precio;
}Venta;

Venta* venta_new();
Venta* empleado_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr);
int venta_delete(Venta* this);
int venta_setId(Venta* this,int id);
int venta_setCuit(Venta* this,char* cuit);
int venta_setFecha(Venta* this,int dia,int mes,int anio);
int venta_setCantidad(Venta* this,int cantidad);
int venta_setPrecio(Venta* this,float precio);

#endif /* VENTAS_H_ */
