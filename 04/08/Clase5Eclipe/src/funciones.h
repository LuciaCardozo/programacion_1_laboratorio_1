/*
 * funciones.h
 *
 *  Created on: 5 sep. 2019
 *      Author: alumno
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

int getNumberInt(int *numero,char *msg,char *msgError,int minInt,int maxInt,int reintentos);
int getArrayInt(int *pArray,int limite,char *msg,char *msgError,int minInt,int maxInt,int reintentos);
int initArrayInt(int *pArray,int limite,int valor);
int printArrayInt(int *pArray,int limite);
int sumaDeNumerosIngresado(int *pNumero,int limite);
int intMaxMinProm(int *pArray,int limite);
int sumaArrays(int *pArray,int len);
int ordenar(int *pArray,int len);


#endif /* FUNCIONES_H_ */
