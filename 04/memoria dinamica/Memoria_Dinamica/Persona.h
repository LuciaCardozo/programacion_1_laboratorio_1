#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
struct S_Persona
{
    int id;
    char nombre[32];
    char apellido[32];
    int edad;
};
typedef struct S_Persona Persona;

Persona* per_new(void);
Persona* per_newParametro(int id,char* nombre,char* apellido,int edad);

int per_setId(Persona* this,int id);
int per_setNombre(Persona* this,char* nombre);
int per_setApellido(Persona* this,char* apellido);
int per_setEdad(Persona* this,int edad);
int per_getId(Persona* this, int* id);
int per_getEdad(Persona* this, int* edad);
int per_getNombre(Persona* this,char* nombre);
int per_getApellido(Persona* this, char* apellido);
int per_delete(Persona* this);
int per_initArray(Persona** list, int len);
int per_buscarLugarLibre(Persona** list,int len);
int proximoId(void);


#endif // PERSONA_H_INCLUDED
