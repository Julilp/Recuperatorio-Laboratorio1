/*
 ============================================================================
 Name        : PRIMER.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"
#include "validaciones.h"
#include "listados.h"

int main(void)
{

	setbuf(stdout,NULL);
	iniciarPrograma(listaDeConsultas, TAM);
	int opcion;
	int bandera=1;
	eEnfermera listaEnfermeras[4];
	eDiagnostico diagnosticos[4];
	eEspecialidad listaEspecialidades[4];
	eMedico listaMedicos [4];
	eLocalidad listaDeLocalidades [4];
	datosHardcodeadas(listaMedicos, listaEspecialidades, listaEnfermeras, diagnosticos,listaDeLocalidades);
	consultasHardcodeadas(listaDeConsultas);
	do
	{
		printf( " ====================================\n"
				" |           1-ALTA CONSULTA         |\n"
				" |           2-MODIFICAR CONSULTA    |\n"
				" |           3-CANCELAR CONSULTA     |\n"
				" |           4-DIAGNOSTICAR          |\n"
				" |           5-LISTAR                |\n "
				"|           6-SALIR                 |\n"
				" =====================================\n");

		opcion=IngresarEntero( "Ingrese una opcion: ",1,6);

		switch(opcion)
		{
		case 1:
			pedirDatos( listaDeConsultas,TAM);
			bandera=1;
		break;
		case 2:
			if(bandera==1)
			{
				modificarConsulta( listaDeConsultas,TAM,listaMedicos,listaEspecialidades);
			}
			else
			{
				printf("Primero debe realizarse un alta...");
			}
		break;
		case 3:
			if(bandera==1)
			{
				bajaDeConsulta( listaDeConsultas,TAM);
			}
			else
			{
				printf("Primero debe realizarse un alta...");
			}
		break;
		case 4:
			if(bandera==1)
			{
				diagnosticar ( listaDeConsultas, listaMedicos, diagnosticos, TAM,listaEnfermeras,listaEspecialidades,listaDeLocalidades);
			}
			else
			{
				printf("Primero debe realizarse un alta...");
			}
		break;
		case 5:
				subMenuListar(listaDeConsultas, listaMedicos, diagnosticos,listaEnfermeras,listaEspecialidades,listaDeLocalidades);
		break;


		}

	}while(opcion!=6);

	return 0;
}
