#include <stdio.h>
#include <stdlib.h>
#include "cola_din_prot.h"

scola *cola;
scola *colafinal;

void crearCola(scola** p) {
  p = NULL;
}

int estaVacia(scola* p) {
  if(p == NULL) {
    return 0;
  }
  return 1;
}

void ingresar(scola** p, scola** pf, int x) {
  scola* nueva;
  nueva = (scola*)malloc(sizeof(scola));
  if (nueva == NULL) {
    printf("Error no se pudo reservar memoria\n");
    exit(-1);
  }
  if (estaVacia(*pf) == 0) {
    *p = nueva;
    nueva->id = x;
    nueva->sig = *pf;
  } else {
    nueva->id = x;
    (*pf)->sig = nueva;
  }
  *pf = nueva;
  nueva->sig = NULL;
}

int eliminar(scola** p) {
  scola* aux;

  if(estaVacia(*p) == 0) {
    printf("\n\t #Cola vacía\n");
    return 0;
  }
  aux = (*p);
  (*p) = (*p)->sig;
  free(aux);
}

void primerelemento(scola* p) {
  if(estaVacia(p) == 0) {
    printf("\n\t #Cola vacía\n");
  } else {
    printf("\n\t #id: %d\n", p->id);
  }
}

void imprimir(scola* p) {
  if(estaVacia(p) == 0) {
    printf("\n\t #Cola vacía\n");
  } else {
    printf("\n");
    while(p != NULL) {
      printf("\t #id: %d\n", p->id);
      p = p->sig;
    }
  }
}

void vaciarcola(scola** p) {
  if(estaVacia(*p) == 0) {
    printf("\n\t #Cola vacía\n");
  } else {
    scola *aux;
    while(estaVacia(*p) != 0) {
      aux = (*p);
      (*p) = (*p)->sig;
      free(aux);
    }
  }
}

void tamanio(scola *p) {
  if(estaVacia(p) == 0) {
    printf("\n\t #Cola vacía\n");
  } else {
    int cont = 0;
    while(p != NULL) {
      cont++;
      p = p->sig;
    }
    printf("\n\t #Cantidad de elementos: %d\n", cont);
  }
}

void cargar(scola** p) {
  int a;
  do {
    printf("\t #Ingresar id (0 salir): ");
    scanf("%d", &a);
    if (a != 0) {
      ingresar(&cola, &colafinal, a);
    }
  } while (a != 0);
}

int menu() {
  int op;

    printf("\n");
    printf("1. Ingresar\n");
    printf("2. Eliminar\n");
    printf("3. Mostrar primer elemento\n");
    printf("4. Imprimir todos los elementos\n");
    printf("5. Vaciar Cola\n");
    printf("6. Hay elementos?\n");
    printf("7. Salir\n");
    printf("\nIngrese opción: ");
    scanf("%d", &op);

  switch(op) {
    case 1: cargar(&cola);
            menu();
            break;
    case 2: eliminar(&cola);
            menu();
            break;
    case 3: primerelemento(cola);
            menu();
            break;
    case 4: imprimir(cola);
            menu();
            break;
    case 5: vaciarcola(&cola);
            menu();
            break;
    case 6: tamanio(cola);
            menu();
            break;
    case 7: return 0;
    default:
            break;
  }
  return 0;
}

int main(int argc, char const *argv[]) {

  crearCola(&cola);
  crearCola(&colafinal);
  menu();

  return 0;
}
