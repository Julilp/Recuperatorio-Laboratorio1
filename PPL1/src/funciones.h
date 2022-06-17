/*
 * funciones.h
 *
 *  Created on: 16 may. 2022
 *      Author: Julian lopez
 */
#ifndef FUNCIONES_H_
#define FUNCIONES_H_
#define ATENDIDO 1
#define ESPERA 0
#define TAM 50
struct
{
	int dia;
	int mes;
	int anio;
}typedef eFecha;

struct
{
	int id;
	char name[25];
	char lastName[25];
	eFecha fecha;
	int idDiagnostico;
	int estadoDeConsulta;
	int idMedicoAtendido;
	int iniciar;
	int idEnfermera;
}typedef eConsulta;

struct
{
	int idDiagnostico;
	char descripcion[25];
}typedef eDiagnostico;

struct
{
	int idMedico;
	char nombre[50];
	int idEspecialidad;
}typedef eMedico;

struct
{
	int idEspecialidad;
	char descripcion[50];

}typedef eEspecialidad;
struct
{
	int idEnfermera;
	char nombre[50];
	float horasDiarias;

}typedef eEnfermera;





eConsulta listaDeConsultas[TAM];


void espaciarLaConsola(void);
int pedirDatos(eConsulta listaDeConsultas[],int tam);
int buscarEspacioLibre(eConsulta listaDeConsultas[], int tam);
int obtenerID();
int pedirFecha (int dia);
void cargarDatos (eConsulta listaDeConsultas[],char nombre[],char apellido[],int estadoDeConsulta,int id,int dia,int mes,int anio,int tam,int inicio);
void Mayuscula (char cadena []);
void modificarConsulta (eConsulta listaDeConsultas[], int tam, eMedico listaDeMedicos[],eEspecialidad listaEspecialidades[]);
int buscarID (eConsulta listaDeConsultas[], int tam,int id);
void bajaDeConsulta(eConsulta listaDeConsultas[], int tam);
int descripcionConsulta(eConsulta listaDeConsultas,eDiagnostico diagnosticos[], int tam);
int MedicoQueAtendio(eConsulta listaDeConsultas,eMedico listaMedicos[], int tam);
void diagnosticar (eConsulta listaDeConsultas[],eMedico listaMedicos[],eDiagnostico diagnosticos[], int tam,eEnfermera listaEnfermeras[],eEspecialidad listaEspecialidades[]);
void mostrarMedico (eMedico listaMedicos,eEspecialidad listaEspecialidades[]);
int mostrarTodosMedicos(eMedico listaMedicos[],eEspecialidad listaEspecialidades[]);
int buscarIDNoAtendido (eConsulta listaDeConsultas[], int tam,int id);
void indice();
int setMedicoAConsulta(eConsulta listaDeConsultas[],int idMedico,int index, int diagnostico,int idEnfermera);
void consultasHardcodeadas(eConsulta listaDeConsultas[]);
void mostrarEnfermeras(eEnfermera listaEnfermeras[]);
void unaEnfermera(eEnfermera listaEnfermeras);
int posicionEnfermera(eEnfermera listaEnfermeras[],eConsulta listaConsulta);
int obtenerEspecialidad(eMedico listaMedicos,eEspecialidad listaEspecialidades[]);
void datosHardcodeadas(eMedico listaMedicos[],eEspecialidad listaEspecialidades[],eEnfermera listaEnfermeras[],eDiagnostico listaDiagnosticos[]);

#endif /* FUNCIONES_H_ */
