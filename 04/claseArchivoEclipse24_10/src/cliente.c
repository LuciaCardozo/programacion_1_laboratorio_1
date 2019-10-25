/*
 * cliente.c
 *
 *  Created on: 24 oct. 2019
 *      Author: alumno
 */
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "utn.h"

sCliente* new_cliente()
{
	return malloc(sizeof(sCliente));
}

sCliente* new_clienteParametros(char *nombre,char *localidad,char *direccion,char *cuit,int id,int status)
{
	sCliente *retorno = NULL;
	sCliente *this;
	this = new_cliente();

	if(this != NULL)
	{
		if(		cli_setNombre(this,nombre) == EXIT_SUCCESS &&
				cli_setLocalidad(this,localidad) == EXIT_SUCCESS &&
				cli_setDireccion(this,direccion) == EXIT_SUCCESS &&
				cli_setCuit(this,cuit) == EXIT_SUCCESS &&
				cli_setId(this,id) == EXIT_SUCCESS )
		{
				retorno = this;
		}
		else
		{
			delete_cliente(this);
		}
	}

	return retorno;
}

void delete_cliente(sCliente *this)
{
	free(this);
}

int cli_setNombre(sCliente *this,char *nombre)
{
	int retorno = EXIT_ERROR;

	if(this != NULL && isValidNombre(nombre))
	{
		strcpy(this->nombre,nombre);
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

int cli_getNombre(sCliente *this,char *nombre)
{
	int retorno = EXIT_ERROR;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre,this->nombre);
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

int isValidNombre(char *nombre)
{
	int retorno = EXIT_ERROR;

	if(nombre != NULL)
	{
		esNombreOApellido(nombre,"\nERROR");
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

int cli_setDireccion(sCliente *this,char *direccion)
{
	int retorno = EXIT_ERROR;

	if(this != NULL && isValidDireccion(direccion))
	{
		strcpy(this->direccion,direccion);
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

int cli_getDireccion(sCliente *this,char *direccion)
{
	int retorno = EXIT_ERROR;

	if(this != NULL && direccion != NULL)
	{
		strcpy(direccion,this->direccion);
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

int isValidDireccion(char *direccion)
{
	int retorno = EXIT_ERROR;

	if(direccion != NULL)
	{
		esAlfaNumerico(direccion,"\nERROR");
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

int cli_setLocalidad(sCliente *this,char *localidad)
{
	int retorno = EXIT_ERROR;

	if(this != NULL && isValidLocalidad(localidad))
	{
		strcpy(this->localidad,localidad);
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

int cli_getLocalidad(sCliente *this,char *localidad)
{
	int retorno = EXIT_ERROR;

	if(this != NULL && localidad != NULL)
	{
		strcpy(localidad,this->localidad);
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

int isValidLocalidad(char *localidad)
{
	int retorno = EXIT_ERROR;

	if(localidad != NULL)
	{
		esAlfaNumerico(localidad,"\nERROR");
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

int cli_setCuit(sCliente *this,char *cuit)
{
	int retorno = EXIT_ERROR;

	if(this != NULL && isValidCuit(cuit))
	{
		strcpy(this->cuit,cuit);
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

int cli_getCuit(sCliente *this,char *cuit)
{
	int retorno = EXIT_ERROR;

	if(this != NULL && cuit != NULL)
	{
		strcpy(cuit,this->cuit);
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

int isValidCuit(char *cuit)
{
	int retorno = EXIT_ERROR;

	if(cuit != NULL)
	{
		esSoloNumerosPositivos(cuit,"\nERROR");
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

int cli_setId(sCliente *this,int id)
{
	int retorno = EXIT_ERROR;

	if(this != NULL && isValidId(&id))
	{
		this->id=id;
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

int cli_getId(sCliente *this,int *id)
{
	int retorno = EXIT_ERROR;

	if(this != NULL && id != NULL)
	{
		*id=this->id;
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

int isValidId(int *id)
{
	int retorno = EXIT_ERROR;

	if(id != NULL)
	{
		if(id > 0)
		{
			retorno = EXIT_SUCCESS;
		}
	}
	return retorno;
}

int cli_setIdString(sCliente *this,char *id)
{
	int retorno = EXIT_ERROR;

	if(this != NULL && isValidIdString(id))
	{
		this->id=atoi(id);
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

int cli_getIdString(sCliente *this,char *id)
{
	int retorno = EXIT_ERROR;

	if(this != NULL && id != NULL)
	{
		sprintf(id,"%d",this->id);
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

int isValidIdString(char *id)
{
	int retorno = EXIT_ERROR;

	if(id != NULL)
	{
		if(esSoloNumerosPositivos(id,"\nERROR"))
		{
			retorno = EXIT_SUCCESS;
		}
	}

	return retorno;
}

