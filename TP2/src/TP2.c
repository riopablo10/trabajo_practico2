/*
 ============================================================================
 Name        : TP2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#define LEN_EMPLEADO 5


int main(void) {

	setbuf(stdout, NULL);

	//Empleado empleados[LEN_EMPLEADO];


/*
 * 	if(initEmpleados(empleados, LEN_EMPLEADO)==0)
	{
		printf("\n\nSe inicializaron los empleados");
		imprimirEmpleados(empleados, LEN_EMPLEADO);
	}

	printf("\n\nIngresando Empleado automaticamente");

	addEmpleado(empleados, LEN_EMPLEADO, 001 , "Pablo", "Rio", 20000, 2);

	imprimirEmpleados(empleados, LEN_EMPLEADO);
 *
 * */

	iniciarMenu();



	return EXIT_SUCCESS;
}
