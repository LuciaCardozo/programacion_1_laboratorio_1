/*
 ============================================================================
 Name        : claseArchivoEclipse24_10.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "utn.h"

int main(void) {

	sCliente *listClientes[1000];

	FILE *pFile;
	    int r;
	    int contador=0;
	    char var1[50],var3[50],var2[50],var4[50],var5[50];
	    pFile = fopen("clientes.txt","r");
	    if(pFile == NULL)
	    {
	        printf("El archivo no existe");
	        exit(EXIT_FAILURE);
	    }
	    do
	    {
	        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
	        if(r==4)
	        {
	        	printf("Lei: %s %s %s %s\n",var1,var2,var3,var4);
	        	int id=atoi(var1);
	        	sCliente *auxCliente=new_clienteParametros(var2,var4,var5,var3,id,1);
	        	if(auxCliente!=NULL)
	        	{
	        		listClientes[contador] = auxCliente;
	        		contador++;
	        		if(contador>=1000)
	        			break;
	        	}
	        }

	        else
	        break;
	     }while(!feof(pFile));
	     fclose(pFile);
	/*FILE *fp = fopen("archivo.txt","w");
	    if(fp!=NULL)
	    {
	        printf("abri el archivo\n");

	        char data[6];
	        data[0]='H';
	        data[1]='O';
	        data[2]='L';
	        data[3]='A';
	        data[4]='\n';
	        data[5]=0;

	        fwrite(data,sizeof(char),5,fp);
	        fprintf(fp,"%s",data);
	        fclose(fp);
	        int i=4569;
	        fwrite(&i,sizeof(int),1,fp);
	        fprintf(fp,"%d",i);
	    }*/
	return EXIT_SUCCESS;
}
