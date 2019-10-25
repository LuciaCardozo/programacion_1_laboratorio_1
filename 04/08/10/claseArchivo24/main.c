#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nombre[32];
    char apellido[32];
    int edad;
}Persona;

int main()
{
    FILE *pFile;
    int r;
    char var1[50],var3[50],var2[50],var4[50];
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
        printf("Lei: %s %s %s %s\n",var1,var2,var3,var4);
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
       fwrite(&i,sizeof(int),1,fp);
        int i=4569;
        fprintf(fp,"%d",i);
        fclose(fp);
    }

    fp = fopen("archivo.txt","r");
    if(fp!=NULL)
    {
        int i;
        fread(&i,sizeof(int),1,fp);
        fscanf(fp,"%d",&i);
        fclose(fp);
        printf("lei de la var: %d",i);
    }*/
    return 0;
}
