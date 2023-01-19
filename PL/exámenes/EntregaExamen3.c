//
//  ALGORITMIA
//
//  CONTROL PRACTICO 3: ESQUEMAS ALGORITMICOS
//
//  GRUPO PL1
//
//  Fecha: 15 de diciembre de 2021
//

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>

#define FILAS 3
#define COLUMNAS 3

// prototipos de funciones
int EXAMEN_programacion_dinamica(int, int, int);
void EXAMEN_backtracking(int , int , int, int , int *, int *, int *);
int valor(int*, int, int);
void tratar(int*, int, int);
int suma(int*, int);
bool EXAMEN_DYV(int[FILAS][COLUMNAS], int, int);
bool AUX(int[FILAS][COLUMNAS], int);


// prototipos de funciones auxiliares
// rellenar por el alumno


int main() {

	// datos del problema para Programacion Dinamica y Vuelta Atras
	int C = 5;
	int N = 3;
	int k = 2;

	// datos del problema para Divide y Venceras
	int M[FILAS][COLUMNAS]={
		{1, 2, 3},
		{4, 5, 2},
		{7, 4, 9}
	};

	int* x = (int *) malloc (N * sizeof(int));
    int* xOptimo = (int *) malloc (N * sizeof(int));
	int mv = INT_MAX; // INT_MAX siempre va a ser menor que el primer valor sugerido.

	EXAMEN_programacion_dinamica(C, N, k);
	EXAMEN_backtracking(C, N, 0, k, x, xOptimo, &mv);
	tratar(xOptimo, N, k);
    printf("DyV: ");
    if(EXAMEN_DYV(M, 0, COLUMNAS)) printf("verdadero");
    else printf("falso");

	return 0;
}


// definiciones de funciones

int EXAMEN_programacion_dinamica(int C, int N, int k){
	int *S = (int *)malloc(N * sizeof(int)); // Vector secuencia de decisiones

    int **Dec = (int **)malloc(N * sizeof(int*)); // Matriz ruta
    for(int i = 0; i < N; i++) Dec[i] = (int*)malloc(C * sizeof(int));

    int **Pmin = (int **)malloc(N * sizeof(int *)); // Matriz mínimos
    for (int i = 0; i < N; i++) Pmin[i] = (int*)malloc(C * sizeof(int));


	// Se rellena la matriz de unos al principio para evitar tener valores aleatorios.
    for(int i = 0; i < N; i++) for(int j = 0; j < C; j++) {
        Pmin[i][j] = 1;
        Dec[i][j] = 1;
    }

	// Se rellenan las matrices con los estados que se conocen desde el principio.
    for(int i = 0; i < C; i++) {
        Pmin[0][i] = (i+1) * k; // <-- cuidado! los casos bases también se multiplican por k.
        Dec[0][i] = i+1;
    }

    // Rellenado de las estructuras general
    for(int i = 1; i < N; i++) for(int j = 1; j < C; j++) {
        Pmin[i][j] = INT_MAX; // <-- ATENCIÓN A ESTO!!!! (40 minutos)
        for(int l = 1; l < j - i + 1; l++) { // No empieza desde 0 porque si no se escogería esa ruta siempre.
            int p = Pmin[i - 1][j - l] * l * k; // Ojo a las multiplicaciones
            if(p < Pmin[i][j]) { // MENOR QUE para que cumpla la minimización
                Pmin[i][j] = p; // nuevo valor mínimo
                Dec[i][j] = l; // ruta mínima a través de 'l'
            }
        }
    }


    // Se imprimen ambas estructuras "bidimensionales" para comprobar que sea correcto.
    /*
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < C; j++) {
            printf("%d ", Pmin[i][j]);     
        }
        printf("\n");
    }

    printf("\n");

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < C; j++) {
            printf("%d ", Dec[i][j]);     
        }
        printf("\n");
    }
    */

    // Se rellena la secuencia de decisiones con la ruta óptima.
    // Por lo general, la ruta óptima estará en [N-1][C-1]
    int i = N-1;
    int j = C-1;
    while(i >= 0) {
        S[i] = Dec[i][j];
        j -= S[i];
        i--;
    }

    // Se calcula el valor de la ruta y se imprime por pantalla.
    int min = Pmin[N-1][C-1];
    printf("Dinámica    : <");
    for(int k = 0; k < N - 1; k++) printf("%d, ", S[k]);
    printf("%d>\tValor: %d\n", S[N - 1], min);

    // Se liberan las matrices y vectores de memoria.
    free(S);
    free(Dec);
    free(Pmin);

    return min; // esto es indiferente.
}


void EXAMEN_backtracking(int C, int N, int l, int k, int *x, int *xOptimo, int *mv){
	x[l] = 0;
    while(x[l] < C) {
    	x[l] = x[l] + 1;
    	if (l == N - 1 && suma(x, N) == C) if(valor(x, N, k) < *mv) {memcpy(xOptimo, x, N * sizeof(int)); *mv = valor(x, N, k);}
    	if (l < N - 1 && suma(x, l) < C) EXAMEN_backtracking(C, N, l + 1, k, x, xOptimo, mv);
   }
}

// Devuelve el valor del vector de decisiones óptimo calculado.
int valor(int* x, int N, int k) {
   int res = 1;
   for(int i = 0; i < N; i++) {res *= x[i] * k;}
   return res;
}

// Imprime el vector de decisiones óptimo y su valor.
void tratar (int *x, int m, int k){
   printf("Backtracking: <");
   for (int i = 0; i < m - 1; i++) printf("%d, ", x[i]);
   printf("%d>\tValor: %d\n", x[m - 1], valor(x, m, k));
}

// Devuelve el sumando de los términos de la secuencia de decisiones actual.
int suma(int* x, int m) {
   int res = 0;
   for(int i = 0; i < m; i++) {res += x[i];}
   return res;
}


bool EXAMEN_DYV(int M[FILAS][COLUMNAS], int inicio, int fin){
    int k = (inicio + fin) / 2;
    
    if(inicio == fin) if(inicio == 0) {return AUX(M, 0);} else {return true;}
    return EXAMEN_DYV(M, inicio, k) && EXAMEN_DYV(M, k+1, fin) && AUX(M, k);
}

bool AUX(int M[FILAS][COLUMNAS], int k) {
    int a = 1;
    int b = 1;
    for(int i = 0; i < FILAS; i++) {
        a *= M[i][k];
        b *= M[i][k+1];
    }
    return a < b;
}

