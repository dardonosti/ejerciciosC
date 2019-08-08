#ifndef PILA_DIN_PROT_H_INCLUDED
#define PILA_DIN_PROT_H_INCLUDED

typedef struct miPila {
  int id;
  struct miPila *sig;
} spila;

void crearPila(spila** p);
int estaVacia(spila* p);
void ingresar(spila** p, int x);
int eliminar(spila** p);
void primerelemento(spila* p);
void imprimir(spila* p);
void vaciarpila(spila** p);
void tamanio(spila *p);
void cargar(spila** p);
int menu();

#endif // PILA_DIN_PROT_H_INCLUDED
