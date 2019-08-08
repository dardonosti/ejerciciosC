#include <stdio.h>
#include "pila_prot.h"

int estavacia(int c) {
  if(c == -1) {
    return 0;
  } else {
    return 1;
  }
}

int cima(int e[], int c) {
  if(estavacia(c) == 0) {
    return printf("\n\t #error: pila vacía\n");
  } else {
    return printf("\n\t #Primer elemento: %d\n", e[c]);
  }
}

int tamanio(int *c) {
  return (*c)+1;
}

void vaciapila(int *c) {
  if(estavacia(*c) == 0) {
    printf("\n\t #error: pila vacía\n");
  } else {
    *c = -1;
  }
}

int desapila(int e[], int *c) {
  if(estavacia(*c) == 0) {
    return printf("\n\t #error: pila vacía\n");
  } else {
    (*c)--;
    return e[*c+1];
  }
}

void apila(int e[], int *c) {
    if (tamanio(c) == N) {
        printf ("\n\t #error: pilla llena\n");
    } else {
      int d;
      printf("\n\t #Ingrese elemento: ");
      scanf("%d", &d);
      (*c)++;
      e[*c] = d;
    }
}

int menu(int e[], int *c) {
  int op;
    printf("\n");
    printf("1. Apila\n");
    printf("2. Desapila\n");
    printf("3. Mostrar primer elemento\n");
    printf("4. Vaciar Pila\n");
    printf("5. Hay elementos?\n");
    printf("6. Salir\n");
    printf("\nIngrese opción: ");
    scanf("%d", &op);

  switch(op) {
    case 1: apila(e, c);
            menu(e, c);
            break;
    case 2: desapila(e, c);
            menu(e, c);
            break;
    case 3: cima(e, *c);
            menu(e, c);
            break;
    case 4: vaciapila(c);
            menu(e, c);
            break;
    case 5: if (estavacia(*c) == 0) {
              printf("\n\t #No hay elementos\n");
            } else {
              printf("\n\t #Cantidad de elementos: %d\n", tamanio(c));
            };
            menu(e, c);
    case 6: break;
    default:
            break;
  }
  return 0;
}

int main() {
    int elementos[N];
    int ccima = -1;
    int *pccima;
    pccima = &ccima;

    menu(elementos, pccima);

    return 0;
}
