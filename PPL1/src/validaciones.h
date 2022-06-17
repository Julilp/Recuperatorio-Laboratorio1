/*
 * validaciones.h
 *
 *  Created on: 16 may. 2022
 *      Author: Julian lopez
 */

#include "funciones.h"

int IngresarEntero(char mensaje [], int min, int max);
float pedirFlotante(char mensaje[], char mensajeError[]);
int pedirCadena(char* cadena, char* mensaje, char* mensajeError,int validar);
int validacionDeCaracteres (char cadena[]);
int validarNumero (char numeros[]);
void iniciarPrograma(eConsulta listaDeConsultas[],int tam);
