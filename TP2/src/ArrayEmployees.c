/*s
 * ArrayEmployees.c
 *
 *  Created on: 9 oct. 2021
 *      Author: Furya
 */
#include "ArrayEmployees.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "jupiter.h"

#define LIBRE 0
#define OCUPADO 1



/// @param list
/// @param len
/// @return
int initEmpleados (Empleado* list, int len)
{
	int retorno = -1;
	Empleado emp_auxiliar; //genero una cadena auxiliar para eliminar la basura del buffer

	if(list != NULL && len>=0)
	{
		retorno = 0;
		for(int i=0; i<len;i++)
			{
				emp_auxiliar = list[i];
				emp_auxiliar.isEmpty=0; //DEJO EL FLAG EN VACIO (ESPACIO LIBRE)
				strncpy(emp_auxiliar.apellido,"\0",1);
				emp_auxiliar.id=0;
				strncpy(emp_auxiliar.name,"\0",1);
				emp_auxiliar.salario=0;
				emp_auxiliar.sector=0;
				list[i]=emp_auxiliar;
			}
	}

	return retorno;
}


/// @param list
/// @param len

void imprimirEmpleados (Empleado* list, int len){

	for(int i=0; i<len; i++){
		printf("\n\nEmpleado %d:", i);
		printf("\nid: %d - apellido: %s - name: %s - salario: %.2f - sector:%d - isEmpty: %d", list[i].id,list[i].apellido,list[i].name,list[i].salario,list[i].sector,list[i].isEmpty);

	}

}


/// @param list
/// @param len
/// @param id
/// @param name
/// @param apellido
/// @param salario
/// @param sector
/// @return
int addEmpleado (Empleado* list, int len, int id, char name[], char apellido[], float salario, int sector)
{
	int retorno = -1; //ERROR
	int indexVacio;

	if(list != NULL && len >=0 && id>=0 && name != NULL && apellido != NULL && salario>=1000 && sector > 0 && sector < 3 )
	{

		indexVacio = findEmptyPosition(list, len);
		if(indexVacio >= 0)
		{
			list[indexVacio].id= id;
			strncpy(list[indexVacio].name,name,sizeof(list->name));
			strncpy(list[indexVacio].apellido,name,sizeof(list->apellido));
			list[indexVacio].salario = salario;
			list[indexVacio].sector = sector;
			list[indexVacio].isEmpty = OCUPADO;
			retorno = 0;
		}
		else
		{
			if(indexVacio == -2)
			{
				retorno = -2;
			}
		}



	}

	return retorno;
}

/// @param list
/// @param len
/// @param id
/// @return
int findEmployeeById(Empleado* list, int len,int id)
{
	int retorno =-1;
	int i;

	if(list != NULL && len>= 0 && id>=0){
		retorno = -2;
		for(i=0; i<len; i++){

			if(list[i].id == id && list[i].isEmpty == 1){

				retorno = i;
				break;
			}
		}

	}

	return retorno;
}

/// Busca posicion libre en el array
/// @param list: array de la estructura
/// @param len: tamaño del array
/// @param pEmptyPosition: puntero que recibe la posicion libre de mi array.
/// @return Retorna un [-1] si hay algun error; un [-2] si los parametros son correctos, pero no pudo recorrer el array; el index vacio si esta todo bien y encontro la posicion libre
///
int findEmptyPosition(Empleado* list, int len) //BUSCA UNA POSICION LIBRE/VACIA
{
	int retorno = -1;
	int index;

	if(list != NULL && len >= 0)
	{
		retorno = -2;
		for(index = 0; index < len; index++)
		{
			if(list[index].isEmpty == LIBRE)
			{
				retorno = index;
				break;
			}
		}
	}

	return retorno;
}

void mostrarSubMenu(void)
{
	puts("-------------------------------------------------------");

		puts("MENU DE MODIFICACION: \n\n");
		puts("1) Nombre\n");
		puts("\n2) Apellido\n");
		puts("\n3) Salario\n");
		puts("\n4) Sector\n");
		puts("\n5) Salir\n");

		puts("-------------------------------------------------------\n");
}


int modifyEmpleado (Empleado* list, int len, int id)
{
	int retorno = -1; //ERROR
	int indiceAModificar;
	Empleado auxEmpleado;
	int opcionSubMenu;

	if(list != NULL && len >=0 && id>=0 )
	{
		indiceAModificar = findEmployeeById(list, len, id); //Me va a retornar un indice si esta todo bien, mayor a 1 y lo evaluo en mi proximo if

		if (indiceAModificar >= 0 && list[indiceAModificar].isEmpty==OCUPADO ) //ENCONTRE ID E INDICE OCUPADO A MODIFICAR
		{
			do
			{
				mostrarSubMenu();
				utn_getNumeroInt(&opcionSubMenu, "Indique campo a modificar", "Error, opcion no valida", 1, 5, 1);

				switch(opcionSubMenu)
				{
					case 1:
						if(utn_getDescripcion(auxEmpleado.name, "\nIngrese nombre a modificar", "\nError", LEN_NOMBREAPELLIDO, 1)==0)
						{
							retorno = 0;
							strncpy(list[indiceAModificar].name,auxEmpleado.name,sizeof(list[indiceAModificar].name));
						}
						break;

					case 2:
						if(utn_getDescripcion(auxEmpleado.apellido, "\nIngrese apellido a modificar", "\nError", LEN_NOMBREAPELLIDO, 1)==0)
						{
							retorno = 0;
							strncpy(list[indiceAModificar].apellido,auxEmpleado.apellido,sizeof(list[indiceAModificar].apellido));
						}
						break;

					case 3:
						if(utn_getNumeroFlotante(&auxEmpleado.salario, "\nIngrese Salario a modificar", "\nError, salario invalido", 100, 10000000, 1)==0)
						{
							retorno = 0;
							list[indiceAModificar].salario = auxEmpleado.salario;
						}
						break;

					case 4:
						if(utn_getNumeroInt(&auxEmpleado.sector, "\nIngrese sector a modificar", "\nError, sector invalido", 1, 3, 1)==0)
						{
							retorno = 0;
							list[indiceAModificar].sector = auxEmpleado.sector;
						}
						break;

				} //FIN DEL SWITCH

			}while(opcionSubMenu != 5);

		}
		else
		{
			if(indiceAModificar == -2)
			{
				retorno = -2;
			}
		}

	}

	return retorno;
}

int removeEmpleado (Empleado* list, int len, int id)
{
	int retorno = -1; //ERROR
	int indiceADarDeBaja;

	if(list != NULL && len >=0 && id>=0 )
	{
		indiceADarDeBaja = findEmployeeById(list, len, id);

		if(indiceADarDeBaja >=0 && list[indiceADarDeBaja].isEmpty == OCUPADO)
		{
			list[indiceADarDeBaja].isEmpty = LIBRE;
			retorno = 0;
		}
		else
		{
			if(indiceADarDeBaja == -2)
			{
				retorno = -2;
			}
		}

	}

	return retorno;
}

int sortEmployee(Empleado* list, int len, int order)
{
	int retorno=-1;
	int flagSwap;
	int i;
	Empleado bufferEmpleado;
	int auxiliarCmp;

	if(list!=NULL && len>=0 && (order==0 ||order==1 ))
	{
		switch(order)
		{
			case 0:
				do
				{
					flagSwap=0;
					for(i=0;i<len-1;i++)
					{
						if(list[i].isEmpty==1||list[i+1].isEmpty==1)
						{
							continue;
						}
						auxiliarCmp=strncmp(list[i].apellido,list[i+1].apellido,len);
						if(auxiliarCmp<0 ||(auxiliarCmp==0 && list[i].sector<list[i+1].sector))
						{
							flagSwap=1;
							bufferEmpleado=list[i];
							list[i]=list[i+1];
							list[i+1]=bufferEmpleado;
						}
					}
					len--;
				}while(flagSwap==1);

				retorno=0;
				break;

				case 1:
					do
					{
						flagSwap=0;
						for(i=0;i<len-1;i++)
						{
							if(list[i].isEmpty==1||list[i+1].isEmpty==1)
							{
								continue;
							}
							auxiliarCmp=strncmp(list[i].apellido,list[i+1].apellido,len);
							if(auxiliarCmp>0 ||(auxiliarCmp==0 && list[i].sector>list[i+1].sector))
							{
								flagSwap=1;
								bufferEmpleado=list[i];
								list[i]=list[i+1];
								list[i+1]=bufferEmpleado;
							}
						}
						len--;
					}while(flagSwap==1);

					retorno=0;
					break;
		}
	}
	return retorno;
}


int informacionSalario( Empleado* list, int len, int* totalSalarios, float* promedioSalarios, int* empleadosPorEncimaPromedio)
{
	int retorno = -1;
	int contadorSalarios = 0;
	int contadorSalariosPorEncima = 0;
	int acumuladorSalarios = 0;
	float auxPromedio;
	int i;

	if(list != NULL && len>=0)
	{
		for(i = 0; i<len;i++)
		{
			if(list[i].isEmpty==OCUPADO)
			{
				acumuladorSalarios = acumuladorSalarios + list[i].salario;
				contadorSalarios++;
			}
		}
		*totalSalarios = acumuladorSalarios;
		auxPromedio = acumuladorSalarios/contadorSalarios;
		*promedioSalarios = auxPromedio;

		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==OCUPADO)
			{
				if(list[i].salario>auxPromedio)
				{
					contadorSalariosPorEncima++;
				}
			}
		}
		*empleadosPorEncimaPromedio = contadorSalariosPorEncima;

		retorno = 0;
	}



	return retorno;
}
