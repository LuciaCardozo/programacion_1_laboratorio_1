#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Llamadas.h"
#include "Asociados.h"
#include "utn.h"
#define LIBRE 0
#define OCUPADO 1
#define INFARTO 1
#define GRIPE 2
#define ACV 3
#define PENDIENTE 0
#define CUMPLIDO 1

static int generarIdLlamada(void);
static int generarIdAmbulancia(void);

int llam_iniLlamada(Llamada *listLlamada,int lenLlamada)
{
    int ret = -1;
    int i;
    if(listLlamada != NULL && lenLlamada > 0)
    {
        for(i=0; i<lenLlamada; i++)
        {
            listLlamada[i].isEmpty = LIBRE;
        }
        ret = 0;
    }
    return ret;
}

int llam_buscarLugarLibre(Llamada *listLlamada,int lenLlamada)
{
    int ret = -1;
    int i;
    if(listLlamada != NULL && lenLlamada > 0)
    {
        for(i=0; i<lenLlamada; i++)
        {
            if(listLlamada[i].isEmpty == LIBRE)
            {
                ret = i;
                break;
            }
        }
    }
    return ret;
}

int llam_buscarLlamadaPorId(Llamada *listLlamada,int lenLlamada,int id,int *posicion)
{
    int ret = -1;
    int i;
    if(listLlamada != NULL && lenLlamada > 0)
    {
        for(i=0; i<lenLlamada; i++)
        {
            if(listLlamada[i].idLlamada == id)
            {
                ret = 0;
                *posicion = i;
                break;
            }
        }
    }
    return ret;
}

int llam_addLlamada(Llamada *listLlamada, int lenLlamada, int id,int idAsociado,int motivo,int estado)
{
    int retorno=-1;
    int posLibre;

    posLibre=llam_buscarLugarLibre(listLlamada,lenLlamada);
    if(listLlamada!=NULL && lenLlamada>0)
    {
        if(posLibre!=-1)
        {
            listLlamada[posLibre].idLlamada=id;
            listLlamada[posLibre].idAsociado=idAsociado;
            listLlamada[posLibre].estado=estado;
            listLlamada[posLibre].motivo=motivo;
            listLlamada[posLibre].isEmpty=OCUPADO;
        }
        retorno=0;
    }
    else
    {
        printf("ERROR en los datos de parametro 'addAsociado'\n");
    }
    return retorno;
}

int llam_altaNuevaLlamada(Llamada *listLlamada,int lenLlamada,Asociados *listAsoc,int lenAsoc,int *posicion)
{
    int ret = -1;
    int auxIdAsociado;
    int auxMotivo;
    int auxId;
    int auxPos;
    if(listLlamada != NULL && lenLlamada > 0 && listAsoc != NULL && lenAsoc > 0)
    {
        if(utn_getValidInt("\nIngrese Id de asociado: ","\nError",&auxIdAsociado,1,99999,2) == 0)
        {
            if(asoc_buscarAsociadoPorId(listAsoc,lenAsoc,auxIdAsociado,&auxPos) == -1)
            {
                printf("\nNo se encontro el ID");
            }
            else
            {
                if(utn_getValidInt("\nMotivos\n1-INFARTO\n2-GRIPE\n3-ACV\nIngrese Motivo: ","\nError",&auxMotivo,1,3,2)==0)
                {
                    *posicion = auxPos;
                    auxId = generarIdLlamada();
                    llam_addLlamada(listLlamada,lenLlamada,auxId,auxIdAsociado,auxMotivo,PENDIENTE);
                    ret = 0;
                }
            }
        }
    }
    return ret;

}

int llam_asignarAmbulancia(Llamada *listLlamada,int lenLlamada,Asociados *listAsoc,int lenAsoc)
{
    int ret = -1;
    int auxPos;
    float auxTiempo;
    int auxId;
    int auxIdAmbulancia;
    if(listLlamada != NULL && lenLlamada > 0)
    {
        printf("Estoy adentro");
        if(utn_getValidInt("\nIngrese Id de Llamada ","\nError",&auxId,1,99999,2)==0)
        {
            if(llam_buscarLlamadaPorId(listLlamada,lenLlamada,auxId,&auxPos)==-1)
            {
                printf("\nNo se encontro Id");
            }
            else
            {
                if(utn_getValidFloat("\nIngrese tiempo insumido: ","\nError.",&auxTiempo,1,999999,2)==0)
                {
                    auxIdAmbulancia = generarIdAmbulancia();
                    listLlamada[auxPos].estado = CUMPLIDO;
                    listLlamada[auxPos].idAmbulancia = auxIdAmbulancia;
                    llam_printfLlamadaPorId(listLlamada,lenLlamada,auxPos);
                    ret = 0;
                }
            }
        }
    }
    return ret;
}

int llam_printfLlamadaPorId(Llamada *listLlamada,int lenLlamada,int id)
{
    int ret=-1;
    int i;
    if(listLlamada!=NULL && lenLlamada>0)
    {
        for(i=0; i<lenLlamada; i++)
        {
            if(listLlamada[i].isEmpty==OCUPADO)
            {
                if(listLlamada[i].idAsociado==id)
                {
                    printf("\nId Pantalla: %d\n",listLlamada[i].idLlamada);
                    printf("\nId Ambulancia: %d",listLlamada[i].idAmbulancia);
                    printf("\nId Asociado: %d",listLlamada[i].idAsociado);
                    printf("\nTiempo: %.2f",listLlamada[i].tiempo);
                    if(listLlamada[i].estado==0)
                    {
                        printf("\nEstado: PEDIENTE");
                    }
                    else if(listLlamada[i].estado==1)
                    {
                        printf("\nEstado: CUMPLIDO");
                    }
                    if(listLlamada[i].motivo==1)
                    {
                        printf("\nMotivo: INFARTO");
                    }
                    else if(listLlamada[i].motivo==2)
                    {
                        printf("\nMotivo: GRIPE");
                    }
                    else if(listLlamada[i].motivo==3)
                    {
                        printf("\nMotivo: ACV");
                    }
                    ret=0;
                }
            }
        }
    }
    return ret;
}

int llam_printfLlamada(Llamada *listLlamada,int lenLlamada)
{
    int ret=-1;
    int i;
    if(listLlamada!=NULL && lenLlamada>0)
    {
        for(i=0; i<lenLlamada; i++)
        {
            if(listLlamada[i].isEmpty==OCUPADO)
            {
                printf("\nId Llamada: %d\n",listLlamada[i].idLlamada);
                printf("\nId Asociado: %d",listLlamada[i].idAsociado);
                if(listLlamada[i].estado==0)
                {
                    printf("\nEstado: PEDIENTE");
                }
                else if(listLlamada[i].estado==1)
                {
                    printf("\nEstado: CUMPLIDO");
                }
                else
                {
                    printf("\nError Estado");
                }
                if(listLlamada[i].motivo==1)
                {
                    printf("\nMotivo: INFARTO");
                }
                else if(listLlamada[i].motivo==2)
                {
                    printf("\nMotivo: GRIPE");
                }
                else if(listLlamada[i].motivo==3)
                {
                    printf("\nMotivo: ACV");
                }
                else
                {
                    printf("\nError Motivo");
                }
                printf("\n------------------------\n");
                ret=0;
            }
        }
    }
    return ret;
}

static int generarIdLlamada(void)
{
    static int idMax=1;
    return idMax++;
}

static int generarIdAmbulancia(void)
{
    static int idMax=1;
    return idMax++;
}

int menu(Asociados *listAsoc,int lenAsoc,Llamada *listLlamada,int lenLlamada)
{
    asoc_initAsociados(listAsoc,lenAsoc);
    llam_iniLlamada(listLlamada,lenLlamada);
    int auxId;
    int auxPosId;
    int auxPosLlamada;
    int opciones;
    if(listAsoc!=NULL && lenAsoc>0 && listLlamada!=NULL && lenLlamada>0)
    {
        do
        {
            if(utn_getValidInt("\n1-Alta del asociado\n2-Modificar datos del asociado\n3-Baja del asociado\n4-Mostrar\n5-Nueva LLamada\n6-Asignar Ambulancia\n7-Salir\nIngrese opcion: "
            ,"\nError.",&opciones,1,7,2)==0)
             {
                switch(opciones)
                {
                    case 1:
                        if(asoc_altaAsociados(listAsoc,lenAsoc)==0)
                        {
                            printf("\nALTA EXITOSA");
                        }
                        else
                        {
                            printf("\nError, no pudo dar la alta");
                        }
                        break;
                    case 2:
                        asoc_printfAsociados(listAsoc,lenAsoc);
                        if(asoc_modificarAsociado(listAsoc,lenAsoc,auxId)==0)
                        {
                            printf("\nMODIFICACION EXITOSA");
                        }
                        else
                        {
                            printf("\nERROR");
                        }
                        break;
                    case 3:
                        asoc_printfAsociados(listAsoc,lenAsoc);
                        if(utn_getValidInt("\nIngrese Id: ","\nError.",&auxId,1,99999,2)==0)
                        {
                            if(asoc_buscarAsociadoPorId(listAsoc,lenAsoc,auxId,&auxPosId)!=-1)
                            {
                                if(asoc_bajaAsociado(listAsoc,lenAsoc,auxId)==0)
                                {
                                    printf("\nBAJA EXITOSA\n");
                                }

                            }
                            else
                            {
                                printf("\nID NO EXISTE\n");
                            }
                        }
                        break;
                    case 4:
                        asoc_printfAsociados(listAsoc,lenAsoc);
                        break;
                    case 5:
                        if(llam_altaNuevaLlamada(listLlamada,lenLlamada,listAsoc,lenAsoc,&auxPosLlamada)==0)
                        {
                            printf("\nNueva llamada PENDIENTE");
                        }
                        else
                        {
                            printf("\nError, no se realizo la llamada");
                        }
                        break;
                        case 6:
                        llam_printfLlamada(listLlamada,lenLlamada);
                        if(llam_asignarAmbulancia(listLlamada,lenLlamada,listAsoc,lenAsoc)==0)
                        {
                            printf("\nLlamada Exitosa");
                        }
                        else
                        {
                            printf("\nError, no se realizo el pedido de ambulancia");
                        }
                    break;
                        case 7:
                    break;
                        default:
                        printf("\nOpcion incorrecta");
                    break;
                }
             }
        }while(opciones!=7);
    }
    return 0;
}
