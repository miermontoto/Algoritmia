// ESTE PROGRAMA MUESTRA C�MO PASAR COMO PAR�METRO UNA MATRIZ DE TAMA�O FIJO A UNA FUNCI�N
#include <stdio.h>

// La directiva #define define una macro. Cada ocurrencia del identificador FILAS en
// el c�digo fuente es reemplazado por 2
#define FILAS 2
#define COLUMNAS 3


// Al pasar como par�metro un vector multidimensional, �ste debe
// tener todas las dimensiones acotadas, salvo la primera

// prototipos de funciones
void lee_matriz (int [][COLUMNAS]);
void escribe_matriz (int [][COLUMNAS]);
int suma_matriz (int [][COLUMNAS]);


int main ()
{
//Declaramos la matriz con tama�o fijo
int mi_matriz[FILAS][COLUMNAS];

//Invocamos a la funci�n de lectura de las componentes
lee_matriz (mi_matriz);

//Invocamos a la funci�n de escritura de las componentes
escribe_matriz (mi_matriz);

//Invocamos a la funci�n que suma las componentes de la matriz
printf("\n\nLa suma de los elementos de la matriz es: %d\n\n",suma_matriz (mi_matriz));

return 0;
}

void lee_matriz (int M[][COLUMNAS])
{
 int i,j;
 for (i=0;i<FILAS;i++)
   for (j=0;j<COLUMNAS;j++){
        printf("Dame el elemento [%d,%d] :  ",i+1,j+1);
        scanf("%d",&M[i][j]);
        }
 }

void escribe_matriz (int M[][COLUMNAS])
{
 int i,j;
 printf("\n");
 printf("M = {");
 for (i=0;i<FILAS;i++)
 {
   for (j=0;j<COLUMNAS;j++)
        printf("\t%d",M[i][j]);
   printf("\n");
 }
printf("    }\n\n");
}

int suma_matriz (int M[][COLUMNAS])
{
 int i,j,suma=0;
 printf("\n");
 for (i=0;i<FILAS;i++)
 {
   for (j=0;j<COLUMNAS;j++)
        suma+=M[i][j];
   printf("\n");
 }
 printf("\n");
 return suma;
}
