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

static int myGets(char pResultado[], int len)
{
    int retorno=-1;
    int indexFinal;


    //gets(pResultado); // NOOOOOOO
    //if(scanf("%s", pResultado)==1) // NOOOOOOO
    if(pResultado != NULL && len>0)
    {
    	 fflush(stdin);
        if(fgets(pResultado,len,stdin)!=NULL)
        {
            // borro el \n del final
            indexFinal = strlen(pResultado)-1;
            if(pResultado[indexFinal] == '\n')
            {
                pResultado[indexFinal] = '\0';
            }
            retorno = 0;
        }
    }

    return retorno;
}


static int getInt (int* pResultado)
{
	int retorno = -1;
	char aux[1024];

	if(pResultado != NULL)
	{
		if(myGets(aux, sizeof(aux))==0 && esNumerica (aux))
			{
				retorno = 0;
				*pResultado = atoi(aux);
			}
	}

	return retorno;
}

static int esNumerica(char* cadena)
{
	int retorno = 1; //verdadero (devuelve un numero)
	int i=0;

	if(cadena[0]=='-')
	{
		i=1;
	}

	for(; cadena[i] != '\0'; i++)
	{

		if(cadena[i]<'0' || cadena[i]>'9')
		{
			retorno = 0; //no es un numero
			break;
		}
	}

	return retorno;
}



int utn_getNumberInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int aux;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin);

			if(getInt(&aux) == 0 && aux>=minimo && aux <= maximo)
			{
				*pResultado = aux;
				retorno = 0;
				break;
			}//fin de maximos
			else
			{
				printf("%s", mensajeError);
				reintentos --;
			}

		}while (reintentos >= 0);

	} //FIN DEL IF VALIDACION

	return retorno;
} //FIN FUNCIOM


int initEmpleados (Empleado* list, int len)
{
	int retorno = -1;
	Empleado emp_auxiliar;

	if(list != NULL && len>=0)
	{
		retorno = 0;
		for(int i=0; i<len;i++)
			{
				emp_auxiliar = list[i];
				emp_auxiliar.isEmpty=0; //VACIO
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

void imprimirEmpleados (Empleado* list, int len){

	for(int i=0; i<len; i++){
		printf("\nEmpleado %d:", i);
		printf("\nid: %d - apellido: %s - name: %s - salario: %.2f - sector:%d - isEmpty: %d", list[i].id,list[i].apellido,list[i].name,list[i].salario,list[i].sector,list[i].isEmpty);

	}

}



int addEmpleado (Empleado* list, int len, int id, char name[], char apellido[], float salario, int sector)
{
	int retorno = -1; //ERROR
	Empleado empleado;

	if(list != NULL && len >=0 && id>=0 && name != NULL && apellido != NULL && salario>=1000 && sector > 0 ){
		for(int i=0; i<len;i++)
		{
			if(list[i].isEmpty == 0)
			{
				empleado.id = id;
				strncpy(empleado.name,name,51);
				empleado.isEmpty = 1;
				strncpy(empleado.apellido,apellido,51);
				empleado.salario = salario;
				empleado.sector = sector;
				retorno = 0; //OK
				list[i]=empleado;
				break;
			}
		}
	}

	return retorno;
}


int findEmployeeById(Empleado* list, int len,int id)
{
	int retorno =-1;
	int i;

	if(list != NULL && len>= 0 && id>=0){

		for(i=0; i<len; i++){

			if(list[i].id == id){

				retorno = i;
				break;
			}
		}

	}

	return retorno;
}
