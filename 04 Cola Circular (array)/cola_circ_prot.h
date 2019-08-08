#ifndef COLA_CIRC_PROT_H_INCLUDED
#define COLA_CIRC_PROT_H_INCLUDED

#define MAX 3

int posicion(int inicial, int contador);
int vacia(int* contador);
void ingresar(int c[], int* inicial, int* contador);
void descolar(int* inicial, int* contador);
void encolar(int c[], int* inicial, int* contador);
void frente(int c[], int* inicial, int* contador);
void anular(int* contador);
int menu(int c[], int* inicial, int* contador);

#endif // COLA_CIRC_PROT_H_INCLUDED
