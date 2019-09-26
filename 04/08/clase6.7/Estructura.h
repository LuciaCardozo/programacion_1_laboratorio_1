#ifndef ESTRUCTURA_H_INCLUDED
#define ESTRUCTURA_H_INCLUDED

typedef struct
{
    int isEmpty;
    int id;
    char nombre[50];
    char apellido[50];
    int edad;
    char dni[10];
}Persona;

int per_initPersona(Persona *list,int len);
int per_buscarLugarLibre(Persona *list,int len);
int per_addPersona(Persona *list, int len, int id, char *name,char *lastName,int edad,char *dni);
int per_altaPersona(Persona *list,int len);
int buscarPersonaPorId(Persona *list,int len,int id,int *posicion);
int bajaPersona(Persona *list,int len,int id);
int per_printfPersonas(Persona *list,int len);
int per_ordenarPorEdad(Persona *list,int len);
int modificarPersona(Persona *list, int len,int id);
int menu(Persona *list,int len);

#endif /* ESTRUCTURA_H_INCLUDED*/
