#ifndef INSTRUMENTO_H_INCLUDED
#define INSTRUMENTO_H_INCLUDED

typedef struct
{
    int idInstrumento;
    int isEmpty;
    char nombre[50];
    int tipo;
}Instrumento;

int initInstrumentos(Instrumento* listInstrumento, int lenInstrumento);
int findFreePlaceInstrumento(Instrumento* listInstrumento, int lenInstrumento);
int findInstrumentoById(Instrumento* listInstrumento, int lenInstrumento,int id,int *posicion);
int addInstrumento(Instrumento* listInstrumento, int lenInstrumento, int id, char *name,int tipo);
int registerAnInstrumento(Instrumento *listInstrumento,int lenInstrumento);
int printInstrumentos(Instrumento *listInstrumento,int lenInstrumento);
int printInstrumentosById(Instrumento *listInstrumento,int lenInstrumento,int id);
int generarIdInstrumento(void);

#endif /* INSTRUMENTO_H_INCLUDED*/
