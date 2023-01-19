#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define NUM_TALLAS 10
#define REPETICIONES 4 // REPETICIONES * 21seg = lo que tarda
                       // en ejecutarse el programa en los PC de LAB.

int Miercoles18H(int **, int **, int, int);
int rellena(int **, int);
int rellenaNum(int **, int, int);

int main() {
    clock_t t0, t1, t2, t3;
    int **A = NULL, **B = NULL;
    int talla[NUM_TALLAS] = {100,200,300,400,500,600,700,800,900,1000};
    // las tallas de 1000, 2000, etc, presentadas en la sesión anterior
    // son una locura con un problema de ene cubo.


    printf("\t\tTalla\tMejor caso\tPeor caso\n");
    printf("\t\t-----\t----------\t----------\n");

    for(int i = 0; i < NUM_TALLAS; i++) {
        // se reserva espacio para ambas matrices.

        // primero se reservan filas:
        A = (int**) malloc (talla[i] * sizeof(int *));
        B = (int**) malloc (talla[i] * sizeof(int *));

        // y posteriormente las columnas:
        for(int a = 0; a < talla[i]; a++) {
            A[a] = (int *) malloc (talla[i] * sizeof(int));
            B[a] = (int *) malloc (talla[i] * sizeof(int));
        }

        // se rellenan las matrices.
        rellena(A, talla[i]);
        rellena(B, talla[i]);
        // puesto que el mejor y peor caso se decide principalmente
        // por el número a comparar con 'total', el contenido de
        // ambas matrices puede ser aleatorio. esto varía los tiempos
        // entre distintas ejecucciones del programa, pero NO entre
        // el mejor y el peor caso, ya que ambos se hacen con las mismas
        // matrices.

        t0 = clock();
        for(int j = 0; j < REPETICIONES; j++) Miercoles18H(A, B, talla[i], 99999999);
        t1 = clock();

        t2 = clock();
        for(int j = 0; j < REPETICIONES; j++) Miercoles18H(A, B, talla[i], 1);
        t3 = clock();

        printf("\t\t%d\t\t%f", talla[i],(t1-t0) /(double)CLOCKS_PER_SEC / REPETICIONES);
        printf("\t\t%f\n",              (t3-t2) /(double)CLOCKS_PER_SEC / REPETICIONES);
    
        // por último, se libera el espacio que contiene a las matrices.
        free(A);
        free(B);
    }
    return 0;
}


// Funciones:

int Miercoles18H(int **A, int** B, int n, int p) {
    int suma, total;
    total = 0;

    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
        suma = 0;
        for(int k = 0; k < n; k++) suma += A[i][k] * B[k][j];
        total += suma;
    }
    if (total <= p) return total;
    else suma = 0;

    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) suma += A[i][j];
    return suma;
}

int rellenaNum(int **M, int n, int x) {
   for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
     M[i][j] = x; // VARIAR MAN. DEPENDIENDO DEL ALGORITMO
   }
 }
}

int rellena(int **M, int n){
 for(int i = 0; i < n; i++) {
   for(int j = 0; j < n; j++) {
     M[i][j] = rand();
   }
 }
}