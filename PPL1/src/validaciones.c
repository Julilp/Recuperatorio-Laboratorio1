/*
 * validaciones.c
 *
 *  Created on: 16 may. 2022
 *      Author: Julian lopez
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "validaciones.h"

#include "listados.h"

int IngresarEntero(char mensaje [], int min, int max)
{
    int retorno;
    char numeroIngresado[100];
    int validacion;

    printf("%s", mensaje);
    fflush(stdin);
    scanf("%s", numeroIngresado);
    validacion=validarNumero(numeroIngresado);
    while(validacion==0)
    {
        printf("\n Reingrese el numero (sin letras):  \n");
        fflush(stdin);
        scanf("%s", numeroIngresado);
        validacion= validarNumero(numeroIngresado);
    }

    retorno=atoi(numeroIngresado);

    while(retorno < min || retorno > max)
        {
            printf("\nError, vuelva a ingresar el numero dentro de los limites:  \n");
            fflush(stdin);
            scanf("%s", numeroIngresado);
            retorno=atoi(numeroIngresado);
        }

    return retorno;
}
float pedirFlotante(char mensaje[], char mensajeError[])
   {
       int retorno = -1;
       char numeroCadena[100];
       int validacion;



   	printf("%s", mensaje);
   	fflush(stdin);
   	scanf("%s", numeroCadena);
   	validacion=validarNumero(numeroCadena);
   	while(validacion==0)
   		{
   		printf("%s", mensajeError);
   		scanf("%s", numeroCadena);
   		validacion=validarNumero (numeroCadena);
   		}

   	retorno=atof(numeroCadena);



       return retorno;
   }
int pedirCadena(char* cadena, char* mensaje, char* mensajeError,int validar)
{
    int retorno = -1;
    char buffer[256];
    int validacion;

    if(cadena != NULL && mensaje != NULL && mensajeError != NULL)
    {
        printf("%s", mensaje);
        fflush(stdin);
        scanf("%[^\n]", buffer);
        if(validar==1)
        {
		 validacion=validacionDeCaracteres (buffer);
		  while(validacion==0)
			{
				printf("%s", mensajeError);
				scanf("%s", buffer);
				validacion=validacionDeCaracteres (buffer);
			}
        }



        strcpy(cadena, buffer);
        retorno = 0;
    }

    return retorno;
}
int validacionDeCaracteres (char cadena[])
{
	int size = strlen(cadena);
	int validacion=-1;
	for(int i=0;i<size;i++)
	{
		if (isdigit(cadena[i]))
		{
			validacion=0;
		}
	}
	return validacion;
}
int validarNumero (char numeros[])
{
	int validacion=-1;
	for(int i=0;i<strlen(numeros);i++)
	{
		 if(!(numeros[i] == 46 || (numeros[i]>=48 && numeros[i]<=57)))
		{

			validacion = 0;

		}
	}
	return validacion;
}

