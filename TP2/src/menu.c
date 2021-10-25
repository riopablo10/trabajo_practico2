/*
 * menu.c
 *
 *  Created on: 16 oct. 2021
 *      Author: Furya
 */


#include "menu.h"

static int createID (void)
{
	int contadorID = 1000;

	contadorID++;

	return contadorID;

}


void iniciarMenu(void)
{
	int opcion; //opcion del menu

	//genero las variables para que el usuario escriba
	int id;
	char nombre[51];
	char apellido[51];
	float salario;
	int sector;
	int banderaEmpleado = 0;
	int idaModificar;
	int idaDarDeBaja;
	int ordenamiento;
	int totalSalarios;
	float promedioSalarios;
	int salariosPorEncima;
	Empleado empleados[LEN_EMPLEADOS];

	initEmpleados(empleados, LEN_EMPLEADOS);

	//imprimirEmpleados(empleados, LEN_EMPLEADOS);



		//muestro el menu
		mostrarMenu();
		// pido opcion de menu a usuario y la guardo en mi variable opcion
		utn_getNumeroInt(&opcion, "\nIngrese opcion", "\nOpcion no valida", 1, 5, 1);

		do
		{
			switch(opcion)
			{
			case 1:
				id = createID();
				if(utn_getChar(nombre, "\nIngrese su nombre: ", "nombre invalido", LEN_EMPLEADOS, 1)==0 &&
					utn_getChar(apellido, "\nIngrese su apellido: ", "apellido invalido", LEN_EMPLEADOS, 1)==0 &&
					utn_getNumeroFlotante(&salario, "\nIngrese su salario ", "Error, salario invalido", 100, 1000000, 1)==0 &&
					utn_getNumeroInt(&sector, "\nIngrese sector ", "Error, sector invalido", 1, 3, 1) == 0)
				{
					if(addEmpleado(empleados, LEN_EMPLEADOS, id, nombre, apellido, salario, sector)==0)
					{
						banderaEmpleado++;
						printf("Empleado cargado existosamente");

					}
					else
						if(addEmpleado(empleados, LEN_EMPLEADOS, id, nombre, apellido, salario, sector)== -2)
						{
							printf("\nNo existe lugar disponible para dar de alta un empleado------");
						}
						else
						{
							printf("\nError, revise los datos ingresados-----------------------------");
						}
				}
			break;

			case 2:
				if(banderaEmpleado>0)
				{
					imprimirEmpleados(empleados, LEN_EMPLEADOS);

					if(utn_getNumeroInt(&idaModificar, "\nIngrese ID a modificar", "\nID no valido", 1000, 2000, 1)==0)
					{
						if(modifyEmpleado(empleados, LEN_EMPLEADOS, idaModificar)==0)
						{
							printf("\nLa modificacion se realizo con exito");
						}
						else
						{
							if(modifyEmpleado(empleados, LEN_EMPLEADOS, idaModificar)==-2)
							{
								printf("\nID inexistente----------------------------------------");
							}
							else
							{
								printf("\nError. No se pudo modificar el empleado----------------");
							}
						}
					}
					else
					{
						printf("\nOcurrio un error. Revise los datos ingresados-------------------");
					}
				}
				else
				{
					printf("\nNo existe id a modificar--------------------------------------------");
					break;
				}

			break;

			case 3:
				if(banderaEmpleado>0)
				{
					if(utn_getNumeroInt(&idaDarDeBaja, "\nIngrese ID a dar de baja", "\nError, id no valido", 1000, 2000, 1)==0)
					{
						if(removeEmpleado(empleados, LEN_EMPLEADOS, idaDarDeBaja)==0)
						{
							banderaEmpleado--;
							printf("\nEmpleado dado de baja exitosamente");
						}
						else
						{
							if(removeEmpleado(empleados, LEN_EMPLEADOS, idaDarDeBaja)==-2)
							{
								printf("\nError, no se encuentra el id indicado---------------------------");
							}
						}
					}
					else
					{
						printf("\nError, revise los datos-----------------------------------------------");
					}


				}
				else
				{
					printf("\nNo existe id a dar de baja-------------------------------------------");
					break;
				}
			break;

			case 4:
				if(banderaEmpleado>0)
				{
					utn_getNumeroInt(&ordenamiento, "\nComo quiere ordenar? -> 0-Descendente/1-Ascendente ", "\nOpcion no valida", 0, 1, 1);
					if(sortEmployee(empleados, LEN_EMPLEADOS, ordenamiento)==0)
					{
						imprimirEmpleados(empleados, LEN_EMPLEADOS);
						informacionSalario(empleados, LEN_EMPLEADOS, &totalSalarios, &promedioSalarios, &salariosPorEncima);
						printf("\nTotal Salarios: %d \nPromedio Salarios: %.2f \nEmpleados por encima del promedio: %d",totalSalarios,promedioSalarios,salariosPorEncima);
					}
					else
					{
						printf("\nOcurrio un error!--------------------------------------------------");
					}
				}
				else
				{
					printf("\nNo existen empleados cargados para mostrar----------------------------");
					break;
				}
				break;

			case 5:

				printf("\nADIOS!");
				break;

			default:
				printf("\nOpcion no valida---------------------------------------------------------");


			} //FIN DEL SWITCH

		}while(opcion != 5);

} //FIN DEL MENU


// FUNCION DE MENU
void mostrarMenu(void)
{
	puts("-------------------------------------------------------");

	puts("Bienvenido! Seleccione opcion a realizar\n\n");
	puts("1) Alta para nuevo empleado");
	puts("\n2) Modificar un empleado");
	puts("\n3) Dar de baja un empleado");
	puts("\n4) Informes");
	puts("\n5) Salir");

	puts("-------------------------------------------------------\n");

} //FIN

