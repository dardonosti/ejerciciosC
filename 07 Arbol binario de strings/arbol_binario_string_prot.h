#ifndef ARBOL_BINARIO_STRING_PROT_H_INCLUDED
#define ARBOL_BINARIO_STRING_PROT_H_INCLUDED

typedef struct nodo {
  char dato[50];
  struct nodo *h_izq, *h_der;
} arbol;

void inserta(arbol **A, char p[]);
int es_miembro(arbol *A, char p[]);
char* suprime_min(arbol **A, char v_ref[]);
void suprime(arbol **A, char p[], char v_ref[]);
void preOrden(arbol *A);
void inOrden(arbol *A);
void postOrden(arbol *A);
int menu(arbol **raiz, char v_ref[]);

#endif // ARBOL_BINARIO_STRING_PROT_H_INCLUDED
