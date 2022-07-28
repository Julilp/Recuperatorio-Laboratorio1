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
	int idLocalidad;
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
struct
{
	int idLocalidad;
	char descripcionLocalidad[50];
	int codPostal;

}typedef eLocalidad;





eConsulta listaDeConsultas[TAM];

/// @brief genera espacios en la consola usando \n
///
void espaciarLaConsola(void);
/// @brief pide y valida todos los datos datos para despues pasarlos a otra funcion que los cargue
///
/// @param listaDeConsultas
/// @param tam
/// @return
int pedirDatos(eConsulta listaDeConsultas[],int tam);
/// @brief busca el primer espacio libre dentro de la lista de consultas
///
/// @param listaDeConsultas
/// @param tam
/// @return devuelve la primer posicion libre para usarla de referencia
int buscarEspacioLibre(eConsulta listaDeConsultas[], int tam);
/// @brief genera ids de manera incremental automaticamente y la asigna a una variable
///
/// @return
int obtenerID();
/// @brief pide que ingresen una fecha y la valida dentro de los paramentros que se le pasan
///
/// @param dia
/// @return
int pedirFecha (int dia);
/// @brief luego de validar y pedir todos los datos con la funcion pedir datos se pasan a esta funcion y los carga en el primer espacio libre
///
/// @param listaDeConsultas
/// @param nombre
/// @param apellido
/// @param estadoDeConsulta
/// @param id
/// @param dia
/// @param mes
/// @param anio
/// @param tam
/// @param inicio
/// @param idLocalidad
void cargarDatos (eConsulta listaDeConsultas[],char nombre[],char apellido[],int estadoDeConsulta,int id,int dia,int mes,int anio,int tam,int inicio,int idLocalidad);
/// @brief agrega la mayuscula al principio de las palabras
///
/// @param cadena
void Mayuscula (char cadena []);
/// @brief genera un sub menu con opciones para poder modificar los datos de las consultas
///
/// @param listaDeConsultas
/// @param tam
/// @param listaDeMedicos
/// @param listaEspecialidades
void modificarConsulta (eConsulta listaDeConsultas[], int tam, eMedico listaDeMedicos[],eEspecialidad listaEspecialidades[]);
/// @brief se le pasa un id y lo busca dentro de la lista
///
/// @param listaDeConsultas
/// @param tam
/// @param id
/// @return devuelve la posicion del id buscado, si es que se encuentra un id
int buscarID (eConsulta listaDeConsultas[], int tam,int id);
/// @brief elimina logicamente una consulta
///
/// @param listaDeConsultas
/// @param tam
void bajaDeConsulta(eConsulta listaDeConsultas[], int tam);
/// @brief se usa para poder mostrar un diagnostico basandones en el id del diagnostico
///
/// @param listaDeConsultas
/// @param diagnosticos
/// @param tam
/// @return
int descripcionConsulta(eConsulta listaDeConsultas,eDiagnostico diagnosticos[], int tam);
/// @brief se usa para poder mostrar el medico asignado a la consulta basandose en su id
///
/// @param listaDeConsultas
/// @param listaMedicos
/// @param tam
/// @return
int MedicoQueAtendio(eConsulta listaDeConsultas,eMedico listaMedicos[], int tam);
/// @brief le da la opcion al sistema de diagnosticar un paciente, a este se le asigna la enfermedad, el medico y la enfermera en esta funcion
///
/// @param listaDeConsultas
/// @param listaMedicos
/// @param diagnosticos
/// @param tam
/// @param listaEnfermeras
/// @param listaEspecialidades
/// @param listaDeLocalidades
void diagnosticar (eConsulta listaDeConsultas[],eMedico listaMedicos[],eDiagnostico diagnosticos[], int tam,eEnfermera listaEnfermeras[],eEspecialidad listaEspecialidades[],eLocalidad listaDeLocalidades[]);
/// @brief muestra un medico con su id y especialidad
///
/// @param listaMedicos
/// @param listaEspecialidades
void mostrarMedico (eMedico listaMedicos,eEspecialidad listaEspecialidades[]);
/// @briefmuestra una lista de todos los medicos
///
/// @param listaMedicos
/// @param listaEspecialidades
/// @return
int mostrarTodosMedicos(eMedico listaMedicos[],eEspecialidad listaEspecialidades[]);
/// @brief busca el id de las consultas no atendidas
///
/// @param listaDeConsultas
/// @param tam
/// @param id
/// @return
int buscarIDNoAtendido (eConsulta listaDeConsultas[], int tam,int id);
/// @brief es un printf con un header para los listados
///
void indice();
/// @brief lo que hace esta funcion es setea el id del medico, el del diagnostico y el de la enfermera a la consulta
///
/// @param listaDeConsultas
/// @param idMedico
/// @param index
/// @param diagnostico
/// @param idEnfermera
/// @return
int setMedicoAConsulta(eConsulta listaDeConsultas[],int idMedico,int index, int diagnostico,int idEnfermera);
/// @brief harcodea consultas para probar el programa
///
/// @param listaDeConsultas
void consultasHardcodeadas(eConsulta listaDeConsultas[]);
/// @brief muestra a las enfermeras existentes en una lista
///
/// @param listaEnfermeras
void mostrarEnfermeras(eEnfermera listaEnfermeras[]);
/// @brief muestra una sola enfermera
///
/// @param listaEnfermeras
void unaEnfermera(eEnfermera listaEnfermeras);
/// @brief matchea el id de la enfermera con el nombre de esta misma para poder mostrarlos en una lista
///
/// @param listaEnfermeras
/// @param listaConsulta
/// @return
int posicionEnfermera(eEnfermera listaEnfermeras[],eConsulta listaConsulta);
/// @brief matchea el id del diagnostico con el nombre de este mismo para poder mostrarlos en una lista
///
/// @param listaMedicos
/// @param listaEspecialidades
/// @return
int obtenerEspecialidad(eMedico listaMedicos,eEspecialidad listaEspecialidades[]);
/// @brief harcodea a los medicos, diagnosticos y localidades
///
/// @param listaMedicos
/// @param listaEspecialidades
/// @param listaEnfermeras
/// @param listaDiagnosticos
/// @param listaDeLocalidades
void datosHardcodeadas(eMedico listaMedicos[],eEspecialidad listaEspecialidades[],eEnfermera listaEnfermeras[],eDiagnostico listaDiagnosticos[],eLocalidad listaDeLocalidades[]);
/// @brief matchea el id de la localidad con el nombre de esta misma para poder mostrarlos en una lista
///
/// @param listaConsultas
/// @param ListaDeLocalidades
/// @return
int obtenerLocalidad(eConsulta listaConsultas,eLocalidad ListaDeLocalidades []);

#endif /* FUNCIONES_H_ */
