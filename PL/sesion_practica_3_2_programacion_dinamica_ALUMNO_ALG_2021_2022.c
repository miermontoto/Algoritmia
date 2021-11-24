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

int MOCHILA_programacion_dinamica (int *, int *, int, int);
int DESCOMPONER_programacion_dinamica(int,int);

// EMBARCADEROS (OPCIONAL)
//int EMBARCADEROS_programacion_dinamica(int, int **);

int main(){
int n,C,i;
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

//
// La funcion MOCHILA_programacion_dinamica recibe:
// - los vectores P y B con los pesos y beneficios de los objetos,
// - el numero de objetos, n, y
// - la capacidad de la mochila, C
//

/*
printf("\n\n\n y el beneficio maximo es:%d\n",MOCHILA_programacion_dinamica(P,B,n,C));
printf("\n\n");
*/

// liberar memoria
free(P);
free(B);

//
// DESCOMPOSICION DE N EN M SUMANDOS
//
/*
int N,M;

do{
    printf("Introduce el numero a descomponer: ");
    scanf("%d",&N);
} while(N<=0);

do{
    printf("\nIntroduce el numero de sumandos en los que se va a descomponer:  ");
    scanf("%d",&M);
} while(M<=0||M>N);

printf("\n\n\n y producto maximo es:%d\n",DESCOMPONER_programacion_dinamica(N,M));
printf("\n\n");

*/

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

int MOCHILA_programacion_dinamica (int *P, int *B, int n, int C){
int **Bmax;
int **Dec;
int *X;

// reserva dinamica de memoria para X, esto es, el vector de decisiones
// realizar por el alumno


// reserva dinamica de memoria de las matrices Bmax y Dec
// realizar por el alumno


// inicializar las matrices con los resultados de los problemas triviales
// realizar por el alumno


// rellenar las matrices por filas en sentido ascendente
// realizar por el alumno


// solucion
// realizar por el alumno


// mostrar por pantalla la secuencia de decisiones optima
// realizar por el alumno


// liberar memoria
// realizar por el alumno


// retornar el beneficio maximo
// realizar por el alumno
}


int DESCOMPONER_programacion_dinamica(int N, int M){
int **Pmax;
int **Dec;
int *S;

// reserva dinamica de memoria para Sumandos, esto es, el vector de decisiones
// realizar por el alumno


// reserva dinamica de memoria de las matrices Pmax y Dec
// realizar por el alumno


// inicializar las matrices con los resultados de los problemas triviales
// realizar por el alumno


// rellenar las matrices por filas en sentido ascendente
// realizar por el alumno


// solucion
// realizar por el alumno


// mostrar por pantalla la secuencia de decisiones optima
// realizar por el alumno


// liberar memoria
// realizar por el alumno


// retornar el producto maximo
// realizar por el alumno
}




// [OPCIONAL]
/*
int embarcaderos_programacion_dinamica(int n, int **C){
// realizar por el alumno
}
*/
