/* Autores: Argenis Chang, Vicente Santacoloma
 * Carnet: 08-10220, 08-11044
 * Fecha: 29-01-2011
 * Contenido: Declaracion de las estructuras Vertice y Lista.
	      Los vertices contienen tres campos:
	        o ID: campo en donde introducimos el elemento.
	        o GradoInterno: definimos la raiz con grado 0 y sucesores con grado 1. Cualquier otro grado hace que no sea arbol.
	        o Sucesor: campo donde se encuentra el apuntador al nodo sucesor.
	      La lista es una lista de nodos.
 */

#ifndef LISTA
#define LISTA
#include <stdio.h>
#include <stdlib.h>

struct Vertice {
  
  int id;
  int gradoInterno;
  struct Lista *suc;
  
};

struct Lista {

  struct Vertice *data;
  struct Lista *next;

};

struct Vertice * _Lista_Add_Aux (struct Lista *, struct Vertice*);
struct Vertice *Lista_Add (struct Lista **, struct Vertice *);
void	Lista_Add_Direct (struct Lista **, struct Vertice *);
void 	Lista_Remove_First (struct Lista **);
int 	Lista_Tam (struct Lista *);
void 	Lista_Print (struct Lista *);

#endif

