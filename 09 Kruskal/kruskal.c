#include <stdio.h>
#include <stdlib.h>
#include "kruskal.h"

int main(int argc, char const *argv[]) {
  int M_Costos[VERTICES][VERTICES];
  int i, j;
  rama *arbol = NULL;

  for (i = 0; i <= VERTICES-1; i++) {
    for (j = i+1; j <= VERTICES-1; j++) {
      printf("Ingrese costo de lado entre vértices %d y %d: ", i, j);
      scanf("%d", &M_Costos[i][j]);
    }
  }

  for (i = 0; i <= VERTICES-1; i++) {
    for (j = i+1; j <= VERTICES-1; j++) {
      if (M_Costos[i][j] != 0) {
       inserta(i, j, M_Costos[i][j], &arbol);
      }
    }
  }

  kruskal(&arbol);

  return 0;
}

void inicial(tipo_nombre A, tipo_elemento v, conjunto_CE* C) {
  C->nombre[v].nombre_conjunto = A;
  C->nombre[v].siguiente_elemento = 0;
  C->encabezamientos_conjunto[A].cuenta = 1;
  C->encabezamientos_conjunto[A].primer_elemento = v;
}

void combina(tipo_nombre A, tipo_nombre B, conjunto_CE* C) {
  int i;
  if (C->encabezamientos_conjunto[A].cuenta > C->encabezamientos_conjunto[B].cuenta) {
    i = C->encabezamientos_conjunto[B].primer_elemento;

    while(C->nombre[i].siguiente_elemento != 0) {
      C->nombre[i].nombre_conjunto = A;
      i = C->nombre[i].siguiente_elemento;
    }

    C->nombre[i].nombre_conjunto = A;
    C->nombre[i].siguiente_elemento = C->encabezamientos_conjunto[A].primer_elemento;
    C->encabezamientos_conjunto[A].primer_elemento = C->encabezamientos_conjunto[B].primer_elemento;
    C->encabezamientos_conjunto[A].cuenta = C->encabezamientos_conjunto[A].cuenta + C->encabezamientos_conjunto[B].cuenta;
  } else {
    i = C->encabezamientos_conjunto[A].primer_elemento;

    while(C->nombre[i].siguiente_elemento != 0) {
      C->nombre[i].nombre_conjunto = B;
      i = C->nombre[i].siguiente_elemento;
    }

    C->nombre[i].nombre_conjunto = B;
    C->nombre[i].siguiente_elemento = C->encabezamientos_conjunto[B].primer_elemento;
    C->encabezamientos_conjunto[B].primer_elemento = C->encabezamientos_conjunto[A].primer_elemento;
    C->encabezamientos_conjunto[B].cuenta = C->encabezamientos_conjunto[B].cuenta + C->encabezamientos_conjunto[A].cuenta;
  }
}

tipo_nombre encuentra(int v, conjunto_CE* C) {
  return (C->nombre[v].nombre_conjunto);
}

arista sacar_min(rama** R) {
  arista A;
  rama* aux;
  A = (*R)->a;
  aux = (*R);
  (*R) = (*R)->sig;
  free(aux);
  return A;
}

void inserta(int u, int v, int c, rama** R) {
  if (*R == NULL) {
    *R = (rama*)malloc(sizeof(rama));
    (*R)->a.u = u;
    (*R)->a.v = v;
    (*R)->a.costo = c;
    (*R)->sig = NULL;
  } else {
    if ((*R)->a.costo > c) {
      rama* nueva = (rama*)malloc(sizeof(rama));
      nueva->a.u = u;
      nueva->a.v = v;
      nueva->a.costo = c;
      nueva->sig = (*R);
      (*R) = nueva;
    } else if ((*R)->a.costo < c && (*R)->sig != NULL && (*R)->sig->a.costo > c) {
      rama* nueva = (rama*)malloc(sizeof(rama));
      nueva->a.u = u;
      nueva->a.v = v;
      nueva->a.costo = c;
      nueva->sig = (*R)->sig;
      (*R)->sig = nueva;
    } else {
      inserta(u, v, c, &(*R)->sig);
    }
  }
}

void lista(rama* R) {
  if (R != NULL) {
    printf("Arista: [%d-%d] -> Costo: %d \n", R->a.u, R->a.v, R->a.costo);
    lista(R->sig);
  }
}

void libera(rama** R) {
  if (*R != NULL) {
    if ((*R)->sig != NULL) {
      libera(&((*R)->sig));
    }
    free(*R);
    (*R) = NULL;
  }
}

void kruskal(rama** R) {
  int comp_n = VERTICES;
  int comp_siguiente = 0;
  int costo_arbol = 0;
  int comp_u, comp_v, i;
  conjunto_CE* componentes = (conjunto_CE*)malloc(sizeof(conjunto_CE));
  rama* T = NULL;
  arista a;

  for (i = 0; i < VERTICES; i++) {
    comp_siguiente = comp_siguiente + 1;
    inicial(comp_siguiente, i, componentes);
  }

  while (comp_n > 1) {
    a = sacar_min(R);
    comp_u = encuentra(a.u, componentes);
    comp_v = encuentra(a.v, componentes);

    if (comp_u != comp_v) {
      combina(comp_u, comp_v, componentes);
      comp_n = comp_n - 1;
      inserta(a.u, a.v, a.costo, &T);
      costo_arbol += a.costo;
    }
  }

  printf("\nTotal del árbol abarcador de costo mínimo: %d\n\n", costo_arbol);
  lista(T);
  printf("\n");
  libera(&T);
  libera(R);
  //free(componentes);
}
