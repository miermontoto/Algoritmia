// -------------------------------------------------------------------
//
//  ALGORITMIA: IMPLEMENTACION DEL PROBLEMA DE LA MOCHILA 0/1
//
//              SEGUN BACKTRACKING (VUELTA ATRAS) - version recursiva
//
//              En esta version, los vectores de pesos y de beneficios
//              (asi como x y x_mejor) tienen n elementos, de 0 a n-1, por
//              lo que, por ejemplo, el peso del objeto k esta en P[k-1]
//
//              k va de 0 a n-1
//              De hecho, cuando k=n-1 tendremos una solucion completa
//
//  SESION 3 DE PRACTICAS DE ESQUEMAS ALGORITMICOS
//
//  Fechas: del 29 de noviembre al 3 de diciembre de 2021
//
// -------------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

// prototipos de funciones
int peso(int *,int *,int);
int valor(int *,int *,int);
void tratar (int *, int);

void mochila_TODAS(int *, int , int , int , int *);
void mochila_UNA(int *, int , int , int , int *, bool *);
void mochila_OPTIMA(int *, int *, int , int , int , int *, int *, int *);

// funcion main
int main(){
    int n,C,i;
    int *x,*x_mejor,v_mejor,*P, *B;
    bool flag;

    printf ("\n\tIntroduce la capacidad de la mochila: ");
    scanf("%d",&C);

    printf ("\n\tIntroduce el numero de objetos: ");
    scanf("%d",&n);
    //
    // Los vectores P y B tienen tama�o n
    //
    P=(int *)malloc(n*sizeof(int));
    B=(int *)malloc(n*sizeof(int));
    x=(int*)malloc(n*sizeof(int));
    x_mejor=(int *)malloc(n*sizeof(int));

    printf ("\n\n\t\t PESOS\n\n");

    for(i=0;i<n;i++){
        printf ("\n\tIntroduce el peso del objeto %d: ",i);
        scanf("%d",&P[i]);
    }

    printf ("\n\n\t\t BENEFICIOS\n\n");

    for(i=0;i<n;i++){
        printf ("\n\tIntroduce el beneficio del objeto %d: ",i);
        scanf("%d",&B[i]);
    }

    // invocamos a TODAS_LAS_FACTIBLES
    // el valor de inicio de k es 0
    printf("\n\n\tTODAS LAS SOLUCIONES FACTIBLES\n");
    mochila_TODAS(P,n,C,0,x);

    // invocamos a UNA_FACTIBLE
    // el valor de inicio de k es 0
    printf("\n\n\tUNA TUPLA FACTIBLE:\n");
    flag=true;
    mochila_UNA(P,n,C,0,x,&flag);

    // invocamos a OPTIMA
    // el valor de inicio de k es 0
    printf("\n\n\tSOLUCION OPTIMA:\n");
    v_mejor=INT_MIN;
    mochila_OPTIMA(P,B,n,C,0,x,x_mejor,&v_mejor);

    // mostrar la solucion (secuencia de decisiones optima y beneficio maximo)
    tratar(x_mejor,n);
    printf("\t\tBeneficio optimo: %d\n\n\n\n", v_mejor);

    // liberacion de memoria
    free(x);
    free(x_mejor);
    free(P);
    free(B);
    return 0;
}

// funcion que calcula el peso asociado a la secuencia de decisiones x
int peso(int *P,int *x,int k){
    int i, total=0;
    for (i=0;i<=k;i++){
        total=total+x[i]*P[i];
    }
    return total;
}

// funcion que calcula el valor asociado a la secuencia de decisiones x
int valor(int *B,int *x,int n){
    int i, total=0;
    for (i=0;i<n;i++){
        total=total+x[i]*B[i];
    }
    return total;
}

// funcion que muestra por pantalla la secuencia de decisiones x




// funcion backtracking que proporciona TODAS LAS SOLUCIONES FACTIBLES
void mochila_TODAS(int *P, int n, int C, int k, int *x){
    x[k]=-1;    // preparar_recorrido_nivel_k
    while (x[k]<1){  // mientras exista_hermano_nivel_k
        x[k]=x[k]+1; // siguiente_hermano_nivel_k
        if (k==n-1 && (peso(P,x,k)<=C)) tratar(x,n); // si solucion(x,k) y correcto(x,k)
        if (k<n-1 && (peso(P,x,k)<=C)) mochila_TODAS(P,n,C,k+1,x);// si no es solucion(x,k) y correcto(x,k)
    }
}






// funcion backtracking que proporciona UNA SOLUCION FACTIBLE
void mochila_UNA(int *P, int n, int C, int k, int *x, bool *flag){
    x[k]=-1;
    while (x[k]<1 && *flag==true){
        x[k]=x[k]+1;
        if (k==n-1 && peso(P,x,k)<=C){
            *flag=false;
            tratar(x,n);
        }
        if (k<n-1 && peso(P,x,k)<=C) mochila_UNA(P,n,C,k+1,x,flag);
    }
}



// funcion backtracking que proporciona la SOLUCI�N �PTIMA
void mochila_OPTIMA(int *P, int *B, int n, int C, int k, int *x, int *x_mejor, int *v_mejor){
    int i,aux;
    x[k]=-1;
    while (x[k]<1){
        x[k]=x[k]+1;
        if (k==n-1 && peso(P,x,k)<=C){
            aux=valor(B,x,n); // funcion objetivo
            if (aux > *v_mejor){
                *v_mejor=aux;
                //opcion 1
                //for(i=1;i<=n;i++)
                //  x_mejor[i-1]=x[i-1];
                //opcion 2
                //void *memcpy(void *s1, const void *s2, size_t n);
                //memcpy copia los primeros n bytes del area de memoria apuntada por
                //s2 al area de memoria apuntada por s1
                memcpy(x_mejor,x,n*sizeof(int));
            }
        }
        if (k<n-1 && peso(P,x,k)<=C) mochila_OPTIMA(P,B,n,C,k+1,x,x_mejor,v_mejor);
    }
}
