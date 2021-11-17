#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define FILAS 3
#define COLUMNAS 4

bool iEvaluacion(int[][COLUMNAS], int[], int, int, int);
bool auxEvaluacion(int[][COLUMNAS], int[], int, int, int);
bool iEvaluacionIterativo(int[][COLUMNAS], int[], int, int, int);
bool iEvaluacionIterativoAlternativo(int[][COLUMNAS], int[], int, int, int);

int main() {
    int n = FILAS, m = COLUMNAS;

    // El enunciado incluía el ejemplo con A[][] y V[] como vector.

    int V[3] = {2, 1, 3};
    int W[3] = {0, 0, 4};
    int A[3][4] = {{8, 1, 6, 0}, {4, 9, 5, 1}, {0, 3, 1, 6}};
    int B[3][4] = {{8, 1, 6, 0}, {4, 9, 5, 1}, {0, 1, 1, 6}};
    int C[3][4] = {{8, 3, 6, 0}, {4, 9, 5, 1}, {0, 1, 1, 6}};
    int D[3][4] = {{9, 9, 9, 9}, {7, 7, 7, 4}, {0, 1, 1, 0}};

    // En el primer error se comprueban que las dos llamadas devuelvan algo diferente (false y true respectivamente)
    // En el segundo error se comprueba que tanto la versión iterativa como la recursiva devuelvan lo mismo.
    // El resto de errores son redundantes.
    // Si el programa se ejecuta sin output significa que todo funciona ""correctamente"".

    if(iEvaluacion(A, V, n, m, n) == iEvaluacion(B, V, n, m, n)) printf("Error #1\n");
    if(iEvaluacion(A, V, n, m, n) != iEvaluacionIterativo(A, V, n, m, n)) printf("Error #2\n");
    if(iEvaluacionIterativo(A, V, n, m, n) == iEvaluacionIterativo(B, V, n, m, n)) printf("Error #3\n");
    if(iEvaluacionIterativo(A, V, n, m, n) != iEvaluacionIterativoAlternativo(A, V, n, m, n)) printf("Error #4\n");
    if(iEvaluacion(C, V, n, m, n) != iEvaluacion(A, V, n, m, n)) printf("Error #1\n");
    if(iEvaluacion(C, V, n, m, n) == iEvaluacionIterativo(B, V, n, m, n)) printf("Error #5\n");
    if(iEvaluacion(D, W, n, m, n) != iEvaluacion(B, V, n, m, n)) printf("Error #1\n");
}

/*
 * Al suponerse k == n en la primera llamada:
 * 
 *  Para un tamaño de problema 3 (como en el enunciado), al haber 3 filas se deberá
 *  acceder a la posición del vector v[2] y a la posición de la matriz a[2][i] en la
 *  primera pasada.
 * 
 *  Al llegar al caso trivial, k es igual a uno, lo que lleva a operar con las posiciones
 *  V[0] y A[0][i], lo cual es válido.
 * 
 */

bool iEvaluacion(int A[][COLUMNAS], int V[], int n, int m, int k) {
    if(k == 1) return auxEvaluacion(A, V, n, m, k);
    else return iEvaluacion(A, V, n, m, k-1) && auxEvaluacion(A, V, n, m, k);
}

// por el mismo motivo que en el método anterior, hay que restarle 1 a "k" al acceder
// tanto a posiciones de matriz como de vector, puesto que k indica el tamaño, no es
// un índice.
bool auxEvaluacion(int A[][COLUMNAS], int V[], int n, int m, int k) {
    int j = 0;
    for(int i = 0; i < m; i++) {
        if(A[k - 1][i] < 2) j++; // calcula la cantidad de elementos en la fila estrictamente menores que 2.
    }
    return V[k - 1] == j; // si la cantidad de elementos menores que 2 es igual a la posición k del vector, se devuelve true.
}



bool iEvaluacionIterativo(int A[][COLUMNAS] , int V[], int n, int m, int k) {
    bool check = true; // elemento neutro de la operación "AND"
    int c = k; // para acceder en el mismo orden que la versión recursiva.
    while(c != 0 && check) { // si check es falso, se sale del bucle y se devuelve falso.
        check &= auxEvaluacion(A, V, n, m, c);
        c--;
    }
    // al llegar a c == 0, ya se comprobaron todas las filas.
    return check;
}

// método alternativo que no almacena el valor booleano.
bool iEvaluacionIterativoAlternativo(int A[][COLUMNAS], int V[], int n, int m, int k) {
    for(int c = k; c > 0; c--) if(!auxEvaluacion(A, V, n, m, c)) return false;
    return true;
}