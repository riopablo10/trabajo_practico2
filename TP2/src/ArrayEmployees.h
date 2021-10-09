/*
 * ArrayEmployees.h
 *
 *  Created on: 9 oct. 2021
 *      Author: Furya
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int id;
	char name[51];
	char apellido[51];
	float salario;
	int sector;
	int isEmpty;
}Empleado;


int initEmpleados (Empleado* list, int len);

void imprimirEmpleados(Empleado* list, int len);

int addEmpleado (Empleado* list, int len, int id, char name[], char apellido[], float salario, int sector);

int utn_getNumberInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

static int esNumerica(char* cadena);

static int myGets(char pResultado[], int len);

#endif /* ARRAYEMPLOYEES_H_ */
