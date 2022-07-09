// --------------------------------------------------------------------------
//
//  ALGORITMIA: IMPLEMENTACION DEL ALGORITMO "MOCHILA 0/1" Y
//
//              DEL ALGORITMO "DESCOMPONER UN NUMERO N EN M SUMANDOS"
//
//
//  SESION 3.2 DE PRACTICAS (ESQUEMAS ALGORITMICOS - PROGRAMACION DINAMICA)
//
//  Fechas: del 19 al 25 de noviembre de 2021
//
// ---------------------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>

int maxMochila (int *, int *, int, int);
int sumandosProducto(int,int);
int EMBARCADEROS_programacion_dinamica(int, int **);

int main() {

    /*
    int n, C, i;
    int *P;
    int *B;

    do{
        printf("Introduce la capacidad de la mochila: ");
        scanf("%d",&C);
    } while(C<0);

    do{
        printf("\nIntroduce el numero de objetos:  ");
        scanf("%d",&n);
    } while(n<0);

    // reserva dinamica de memoria para vectores de pesos y beneficios
    P=(int *)malloc(n*sizeof(int));
    B=(int *)malloc(n*sizeof(int));

    printf("\n\nIntroduce los pesos de los %d objetos\n",n);
    for (i=1;i<=n;i++){
        do {
            printf("\nPeso[%d]= ", i);
            scanf("%d",&P[i-1]);
        } while(P[i-1]<=0);
    }

    printf("\n\nIntroduce los beneficios de los %d objetos\n",n);
    for (i=1;i<=n;i++){
        do {
            printf("\nBeneficio[%d]= ", i);
            scanf("%d",&B[i-1]);
        } while(B[i-1]<=0);
    }

    // la función maxMochila recibe:
    // - los pesos y beneficios de los objetos en forma de vectores, P y B
    // - el número de objetos, n
    // - la capacidad de la mochila, C

    maxMochila(P, B, n, C);
    

    // liberar memoria
    free(P);
    free(B);
    */

    //
    // DESCOMPOSICION DE N EN M SUMANDOS
    //
    
    int N, M;

    do{
        printf("Introduce el numero a descomponer: ");
        scanf("%d",&N);
    } while(N<=0);

    do{
        printf("\nIntroduce el numero de sumandos en los que se va a descomponer:  ");
        scanf("%d",&M);
    } while(M<=0||M>N);

    sumandosProducto(N, M);

    

    //
    // EMBARCADEROS [OPCIONAL]
    //

    /* int n;
    printf("Introduce el numero de embarcaderos: ");
    scanf("%d",&n);

    // reserva dinámica de memoria para la matriz de costes C
    // realizar por el alumno

    // lectura de la matriz C de costes
    // realizar por el alumno

    printf("\n\nEl coste final del recorrido es %d\n",EMBARCADEROS_programacion_dinamica(n,C));
    */

    return 0;
}

int maxMochila (int *P, int *B, int n, int C){

    // reserva dinamica de memoria para X, esto es, el vector de decisiones
    // realizar por el alumno
    int *X = (int *)malloc(n * sizeof(int));

    // reserva dinamica de memoria de las matrices Bmax y Dec
    // realizar por el alumno
    int **Dec = (int **)malloc((n + 1) * sizeof(int*));
    for(int i = 0; i < n + 1; i++) Dec[i] = (int*)malloc((C + 1) * sizeof(int));

    int **Bmax = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i < n + 1; i++) Bmax[i] = (int*)malloc((C + 1) * sizeof(int));

    // inicializar las matrices con los resultados de los problemas triviales
    // realizar por el alumno
    for(int i = 0; i < C + 1; i++) {
        Bmax[0][i] = 0;
        Dec[0][i] = 0;
    }


    // rellenar las matrices por filas en sentido ascendente
    // realizar por el alumno
    for(int i = 1; i < n + 1; i++) for(int j = 0; j < C + 1; j++) {
        if(j < P[i-1]) {
            Bmax[i][j] = Bmax [i-1][j];
            Dec[i][j] = 0;
        } else {
            if (Bmax[i - 1][j] >= Bmax[i - 1][j - P[i-1]] + B[i-1]) {
                Bmax[i][j] = Bmax[i - 1][j];
                Dec[i][j] = 0;
            } else {
                Bmax[i][j] = Bmax[i - 1][j - P[i-1]] + B[i-1];
                Dec[i][j] = 1;
            }
        }
    }


    // solución
    // realizar por el alumno
    int i = n;
    int j = C;
    while(i > 0) {
        X[i-1] = Dec[i][j];
        j -= X[i-1] * P[i-1];
        i--;
    }


    int max = Bmax[n][C];
    printf("El resultado optimo es: %d\nSe ha obtenido el resultado con la secuencia de decisiones: <", max);
    for(int k = 0; k < n - 1; k++) printf("%d, ", X[k]);
    printf("%d>\n", X[n - 1]);


    // liberar memoria
    free(Dec);
    free(Bmax);
    free(X);


    return max;
}


int sumandosProducto(int N, int M){

    // reserva dinamica de memoria para Sumandos, esto es, el vector de decisiones
    // realizar por el alumno
    int *S = (int *)malloc(M * sizeof(int));

    // reserva dinamica de memoria de las matrices Pmax y Dec
    // realizar por el alumno
    int **Dec = (int **)malloc(M * sizeof(int*));
    for(int i = 0; i < M; i++) Dec[i] = (int*)malloc(N * sizeof(int));

    int **Pmax = (int **)malloc(M * sizeof(int *));
    for (int i = 0; i < M; i++) Pmax[i] = (int*)malloc(N * sizeof(int));


    // inicializar las matrices con los resultados de los problemas triviales
    // realizar por el alumno
    for(int i = 0; i < M; i++) for(int j = 0; j < N; j++) {
        Pmax[i][j] = 1;
        Dec[i][j] = 1;
    }
    for(int i = 0; i < N; i++) {
        Pmax[0][i] = i+1;
        Dec[0][i] = i+1;
    }


    // rellenar las matrices por filas en sentido ascendente
    // realizar por el alumno
    for(int i = 1; i < M; i++) for(int j = 1; j < N; j++) {
        Pmax[i][j] = 1;
        for(int k = 0; k < j - i + 1; k++) {
            int p = Pmax[i - 1][j - k] * k;
            if(p >= Pmax[i][j]) {
                Pmax[i][j] = p;
                Dec[i][j] = k;
            }
        }
    }

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            printf("%d ", Pmax[i][j]);     
        }
        printf("\n");
    }

    printf("\n");

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            printf("%d ", Dec[i][j]);     
        }
        printf("\n");
    }

    // solucion
    // realizar por el alumno
    int i = M-1;
    int j = N-1;
    while(i >= 0) {
        S[i] = Dec[i][j];
        j -= S[i];
        i--;
    }

    // mostrar por pantalla la secuencia de decisiones optima
    // realizar por el alumno
    int max = Pmax[M-1][N-1];
    printf("El resultado optimo es: %d\nSe ha obtenido el resultado con la secuencia de decisiones: <", max);
    for(int k = 0; k < M - 1; k++) printf("%d, ", S[k]);
    printf("%d>\n", S[M - 1]);


    // liberar memoria
    // realizar por el alumno
    free(S);
    free(Dec);
    free(Pmax);


    // retornar el producto maximo
    // realizar por el alumno
    return max;
}




// [OPCIONAL]
/*
int embarcaderos_programacion_dinamica(int n, int **C){
// realizar por el alumno
}
*/
