#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

int getNumberInt(int *numero,char *msg,char *msgError,int minInt,int maxInt,int reintentos);
int getNumberFloat(float *numero,char *msg,char *msgError,int minInt,int maxInt,int reintentos);
int getChar(char *str,char *msg,char *msgError,int minInt,int maxInt,int reintentos);
int getArrayInt(int *pArray,int limite,char *msg,char *msgError,int minInt,int maxInt,int reintentos);
int initArrayInt(int *pArray,int limite,int valor);
int printArrayInt(int *pArray,int limite);
int sumaDeNumerosIngresado(int *pNumero,int limite);
int intMaxMinProm(int *pArray,int limite);
int sumaArrays(int *pArray,int len);
int ordenar(int *pArray,int len);
void utn_getString(char *mensaje,char *input);
int utn_printString(char str[][50],int len);
int cargarSetDatos(int *aLegajo,char *aSexo,int *aEdad,int *aNotaP,int *aNotaSP,float *aPromedio,int len);
int isValidNumber(int *numero);

#endif // FUNCIONES_H_INCLUDED
