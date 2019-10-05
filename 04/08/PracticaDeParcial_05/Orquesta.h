#ifndef ORQUESTA_H_INCLUDED
#define ORQUESTA_H_INCLUDED

typedef struct
{
    int idOrquesta;
    int isEmpty;
    char nombre[50];
    char lugar[50];
    int tipo;
}Orquesta;

int initOrquesta(Orquesta* listOrquesta, int lenOrquesta);
int findFreePlace(Orquesta* listOrquesta, int lenOrquesta);
int findOrquestaById(Orquesta* listOrquesta, int lenOrquesta,int id,int *posicion);
int addOrquesta(Orquesta* listOrquesta, int lenOrquesta, int id, char *name,char *place,int tipo);
int registerAnOrquesta(Orquesta *listOrquesta,int lenOrquesta);
int removeOrquesta(Orquesta* listOrquesta, int lenOrquesta,int id);
int printOrquestas(Orquesta *listOrquesta,int lenOrquesta);
int printOrquestasById(Orquesta *listOrquesta,int lenOrquesta,int id);
int generarIdOrquesta(void);

#endif /* ORQUESTA_H_INCLUDED*/
