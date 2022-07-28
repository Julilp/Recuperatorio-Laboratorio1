/*
 * listados.h
 *
 *  Created on: 13 jun. 2022
 *      Author: Julian lopez
 */

#ifndef LISTADOS_H_
#define LISTADOS_H_

#include "funciones.h"

/// @brief genera un menu con todas las opciones de listados
///
/// @param listaDeConsultas
/// @param listaMedicos
/// @param diagnosticos
/// @param ListaEnfermeras
/// @param listaEspecialidades
/// @param listaDeLocalidades
void subMenuListar(eConsulta listaDeConsultas[],eMedico listaMedicos[],eDiagnostico diagnosticos[],eEnfermera ListaEnfermeras[],eEspecialidad listaEspecialidades[],eLocalidad listaDeLocalidades[]);//MENU
/// @brief muestra a todos los medicos
///
/// @param listaMedicos
/// @param listaEspecialidades
void listarTodosMedicos (eMedico listaMedicos[],eEspecialidad listaEspecialidades[]);//LISTADO A
/// @brief muesttra una sola consulta
///
/// @param listaDeConsultas
/// @param listaMedicos
/// @param diagnosticos
/// @param tam
/// @param listaEnfermeras
/// @param listaEspecialidades
/// @param listaDeLocalidades
void mostrarUnaConsulta(eConsulta listaDeConsultas,eMedico listaMedicos[],eDiagnostico diagnosticos[], int tam,eEnfermera listaEnfermeras[],eEspecialidad listaEspecialidades[],eLocalidad listaDeLocalidades[]);//LISTADO B
/// @brief muestra el listado de todas las consultas
///
/// @param listaDeConsultas
/// @param listaMedicos
/// @param diagnosticos
/// @param tam
/// @param listaEnfermeras
/// @param listaEspecialidades
/// @param listaDeLocalidades
void mostrarConsultas(eConsulta listaDeConsultas[],eMedico listaMedicos[],eDiagnostico diagnosticos[], int tam,eEnfermera listaEnfermeras[],eEspecialidad listaEspecialidades[],eLocalidad listaDeLocalidades[]);//LISTADO B
/// @brief muestra a todos los medicos que hayan atendido por lo menos 1 consulta
///
/// @param listaMedicos
/// @param listaDeConsultas
/// @param tam
void listarMedicosConConsultas(eMedico listaMedicos[], eConsulta listaDeConsultas[],int tam);//LISTADO C
/// @brief muestra solo las consultas que ya tienen un diagnostico
///
/// @param listaConsulta
/// @param listaMedicos
/// @param diagnosticos
/// @param tam
/// @param listaEnfermeras
/// @param listaEspecialidades
/// @param listaDeLocalidades
void consultasDiagnosticadas(eConsulta listaConsulta[], eMedico listaMedicos[],eDiagnostico diagnosticos[],int tam,eEnfermera listaEnfermeras[],eEspecialidad listaEspecialidades[],eLocalidad listaDeLocalidades[]);//LISTADO E
/// @brief muestra una sola consulta con diagnostico
///
/// @param listaDeConsultas
/// @param listaMedicos
/// @param diagnosticos
/// @param tam
/// @param listaEnfermeras
/// @param listaEspecialidad
/// @param listaDeLocalidades
void mostrarUnDiagnostico (eConsulta listaDeConsultas,eMedico listaMedicos[],eDiagnostico diagnosticos[], int tam,eEnfermera listaEnfermeras[],eEspecialidad listaEspecialidad[],eLocalidad listaDeLocalidades[]);//LISTADO E
/// @brief muestra una sola consulta, que tiene que cumplir un requisito determinado
///
/// @param listaDeConsultas
/// @param listaMedicos
/// @param diagnosticos
/// @param tam
/// @param especialidad
/// @param listaEnfermeras
/// @param listaEspecialidades
/// @param listaDeLocalidades
void unaComparacion(eConsulta listaDeConsultas[],eMedico listaMedicos[],eDiagnostico diagnosticos[], int tam,int especialidad,eEnfermera listaEnfermeras[],eEspecialidad listaEspecialidades[], eLocalidad listaDeLocalidades[]);//LISTADO E
/// @brief muestra solo consultas con x especialidad
///
/// @param listaDeConsultas
/// @param listaMedicos
/// @param diagnosticos
/// @param tam
/// @param especialidad
/// @param listaEnfermeras
/// @param listaEspecialidades
/// @param listaDeLocalidades
void printEspecialidadComparada(eConsulta listaDeConsultas,eMedico listaMedicos[],eDiagnostico diagnosticos[], int tam,int especialidad,eEnfermera listaEnfermeras[],eEspecialidad listaEspecialidades[],eLocalidad listaDeLocalidades[]);
/// @brief ordena las consultas por fecha
///
/// @param listaDeConsultas
/// @param listaMedicos
/// @param diagnosticos
/// @param tam
void ordenamientoFecha(eConsulta listaDeConsultas[],eMedico listaMedicos[],eDiagnostico diagnosticos[], int tam);
/// @brief muestra las consultas con x especialidad y que sean diagnosticadas de covid
///
/// @param listaDeConsultas
/// @param listaMedicos
/// @param diagnosticos
/// @param tam
/// @param listaEnfermera
/// @param listaEspecialidades
/// @param listaDeLocalidades
void DiagnosticosCovidYEspecialidad(eConsulta listaDeConsultas[],eMedico listaMedicos[],eDiagnostico diagnosticos[], int tam,eEnfermera listaEnfermera[],eEspecialidad listaEspecialidades[], eLocalidad listaDeLocalidades[]);
/// @brief ordena alfabeticamente las consultas segun su especialidad
///
/// @param listaDeConsultas
/// @param listaMedicos
/// @param diagnosticos
/// @param tam
/// @param listaEspecialidades
void ordenamientoAlfabeticoEspecialidad(eConsulta listaDeConsultas[],eMedico listaMedicos[],eDiagnostico diagnosticos[], int tam,eEspecialidad listaEspecialidades[]);
/// @brief muestra solo las consulas entre 2 meses seleccionados
///
/// @param listaDeConsultas
/// @param listaMedicos
/// @param diagnosticos
/// @param tam
/// @param mes1
/// @param mes2
/// @param especialidad
/// @param listaEnfermera
/// @param listaEspecialidades
/// @param listaDeLocalidades
void consultasEntreMeses(eConsulta listaDeConsultas[],eMedico listaMedicos[],eDiagnostico diagnosticos[], int tam,int mes1,int mes2,int especialidad,eEnfermera listaEnfermera[],eEspecialidad listaEspecialidades[], eLocalidad listaDeLocalidades[]);
/// @briefagrega el filtro de especialidad a la funcion anteriro
///
/// @param listaDeConsultas
/// @param listaMedicos
/// @param diagnosticos
/// @param tam
/// @param listaEnfermeras
/// @param listaEspecialidades
/// @param listaDeLocalidades
void DiagnosticosEntreMeses(eConsulta listaDeConsultas[],eMedico listaMedicos[],eDiagnostico diagnosticos[], int tam,eEnfermera listaEnfermeras[],eEspecialidad listaEspecialidades[],eLocalidad listaDeLocalidades[]);
/// @brief saca el porcentaje de cuantos medicos atiende cada doctor
///
/// @param listaDeConsultas
/// @param listaMedicos
/// @param tam
/// @param listaEspecialidades
void sacarPorcentajes(eConsulta listaDeConsultas[],eMedico listaMedicos[], int tam,eEspecialidad listaEspecialidades[]);
/// @brief el total de las consultas y cuantas cada medico
///
/// @param listaConsultas
/// @param tam
/// @return
int totalConsultas(eConsulta listaConsultas[],int tam);
/// @brief muestra y analiza los datos anteriores
///
/// @param listaDeConsultas
/// @param listaMedicos
/// @param diagnosticos
/// @param tam
/// @param listaEspecialidades
void porcentajeYDatos (eConsulta listaDeConsultas[],eMedico listaMedicos[],eDiagnostico diagnosticos[], int tam,eEspecialidad listaEspecialidades[]);
/// @brief muestra la enfermedad menos diagnosticada
///
/// @param listaDeConsultas
/// @param diagnosticos
/// @param tam
void enfermedadMenosDiagnosticada(eConsulta listaDeConsultas[],eDiagnostico diagnosticos[], int tam);
/// @brief
///
/// @param listaDeConsultas
/// @param diagnosticos
/// @param tam
/// @return
int sumaDeDiagnostico(eConsulta listaDeConsultas[],eDiagnostico diagnosticos,int tam);
/// @brief
///
/// @param listaDeConsultas
/// @param listaMedicos
/// @param tam
/// @param listaEspecialidades
void especialidadMasEstudiada(eConsulta listaDeConsultas[],eMedico listaMedicos[], int tam,eEspecialidad listaEspecialidades[]);
/// @brief
///
/// @param listaDeConsultas
/// @param listaMedicos
/// @param diagnosticos
/// @param tam
/// @param listaEnfermeras
/// @param listaEspecialidades
void mostrarEnfermerasConMedicos(eConsulta listaDeConsultas[],eMedico listaMedicos[],eDiagnostico diagnosticos[], int tam,eEnfermera listaEnfermeras[],eEspecialidad listaEspecialidades[]);
/// @brief
///
/// @param listaDeConsultas
/// @param listaMedicos
/// @param diagnosticos
/// @param tam
/// @param listaEnfermeras
/// @param idMedico
/// @param idEnfermera
/// @param listaEspecialidades
void mostrarEnfermeraConMedico(eConsulta listaDeConsultas,eMedico listaMedicos[],eDiagnostico diagnosticos[], int tam,eEnfermera listaEnfermeras[],int idMedico,int idEnfermera,eEspecialidad listaEspecialidades[]);

#endif /* LISTADOS_H_ */
