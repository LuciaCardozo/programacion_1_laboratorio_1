#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Pantalla.h"
#include "Publicidad.h"
#define LIBRE 0
#define OCUPADO 1

static int generarIdPublicidad(void);

static int generarIdPublicidad(void)
{
    static int idMax=1;
    return idMax++;
}

int pub_initPublicidad(Publicidad *listPub,int lenPub)
{
    int ret = -1;
    int i;
    if(listPub!=NULL && lenPub>0)
    {
        for(i=0; i<lenPub; i++)
        {
            listPub[i].isEmpty=LIBRE;
        }
        ret = 0;
    }
    return ret;
}

int pub_buscarLugarLibre(Publicidad *listPub,int lenPub)
{
    int ret = -1;
    int i;
    if(listPub!=NULL && lenPub>0)
    {
        for(i=0; i<lenPub; i++)
        {
            if(listPub[i].isEmpty==LIBRE)
            {
                ret=i;
                break;
            }
        }
    }
    return ret;
}

int pub_addPublicidad(Publicidad *listPub, int lenPub, int idPub,int idPantalla,int cantDeDia,char *cuit,char *nombre)
{
    int retorno=-1;
    int posLibre;

    posLibre=pub_buscarLugarLibre(listPub,lenPub);
    if(listPub!=NULL && lenPub>0)
    {
        if(posLibre!=-1)
        {
            listPub[posLibre].cantidadDeDia=cantDeDia;
            strncpy(listPub[posLibre].cuit,cuit,20);
            strncpy(listPub[posLibre].nombreArch,nombre,50);
            listPub[posLibre].idPan=idPantalla;
            listPub[posLibre].isEmpty=OCUPADO;
            listPub[posLibre].idPub=idPub;
        }
        retorno=0;
    }
    else
    {
        printf("ERROR en los datos de parametro 'addPersona'\n");
    }
    return retorno;
}

int pub_altaPublicidad(Publicidad *listPub,int lenPub,Pantalla *listPan,int lenPan)
{
    char auxNombre[50];
    char auxCuit[20];
    int auxCantDeDia;
    int auxId;
    int auxIdPan;
    int posIdPan;
    int ret = -1;
    if(listPub!=NULL && lenPub>0)
    {
        if(utn_getValidInt("Ingrese Id pantalla: ","Error.",&auxIdPan,1,1000,2)==0)
        {
            if(pan_buscarPantallaPorId(listPan,lenPan,auxIdPan,&posIdPan)==-1)
            {
                printf("No se encontro ID Pantalla");
            }
            else
            {
                if(utn_getValidStringNumerico("Ingrese Cuit:","\nError.","Error, excediste el maximo de caracteres",auxCuit,20,2)==0 &&
                        utn_getValidName(auxNombre)==0 && utn_getValidInt("Ingrese cantidad de dias: ","\nError.",&auxCantDeDia,1,99999,2)==0)
                {
                    auxId=generarIdPublicidad();
                    pub_addPublicidad(listPub,lenPub,auxId,posIdPan,auxCantDeDia,auxCuit,auxNombre);
                    printf("\n------------------------\n");

                    ret=0;

                }
            }
        }

    }
    return ret;
}

int pub_printfPublicidad(Publicidad *listPub,int lenPub,Pantalla *listPan,int lenPan)
{
    int ret=-1;
    int i;
    if(listPub!=NULL && lenPub>0)
    {
        for(i=0; i<lenPub; i++)
        {
            if(listPub[i].isEmpty==OCUPADO)
            {
                if(listPan[i].isEmpty==OCUPADO)
                {
                    printf("\nId Publicidad: %d",listPub[i].idPub);
                    pan_printfPantallaPorId(listPan,lenPan,listPub[i].idPan);
                    printf("\nNombre: %s",listPub[i].nombreArch);
                    printf("\nCuit: %s",listPub[i].cuit);
                    printf("\nCantidad de dias: %d",listPub[i].cantidadDeDia);
                    printf("\n------------------------\n");
                    ret=0;
                }
            }
        }
    }
    return ret;
}

int pub_printfPublicidadPorCuit(Publicidad *listPub,int lenPub,char *cuit)
{
    int ret=-1;
    int i;
    if(listPub!=NULL && lenPub>0)
    {
        for(i=0; i<lenPub; i++)
        {
            if(listPub[i].isEmpty==OCUPADO)
            {
                if(strncmp(listPub[i].cuit,cuit,20)==0)
                {
                    printf("\nId Publicidad: %d\n",listPub[i].idPub);
                    printf("\nId Pantalla: %d\n",listPub[i].idPan);
                    printf("\nNombre: %s",listPub[i].nombreArch);
                    printf("\nCuit: %s",listPub[i].cuit);
                    printf("\nCantidad de dias: %d",listPub[i].cantidadDeDia);
                    printf("\n------------------------\n");
                }
            }
        }
        ret=0;
    }
    return ret;
}

int pub_buscarPublicidadPorId(Publicidad *listPub,int lenPub,int id,int *posicion)
{
    int ret = -1;
    int i;
    if(listPub!=NULL && lenPub>0)
    {
        for(i=0; i<lenPub; i++)
        {
            if(listPub[i].idPub==id)
            {
                ret=0;
                *posicion=i;
                break;
            }
        }
    }
    return ret;
}

int pub_buscarPublicidadPorCuit(Publicidad *listPub,int lenPub,char *cuit,int *posicion)
{
    int ret = -1;
    int i;
    if(listPub!=NULL && lenPub>0)
    {
        for(i=0; i<lenPub; i++)
        {
            if(listPub[i].isEmpty==LIBRE)
            {
                continue;
            }
            else
            {
                if(strncmp(listPub[i].cuit,cuit,20)==0)
                {
                    ret=0;
                    *posicion=i;
                    break;
                }
            }
        }
    }
    return ret;
}

int pub_buscarPublicidadPorIdPan(Publicidad *listPub,int lenPub,int idPan,int *posicion)
{
    int ret = -1;
    int i;
    if(listPub!=NULL && lenPub>0)
    {
        for(i=0; i<lenPub; i++)
        {
            if(listPub[i].isEmpty==LIBRE)
            {
                continue;
            }
            else
            {
                if(listPub[i].idPan==idPan)
                {
                    ret=0;
                    *posicion=i;
                    break;
                }
            }
        }
    }
    return ret;
}

int pub_bajaPublicidad(Publicidad *listPub,int lenPub,int id)/*falta baj publicidad*/
{
    int i;
    int ret = -1;
    if(listPub!=NULL && lenPub>0)
    {
        for(i=0; i<lenPub; i++)
        {
            if(listPub[i].idPub==id)
            {
                listPub[i].isEmpty=LIBRE;
            }
        }
        ret=0;
    }
    return ret;
}

int pub_bajaPublicidadPorCuit(Publicidad *listPub,int lenPub)/*falta baj publicidad*/
{
    char auxCuit[20];
    int auxPosPan;
    int ret = -1;
    int auxId;
    int auxPos;

    if(listPub!=NULL && lenPub>0)
    {
        if(utn_getValidStringNumerico("Ingrese Cuit:","\nError.","Error, excediste el maximo de caracteres",auxCuit,20,2)==0)
        {
            if(pub_buscarPublicidadPorCuit(listPub,lenPub,auxCuit,&auxPos)==-1)
            {
                printf("\nNo se encontro el Cuit");
            }
            else
            {
                pub_printfPublicidadPorCuit(listPub,lenPub,auxCuit);
                if(utn_getValidInt("Ingrese id Pantalla: ","Error",&auxId,1,99999,2)==0)
                {
                    if(pub_buscarPublicidadPorIdPan(listPub,lenPub,auxId,&auxPosPan)==-1)
                    {
                        printf("\nNo se encontro el ID");
                    }
                else
                {
                    listPub[auxPosPan].isEmpty=LIBRE;
                }
            }
            ret=0;
        }
    }

    }
    return ret;
}

int pub_modificarPublicacion(Publicidad *listPub, int lenPub,int id)
{
    int ret = -1;
    char auxCuit[20];
    int auxCantDeDia;
    int opciones;
    int auxIdPan;
    int auxPos;
    int auxPosPan;
    if(utn_getValidStringNumerico("Ingrese Cuit: ","Error","Error, excediste el maximo de caracteres",auxCuit,20,2)==0)
    {
        if(pub_buscarPublicidadPorCuit(listPub,lenPub,auxCuit,&auxPos)==-1)
        {
            printf("\nNo se encontro el Cuit");
        }
        else
        {
            pub_printfPublicidadPorCuit(listPub,lenPub,auxCuit);
            if(utn_getValidInt("Ingrese id Pantalla: ","Error",&auxIdPan,1,99999,2)==0)
            {
                if(pub_buscarPublicidadPorIdPan(listPub,lenPub,auxIdPan,&auxPosPan)==-1)
                {
                    printf("\nNo se encontro el ID");
                }
                else
                {
                    do
                    {
                        if(utn_getValidInt("\n\n¿Que desea modificar?\n1-Cantidad de dias: \n2-Cancelar\nEliga la opcion: ",
                                           "Error",&opciones,1,2,2)==0)
                        {
                            switch(opciones)
                            {
                            case 1:
                                utn_getValidInt("\nIngrese cantidad de dias: ","\nError",&auxCantDeDia,1,99999,2);
                                listPub[auxPosPan].cantidadDeDia=auxCantDeDia;
                                break;
                            case 2:
                                break;
                            default :
                                printf("No es una opcion");
                                break;
                            }
                        }
                    }
                    while(opciones!=2);
                    ret=0;
                }
            }
        }
    }
    return ret;
}

/*int consultaFacturacionPorCuit(Publicidad *listPub,int lenPub,Pantalla *listPan,int lenPan)
{
    char auxCuit[20];
    int ret = -1;
    int i;
    int auxPos;
    float auxPrecio;
    float auxCantDia;
    float importe;
    if(listPub!=NULL && lenPub>0)
    {
        if(utn_getValidStringNumerico("Ingrese Cuit:","\nError.","Error, excediste el maximo de caracteres",auxCuit,20,2)==0)
        {
            for(i=0;i<lenPub;i++)
            {
                if(listPub[i].isEmpty==OCUPADO && listPan[i].isEmpty==OCUPADO)
                {
                    if(strncmp(listPub[i].cuit,auxCuit,20)==0)
                    {
                        if(pub_buscarPublicidadPorCuit(listPub,lenPub,auxCuit,&auxPos)!=-1)
                        {
                            auxCantDia=listPub[auxPos].cantidadDeDia;
                            auxPrecio=listPan[auxPos].precio;
                            importe=auxCantDia*auxPrecio;


                        }
                    }
                }
            }
            ret = 0;
        }
    }
    return ret;
}*/

int pub_ordenarCuit(Publicidad *listPub,int lenPub)
{
    int ret=-1;
    int i;
    int j;
    Publicidad aux;
    if(listPub!=NULL && lenPub>0)
    {
        for(i=0; i<lenPub-1; i++)
        {
            if(listPub[i].isEmpty==OCUPADO)
            {
                for(j=i+1; j<lenPub; j++)
                {
                    if(listPub[i].cuit>listPub[j].cuit)
                    {
                        aux=listPub[i];
                        listPub[i]=listPub[j];
                        listPub[j]=aux;
                        ret=0;
                    }
                }
            }

        }
    }
    return ret;
}

int pub_printfContrataciones(Publicidad *listPub,int lenPub,Pantalla *listPan,int lenPan)
{
    int ret=-1;
    int i;
    if(listPub!=NULL && lenPub>0 && listPan!=NULL && lenPan>0)
    {
        for(i=0;i<lenPub;i++)
        {
            if(pub_ordenarCuit(listPub,lenPub)==0)
            {
                printf("cuit: %s",listPub[i].cuit);
                ret=0;
            }
        }
    }
    return ret;
}
/* auxCantDia=listPub[i].cantidadDeDia;
        auxPrecio=listPan[i].precio;
        auxIdPan=listPub[i].idPan;
        importe=auxCantDia*auxPrecio;
        printf("\nId Publicidad: %d",listPub[i].idPub);
        pan_printfPantallaPorId(listPan,lenPan,auxIdPan);
        printf("\nNombre: %s",listPub[i].nombreArch);
        printf("\nCuit: %s",listPub[i].cuit);
        printf("\nCantidad de dias: %d",listPub[i].cantidadDeDia);
        printf("\nImporte a pagar: %.2f",importe);
        printf("\n------------------------\n");
        ret=0;*/
int clienteConImporteMasAlto(Publicidad *listPub,int lenPub,Pantalla *listPan,int lenPan)
{
    int ret = -1;
    int i;
    float mayorImporte=0;
    float auxCantDia;
    float auxPrecio;
    float importe=0;
    int auxIdPan;
    if(listPub!=NULL && lenPub>0)
    {
        for(i=0;i<lenPub;i++)
        {
            if(listPub[i].isEmpty==OCUPADO)
            {
                if(listPan[i].isEmpty==OCUPADO)
                {
                    auxCantDia=listPub[i].cantidadDeDia;
                    auxPrecio=listPan[i].precio;
                    importe=auxCantDia*auxPrecio;
                    auxIdPan=listPub[i].idPan;
                    if(mayorImporte==importe)
                    {
                        if(importe>mayorImporte)
                        {
                            mayorImporte=importe;
                            printf("\nId Publicidad: %d",listPub[i].idPub);
                            pan_printfPantallaPorId(listPan,lenPan,auxIdPan);
                            printf("\nNombre: %s",listPub[i].nombreArch);
                            printf("\nCuit: %s",listPub[i].cuit);
                            printf("\nCantidad de dias: %d",listPub[i].cantidadDeDia);
                            printf("\nImporte mayor a Facturar: %.2f",mayorImporte);
                            printf("\n------------------------\n");
                            break;
                            ret=0;
                        }
                    }
                }
            }
        }
    }
    return ret;
}

int pub_calcularFacturacion(Pantalla *listPan,int lenPan,Publicidad *listPub,int lenPub,char *cuit,int *contadorPub)
{
    int ret = -1;
    int i;
    float total=0;
    int posPan;
    int aux = 0;
    if(listPan!=NULL && lenPub > 0)
    {
        for(i=0;i<lenPub;i++)
        {
            if(listPub[i].isEmpty==OCUPADO && listPan[i].isEmpty==OCUPADO)
            {
                if(strcmp(cuit,listPub[i].cuit)==0)
                {
                    aux++;
                    pan_buscarPantallaPorId(listPan,lenPan,listPub[i].idPan,&posPan);
                    total=listPub[i].cantidadDeDia*listPan[posPan].precio;
                    printf("\nPublicacion: %d\nPantalla: %s\nDireccion: %s\nPrecio: %.2f\nCantidad de dia: %d\nTotal a abonar: %.2f\n"
                            ,listPub[i].idPub,listPan[posPan].nombre,listPan[posPan].direccion,listPan[posPan].precio,
                            listPub[i].cantidadDeDia,total);
                            ret=0;
                }
            }
        }
    *contadorPub = aux;
    }
    return ret;
}

int pub_facturacionPorCuit(Publicidad *listPub,int lenPub,Pantalla *listPan,int lenPan)
{
    int i;
    int ret=-1;
    char auxCuit[20];
    int auxPos;
    int aux;
    if(listPub!=NULL && lenPub>0)
    {
        for(i=0;i<lenPub;i++)
        {
            if(listPub[i].isEmpty==OCUPADO && listPan[i].isEmpty==OCUPADO)
            {
                if(utn_getValidStringNumerico("\nIngrese cuit: ","\nError","\nError, excediste el maximo de caracteres",auxCuit,12,2)==0)
                {
                    if(pub_buscarPublicidadPorCuit(listPub,lenPub,auxCuit,&auxPos)==-1)
                    {
                        printf("Error, no existe cuit");
                    }
                    else
                    {
                        pub_calcularFacturacion(listPan,lenPan,listPub,lenPub,auxCuit,&aux);
                        printf("%s.....%d",auxCuit,aux);
                        break;
                    }
                }
            }
        }
        ret=0;
    }
    return ret;
}

int pub_facturacionesDeClientes(Publicidad *listPub,int lenPub,Pantalla *listPan,int lenPan)
{
    int i;
    int ret=-1;
    int aux;
    if(listPub!=NULL && lenPub>0)
    {
        for(i=0;i<lenPub;i++)
        {
            if(listPub[i].isEmpty==OCUPADO && listPan[i].isEmpty==OCUPADO)
            {
                pub_ordenarCuit(listPub,lenPub);


                    printf("\nNombre del cliente: %s\n",listPub[i].nombreArch);
                    pub_calcularFacturacion(listPan,lenPan,listPub,lenPub,listPub[i].cuit,&aux);
                    ret=0;

            }
        }
    }
    return ret;
}
