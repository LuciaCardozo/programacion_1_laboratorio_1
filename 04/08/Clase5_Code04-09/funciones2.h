#ifndef FUNCIONES2_H_INCLUDED
#define FUNCIONES2_H_INCLUDED

int getNumberInt(int *numero,char *msg,char *msgError,int minInt,int maxInt,int reintentos);
int getArrayInt(int *pArray,int limite,char *msg,char *msgError,int minInt,int maxInt,int reintentos);
int initArrayInt(int *pArray,int limite,int valor);
int printArrayInt(int *pArray,int limite);
int sumaDeNumerosIngresado(int *pNumero,int limite);
int printMaxMinInt(int *pArray,int limite);
int printSumaArrays(int *pArray,int len);
int printSacarPromedio(int *pArray,int len);
int swapBubble(int *pArray,int len);

#endif // FUNCIONES2_H_INCLUDED
