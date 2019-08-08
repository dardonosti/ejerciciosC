#ifndef COLA_DIN_PROT_H_INCLUDED
#define COLA_DIN_PROT_H_INCLUDED

typedef struct Cola {
  int id;
  struct Cola *sig;
} scola;

void crearCola(scola** p);
int estaVacia(scola* p);
void ingresar(scola** p, scola** pf, int x);
int eliminar(scola** p);
void primerelemento(scola* p);
void imprimir(scola* p);
void vaciarcola(scola** p);
void tamanio(scola *p);
void cargar(scola** p);
int menu();

#endif // COLA_DIN_PROT_H_INCLUDED
