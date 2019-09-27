#ifndef LLAMADAS_H_INCLUDED
#define LLAMADAS_H_INCLUDED

typedef struct
{
    int idLlamada;
    int isEmpty;
    int idAsociado;
    char motivo[50];
    int estado;
    int idAmbulancia;
    float tiempo;
}Llamadas;

#endif /* LLAMADAS_H_INCLUDED*/
