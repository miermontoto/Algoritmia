#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>

void descomponerTodas(int, int, int, int *);
void descomponerUna(int, int, int, int *, bool *);
void descomponerOptima(int, int, int, int *, int *, int *);

void tratar(int*, int);
int suma(int*, int);
int valor(int*, int);


int main(){
   int n, m;
   int mv;
   bool flag;

   do {
      printf("\nIntroduce el numero a descomponer: ");
      scanf("%d", &n);
   } while(n <= 0);

   do {
      printf("\nIntroduce el numero de sumandos: ");
      scanf("%d", &m);
   } while(m > n);

   // Los vectores tienen tamaño M

   int* x = (int *) malloc (m * sizeof(int));
   int* xOptimo = (int *) malloc (m * sizeof(int));

   printf("\n\nSoluciones factibles:\n");
   descomponerTodas(n, m, 0, x);

   printf("\n\nUna de las soluciones factibles:\n");
   flag = false;
   descomponerUna(n, m, 0, x, &flag);

   printf("\n\nLa solucion optima:\n");
   mv = INT_MIN;
   descomponerOptima(n, m, 0, x, xOptimo, &mv);
   tratar(xOptimo, m);

   free(x);
   free(xOptimo);

   return 0;
}

void tratar (int *x, int m){
   printf("<");
   for (int i = 0; i < m - 1; i++) printf("%d, ", x[i]);
   printf("%d>\tValor: %d\n", x[m - 1], valor(x, m));
}


int suma(int* x, int m) {
   int res = 0;
   for(int i = 0; i < m; i++) {res += x[i];}
   return res;
}

int valor(int* x, int m) {
   int res = 1;
   for(int i = 0; i < m; i++) {res *= x[i];}
   return res;
}


void descomponerTodas(int n, int m, int k, int *x){
   x[k] = 0;
   while(x[k] < n) {
      x[k] = x[k] + 1;
      if (k == m - 1 && suma(x, m) == n) tratar(x, m); // si solucion(x,k) y correcto(x,k)
      if (k < m - 1 && suma(x, k) < n) descomponerTodas(n, m, k + 1, x);// si no es solucion(x,k) y correcto(x,k)
   }
}

void descomponerUna(int n, int m, int k, int *x, bool *flag){
   x[k] = 0;
   while(x[k] < n && !*flag) {
      x[k] = x[k] + 1;
      if (k == m - 1 && suma(x, m) == n) {*flag = true; tratar(x, m);}
      if (k < m - 1 && suma(x, k) < n) descomponerUna(n, m, k + 1, x, flag);
   }
}


void descomponerOptima(int n, int m, int k, int *x, int *xOptimo, int *mv){
   x[k] = 0;
   while(x[k] < n) {
      x[k] = x[k] + 1;
      if (k == m - 1 && suma(x, m) == n) if(valor(x, m) > *mv) {memcpy(xOptimo, x, m * sizeof(int)); *mv = valor(x, m);}
      if (k < m - 1 && suma(x, k) < n) descomponerOptima(n, m, k + 1, x, xOptimo, mv);
   }
}

