/* Autores: Argenis Chang, Vicente Santacoloma
 * Carnet: 08-10220, 08-11044
 * Fecha: 29-01-2011
 * Contenido: Funciones para agregar elementos a la lista, verificacion si ya se encuentra el elemento o no,
 *            para remover el primer elemento de la lista, contador para el tamano de la lista y la 
 *            impresion de los elementos de la lista.
 */

#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

/* Funcion que se encarga de verificar si el elemento esta o no en la lista 
 * Parametros de entrada: Apuntador a lista, Nodo
 * Parametro de retorno: apuntador al elemento en caso de estar ya en la lista. En otro caso devuelve NULL  
 */
struct Vertice * _Lista_Add_Aux (struct Lista *p, struct Vertice* i) {

  struct Vertice *x = NULL;

  while (p != NULL) {

    if (((p->data)->id) == (i->id)) {

      x = (p->data);
      return x;

    }
    
    p = p->next;
    
  }
  return x;

}

/* Funcion que se encarga de agregar elementos a la lista utilizando una funcion auxiliar
   para verificar si esta o no ya el elemento.
 * Parametros de entrada: Apuntador a apuntador de lista, Nodo
 * Parametro de retorno: apuntador al ultimo elemento agregado
 */
struct Vertice *Lista_Add (struct Lista **p, struct Vertice *i) {

  struct Vertice *x = NULL;

  if (*p == NULL) {

    struct Lista *n = (struct Lista*)malloc(sizeof(struct Lista));
    n->data = i;
    n->next = NULL;
    *p = n;
    x = i;	

  }
  else {
  
    x = _Lista_Add_Aux(*p,i);
    
    if (x == NULL) {
      
      struct Lista *n = (struct Lista*)malloc(sizeof(struct Lista));
      n->data = i;
      n->next = *p;
      *p = n;
      x = i;
      
    }
    else {
      free(i);
    }
    
  }

  return x;
}

/* Funcion que se encarga de agregar elementos a la lista sin verificar si esta o no
 * Parametros de entrada: Apuntador a apuntador de lista, Nodo
 * Parametro de retorno: Ninguno 
 */
void	Lista_Add_Direct (struct Lista **p , struct Vertice *i) {
	
  struct Lista *n = (struct Lista*)malloc(sizeof(struct Lista));

  n->data = i;
  n->next = NULL;
  if (*p == NULL) {
    
    *p = n;
    
  }
  else {
    
    n->next = *p;
    *p = n;
    
  }
  
}

/* Funcion que se encarga de remover el primer elemento del arbol
 * Parametros de entrada: Apuntador a apuntador de lista
 * Parametro de retorno: Ninguno 
 */
void 	Lista_Remove_First (struct Lista **p) {
  
  struct Lista *aux = *p;
  
  *p = (*p)->next;
  aux->next = NULL;
  
}

/* Funcion que se encarga de agregar nodos al arbol
 * Parametros de entrada: Apuntador a la lista 
 * Parametro de retorno: tamano de la lista 
 */
int 	Lista_Tam (struct Lista *l) {

  int k = 0;

  while (l !=NULL) {

    l = l->next;
    k++;

  }

  return k;

}

/* Funcion que se encarga de imprimir los elementos de la lista 
 * Parametros de entrada: Apuntador a la lista 
 * Parametro de retorno: Ninguno 
 */
void 	Lista_Print (struct Lista *l) {
	
  if (l == NULL) {
    
    printf("La lista esta vacia\n");
    
  }
  
  while (l != NULL) {
    
    printf("%d %d",(l->data)->id,(l->data)->gradoInterno);
    printf(" ");
    l = l->next;	
    
  }
  
  printf("\n");
}


