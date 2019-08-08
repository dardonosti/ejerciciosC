#ifndef LISTA_DOB_EN_PROT_H_INCLUDED
#define LISTA_DOB_EN_PROT_H_INCLUDED

typedef struct nodo {
  int dato;
  struct nodo *sig;
  struct nodo *ant;
} lista;

void insertar(int d, lista **i);
int estavacia(lista* i);
int listar(lista *i);
int listar_desc(lista *i);
void eliminar(int d, lista** i);
int menu(lista **nueva);

#endif // LISTA_DOB_EN_PROT_H_INCLUDED
