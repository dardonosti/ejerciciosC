#include <stdio.h>
#include <stdlib.h>
#include "pila_din_prot.h"

spila *pila;

void crearPila(spila** p) {
  p = NULL;
}

int estaVacia(spila* p) {
  if(p == NULL) {
    return 0;
  }
  return 1;
}

void ingresar(spila** p, int x) {
  spila* nueva;
  nueva = (spila*)malloc(sizeof(spila));
  if (nueva == NULL) {
    printf("Error no se pudo reservar memoria\n");
    exit(-1);
  } else {
    nueva->sig = *p;
    nueva->id = x;
    *p = nueva;
  }
}

int eliminar(spila** p) {
  spila* aux;

  if(estaVacia(*p) == 0) {
    printf("\n\t #Pila vacía\n");
    return 0;
  }
  aux = (*p);
  (*p) = (*p)->sig;
  free(aux);
}

void primerelemento(spila* p) {
  if(estaVacia(p) == 0) {
    printf("\n\t #Pila vacía\n");
  } else {
    printf("\n\t #id: %d\n", p->id);
  }
}

void imprimir(spila* p) {
  if(estaVacia(p) == 0) {
    printf("\n\t #Pila vacía\n");
  } else {
    printf("\n");
    while(p != NULL) {
      printf("\t #id: %d\n", p->id);
      p = p->sig;
    }
  }
}

void vaciarpila(spila** p) {
  if(estaVacia(*p) == 0) {
    printf("\n\t #Pila vacía\n");
  } else {
    spila *aux;
    while(estaVacia(*p) != 0) {
      aux = (*p);
      (*p) = (*p)->sig;
      free(aux);
    }
  }
}

void tamanio(spila *p) {
  if(estaVacia(p) == 0) {
    printf("\n\t #Pila vacía\n");
  } else {
    int cont = 0;
    while(p != NULL) {
      cont++;
      p = p->sig;
    }
    printf("\n\t #Cantidad de elementos: %d\n", cont);
  }
}

void cargar(spila** p) {
  int a;
  do {
    printf("\t #Ingresar id (0 salir): ");
    scanf("%d", &a);
    if (a != 0) {
      ingresar(&pila, a);
    }
  } while (a != 0);
}

int menu() {
  int op;

    printf("\n");
    printf("1. Apila\n");
    printf("2. Desapila\n");
    printf("3. Mostrar primer elemento\n");
    printf("4. Imprimir todos los elementos\n");
    printf("5. Vaciar Pila\n");
    printf("6. Hay elementos?\n");
    printf("7. Salir\n");
    printf("\nIngrese opción: ");
    scanf("%d", &op);

  switch(op) {
    case 1: cargar(&pila);
            menu();
            break;
    case 2: eliminar(&pila);
            menu();
            break;
    case 3: primerelemento(pila);
            menu();
            break;
    case 4: imprimir(pila);
            menu();
            break;
    case 5: vaciarpila(&pila);
            menu();
            break;
    case 6: tamanio(pila);
            menu();
            break;
    case 7: return 0;
    default:
            break;
  }
  return 0;
}

int main(int argc, char const *argv[]) {

  crearPila(&pila);
  menu();

  return 0;
}
