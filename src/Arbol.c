/* Autores: Argenis Chang, Vicente Santacoloma
 * Carnet: 08-10220, 08-11044
 * Fecha: 29-01-2011
 * Contenido: Funciones arbol. Entre ellos se encuentra: agregar nodos e imprimir el contenido del arbol.
 *            Ademas se implemento una funcion que se encarga de liberar el espacio de memoria que se 
 *	      utilizo para el arbol.
 */

#include <stdio.h>
#include <stdlib.h>
#include "Arbol.h"
#include "Lista.h"
#include "Lista.c"
#define FALSE 0
#define TRUE 1

/* Funcion que se encarga de agregar nodos al arbol 
 * Parametros de entrada: Apuntador a apuntador de lista, Nodo, Nodo 
 * Parametro de retorno: Ninguno 
 */
void	Arbol_Add (struct Lista **arbol, struct Vertice *nodoIn, struct Vertice *nodoOut) {

  struct Vertice *x = NULL;
  struct Vertice *y = NULL;
  

  x = Lista_Add(arbol, nodoIn);
  y = Lista_Add(arbol, nodoOut);
  y->gradoInterno++;
  Lista_Add_Direct(&(x->suc),y);
  
}

/* Funcion que se encarga imprimir todos los elementos del arbol
 * Parametros de entrada: Apuntador a lista (el que se encuentra apuntando al arbol)
 * Parametro de retorno: Ninguno 
 */
void	Arbol_Print (struct Lista *arbol) {
  
  printf("NODOS|   SUCESORES            \n");
  
  while(arbol != NULL) {
    
    struct Vertice *v = (arbol->data);
    int k = (v->id); 
    printf("%d    |       ",k);
    
    struct Lista *suc = (v->suc);
    
    while (suc!=NULL) {
      
	struct Vertice *i = (suc->data);
	int j = (i->id);
	printf("%d ",j);
	suc = suc->next;
    }
    
    printf("\n");
    arbol = (arbol->next);
      
  }
}

/* Funcion que se liberar el espacio utilizado por el arbol 
 * Parametros de entrada: Apuntador a lista (el que se encuentra apuntando al arbol)
 * Parametro de retorno: Ninguno 
 */
void 	Arbol_Free(struct Lista* arbol) {
	
  while (arbol!=NULL) {

	  free(arbol->data);
	  arbol = arbol->next;

  }

  free(arbol);

}