/* Autores: Argenis Chang, Vicente Santacoloma
 * Carnet: 08-10220, 08-11044
 * Fecha: 29-01-2011
 * Contenido: Declaracion de funciones que se utilizan en el archivo Arbol.c
 */

#ifndef ARBOL
#define ARBOL
#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

void	Arbol_Add (struct Lista **, struct Vertice *, struct Vertice *);
void	Arbol_Print (struct Lista *);
void 	Arbol_Free(struct Lista*);

#endif 