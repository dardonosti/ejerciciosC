#ifndef ARBOL_BINARIO_ENTEROS_PROT_H_INCLUDED
#define ARBOL_BINARIO_ENTEROS_PROT_H_INCLUDED

typedef struct nodo {
  int dato;
  struct nodo *h_izq, *h_der;
} arbol;

void inserta(arbol **A, int x);
int es_miembro(arbol *A, int x);
int suprime_min(arbol **A);
void suprime(arbol **A, int x);
void preOrden(arbol *A);
void inOrden(arbol *A);
void postOrden(arbol *A);
int menu(arbol **raiz);

#endif // ARBOL_BINARIO_ENTEROS_PROT_H_INCLUDED
