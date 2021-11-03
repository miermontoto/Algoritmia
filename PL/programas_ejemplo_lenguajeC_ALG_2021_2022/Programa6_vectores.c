// ESTE PROGRAMA MUESTRA C�MO PASAR COMO PAR�METRO UN VECTOR DE TAMA�O FIJO A UNA FUNCI�N
#include <stdio.h>

// La directiva #define define una macro. Cada ocurrencia del identificador ELEMENTOS en
// el c�digo fuente es reemplazado por 6
#define ELEMENTOS 6

// Al pasar como par�metro un vector unidimensional, no tiene por que tener la
// dimension acotada

// prototipos de funciones
void lee_vector (int []);
void escribe_vector (int []);
int suma_vector (int []);

int main ()
{
//Declaramos un vector de tama�o fijo
int mi_vector[ELEMENTOS];

//Invocamos a la funci�n de lectura de las componentes del vector
lee_vector (mi_vector);

//Invocamos a la funci�n de escritura de las componentes del vector
escribe_vector (mi_vector);

//Invocamos a la funci�n que suma las componentes del vector
printf("\n\nLa suma de los elementos del vector es: %d\n\n",suma_vector (mi_vector));

return 0;
}

//
// Funciones
//

void lee_vector (int V[])
{
 int i;
 for (i=0;i<ELEMENTOS;i++){
        printf("Dame el elemento [%d] :  ",i+1);
        scanf("%d",&V[i]);
        }
 printf("\n\n");
 }

void escribe_vector (int V[])
{
 int i;
 printf("V = {");
 for (i=0;i<ELEMENTOS;i++)
        printf("  %d",V[i]);
 printf(" }\n\n");
 }

 int suma_vector (int V[])
{
 int i,suma=0;
 for (i=0;i<ELEMENTOS;i++)
        suma+=V[i];
 return suma;
 }

