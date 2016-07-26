/* Autores: Argenis Chang, Vicente Santacoloma
 * Carnet: 08-10220, 08-11044
 * Fecha: 29-01-2011
 * Contenido: Funciones para verificar si es arbol y funcion para recorrer todo el arbol por todos los caminos.
 *	      La funcion es_Arbol se asegura de que haya una unica raiz, no hayan dos caminos al mismo nodo y
 *            haya una unica secuencia de arcos desde el nodo raiz hasta cualquier otro nodo del arbol.
 *            La funcion DFS es un algoritmos que se implemento para recorrer todos los caminos que hay en el 
 *            arbol.
 */

#include <stdio.h>
#include <stdlib.h>
#include "Arbol.h"
#include "Lista.h"
#define FALSE 0
#define TRUE 1

/* Funcion que se encarga de verificar si es arbol o no 
 * Parametros de entrada: Apuntador al arbol 
 * Parametro de retorno: True / False 
 */
int es_Arbol (struct Lista *arbol) {

  struct Vertice *raiz = NULL;
  struct Lista *aux = arbol; 
  int tmp = FALSE;
  int esArbol = 0;

  while (arbol != NULL) {

    struct Vertice *v = arbol->data;
    if((v->gradoInterno == 0 && tmp!=FALSE) || ((v->gradoInterno)>1)) {

      return esArbol;

    }
    else if (v->gradoInterno == 0) 	{

      tmp = TRUE;
      raiz = v;

    }
    arbol = arbol->next;
  }
  
  if (raiz == NULL) {
      
    return FALSE;
    
  }
  
  if (_DFS(raiz) == Lista_Tam(aux)-1) {

    esArbol = 1;
  }
  
  return esArbol;

}

/* Funcion que se encarga de recorrer el arbol 
 * Parametros de entrada: Apuntador a la raiz del arbol
 * Parametro de retorno: Numero de nodos en el arbol 
 */
int _DFS (struct Vertice *raiz) {
  
   struct Lista *nodos = NULL;
   int numnodos = 0;
   
   Lista_Add_Direct(&nodos,raiz);
   
   while (nodos != NULL) {
     
      struct Vertice *aux = nodos->data;
      Lista_Remove_First(&nodos);
      
      struct Lista *suc = aux->suc;
      
      while (suc != NULL) {
	
	Lista_Add_Direct(&nodos,suc->data);
	numnodos++;
	suc = suc->next;
	
      }
     
   }

   return numnodos;
  
}

