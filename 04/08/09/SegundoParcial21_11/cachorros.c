#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "cachorros.h"
#include "linkedList.h"
#include "utn.h"

Cachorro* cachorro_new()
{
	Cachorro* pCach = (Cachorro*)malloc( sizeof(Cachorro));

	if(pCach != NULL)
	{
        pCach->id = 0;
	    strcpy(pCach->nombre, "");
	    pCach->dia = 0;
	    strcpy(pCach->raza, "");
	    strcpy(pCach->reservado, "");
	    strcpy(pCach->genero, "");
	}
	return pCach;
}

Cachorro* cachorro_newParametros(char* idStr,char* nombreStr,char* diasStr,char* razaStr,char* reservadoStr,char* generoStr)
{
	Cachorro* pCach = cachorro_new();
	int auxId;
	int auxDia;
	auxId = atoi(idStr);
	auxDia = atoi(diasStr);
	if(pCach != NULL && idStr != NULL && nombreStr != NULL && diasStr != NULL && razaStr != NULL &&
	reservadoStr != NULL && generoStr != NULL)
    {
    	cachorro_setId(pCach,auxId);
    	cachorro_setNombre(pCach,nombreStr);
    	cachorro_setDia(pCach,auxDia);
        cachorro_setRaza(pCach,razaStr);
        cachorro_setReservado(pCach,reservadoStr);
        cachorro_setGenero(pCach,generoStr);
    }
    else
    {
        cachorro_delete(pCach);
    }
    return pCach;
}

int cachorro_delete(Cachorro* this)
{
    int ret = -1;
    if(this != NULL)
    {
        free(this);
        ret = 0;
    }
    return ret;
}

int cachorro_setId(Cachorro* this,int id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}

int cachorro_setNombre(Cachorro* this,char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre!=NULL)
    {
        strncpy(this->nombre,nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int cachorro_setDia(Cachorro* this,int dia)
{
    int retorno = -1;
    if(this != NULL && dia >= 0)
    {
        this->dia = dia;
        retorno = 0;
    }
    return retorno;
}

int cachorro_setRaza(Cachorro* this,char* raza)
{
    int retorno = -1;
    if(this != NULL && raza!=NULL)
    {
        strncpy(this->raza,raza,sizeof(this->raza));
        retorno = 0;
    }
    return retorno;
}

int cachorro_setReservado(Cachorro* this,char* reservado)
{
    int retorno = -1;
    if(this != NULL && reservado != NULL)
    {
        strncpy(this->reservado,reservado,sizeof(this->reservado));

        retorno = 0;
    }
    return retorno;
}

int cachorro_setGenero(Cachorro* this,char* genero)
{
    int retorno = -1;
    if(this != NULL && genero != NULL)
    {
        strncpy(this->genero,genero,sizeof(this->genero));
        retorno = 0;
    }
    return retorno;
}


int cachorro_getId(Cachorro* this,int* id)
{
    int retorno = -1;
    if(this != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}

int cachorro_getNombre(Cachorro* this,char* nombre)
{
    int retorno = -1;
    if(this != NULL)
    {
        strncpy(nombre,this->nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int cachorro_getDia(Cachorro* this,int* dia)
{
    int retorno = -1;
    if(this != NULL)
    {
        *dia = this->dia;
        retorno = 0;
    }
    return retorno;
}

int cachorro_getRaza(Cachorro* this,char* raza)
{
    int retorno = -1;
    if(this != NULL)
    {
        strncpy(raza,this->raza,sizeof(this->raza));
        retorno = 0;
    }
    return retorno;
}


int cachorro_getReservado(Cachorro* this,char* reservado)
{
    int retorno = -1;
    if(this != NULL)
    {
        strncpy(reservado,this->reservado,sizeof(this->reservado));
        retorno = 0;
    }
    return retorno;
}

int cachorro_getGenero(Cachorro* this,char* genero)
{
    int retorno = -1;
    if(this != NULL)
    {
        strncpy(genero,this->genero,sizeof(this->genero));
        retorno = 0;
    }
    return retorno;
}

/** \brief Listar empleados
 *
 * \param pArrayListCachorro LinkedList*
 * \return retorna 0 si esta todo ok o -1 si hay error
 *
 */
int controller_ListCachorro(LinkedList* pArrayListCachorro)
{
    int i;
    int ret = -1;
    int len;
    if(pArrayListCachorro != NULL)
    {
        if(ll_len(pArrayListCachorro) > 0)
        {
            len = ll_len(pArrayListCachorro);
            for(i=0 ; i<len ; i++)
            {
                controller_mostrarCachorroPorIdEnFila(pArrayListCachorro,i);
            }
            ret = 0;
        }
        else
        {
            printf("No existen datos cargados.");
        }
    }
    return ret;
}
/** \brief Muestra un empleado en fila
 *
 * \param index es el indice de la lista
 * \param pArrayListCachorro LinkedList*
 * \return retorna 0 si esta todo ok o -1 si hay error
 *
 */
int controller_mostrarCachorroPorIdEnFila(LinkedList* pArrayListCachorro, int index)
{
    Cachorro* pCach;
    int auxId;
    char auxNombre[50];
    int auxDia;
    char auxRaza[50];
    char auxReservado[3];
    char auxGenero[3];
    int ret = -1;
    if(pArrayListCachorro != NULL && index >= 0 && index < ll_len(pArrayListCachorro))
    {
        pCach = (Cachorro*)ll_get(pArrayListCachorro,index);
        cachorro_getId(pCach,&auxId);
        cachorro_getNombre(pCach,auxNombre);
        cachorro_getDia(pCach,&auxDia);
        cachorro_getRaza(pCach,auxRaza);
        cachorro_getReservado(pCach,auxReservado);
        cachorro_getGenero(pCach,auxGenero);
        printf("%d,%s,%d,%s,%s,%s\n",auxId,auxNombre,auxDia,auxRaza,auxReservado,auxGenero);
        ret = 0;
    }
    return ret;
}

int em_filtrarMenoresDe45Dias(void* p)
{
    int auxDia;
    int ret = 0;
	if(p != NULL)
    {
        cachorro_getDia(p,&auxDia);
        if(auxDia>0 && auxDia < 45)
        {
            ret = 1;
        }
    }
    return ret;
}

int em_filtrarMachos(void* p)
{
    char auxGenero[3];
    int ret = 0;
	if(p != NULL)
    {
        cachorro_getGenero(p,auxGenero);
        if(strcmp(auxGenero,"M")!=0)
        {
            ret = 1;
        }
    }
    return ret;
}

int controller_ListCachorroCallejero(LinkedList* pArrayListCachorro)
{
    int i;
    int ret = -1;
    int len;
    Cachorro* pCach;
    if(pArrayListCachorro != NULL)
    {
        if(ll_len(pArrayListCachorro) > 0)
        {
            len = ll_len(pArrayListCachorro);
            for(i=0 ; i<len ; i++)
            {
                pCach=ll_get(pArrayListCachorro,i);
                if(strcmp(pCach->raza,"Callejero")==0)
                {
                    controller_mostrarCachorroPorIdEnFila(pArrayListCachorro,i);
                }
            }
            ret = 0;
        }
        else
        {
            printf("No existen datos cargados.");
        }
    }
    return ret;
}

static int idMax = 0;

void cachorro_idInit(int id)
{
    idMax = id+1;
}

int generarId()
{
    return idMax++;
}
