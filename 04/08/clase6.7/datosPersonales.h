#ifndef DATOSPERSONALES_H_INCLUDED
#define DATOSPERSONALES_H_INCLUDED

typedef struct()
{
    char adress[20];
    int number;
}Direccion;

typedef struct()
{
    char name[20];
    char lastName[20];
    Direccion domicilio;
}Datos;


#endif /* DATOSPERSONALES_H_INCLUDED*/
