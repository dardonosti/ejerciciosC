#include <stdio.h>
#include <stdlib.h>
#include "lista_dob_en_prot.h"

void insertar(int d, lista **i) {
  if (*i == NULL) {
    printf("Insertando %d en la lista\n", d);
    *i = (lista*)malloc(sizeof(lista));
    (*i)->dato = d;
    (*i)->sig = NULL;
    (*i)->ant = NULL;
  } else {
    if (d < (*i)->dato) {
      printf("Insertando %d en la lista\n", d);
      lista* nuevo = (lista*)malloc(sizeof(lista));
      nuevo->dato = d;
      nuevo->sig = *i;
      (*i)->ant = nuevo;
      nuevo->ant = NULL;
      *i = nuevo;
    } else if ((*i)->dato < d && (*i)->sig != NULL && (*i)->sig->dato > d) {
      printf("\nInsertando %d en la lista\n", d);
      lista* nuevo = (lista*)malloc(sizeof(lista));
      nuevo->dato = d;
      nuevo->sig = (*i)->sig;
      (*i)->sig->ant = nuevo;
      nuevo->ant = *i;
      (*i)->sig = nuevo;
    } else if ((*i)->dato < d && (*i)->sig == NULL) {
      printf("\nInsertando %d en la lista\n", d);
      lista* nuevo = (lista*)malloc(sizeof(lista));
      nuevo->dato = d;
      nuevo->sig = (*i)->sig;
      nuevo->ant = *i;
      (*i)->sig = nuevo;
    } else if ((*i)->dato == d) {
      printf("\nYa existe el elemento %d en la lista\n", d);
    } else {
      insertar(d, &(*i)->sig);
    }
  }
}

int estavacia(lista* i) {
  if (i == NULL) {
    return 1;
  } else {
    return 0;
  }
}

int listar(lista *i) {
  if (i != NULL) {
    printf("Dato: %d\n", i->dato);
    listar(i->sig);
  }
}

int listar_desc(lista *i) {
  while(i->sig != NULL) {
    i = i->sig;
  }
  while(i != NULL) {
    printf("Dato: %d\n", i->dato);
    i = i->ant;
  }
}

void eliminar(int d, lista** i) {
  if (*i == NULL) {
    printf("No existe el elemento a eliminar\n");
  } else {
    if ((*i)->dato == d) {
      if ((*i)->sig == NULL) {
        printf("\nElimino a %d\n", d);
        lista* aux = (*i);
        (*i) = NULL;
        free(aux);
      } else {
        printf("\nElimino a %d\n", d);
        lista* aux = (*i);
        (*i) = (*i)->sig;
        (*i)->ant = NULL;
        free(aux);
      }
    } else if((*i)->dato < d && (*i)->sig != NULL && (*i)->sig->dato == d) {
      printf("\nElimino a %d\n", d);
      lista* aux = (*i)->sig;
      (*i)->sig = (*i)->sig->sig;
      free(aux);
    } else
      eliminar(d, &(*i)->sig);
  }
}

int menu(lista **nueva) {
  int opcion;
  int d;
  do {
      printf("\n");
      printf("1. Ingresar\n");
      printf("2. Eliminar\n");
      printf("3. Listar ascedente\n");
      printf("4. Listar descendente\n");
      printf("5. Salir\n");
      printf("\nIngrese opción: ");
      scanf("%d", &opcion);
      printf("\n");
  } while (opcion < 1 && opcion > 6);

  switch(opcion) {
      case 1: printf("Ingrese número: ");
              scanf("%d", &d);
              insertar(d, nueva);
              menu(nueva);
              break;

      case 2: printf("Ingrese número a eliminar: ");
              scanf("%d", &d);
              eliminar(d, nueva);
              menu(nueva);
              break;

      case 3: if(estavacia(*nueva) == 1) {
                printf("Lista vacía\n");
              } else {
                listar(*nueva);
              }
              menu(nueva);
              break;

      case 4: if(estavacia(*nueva) == 1) {
                printf("Lista vacía\n");
              } else {
                listar_desc(*nueva);
              }
              menu(nueva);
              break;

      case 5: return 0;
              break;

      default: break;
  }

  return 0;
}

int main(int argc, char const *argv[]) {
  lista* nueva;
  nueva = NULL;

  menu(&nueva);

  return 0;
}
