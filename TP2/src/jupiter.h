/*
 * jupiter.h
 *
 *  Created on: 18 oct. 2021
 *      Author: Furya
 */

#ifndef JUPITER_H_
#define JUPITER_H_

int utn_getNumeroInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int utn_getChar(char* pResultado, char* mensaje, char* mensajeError, int longitud, int reintentos);

int utn_getDescripcion(char* pResultado,char* mensaje, char* mensajeError, int longitud, int reintentos);
int utn_getDni(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);

#endif /* JUPITER_H_ */
