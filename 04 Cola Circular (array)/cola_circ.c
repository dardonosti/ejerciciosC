#include <stdio.h>
#include "cola_circ_prot.h"

int posicion(int inicial, int contador) {
    return ((inicial + contador) % MAX);
}

int vacia(int* contador) {
    if (*contador == 0) {
        return 1;
    } else {
        return 0;
    }
}

void ingresar(int c[], int* inicial, int* contador) {
    int dato;
    printf("Ingrese dato a ingresar: ");
    scanf("%d", &dato);
    c[posicion(*inicial, *contador)] = dato;
    (*contador) = (*contador) + 1;
}

void descolar(int* inicial, int* contador) {
    if (vacia(contador) == 1) {
        printf("#error: cola vacía\n");
    } else {
        (*contador) = (*contador) - 1;
        (*inicial) = (*inicial) + 1;
        if(*inicial == MAX) {
            (*inicial) = 0;
        }
    }
}

void encolar(int c[], int* inicial, int* contador) {
    if (*contador != MAX) {
        ingresar(c, inicial, contador);
    } else {
        printf("#error: cola llena\n");
    }
}

void frente(int c[], int* inicial, int* contador) {
    if (vacia(contador) == 1) {
        printf("#error: cola vacía\n");
    } else {
        printf("Frente: %d\n", c[*inicial]);
    }
}

void anular(int* contador) {
    *contador = 0;
    printf("#cola vacía\n");
}

int menu(int c[], int* inicial, int* contador) {
    int opcion;
    do {
        printf("\n");
        printf("1. Encolar\n");
        printf("2. Descolar\n");
        printf("3. Frente Cola\n");
        printf("4. Anular Cola\n");
        printf("5. Salir\n");
        printf("\nIngrese opción: ");
        scanf("%d", &opcion);
        printf("\n");
    } while (opcion < 1 && opcion > 4);

    switch(opcion) {
        case 1: encolar(c, inicial, contador);
                menu(c, inicial, contador);
                break;
        case 2: descolar(inicial, contador);
                menu(c, inicial, contador);
                break;
        case 3: frente(c, inicial, contador);
                menu(c, inicial, contador);
                break;
        case 4: anular(contador);
                menu(c, inicial, contador);
                break;
        case 5: return 0;
                break;
        default: break;
    }
    return 0;
}

int main() {
    int cola[MAX];
    int posInic = 0, cont = 0;
    int *ptrI = &posInic;
    int *ptrC = &cont;

    menu(cola, ptrI, ptrC);

    return 0;
}
