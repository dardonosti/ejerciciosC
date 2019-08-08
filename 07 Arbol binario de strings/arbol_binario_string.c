#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbol_binario_string_prot.h"

void inserta(arbol **A, char p[]) {
  if (*A == NULL) {
    *A = (arbol*)malloc(sizeof(arbol));
    strcpy((*A)->dato,p);
    (*A)->h_izq = NULL;
    (*A)->h_der = NULL;
  } else {
    if (strcmp(p,(*A)->dato) < 0) {
      inserta(&((*A)->h_izq), p);
    } else if (strcmp(p,(*A)->dato) > 0) {
        inserta(&((*A)->h_der), p);
    }
  }
}

int es_miembro(arbol *A, char p[]) {
  if (A == NULL) {
    return -1;
  } else if (strcmp((A)->dato,p) == 0) {
    return 1;
  } else if (strcmp((A)->dato,p) > 0) {
    return es_miembro(A->h_izq, p);
  } else {
    return es_miembro(A->h_der, p);
  }
}

char* suprime_min(arbol **A, char v_ref[]) {
  if ((*A)->h_izq == NULL) {
    strcpy(v_ref,(*A)->dato);
    arbol *tmp = *A;
    *A = (*A)->h_der;
    free(tmp);
    return v_ref;
  } else {
    return suprime_min(&((*A)->h_izq), v_ref);
  }
}

void suprime(arbol **A, char p[], char v_ref[]) {
  if (*A != NULL) {
    if (strcmp((*A)->dato,p) > 0) {
      suprime(&((*A)->h_izq), p, v_ref);
    } else if (strcmp((*A)->dato,p) < 0) {
      suprime(&((*A)->h_der), p, v_ref);
    } else if ((*A)->h_izq == NULL && (*A)->h_der == NULL) {
      arbol *tmp = *A;
      *A = NULL;
      free(tmp);
    } else if ((*A)->h_izq == NULL) {
      arbol *tmp = *A;
      *A = (*A)->h_der;
      free(tmp);
    } else if ((*A)->h_der == NULL) {
      arbol *tmp = *A;
      *A = (*A)->h_izq;
      free(tmp);
    } else {
      strcpy((*A)->dato,suprime_min(&((*A)->h_der), v_ref));
    }
  }
}

void preOrden(arbol *A) {
  if (A != NULL) {
    printf("%s ", A->dato);
    preOrden(A->h_izq);
    preOrden(A->h_der);
  }
}

void inOrden(arbol *A) {
  if (A != NULL) {
    inOrden(A->h_izq);
    printf("%s ", A->dato);
    inOrden(A->h_der);
  }
}

void postOrden(arbol *A) {
  if (A != NULL) {
    postOrden(A->h_izq);
    postOrden(A->h_der);
    printf("%s ", A->dato);
  }
}

int menu(arbol **raiz, char v_ref[]) {
  int opcion;
  char p[50];
  do {
      printf("\n");
      printf("1. Ingresar\n");
      printf("2. Eliminar\n");
      printf("3. Es miembro?\n");
      printf("4. Listar In-Orden\n");
      printf("5. Listar Pre-Orden\n");
      printf("6. Listar Post-Orden\n");
      printf("7. Salir\n");
      printf("\nIngrese opción: ");
      scanf("%d", &opcion);
      printf("\n");
  } while (opcion < 1 && opcion > 7);

  switch(opcion) {
      case 1: printf("Ingrese palabra: ");
              scanf("%s", p);
              while(getchar() != '\n');
              inserta(raiz, p);
              menu(raiz, v_ref);
              break;

      case 2: printf("Ingrese palabra a eliminar: ");
              scanf("%s", p);
              while(getchar() != '\n');
              suprime(raiz, p, v_ref);
              menu(raiz, v_ref);
              break;

      case 3: printf("Ingrese palabra a buscar: ");
              scanf("%s", p);
              while(getchar() != '\n');
              if(es_miembro(*raiz, p) == 1) {
                printf("\nEl elemento buscado existe en el árbol.\n");
              } else {
                printf("\nEl elemento buscado no existe.\n");
              }
              menu(raiz, v_ref);
              break;

      case 4: inOrden(*raiz);
              printf("\n");
              menu(raiz, v_ref);
              break;

      case 5: preOrden(*raiz);
              printf("\n");
              menu(raiz, v_ref);
              break;
              
      case 6: postOrden(*raiz);
              printf("\n");
              menu(raiz, v_ref);
              break;

      case 7: return 0;
              break;

      default: break;
  }
  return 0;
}

int main(int argc, char const *argv[]) {
  arbol *raiz;
  raiz = NULL;
  char v_ref[50];

  menu(&raiz, v_ref);

  return 0;
}
