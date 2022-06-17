/*
 * listados.h
 *
 *  Created on: 13 jun. 2022
 *      Author: Julian lopez
 */

#ifndef LISTADOS_H_
#define LISTADOS_H_

#include "funciones.h"

void subMenuListar(eConsulta listaDeConsultas[],eMedico listaMedicos[],eDiagnostico diagnosticos[],eEnfermera ListaEnfermeras[],eEspecialidad listaEspecialidades[]);//MENU
void listarTodosMedicos (eMedico listaMedicos[],eEspecialidad listaEspecialidades[]);//LISTADO A
void mostrarUnaConsulta(eConsulta listaDeConsultas,eMedico listaMedicos[],eDiagnostico diagnosticos[], int tam,eEnfermera listaEnfermeras[],eEspecialidad listaEspecialidades[]);//LISTADO B
void mostrarConsultas(eConsulta listaDeConsultas[],eMedico listaMedicos[],eDiagnostico diagnosticos[], int tam,eEnfermera listaEnfermeras[],eEspecialidad listaEspecialidades[]);//LISTADO B
void listarMedicosConConsultas(eMedico listaMedicos[], eConsulta listaDeConsultas[],int tam);//LISTADO C
void consultasDiagnosticadas(eConsulta listaConsulta[], eMedico listaMedicos[],eDiagnostico diagnosticos[],int tam,eEnfermera listaEnfermeras[],eEspecialidad listaEspecialidades[]);
void mostrarUnDiagnostico (eConsulta listaDeConsultas,eMedico listaMedicos[],eDiagnostico diagnosticos[], int tam,eEnfermera listaEnfermeras[],eEspecialidad listaEspecialidad[]);//LISTADO E
void unaComparacion(eConsulta listaDeConsultas[],eMedico listaMedicos[],eDiagnostico diagnosticos[], int tam,int especialidad,eEnfermera listaEnfermeras[],eEspecialidad listaEspecialidades[]);//LISTADO E
void printEspecialidadComparada(eConsulta listaDeConsultas,eMedico listaMedicos[],eDiagnostico diagnosticos[], int tam,int especialidad,eEnfermera listaEnfermeras[],eEspecialidad listaEspecialidades[]);
void ordenamientoFecha(eConsulta listaDeConsultas[],eMedico listaMedicos[],eDiagnostico diagnosticos[], int tam);
void DiagnosticosCovidYEspecialidad(eConsulta listaDeConsultas[],eMedico listaMedicos[],eDiagnostico diagnosticos[], int tam,eEnfermera listaEnfermera[],eEspecialidad listaEspecialidades[]);
void ordenamientoAlfabeticoEspecialidad(eConsulta listaDeConsultas[],eMedico listaMedicos[],eDiagnostico diagnosticos[], int tam,eEspecialidad listaEspecialidades[]);
void consultasEntreMeses(eConsulta listaDeConsultas[],eMedico listaMedicos[],eDiagnostico diagnosticos[], int tam,int mes1,int mes2,int especialidad,eEnfermera listaEnfermera[],eEspecialidad listaEspecialidades[]);
void DiagnosticosEntreMeses(eConsulta listaDeConsultas[],eMedico listaMedicos[],eDiagnostico diagnosticos[], int tam,eEnfermera listaEnfermeras[],eEspecialidad listaEspecialidades[]);
void sacarPorcentajes(eConsulta listaDeConsultas[],eMedico listaMedicos[], int tam,eEspecialidad listaEspecialidades[]);
int totalConsultas(eConsulta listaConsultas[],int tam);
void porcentajeYDatos (eConsulta listaDeConsultas[],eMedico listaMedicos[],eDiagnostico diagnosticos[], int tam,eEspecialidad listaEspecialidades[]);
void enfermedadMenosDiagnosticada(eConsulta listaDeConsultas[],eDiagnostico diagnosticos[], int tam);
int sumaDeDiagnostico(eConsulta listaDeConsultas[],eDiagnostico diagnosticos,int tam);
void especialidadMasEstudiada(eConsulta listaDeConsultas[],eMedico listaMedicos[], int tam,eEspecialidad listaEspecialidades[]);
void mostrarEnfermerasConMedicos(eConsulta listaDeConsultas[],eMedico listaMedicos[],eDiagnostico diagnosticos[], int tam,eEnfermera listaEnfermeras[],eEspecialidad listaEspecialidades[]);
void mostrarEnfermeraConMedico(eConsulta listaDeConsultas,eMedico listaMedicos[],eDiagnostico diagnosticos[], int tam,eEnfermera listaEnfermeras[],int idMedico,int idEnfermera,eEspecialidad listaEspecialidades[]);
#endif /* LISTADOS_H_ */
