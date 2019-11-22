#ifndef CACHORROS_H_INCLUDED
#define CACHORROS_H_INCLUDED
#include "linkedList.h"
typedef struct
{
    int id;
    char nombre[50];
    int dia;
    char raza[50];
    char reservado[3];
    char genero[3];
}Cachorro;

Cachorro* cachorro_new();
Cachorro* cachorro_newParametros(char* idStr,char* nombreStr,char* diasStr,char* razaStr,char* reservadoStr,char* generoStr);
int cachorro_delete(Cachorro* this);

int cachorro_setId(Cachorro* this,int id);
int cachorro_setNombre(Cachorro* this,char* nombre);
int cachorro_setDia(Cachorro* this,int dia);
int cachorro_setRaza(Cachorro* this,char* raza);
int cachorro_setReservado(Cachorro* this,char* reservado);
int cachorro_setGenero(Cachorro* this,char* genero);

int cachorro_getId(Cachorro* this,int* id);
int cachorro_getNombre(Cachorro* this,char* nombre);
int cachorro_getDia(Cachorro* this,int* dia);
int cachorro_getRaza(Cachorro* this,char* raza);
int cachorro_getReservado(Cachorro* this,char* reservado);
int cachorro_getGenero(Cachorro* this,char* genero);

int controller_mostrarCachorroPorIdEnFila(LinkedList* pArrayListCachorro, int index);
int controller_ListCachorro(LinkedList* pArrayListCachorro);

void cachorro_idInit(int id);
int generarId();

int em_filtrarMenoresDe45Dias(void* p);
int em_filtrarMachos(void* p);
int controller_ListCachorroCallejero(LinkedList* pArrayListCachorro);
#endif /* CACHORROS_H_INCLUDED */
