#ifndef MUSICO_H_INCLUDED
#define MUSICO_H_INCLUDED

typedef struct
{
    int idMusico;
    int isEmpty;
    char nombre[50];
    char apellido[50];
    int edad;
}Musico;

int initMusicos(Musico* listMusico, int lenMusico);
int findFreePlaceMusico(Musico* listMusico, int lenMusico);
int findMusicoById(Musico* listMusico, int lenMusico,int id,int *posicion);
int addMusico(Musico* listMusico, int lenMusico, int id, char *name,char *lastName,int edad);
int registerAnMusico(Musico *listMusico,int lenMusico);
int modifyAnMusico(Musico *listMusico,int lenMusico);
int removeMusico(Musico* listMusico, int lenMusico,int id);
int printMusicos(Musico *listMusico,int lenMusico);
int printMusicosById(Musico *listMusico,int lenMusico,int id);
int generarIdMusico(void);


#endif /* MUSICO_H_INCLUDED */
