#ifndef KRUSKAL_H_INCLUDED
#define KRUSKAL_H_INCLUDED

#define VERTICES 5

typedef int tipo_nombre;
typedef int tipo_elemento;
typedef int vertice;

typedef struct _ARISTA {
  vertice u;
  vertice v;
  int costo;
} arista;

typedef struct _RAMA {
  struct _ARISTA a;
  struct _RAMA *sig;
} rama;

typedef struct _ENCABEZADO {
  int cuenta;
  int primer_elemento;
} encabezado;

typedef struct _NOMBRE {
  tipo_nombre nombre_conjunto;
  int siguiente_elemento;
} nombre;

typedef struct _CONJUNTO_CE {
  nombre nombre[VERTICES];
  encabezado encabezamientos_conjunto[VERTICES];
} conjunto_CE;

void inicial(tipo_nombre A, tipo_elemento v, conjunto_CE* C);
void combina(tipo_nombre A, tipo_nombre B, conjunto_CE* C);
tipo_nombre encuentra(int v, conjunto_CE* C);
arista sacar_min(rama** R);
void inserta(int u, int v, int c, rama** R);
void lista(rama* R);
void libera(rama** R);
void kruskal(rama** R);

#endif // KRUSKAL_H_INCLUDED
