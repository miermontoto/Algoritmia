// ----------------------------------------------------------------------------------------------------------
//
// ALGORITMIA: PRACTICA DE DIVIDE Y VENCERAS
//
// Maximo_vector y Producto_vector
//
// Copyright: Raquel Cortina
//
// Fecha: 11 de noviembre de 2021
//
// --------------------------------------------------------------------------------------------------------------------------------
//
// Programa en el que se pide el tamanio del vector (n>=1), se reserva dinamicamente memoria,
// se leen sus elementos. Los elementos se muestran por pantalla y seguidamente, a traves de las funciones
// MAXIMO_VECTOR y PRODUCTO_VECTOR, que siguen el esquema de divide y venceras, se busca el elemento de mayor
// valor en el vector y se calcula el producto de los elementos del vector respectivamente.
//
// OPCIONAL: Programa en el que se pide el numero de filas y de columnas de la matriz (n,m>=1), se reserva dinamicamente memoria,
// se leen sus elementos. Los elementos se muestran por pantalla y seguidamente, a traves de la funcion
// EXAMEN_RECURSION_NOVIEMBRE_2021, que sigue el esquema de divide y venceras, se resuelve el problema 1 del examen del tema 2:
//
// "Dada una matriz de enteros A[1..n][1..m] siendo n≥1 y m≥1, diseniar una funcion recursiva que retorne cierto si se cumple
// que para cada fila  el numero de ceros que contiene es menor o igual que el numero de ceros que contiene la fila inmediatamente
// siguiente, y falso en caso contrario"
//
//---------------------------------------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// prototipos de funciones
int lee_vector(int *, int);
int escribe_vector(int *, int);
int maximo_vector_DyV(int *,int,int);
int producto_vector_DyV(int *,int,int);


// PROBLEMA 1 DEL EXAMEN RECURSION NOVIEMBRE 2021

/*
void lee_matriz (int **, int, int);
void escribe_matriz (int **, int, int);
bool EXAMEN_RECURSION_NOVIEMBRE_2021 (int **, int, int, int);
*/

// programa principal
int main() {

    int n,m;
    int *V;


    do{
       printf("\nIntroduce el numero de elementos del vector para obtener el maximo y el producto (>=1): ");
       scanf("%d",&n);} while (n<1);

    // reservar dinamicamente memoria
    V = (int*) malloc(n*sizeof(int));


    lee_vector(V,n);
    escribe_vector (V,n);

    printf("\nEl maximo de los elementos del vector es %d\n\n",maximo_vector_DyV(V,0,n-1));
    printf("\nEl producto de los elementos del vector es %d\n\n",producto_vector_DyV(V,0,n-1));


// PROBLEMA 1 DEL EXAMEN RECURSION NOVIEMBRE 2021
/*
    int n,m;
    printf("Dame el numero de filas: ");
    scanf("%d",&n);
    printf("Dame el numero de columnas: ");
    scanf("%d",&m);

    // definimos una variable de tipo puntero a puntero a int y reservamos memoria para n filas
    int **M = (int**) malloc(n*sizeof(int*));

    //reservamos espacio para las columnas
    for(int i=0;i<n;i++)
            M[i] = (int*) malloc(m*sizeof(int));

    // Leemos la matriz
    lee_matriz (M,n,m);


    printf("\n\nLa matriz introducida es:\n\n");

    // Mostramos el contenido de la matriz
    escribe_matriz (M,n,m);

    //Invocamos a la funcion que comprueba
    if (EXAMEN_RECURSION_NOVIEMBRE_2021(M,0,n-1,m)) printf("Se cumple que cada fila tiene un numero de ceros menor o igual que la fila inmediatamente siguiente\n\n");
    else printf("No se cumple que cada fila tiene un numero de ceros menor o igual que la fila inmediatamente siguiente\n\n");

    // Liberamos el espacio reservado para las columnas
    for (int i=0;i<n;i++) free(M[i]);

    // Liberamos el espacio reservado para las filas
    free(M);
*/
    return 0;
}

//
// Definiciones de funciones
//

// Funcion para leer las componentes del vector
int lee_vector(int *V, int n){
    for (int i=0;i<n;i++) {
        printf("\nDame el valor de la componente %d: ",i+1);
    scanf("%d",V+i);
    }
    return 0;
}

// Funcion para escribir las componentes del vector
int escribe_vector(int *V, int n){
    printf("\nEl vector introducido es: [ ");
    for (int i=0;i<n;i++) {
        printf("%d ",*(V+i));
    }
    printf("]\n");
    return 0;
}

/*
void lee_matriz (int **M, int n, int m){
    int i,j;
    for (i=0;i<n;i++)
        for (j=0;j<m;j++){
            printf("Dame el elemento [%d,%d] :  ",i+1,j+1);
            scanf("%d",&M[i][j]);
            // otra opcion
            //scanf("%d",M[i]+j);
            // y otra opcion
            //scanf("%d",*(M+i)+j);
        }
    }

void escribe_matriz (int **M, int n, int m){
    int i,j,aux;
    for (i=0;i<n;i++)
    {
        for (j=0;j<m;j++){
            printf("%d\t",M[i][j]);
            // otra opcion
            //printf("%d\t",*(M[i]+j));
            // y otra opcion
            //printf("%d\t",*(*(M+i)+j));
        };
    printf("\n\n");
    }
}
*/

// Funcion que proporciona el maximo del vector siguiendo el esquema de Divide y Venceras
int maximo_vector_DyV(int *V, int inicio, int fin){
int m, max1, max2, max;

if (¿?) return ¿?;
else {
      // dividir
      m=(inicio+fin)/2;

      // resolver
      max1=maximo_vector_DyV(V,inicio,m);
      max2=maximo_vector_DyV(V,m+1,fin);

      // combinar
      // completar por el alumno
    }
}

/*
// Funcion que proporciona el producto de los elementos del vector siguiendo el esquema de Divide y Venceras
   int producto_vector_DyV(int *V, int inicio, int fin){
   // completar por el alumno
}
*/


/*
// Funcion que soluciona el problema 1 del examen del tema 2, siguiendo el esquema de Divide y Venceras
   bool EXAMEN_RECURSION_NOVIEMBRE_2021(int **M, int inicio_filas, int fin_filas, int m){
   //completar por el alumno
}
*/
