/*
 * funciones.c
 *
 *  Created on: 16 may. 2022
 *      Author: Julian lopez
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <ctype.h>
#include <string.h>
#include "validaciones.h"
#include "listados.h"
void espaciarLaConsola(void)
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

void iniciarPrograma( eConsulta listaDeConsultas[],int tam)
{
	for(int i=0;i<tam;i++)
	{
		listaDeConsultas[i].iniciar =0;
		listaDeConsultas[i].estadoDeConsulta =ESPERA;
		listaDeConsultas[i].idMedicoAtendido =000;
		listaDeConsultas[i].idDiagnostico=0;
		listaDeConsultas[i].idEnfermera=0;
	}
}
int buscarEspacioLibre(eConsulta listaDeConsultas[], int tam)
{
    int rtn = -1;
    int indice;

    if(listaDeConsultas != NULL)
    {
        if (tam >= 0)
        {
            for (indice = 0; indice < tam; indice++)
            {
                if(listaDeConsultas[indice].iniciar == 0)
                {
                    rtn = indice;
                    break;
                }
            }
        }
    }
    return rtn;
}
int pedirDatos(eConsulta listaDeConsultas[],int tam)
{
	int retorno = -1;
	char nombre[51];
	char apellido[51];
	int estadoDeConsulta;
	int idLocalidad;
	int id;
	int dia=0;
	int mes=0;
	int anio=0;
	int inicio=1;



	id=obtenerID();
	pedirCadena(nombre, "Ingrese su nombre: ", "ingresar solo letras: ", 1);
	Mayuscula (nombre);
	pedirCadena(apellido, "Ingrese su apellido: ", "ingresar solo letras: ", 1);
	Mayuscula (apellido);
	dia=IngresarEntero("ingrese el dia: ", 1, 31);
	mes=pedirFecha (dia);
	anio=IngresarEntero("ingrese el año (desde 2010 hasta 2025)", 2010, 2025);
	idLocalidad=IngresarEntero("1.Esteban Echeverria\n2.Ezeiza\n3.San Vicente\n4.Lomas De Zamora\ningrese su localidad:", 1, 4);
	estadoDeConsulta=ESPERA;

	cargarDatos (listaDeConsultas,nombre,apellido,estadoDeConsulta,id,dia,mes,anio,TAM,inicio,idLocalidad);

	return retorno;
}
int pedirFecha (int dia)
{

	int validacion;
	int mes;
	switch(dia)
	{
		case 31:
			do
			{
				mes=IngresarEntero("ingrese el mes: ", 1, 12);
				if (mes != 1 && mes != 3 && mes != 5 && mes != 7 && mes != 8 && mes != 10 && mes != 12)
				{
					validacion=-1;
				}
				else
				{
					validacion =0;
				}
			}while (validacion ==-1);
		break;

		case 30:
			do
			{
				mes=IngresarEntero("ingrese el mes: ", 1, 12);
				if (mes == 2)
					{
						validacion=-1;
					}
					else
					{
						validacion =0;
					}
			}while (validacion ==-1);
		break;
		default:
			mes=IngresarEntero("ingrese el mes: ", 1, 12);

		break;
	}
	return mes;
}
int obtenerID()
{
	static int idIncremental = 1000;
	return idIncremental++;
}
void cargarDatos (eConsulta listaDeConsultas[],char nombre[],char apellido[],int estadoDeConsulta,int id,int dia,int mes,int anio,int tam,int inicio,int idLocalidad)
{

	int index;

	index=buscarEspacioLibre(listaDeConsultas, tam);

	listaDeConsultas[index].id=id;
	strcpy(listaDeConsultas[index].name,nombre);
	strcpy(listaDeConsultas[index].lastName,apellido);
	listaDeConsultas[index].fecha.dia=dia;
	listaDeConsultas[index].fecha.mes=mes;
	listaDeConsultas[index].fecha.anio=anio;
	listaDeConsultas[index].iniciar=inicio;
	listaDeConsultas[index].idLocalidad=idLocalidad;



}
void Mayuscula (char cadena [])
{
    int i;
    int size;

    size= strlen(cadena);
    strlwr(cadena);

    for(i= 0; i<size; i++)
    {
        if(cadena[i-1]==32 || i==0)
        {
        	cadena[i] = toupper(cadena[i]);
        }
    }

}
void modificarConsulta (eConsulta listaDeConsultas[], int tam, eMedico listaDeMedicos[],eEspecialidad listaEspecialidades[])
{
	int idIngresado;
	int index;
	int opcion;
	char name[51];
	char lastName[51];
	int idMedico;
	int dia;
	int mes;
	int anio;

	printf("ingrese el id del pasajero: ");
	scanf("%d", &idIngresado);
	index = buscarID(listaDeConsultas, tam, idIngresado);
	if(index!=-1)
	{
		do
		{

			printf(     "------MENU DE MODIFICACIONES------\n");
			printf(     "==================================\n"
						"|           1-NOMBRE             |\n"
						"|           2-APELLIDO           |\n"
						"|           3-MEDICO             |\n"
						"|           4-FECHA              |\n "
						"|           5-SALIR              |\n"
						"==================================\n"
						"\n");

			opcion=IngresarEntero("Ingrese una opcion: ", 1, 5);
			fflush(stdin);
				switch(opcion)
					{
					case 1:
						pedirCadena(name, "Ingrese el nuevo nombre: ", "Solo letras por favor: ", 1);
						strcpy(listaDeConsultas[index].name,name);
					break;

					case 2:

						pedirCadena(lastName, "Ingrese el apellido nombre: ", "Solo letras por favor: ", 1);
						strcpy(listaDeConsultas[index].lastName,lastName);
					break;

					case 3:

						idMedico=mostrarTodosMedicos(listaDeMedicos,listaEspecialidades);
						listaDeConsultas[index].idMedicoAtendido=idMedico;
					break;

					case 4:
						dia=IngresarEntero("ingrese el dia: ", 1, 31);
						mes=pedirFecha(dia);
						anio=IngresarEntero("ingresar un año entre 2010 y 2025", 2010, 2025);
						listaDeConsultas[index].fecha.dia=dia;
						listaDeConsultas[index].fecha.mes=mes;
						listaDeConsultas[index].fecha.anio=anio;
						break;
				case 5:
					printf("SALIENDO....\n");
					break;
					}
		}while(opcion != 5);
	}

}
int buscarID (eConsulta listaDeConsultas[], int tam,int id)
{
	int index;
	index=-1;
	for(int i=0;i<tam;i++)
	{
		if(listaDeConsultas[i].id==id && listaDeConsultas[i].iniciar==1)
		{
			index=i;
			break;
		}
	}

	return index;
}
void bajaDeConsulta(eConsulta listaDeConsultas[], int tam)
{
	int index;
	int id;
	int seguro;

	id=IngresarEntero("Ingrese el ID de la consulta: ", 0, 5000);


	index=buscarID( listaDeConsultas,tam,id);
	if ( index==-1)
	{
		printf("No se encontro ese ID.....\n");

	}
	else
	{
		printf("esta seguro que desea borrar la siguiente consulta?:\nID %d\n Nombre:%s , %s\n",listaDeConsultas[index].id,listaDeConsultas[index].name,listaDeConsultas[index].lastName);
		seguro=IngresarEntero("INGRESE \n 1-BORRAR\n2-CANCELAR", 1, 2);
		if(seguro==1)
		{
			listaDeConsultas[index].iniciar=0;
		}
		else
		{
			printf("Se cancelo el borrado de consulta");
		}
	}

}


	int MedicoQueAtendio(eConsulta listaDeConsultas,eMedico listaMedicos[], int tam)
	{
		int index;

		for(int i=0;i<tam;i++)
		{
			if(listaDeConsultas.idMedicoAtendido==listaMedicos[i].idMedico)
			{
				index=i;
				break;
			}
		}


		return index;
	}
	int descripcionConsulta(eConsulta listaDeConsultas,eDiagnostico diagnosticos[], int tam)
	{
		int index;

		for(int i=0;i<tam;i++)
		{
			if(listaDeConsultas.idDiagnostico==diagnosticos[i].idDiagnostico)
			{
				index=i;
				break;
			}
		}


		return index;
	}

void diagnosticar (eConsulta listaDeConsultas[],eMedico listaMedicos[],eDiagnostico diagnosticos[], int tam,eEnfermera listaEnfermeras[],eEspecialidad listaEspecialidades[],eLocalidad listalocalidades[]){
	int idMedico;
	int idPaciente;
	int index;
	int diagnostico;
	int idEnfermera;

	idMedico=mostrarTodosMedicos(listaMedicos,listaEspecialidades);
	mostrarEnfermeras(listaEnfermeras);
	idEnfermera=IngresarEntero("Elegir enfermera por id:", 1, 3);
	printf("\n\n\n");
	indice();


	for(int i=0;i<tam;i++)
	{
		if(listaDeConsultas[i].idDiagnostico==0 && listaDeConsultas[i].estadoDeConsulta==ESPERA)
		{
			mostrarUnaConsulta(listaDeConsultas[i], listaMedicos, diagnosticos, tam,listaEnfermeras,listaEspecialidades,listalocalidades);
		}
	}
	printf(" |_____________________________________________________________________________________________________________________________________________________________________|\n");

	idPaciente=IngresarEntero("seleccione el id del paciente que desee atender", 0, 9999);
	index=buscarIDNoAtendido ( listaDeConsultas,TAM, idPaciente);
	if(index==-1)
		{
			printf("Esa opcion no es valida\n");
		}
		else
		{
			printf("-------INGRESE SU DIAGNOSTICO-------\n");
			diagnostico=IngresarEntero("1.GripeA     2.Covid-19      3.Pre Infarto\n Opcion: ", 1, 3);
			setMedicoAConsulta(listaDeConsultas, idMedico, index, diagnostico,idEnfermera);
		}



}

void mostrarMedico (eMedico listaMedicos,eEspecialidad listaEspecialidades[])
{
	int especiallidad;
	especiallidad=obtenerEspecialidad(listaMedicos, listaEspecialidades);
	printf("%d, %s  %s \n",listaMedicos.idMedico,listaMedicos.nombre,listaEspecialidades[especiallidad].descripcion);

}

int mostrarTodosMedicos(eMedico listaMedicos[],eEspecialidad listaEspecialidades[])
{
	int opcion;
	printf("seleccione un medico\n");
	for (int i=0;i<4;i++)
	{
		if(listaMedicos[i].idMedico!=0)
		{
			mostrarMedico(listaMedicos[i],listaEspecialidades);
		}
	}
	opcion=IngresarEntero("ingrese el id de un medico: ", 100, 102);
	return opcion;
}

int buscarIDNoAtendido (eConsulta listaDeConsultas[], int tam,int id)
{
	int retorno=-1;
	int index;
	index=buscarID(listaDeConsultas, tam, id);
	if(index ==-1){
		printf("No se encontro ese id\n");
	}
	else{
		if(listaDeConsultas[index].estadoDeConsulta==ESPERA){
			retorno=index;
		}
	}
	return retorno;
}
void indice()
{
	printf( "  _____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________\n "
			"|  ID   |      APELLIDO           |         NOMBRE        |        FECHA       |       DIAGNOSTICO       |      MEDICO A CARGO            |     ESPECIALIDAD MEDICO   |      ENFERMERA A CARGO         |       HORAS TRABAJADAS              |       LOCALIDAD         |\n");
	printf( " |_______|_________________________|_______________________|____________________|_________________________|________________________________|___________________________|________________________________|_____________________________________|_________________________|\n");
}

int setMedicoAConsulta(eConsulta listaDeConsultas[],int idMedico,int index, int diagnostico,int idEnfermera){
	int retorno=-1;
	if(listaDeConsultas[index].iniciar==1){;
		listaDeConsultas[index].idDiagnostico=diagnostico;
		listaDeConsultas[index].idMedicoAtendido=idMedico;
		listaDeConsultas[index].idEnfermera=idEnfermera;
		retorno=1;
	}
	return retorno;
}
void consultasHardcodeadas(eConsulta listaDeConsultas[]){
	int size=4;
	eConsulta hardcodeo [4]={{001,"Julian" ,"Lopez"    ,{18,05,2020},1,ATENDIDO,101,1,0},
							 {002,"Franco" ,"Mendez"   ,{14,02,2020},2,ATENDIDO,100,1,2},
							 {003,"Facundo","Brito"    ,{03,04,2020},2,ATENDIDO,102,1,1},
							 {004,"Luciano","Rodriguez",{20,10,2023},2,ATENDIDO ,100,1,3}};

	for (int i=0;i<size;i++){
		listaDeConsultas[i]=hardcodeo[i];
	}
}
int posicionEnfermera(eEnfermera listaEnfermeras[],eConsulta listaConsulta){
	int index;
		for (int i=0;i<4;i++){
			if(listaConsulta.idEnfermera==listaEnfermeras[i].idEnfermera){
				index=i;
				break;
			}
		}

	return index;
}
int obtenerEspecialidad(eMedico listaMedicos,eEspecialidad listaEspecialidades[]){
	int index;
	for(int i=0;i<4;i++){
		if(listaMedicos.idEspecialidad==listaEspecialidades[i].idEspecialidad){
			index=i;
			break;
		}
	}
	return index;
}
int obtenerLocalidad(eConsulta listaConsultas,eLocalidad ListaDeLocalidades []){
	int index;
	for(int i=0;i<4;i++){
		if(listaConsultas.idLocalidad==ListaDeLocalidades[i].idLocalidad){
			index=i;
			break;
		}
	}
	return index;
}
void datosHardcodeadas(eMedico listaMedicos[],eEspecialidad listaEspecialidades[],eEnfermera listaEnfermeras[],eDiagnostico listaDiagnosticos[], eLocalidad listaDeLocalidades[]){
	int size=4;
	eEnfermera harcodeEnfermeras[4]={{0,"Sin Enfermera"   ,0},
									   {1,"Martina Sanchez" ,9},
									   {2,"Cintia Dominguez",10},
									   {3,"Isabella Lopez"  ,8}};

	eDiagnostico harcodeoDiagnosticos[4]={{0,"Sin Diagnostico"},
									  {1,"Gripe A"        },
									  {2,"Covid-19"       },
									  {3,"Pre infarto"   }};

	eEspecialidad HarcodeoEspecialidades[4]={{0,"SIN ESPECIALIDAD"},
											   {1,"Cardiologo"},
											   {2,"Neumonologo"},
											   {3,"Traumatologa"}};

	eMedico harcodeoMedicos [4]={{000,"EN ESPERA.."    ,0},
								  {100,"Lautaro Lopez"  ,1},
								  {101,"Fernan Martinez",2},
								  {102,"Martina Farias" ,3}};

	eLocalidad harcodeDeLocalidades [4]={{1, "Esteban Echeverria", 1842},
									     {2, "Ezeiza"            , 1804},
	                                     {3, "San Vicente"       , 1865},
	                                     {4, "Lomas De Zamora"   , 1832}};


	for (int i=0;i<size;i++){
		listaMedicos[i]=harcodeoMedicos[i];
		listaEspecialidades[i]=HarcodeoEspecialidades[i];
		listaEnfermeras[i]=harcodeEnfermeras[i];
		listaDiagnosticos[i]=harcodeoDiagnosticos[i];
		listaDeLocalidades[i]=harcodeDeLocalidades[i];
	}
	/*eConsulta hardcodeo [4]={{001,"Julian" ,"Lopez"    ,{18,05,2020},1,ATENDIDO,101,1,0},
							 {002,"Franco" ,"Mendez"   ,{14,02,2020},2,ATENDIDO,100,1,2},
							 {003,"Facundo","Brito"    ,{03,04,2020},2,ATENDIDO,102,1,1},
							 {004,"Luciano","Rodriguez",{20,10,2023},2,ATENDIDO ,100,1,3}};

	for (int i=0;i<size;i++){
		listaDeConsultas[i]=hardcodeo[i];
	}*/
}
