#include <stdio.h>
#include <stdlib.h>
#include "arbol_binario_enteros_prot.h"

void inserta(arbol **A, int x) {
  if (*A == NULL) {
    *A = (arbol*)malloc(sizeof(arbol));
    (*A)->dato = x;
    (*A)->h_izq = NULL;
    (*A)->h_der = NULL;
  } else {
    if (x < (*A)->dato) {
      inserta(&((*A)->h_izq), x);
    } else if (x > (*A)->dato) {
        inserta(&((*A)->h_der), x);
    }
  }
}

int es_miembro(arbol *A, int x) {
  if (A == NULL) {
    return -1;
  } else if (A->dato == x) {
    return 1;
  } else if (A->dato > x) {
    return es_miembro(A->h_izq, x);
  } else {
    return es_miembro(A->h_der, x);
  }
}

int suprime_min(arbol **A) {
  int v_ref;
  if ((*A)->h_izq == NULL) {
    v_ref = (*A)->dato;
    arbol *tmp = *A;
    *A = (*A)->h_der;
    free(tmp);
    return v_ref;
  } else {
    return suprime_min(&((*A)->h_izq));
  }
}

void suprime(arbol **A, int x) {
  if (*A != NULL) {
    if (x < (*A)->dato) {
      suprime(&((*A)->h_izq), x);
    } else if (x > (*A)->dato) {
      suprime(&((*A)->h_der), x);
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
      (*A)->dato = suprime_min(&((*A)->h_der));
    }
  }
}

void preOrden(arbol *A) {
  if (A != NULL) {
    printf("%d ", A->dato);
    preOrden(A->h_izq);
    preOrden(A->h_der);
  }
}

void inOrden(arbol *A) {
  if (A != NULL) {
    inOrden(A->h_izq);
    printf("%d ", A->dato);
    inOrden(A->h_der);
  }
}

void postOrden(arbol *A) {
  if (A != NULL) {
    postOrden(A->h_izq);
    postOrden(A->h_der);
    printf("%d ", A->dato);
  }
}

int menu(arbol **raiz) {
  int opcion;
  int d;
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
      case 1: printf("Ingrese número: ");
              scanf("%d", &d);
              inserta(raiz, d);
              menu(raiz);
              break;

      case 2: printf("Ingrese número a eliminar: ");
              scanf("%d", &d);
              suprime(raiz, d);
              menu(raiz);
              break;

      case 3: printf("Ingrese número a buscar: ");
              scanf("%d", &d);
              if(es_miembro(*raiz, d) == 1) {
                printf("\nEl elemento buscado existe en el árbol.\n");
              } else {
                printf("\nEl elemento buscado no existe.\n");
              }
              menu(raiz);
              break;

      case 4: inOrden(*raiz);
              printf("\n");
              menu(raiz);
              break;

      case 5: preOrden(*raiz);
              printf("\n");
              menu(raiz);
              break;

      case 6: postOrden(*raiz);
              printf("\n");
              menu(raiz);
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

  menu(&raiz);

  return 0;
}
