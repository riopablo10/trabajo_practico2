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
#include "jupiter.h"

#define LEN_NOMBREAPELLIDO 51

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
int findEmptyPosition(Empleado* list, int len);
int modifyEmpleado (Empleado* list, int len, int id);
void mostrarSubMenu(void);
int sortEmployee(Empleado* list, int len, int order);
int removeEmpleado (Empleado* list, int len, int id);
int informacionSalario( Empleado* list, int len, int* totalSalarios, float* promedioSalarios, int* empleadosPorEncimaPromedio);

#endif /* ARRAYEMPLOYEES_H_ */
