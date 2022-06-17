/*
 * listados.c
 *
 *  Created on: 13 jun. 2022
 *      Author: Julian lopez
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "listados.h"

#include "validaciones.h"

void subMenuListar(eConsulta listaDeConsultas[],eMedico listaMedicos[],eDiagnostico diagnosticos[],eEnfermera ListaEnfermeras[],eEspecialidad listaEspecialidades[]){//SUB MENU LISTADOS

	int opcion;

	printf("-------------------------------------------------------------------------------------------------------------\n");
	printf(" 1.Todos los medicos                                                                                        M\n");
	printf(" 2.Todas las consultas                                                                                      E\n");
	printf(" 3.Todos los medicos con consultas                                                                          N\n");
	printf(" 4.Consultas ordenadas por fecha, desde la más reciente hasta la más antigua                                U\n");
	printf(" 5.Consultas diagnosticadas                                                                                  \n");
	printf(" 6.Consultas de covid, desde la pandemia y una sola especialidad.                                           L\n");
	printf(" 7.Consultas ordenadas por especialidad alfabéticamente                                                     I\n");
	printf(" 8.Todas las consultas entre el mes de abril y julio para una especialidad determinada.                     S\n");
	printf(" 9.Porcentaje de consultas diagnosticadas que atiende cada médico en función del total de diagnósticos.     T\n");
	printf(" 10.Consultas con un determinado id de medico y de enfermera, previamente elegido por el usuario            A\n");
	printf("-------------------------------------------------------------------------------------------------------------\n");
	opcion=IngresarEntero(" ingresar lista: ", 1, 10);
	switch(opcion){
	case 1:
		listarTodosMedicos(listaMedicos,listaEspecialidades);
	break;
	case 2:
		mostrarConsultas( listaDeConsultas, listaMedicos, diagnosticos,TAM,ListaEnfermeras,listaEspecialidades);
	break;
	case 3:
		listarMedicosConConsultas(listaMedicos, listaDeConsultas, TAM);
	break;
	case 4:
		ordenamientoFecha(listaDeConsultas, listaMedicos, diagnosticos, TAM);
		mostrarConsultas( listaDeConsultas, listaMedicos, diagnosticos,TAM,ListaEnfermeras,listaEspecialidades);
	break;
	case 5:
		consultasDiagnosticadas(listaDeConsultas, listaMedicos, diagnosticos, TAM,ListaEnfermeras,listaEspecialidades);
	break;
	case 6:
		 DiagnosticosCovidYEspecialidad(listaDeConsultas, listaMedicos, diagnosticos, TAM,ListaEnfermeras,listaEspecialidades);
	break;
	case 7:
		ordenamientoAlfabeticoEspecialidad(listaDeConsultas, listaMedicos, diagnosticos, TAM,listaEspecialidades);
		mostrarConsultas( listaDeConsultas, listaMedicos, diagnosticos,TAM,ListaEnfermeras,listaEspecialidades);
	break;
	case 8:
		DiagnosticosEntreMeses(listaDeConsultas, listaMedicos, diagnosticos, TAM,ListaEnfermeras,listaEspecialidades);
	break;
	case 9:
		porcentajeYDatos(listaDeConsultas, listaMedicos, diagnosticos, TAM,listaEspecialidades);
	break;
	case 10:
		mostrarEnfermerasConMedicos(listaDeConsultas, listaMedicos, diagnosticos, TAM, ListaEnfermeras,listaEspecialidades);
	break;
	}

}
void listarTodosMedicos (eMedico listaMedicos[],eEspecialidad listaEspecialidades[]){//LISTADO A

	int especialidad;
	for(int i;i<4;i++){
		especialidad=obtenerEspecialidad(listaMedicos[i], listaEspecialidades);
		printf("|Id: %d |Nombre: %15s |Especialidad:%15s| \n",listaMedicos[i].idMedico,listaMedicos[i].nombre,listaEspecialidades[especialidad].descripcion);
	}
}
void mostrarUnaConsulta(eConsulta listaDeConsultas,eMedico listaMedicos[],eDiagnostico diagnosticos[], int tam,eEnfermera listaEnfermeras[],eEspecialidad listaEspecialidades[])//LISTADO B1
{

	int consultaTipo;
	int medico;
	int enfermera;
	int especialidad;
	if(listaDeConsultas.id>0 )
	{

		medico=MedicoQueAtendio( listaDeConsultas, listaMedicos,4);
		consultaTipo=descripcionConsulta( listaDeConsultas, diagnosticos,4);
		enfermera=posicionEnfermera(listaEnfermeras, listaDeConsultas);
		especialidad=obtenerEspecialidad(listaMedicos[medico], listaEspecialidades);

		printf(
				" |%4d   |       %12s      |        %8s       |       %2d/%2d/%4d    |     %15s     |        %15s         |        %13s     |         %16s       |     %14.2f           |\n"
				,listaDeConsultas.id ,listaDeConsultas.lastName,listaDeConsultas.name,listaDeConsultas.fecha.dia,listaDeConsultas.fecha.mes,listaDeConsultas.fecha.anio,diagnosticos[consultaTipo].descripcion,listaMedicos[medico].nombre,listaEspecialidades[especialidad].descripcion,listaEnfermeras[enfermera].nombre,listaEnfermeras[enfermera].horasDiarias);

	}
}
void mostrarConsultas(eConsulta listaDeConsultas[],eMedico listaMedicos[],eDiagnostico diagnosticos[], int tam,eEnfermera listaEnfermeras[],eEspecialidad listaEspecialidades[])//LISTADO B2
{
	indice();
	for (int i=0;i<tam;i++)
	{
		if(listaDeConsultas[i].iniciar==1){
			mostrarUnaConsulta(listaDeConsultas[i], listaMedicos, diagnosticos, tam, listaEnfermeras,listaEspecialidades);
		}
	}
	printf(" |_____________________________________________________________________________________________________________________________________________________________________________________________________________________________________|\n");


}
void listarMedicosConConsultas(eMedico listaMedicos[], eConsulta listaDeConsultas[],int tam){//LISTADO C

	int contadorconsultas=0;

	for(int i=1;i<4;i++){
		contadorconsultas=0;
		for(int j=0;j<tam;j++){
			if(listaDeConsultas[j].idMedicoAtendido==listaMedicos[i].idMedico){
				contadorconsultas++;
			}
		}
		printf("|Id: %d |Nombre: %15s |Consultas atendias:%8d| \n",listaMedicos[i].idMedico,listaMedicos[i].nombre,contadorconsultas);
	}


}
void ordenamientoFecha(eConsulta listaDeConsultas[],eMedico listaMedicos[],eDiagnostico diagnosticos[], int tam){//LISTADO D

	eConsulta aux;
	for(int i=0;i<tam;i++){
		for(int j=0;j<tam - 1;j++){
			if(listaDeConsultas[i].fecha.anio>listaDeConsultas[j].fecha.anio){
				aux=listaDeConsultas[i];
				listaDeConsultas[i]=listaDeConsultas[j];
				listaDeConsultas[j]=aux;
			}
			else{
				if(listaDeConsultas[i].fecha.mes>listaDeConsultas[j].fecha.mes){
					aux=listaDeConsultas[i];
					listaDeConsultas[i]=listaDeConsultas[j];
					listaDeConsultas[j]=aux;
				}
				else{
					if(listaDeConsultas[i].fecha.dia>listaDeConsultas[j].fecha.dia){
						aux=listaDeConsultas[i];
						listaDeConsultas[i]=listaDeConsultas[j];
						listaDeConsultas[j]=aux;
					}
				}
			}
		}
	}
}
void consultasDiagnosticadas(eConsulta listaConsulta[], eMedico listaMedicos[],eDiagnostico diagnosticos[],int tam,eEnfermera listaEnfermeras[],eEspecialidad listaEspecialidades[]){//LISTADO E
	indice();
		for (int i=0;i<tam;i++)
		{
			if(listaDeConsultas[i].iniciar==1){
				mostrarUnDiagnostico(listaDeConsultas[i], listaMedicos, diagnosticos, tam,listaEnfermeras,listaEspecialidades);
			}
		}
		printf(" |_____________________________________________________________________________________________________________________________________________________________________________________________________________________________________|\n");
}
void mostrarUnDiagnostico (eConsulta listaDeConsultas,eMedico listaMedicos[],eDiagnostico diagnosticos[], int tam,eEnfermera listaEnfermeras[],eEspecialidad listaEspecialidad[]){//LISTADO E
	int consultaTipo;
	int medico;
	int enfermera;
	int especialidad;
		if(listaDeConsultas.estadoDeConsulta==ATENDIDO)
		{

			medico=MedicoQueAtendio( listaDeConsultas, listaMedicos,4);
				consultaTipo=descripcionConsulta( listaDeConsultas, diagnosticos,4);
				enfermera=posicionEnfermera(listaEnfermeras, listaDeConsultas);
				especialidad=obtenerEspecialidad(listaMedicos[medico], listaEspecialidad);

				printf(
						" |%4d   |       %12s      |        %8s       |       %2d/%2d/%4d    |     %15s     |        %15s         |        %13s     |         %16s       |     %14.2f           |\n"
						,listaDeConsultas.id ,listaDeConsultas.lastName,listaDeConsultas.name,listaDeConsultas.fecha.dia,listaDeConsultas.fecha.mes,listaDeConsultas.fecha.anio,diagnosticos[consultaTipo].descripcion,listaMedicos[medico].nombre,listaEspecialidad[especialidad].descripcion,listaEnfermeras[enfermera].nombre,listaEnfermeras[enfermera].horasDiarias);

		}
}
void DiagnosticosCovidYEspecialidad(eConsulta listaDeConsultas[],eMedico listaMedicos[],eDiagnostico diagnosticos[], int tam,eEnfermera listaEnfermera[],eEspecialidad listaEspecialidades[]){//LISTADO F

	int especialidad;



	printf("---------------ELEGIR UNA ESPECIALIDAD---------------\n");
	printf("   1.Cardiologo     2.Neumonologo     3.Traumatologa \n");
	especialidad=IngresarEntero("ingresar opcion: ", 1, 3);

	unaComparacion(listaDeConsultas, listaMedicos, diagnosticos, tam, especialidad,listaEnfermera,listaEspecialidades);



}
void unaComparacion(eConsulta listaDeConsultas[],eMedico listaMedicos[],eDiagnostico diagnosticos[], int tam,int especialidad,eEnfermera listaEnfermeras[],eEspecialidad listaEspecialidades[]){//LISTADO F
	indice();
		for (int i=0;i<tam;i++)
		{
			if(listaDeConsultas[i].iniciar==1 && listaDeConsultas[i].idDiagnostico==2){
				if(listaDeConsultas[i].fecha.anio>2019){
					printEspecialidadComparada(listaDeConsultas[i], listaMedicos, diagnosticos, tam,especialidad,listaEnfermeras,listaEspecialidades);
				}
			}
		}
		printf(" |_____________________________________________________________________________________________________________________________________________________________________|\n");
}
void printEspecialidadComparada(eConsulta listaDeConsultas,eMedico listaMedicos[],eDiagnostico diagnosticos[], int tam,int especialidad,eEnfermera listaEnfermeras[],eEspecialidad listaEspecialidades[]){//LISTADO F Y H
	int referencia;
	int consultaTipo;
	int medico;
	int enfermera;
	int indexEspecialidad;

	referencia=listaDeConsultas.idMedicoAtendido;
	for (int i=0;i<4;i++){
		if(listaMedicos[i].idMedico==referencia && listaMedicos[i].idEspecialidad==especialidad){
			medico=MedicoQueAtendio( listaDeConsultas, listaMedicos,4);
			consultaTipo=descripcionConsulta( listaDeConsultas, diagnosticos,4);
			enfermera=posicionEnfermera(listaEnfermeras, listaDeConsultas);
			indexEspecialidad=obtenerEspecialidad(listaMedicos[medico], listaEspecialidades);
			printf(
					" |%4d   |       %12s      |        %8s       |       %2d/%2d/%4d    |     %15s     |        %15s         |        %13s     |         %16s       |     %14.2f           |\n"
					,listaDeConsultas.id ,listaDeConsultas.lastName,listaDeConsultas.name,listaDeConsultas.fecha.dia,listaDeConsultas.fecha.mes,listaDeConsultas.fecha.anio,diagnosticos[consultaTipo].descripcion,listaMedicos[medico].nombre,listaEspecialidades[indexEspecialidad].descripcion,listaEnfermeras[enfermera].nombre,listaEnfermeras[enfermera].horasDiarias);

		}
	}
}
void ordenamientoAlfabeticoEspecialidad(eConsulta listaDeConsultas[],eMedico listaMedicos[],eDiagnostico diagnosticos[], int tam,eEspecialidad listaEspecialidades[]){//LISTADO G
	int referencia1;
	int referencia2;
	int ref1;
	int ref2;

	eConsulta aux;
	for (int i=0;i<tam;i++){
		ref1=MedicoQueAtendio(listaDeConsultas[i], listaMedicos, TAM);
		referencia1=obtenerEspecialidad(listaMedicos[ref1], listaEspecialidades);
		for (int j=0;j<tam - 1;j++){
			ref2=MedicoQueAtendio(listaDeConsultas[j], listaMedicos, TAM);
			referencia2=obtenerEspecialidad(listaMedicos[ref2], listaEspecialidades);
			if(strcmp(listaEspecialidades[referencia1].descripcion,listaEspecialidades[referencia2].descripcion)<0){
				aux=listaDeConsultas[i];
				listaDeConsultas[i]=listaDeConsultas[j];
				listaDeConsultas[j]=aux;

			}
		}
	}
}
void consultasEntreMeses(eConsulta listaDeConsultas[],eMedico listaMedicos[],eDiagnostico diagnosticos[], int tam,int mes1,int mes2,int especialidad,eEnfermera listaEnfermera[],eEspecialidad listaEspecialidades[]){//LISTADO H

	indice();
	//printf("hola");
	for (int i=0;i<tam;i++)
	{
		if(listaDeConsultas[i].fecha.mes>mes1 && listaDeConsultas[i].fecha.mes<mes2){
			printEspecialidadComparada(listaDeConsultas[i], listaMedicos, diagnosticos, tam,especialidad,listaEnfermera,listaEspecialidades);
		}
	}
	printf(" |_____________________________________________________________________________________________________________________________________________________________________|\n");



}
void DiagnosticosEntreMeses(eConsulta listaDeConsultas[],eMedico listaMedicos[],eDiagnostico diagnosticos[], int tam,eEnfermera listaEnfermeras[],eEspecialidad listaEspecialidades[]){//LISTADO H

	int especialidad;


	printf("---------------ELEGIR UNA ESPECIALIDAD---------------\n");
	printf("   1.Cardiologo     2.Neumonologo     3.Traumatologa \n");
	especialidad=IngresarEntero("ingresar opcion: ", 1, 3);
	unaComparacion(listaDeConsultas, listaMedicos, diagnosticos, tam, especialidad,listaEnfermeras,listaEspecialidades);

}
void porcentajeYDatos (eConsulta listaDeConsultas[],eMedico listaMedicos[],eDiagnostico diagnosticos[], int tam,eEspecialidad listaEspecialidades[]){

	sacarPorcentajes(listaDeConsultas, listaMedicos, TAM,listaEspecialidades);
	printf("\n\n\n");
	enfermedadMenosDiagnosticada(listaDeConsultas, diagnosticos, TAM);
	printf("\n\n\n");
	especialidadMasEstudiada(listaDeConsultas, listaMedicos, TAM,listaEspecialidades);
}
void sacarPorcentajes(eConsulta listaDeConsultas[],eMedico listaMedicos[], int tam,eEspecialidad listaEspecialidades[]){

	int contador=0;
	float porcentaje;
	int total;
	int especialidad;
	total=totalConsultas(listaDeConsultas, TAM);

	for(int i=0;i<tam;i++){
		if(listaDeConsultas[i].iniciar==1){
			contador=0;
				for(int j=0;j<tam;j++){
					if(listaMedicos[i].idMedico==listaDeConsultas[j].idMedicoAtendido){
						contador++;
					}
				}
				if(listaMedicos[i].idMedico!=0){
					porcentaje=contador*100/total;
					especialidad=obtenerEspecialidad(listaMedicos[i],listaEspecialidades);
					printf("|Id: %d |Nombre: %15s |Especialidad:%15s|Porcentaje de atencion: %.2f  \n",listaMedicos[i].idMedico,listaMedicos[i].nombre,listaEspecialidades[especialidad].descripcion,porcentaje);
			}
		}
	}
}
int totalConsultas(eConsulta listaConsultas[],int tam){
	int contadorDeTotal=0;
	for (int i=0;i<tam;i++){
		if(listaConsultas[i].iniciar==1){
			contadorDeTotal++;
		}
	}
	return contadorDeTotal;
}
void enfermedadMenosDiagnosticada(eConsulta listaDeConsultas[],eDiagnostico diagnosticos[], int tam){
	int posicion;
	int valorchico;
	int valorAux;
	int bandera=1;


	for(int i=0;i<4;i++){
			valorAux=sumaDeDiagnostico(listaDeConsultas, diagnosticos[i], TAM);
			if(bandera==1 && diagnosticos[i].idDiagnostico!=0)
			{
				valorchico=valorAux;
				posicion=i;
				bandera=0;
			}
			else
			{
				if(valorAux<valorchico)
				{
					valorchico=valorAux;
					posicion=i;
			}
		}
	}
	printf("la enfermedad menos diagnosticada es %s con %d diagnosticos\n",diagnosticos[posicion].descripcion,valorchico);
}
int sumaDeDiagnostico(eConsulta listaDeConsultas[],eDiagnostico diagnosticos,int tam){
	int valorAux=0;
	for(int j=0;j<tam;j++)
	{
		if(listaDeConsultas[j].iniciar==1 && diagnosticos.idDiagnostico>0 && diagnosticos.idDiagnostico==listaDeConsultas[j].idDiagnostico){
			valorAux++;
		}
	}
	return valorAux;
}
void especialidadMasEstudiada(eConsulta listaDeConsultas[],eMedico listaMedicos[], int tam,eEspecialidad listaEspecialidades[]){

	int especialidadContador=0;
	int especialidad;
	int banderaMayor=0;
	//char especialidadMayor[20];
	int cantidadMayor;
	int posicion;



	for (int i=0;i<4;i++){
		especialidadContador=0;
			if(listaMedicos[i].idMedico!=000){
				for (int j=0;j<4;j++){
					if(listaMedicos[i].idEspecialidad==listaMedicos[j].idEspecialidad){
						especialidadContador++;
					}
				}
				if(banderaMayor==0){
					cantidadMayor=especialidadContador;
					posicion=i;
					banderaMayor=1;
				}
				else{
					if(especialidadContador>cantidadMayor){
						cantidadMayor=especialidadContador;
						posicion=i;
					}
				}
			}
		}
	especialidad=obtenerEspecialidad(listaMedicos[posicion], listaEspecialidades);
	printf("la especialidad mas estudiada es %s con un total de %d medicos especializados en ella",listaEspecialidades[especialidad].descripcion,cantidadMayor);
}
void mostrarEnfermeras(eEnfermera listaEnfermeras[]){
	printf("ID         NOMBRE      HORAS DIARIAS\n");
	for(int i=1;i<4;i++){
		unaEnfermera(listaEnfermeras[i]);
	}
}
void unaEnfermera(eEnfermera listaEnfermeras){
	printf(" %-4d  %-16s  %.2f\n",listaEnfermeras.idEnfermera,listaEnfermeras.nombre,listaEnfermeras.horasDiarias);
}
void mostrarEnfermerasConMedicos(eConsulta listaDeConsultas[],eMedico listaMedicos[],eDiagnostico diagnosticos[], int tam,eEnfermera listaEnfermeras[],eEspecialidad listaEspecialidades[]){
	int idMedico;
	int idEnfermera;
	idMedico=mostrarTodosMedicos(listaMedicos,listaEspecialidades);
	mostrarEnfermeras(listaEnfermeras);
	idEnfermera=IngresarEntero("seleccionar el id de una enfermera: ", 1, 3);
	indice();
	for(int i=0;i<tam;i++){
		mostrarEnfermeraConMedico(listaDeConsultas[i], listaMedicos, diagnosticos, TAM, listaEnfermeras, idMedico, idEnfermera,listaEspecialidades);
	}
	printf(" |_____________________________________________________________________________________________________________________________________________________________________________________________________________________________________|\n");
}
void mostrarEnfermeraConMedico(eConsulta listaDeConsultas,eMedico listaMedicos[],eDiagnostico diagnosticos[], int tam,eEnfermera listaEnfermeras[],int idMedico,int idEnfermera,eEspecialidad listaEspecialidades[]){
	int medico;
	int consultaTipo;
	int enfermera;
	int especialidad;

	if(listaDeConsultas.iniciar==1 && listaDeConsultas.idMedicoAtendido == idMedico && listaDeConsultas.idEnfermera==idEnfermera){

		medico=MedicoQueAtendio( listaDeConsultas, listaMedicos,4);
		consultaTipo=descripcionConsulta( listaDeConsultas, diagnosticos,4);
		enfermera=posicionEnfermera(listaEnfermeras, listaDeConsultas);
		especialidad=obtenerEspecialidad(listaMedicos[medico], listaEspecialidades);
		obtenerEspecialidad(listaMedicos[medico], listaEspecialidades);
		printf(
					" |%4d   |       %12s      |        %8s       |       %2d/%2d/%4d    |     %15s     |        %15s         |        %13s     |         %16s       |     %14.2f           |\n"
					,listaDeConsultas.id ,listaDeConsultas.lastName,listaDeConsultas.name,listaDeConsultas.fecha.dia,listaDeConsultas.fecha.mes,listaDeConsultas.fecha.anio,diagnosticos[consultaTipo].descripcion,listaMedicos[medico].nombre,listaEspecialidades[especialidad].descripcion,listaEnfermeras[enfermera].nombre,listaEnfermeras[enfermera].horasDiarias);

	}
}
