#ifndef ESTRUCTURA_H_INCLUDED
#define ESTRUCTURA_H_INCLUDED

typedef struct
{
    int isEmpty;
    int id;
    char nombre[50];
    int edad;
    char dni[10];
}Persona;

int per_initPersona(Persona *list,int len);
int per_buscarLugarLibre(Persona *list,int len);
int per_addPersona(Persona *list,int len,char *name,int *edad,char *dni);
int per_printfPersonas(Persona *list,int len,char *name,int *edad,char *dni);
int per_ordenarPorEdad(Persona *list,int len);

#endif /* ESTRUCTURA_H_INCLUDED*/
