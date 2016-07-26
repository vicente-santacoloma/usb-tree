/* Autores: Argenis Chang, Vicente Santacoloma
 * Carnet: 08-10220, 08-11044
 * Fecha: 29-01-2011
 * Contenido: Funciones para devolver si es un arbol o no y funcion para la lectura de archivo.
	      La funcion Resultado utiliza la funcion esArbol para verificar si es no arbol.
	      La funcion Read es utilizado para leer el archivo de entrada y extraer la informacion.
 */

#ifndef MAIN
#define MAIN
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"
#include "Arbol.c"
#include "esArbol.c"
#define TRUE 1
#define FALSE 0

/* Funcion que se encarga de verificar si es arbol o no
 * Parametros de entrada: True / False, apuntador a lista
 * Parametro de retorno: Ninguno
 */
void	Resultado (int esArbol, struct Lista* arbol) {
  
  if (esArbol == TRUE) {
    
    esArbol = es_Arbol(arbol);
	
    if (esArbol == TRUE) {
      printf("ES UN ARBOL");
    }
    else if (esArbol == FALSE) {
      printf("NO ES UN ARBOL");
    }
  }
  else if (esArbol == FALSE) {
    printf("NO ES UN ARBOL");
  }
    
  printf("\n");
  
}

/* Funcion que se encarga de la lectura del archivo
 * Parametros de entrada: Archivo externo
 * Parametro de retorno: Ninguno
 */
void Read (char *argv[]) {
  
  FILE *fp = fopen(argv[1],"r");
  int read1;
  int read2;
  
  while(((fscanf(fp,"%d",&read1))!=EOF && (fscanf(fp,"%d",&read2))!=EOF) && (read1!=-1 || read2!=-1)) {
    
    struct Lista* arbol = NULL;

    struct Vertice *v1 = (struct Vertice*)malloc(sizeof(struct Vertice));
    v1->id = read1;
    v1->gradoInterno = 0;
    v1->suc = NULL;

    struct Vertice *v2 = (struct Vertice*)malloc(sizeof(struct Vertice));
    v2->id = read2;
    v2->gradoInterno = 0;
    v2->suc = NULL;
    
    Arbol_Add(&arbol,v1,v2);
    
    int esArbol = 1;
    
    while((fscanf(fp,"%d",&read1))!=EOF && (fscanf(fp,"%d",&read2))!=EOF && (read1!=0 || read2!=0) && esArbol == TRUE) {
      
      v1 = (struct Vertice*)malloc(sizeof(struct Vertice));
      v1->id = read1;
      v1->gradoInterno = 0;
      v1->suc = NULL;

      v2 = (struct Vertice*)malloc(sizeof(struct Vertice));
      v2->id = read2;
      v2->gradoInterno = 0;
      v2->suc = NULL;
    
      Arbol_Add(&arbol,v1,v2);
      
    }
    
      Resultado(esArbol,arbol);  
      Arbol_Free(arbol);
    
  }
  
  
}

/* Programa principal */
int main(int argc, char *argv[]) {

  if (argc == 1) {
    printf("No se introdujo archivo");
    
  }
  else {
    Read(argv);
  }
  
}

#endif