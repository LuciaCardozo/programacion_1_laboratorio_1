#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Persona.h"
#include "utn.h"

Persona* per_new(void)
{
    return (Persona*)malloc(sizeof(Persona));
}

Persona* per_newParametro(int id,char* nombre,char* apellido,int edad)
{
    Persona* p = per_new();
    if(p!=NULL)
    {
        per_setId(p,id);
        per_setNombre(p,nombre);
        per_setApellido(p,apellido);
        per_setEdad(p,edad);

    }
    return p;
}

int per_setId(Persona* this,int id)
{
    if(this!=NULL)
    {
        this->id = id;
        return 0;
    }
    return 1;
}

int per_getId(Persona* this, int* id)
{
    if(this!=NULL)
        {
            *id=this->id;
            return 0;
        }
        return 1;
}
int per_setEdad(Persona* this,int edad)
{

    if(this!=NULL)
    {
        this->edad = edad;
        return 0;
    }
    return 1;
}
int per_getEdad(Persona* this, int* edad)
{
    if(this!=NULL)
    {
        *edad=this->edad;
        return 0;
    }
    return 1;
}
int per_setNombre(Persona* this,char* nombre)
{
    if(this!=NULL && nombre!=NULL)
        {
            strncpy(this->nombre,nombre,sizeof(this->nombre));
            return 0;
        }
        return 1;
}
int per_setApellido(Persona* this,char* apellido)
{
    if(this!=NULL && apellido!=NULL)
        {
            strncpy(this->apellido,apellido,sizeof(this->apellido));
            return 0;
        }
        return 1;
}
int per_getNombre(Persona* this,char* nombre)
{
    if(this!=NULL && nombre!=NULL)
        {
            strncpy(nombre,this->nombre,sizeof(this->nombre));
            return 0;
        }
        return 1;
}
int per_getApellido(Persona* this, char* apellido)
{
     if(this!=NULL && apellido!=NULL)
        {
            strncpy(apellido,this->apellido,sizeof(this->apellido));
            return 0;
        }
        return 1;
}
int per_delete(Persona* this)
{
    if(this!=NULL)
    {
        free(this);
        return 0;
    }
    return 1;
}
int per_initArray(Persona** list, int len)
{
    int retorno=-1;
    int i;
    if(list!=NULL && len>0)
    {
        retorno=0;
        for(i=0; i<len; i++)
        {
            list[i]=NULL;
        }
    }
    return retorno;
}

int per_buscarLugarLibre(Persona** list,int len)
{
    int retorno=-1;//-1 devuelve si no hay lugar libre
    int i;
    if(list!=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            if(list[i]==NULL)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

int proximoId(void)
{
    static int idMax=1;
    return idMax ++;
}

/*int per_findPersById(Persona** list, int len,int id)
{
    int retorno=-1;
    int i;
    if(list!=NULL && len>0 && id>0)
    {
        for(i=0; i<len; i++)
        {
            if(list[i]==id)
            {
                retorno=i;
            }
        }
    }
    return retorno;
}*/

int per_altaPersona(Persona** list, int len)
{
    int retorno=-1;
    Persona* auxPers;
    int posLibre;
    int auxId;
    char auxNombre[31];
    char auxApellido[31];
    int auxEdad;

    posLibre=per_buscarLugarLibre(list,len);
        if((utn_getValidName(auxNombre)==0) &&
        (utn_getValidLastName(auxApellido)==0) &&
        (utn_getValidInt("\nIngrese edad: ","\nError",&auxEdad,1,90,3)==0))
        {
            auxId=proximoId();
            auxPers=per_newParametro(auxId,auxNombre,auxApellido,auxEdad);
            if(auxPers!=NULL)
            {
                if(posLibre>=0)
                {
                    list[posLibre]=auxPers;
                retorno=0;
                }
            //printf("\nId: %d\nNombre: %s\nLugar: %s\n",auxIdOrquesta,auxName,auxLugar);
        }

    }
    return retorno;
    }
