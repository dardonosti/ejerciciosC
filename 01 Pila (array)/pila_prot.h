#ifndef PILA_PROT_H_INCLUDED
#define PILA_PROT_H_INCLUDED

#define N 10

int estavacia(int c);
int cima(int e[], int c);
int tamanio(int *c);
void vaciapila(int *c);
int desapila(int e[], int *c);
void apila(int e[], int *c);
int menu(int e[], int *c);

#endif // PILA_PROT_H_INCLUDED
