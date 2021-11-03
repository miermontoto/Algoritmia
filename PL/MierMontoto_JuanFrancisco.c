#include <stdio.h>
#include <stdbool.h>

// Declaración de métodos recursivos
int potencia(int, int);
int potenciaEntresijos(int, int);
int potencia3(int);
int potencia3Entresijos(int);
int mcd(int, int);
int mcdEntresijos(int, int);
int fibonacci(int);
int rayuela(int);
int numeroCifras(int);
int sumaCifras(int);
int semifactorial(int);
int plano(int, int);
int tableros(int, int);
int sumavector(int*, int);
bool capicua(int*, int, int);
bool matrizSimetrica(int**, int);

// Declaración de métodos iterativos
int potenciaIterativo(int, int);
int mcdIterativo(int, int);
int tablerosIterativo(int, int);
int sumaVectorIterativo(int*, int);
bool capicuaIterativo(int*, int);
bool matrizSimetricaIterativo(int**, int);


bool bandaSimetrica(int**, int);

int main() {
    int i, n, a, b, x, y;

    do {
        printf("Base a (a>=0): ");
        scanf("%d",&i);
    } while(i < 0);

    do {
        printf("Exponente n (n>=0): ");
        scanf("%d",&n);
    } while(n < 0);

    
    printf("\n\nPotencia\n");
    printf("La potencia %d-esima de %d es: %d\n", n, i, potencia(i, n));
    printf("La potencia %d-esima de %d es: %d\n\n", n, i, potenciaIterativo(i, n));

    /*
    printf("\n\nPotencia, mostrando el funcionamiento interno.\n");

    printf("DESCENSO en la cadena de llamadas\n\n");
    printf("\nLa potencia %d-esima de %d es: %d\n\n", n, a, potenciaEntresijos(a,n));
    */

    /* --- */

    /*
    printf("\n\nPotencia 3\n");
    printf("La potencia tercera de %d es: %d", a, potencia3(a));

    printf("\n\nPotencia 3, mostrando el funcionamiento interno.\n");
    printf("DESCENSO en la cadena de llamadas\n\n");

    printf("\nLa potencia tercera de %d es: %d\n\n", a, potencia3Entresijos(a));
    */

    /* --- */

    do {
        printf("Numero 'a': ");
        scanf("%d", &a);
    } while (a < 0);

    do {
        printf("Numero 'b': ");
        scanf("%d", &b);
    } while (b < 0);


    printf("\n\nMCD\n");
    printf("El mcd de %d y %d es: %d\n", a, b, mcd(a, b));
    printf("El mcd de %d y %d es: %d\n\n", a, b, mcdIterativo(a, b));

    /*
    printf("\n\nMCD, mostrando el funcionamiento interno.\n");
    printf("DESCENSO en la cadena de llamadas\n\n");

    printf("El mcd de %d b %d es: %d", x, y, mcdEntresijos(x, y));
    printf("\n\nEn el programa estan incluidas las funciones extra del enunciado.\n");
    */

    do
    {
        printf("Numero 'x': ");
        scanf("%d", &x);
    } while (a < 0);

    do
    {
        printf("Numero 'y': ");
        scanf("%d", &y);
    } while (b < 0);

    printf("\n\nTablero\n");
    printf("Caben %d tableros de %dx%d en uno de %dx%d\n", tableros(x, y) , y, y, x, x);
    printf("Caben %d tableros de %dx%d en uno de %dx%d\n\n", tablerosIterativo(x, y), y, y, x, x);

    return 0;
}


int potencia(int a, int n){
    if (n==0) return 1;
    else return potencia(a, n - 1) * a;
}

int potenciaEntresijos(int a, int n){
    int p;
    if (n==0) {
        printf("\tpotencia(%d,%d)\n\n",a,n);
        p = 1;
        printf("\n\nCASO BASE y su resultado\n\n");
        printf("\tpotencia(%d,%d) ---> resultado = %d\n\n",a,n,p);
        printf("\n\nASCENSO en la cadena de llamadas ... (se aplica la FUNCION de COMBINACION hasta alcanzar la llamada inicial)\n\n");
    } else {
        printf("\tpotencia(%d,%d)\n",a,n);
        p = potenciaEntresijos(a, n-1) * a;
        printf("\tpotencia(%d,%d) ---> resultado = %d\n",a,n,p);
    }

    return p;
}


int potencia3(int n) {
    if(n == 0 || n == 1) return 2 * n + 1; // n = 0 -> 1, n = 1 -> 3
    else if (n > 1) return 2 * potencia3(n - 1) + 3 * potencia3(n - 2);
}

int potencia3Entresijos(int n) {
    int p;
    printf("\tpotencia3(%d)\n", n);
    if (n == 0) {
        p = 1;
        printf("CASO BASE y su resultado:");
        printf("\tpotencia3(%d) ---> resultado = %d\n\n", n, p);
    } else if (n == 1) {
        p = 3;
        printf("CASO BASE y su resultado:");
        printf("\tpotencia3(%d) ---> resultado = %d\n\n", n, p);
    } else {
        printf("\tpotencia3(%d)\n", n);
        p = 2 * potencia3Entresijos(n - 1) + 3 * potencia3Entresijos(n - 2);
        printf("\tpotencia3(%d) ---> resultado = %d\n", n, p);
    }
    return p;
}


int mcd(int a, int b) {
    if(a < b) return mcd(a, b - a);
    else if(a > b) return mcd(a - b, b);
    return a; // if (a == b)
}

int mcdEntresijos(int a, int b) {
    printf("\tmcd(%d, %d)\n", a, b);
    if (a < b) mcdEntresijos(a, b - a);
    else if (a > b) mcdEntresijos(a - b, b);
    else if (a == b) printf("\tmcd(%d, %d) --> resultado = %d\n\n", a, b, a);
    return a;
}


int factorial(int n) {
  if(n >= 0 && n <= 1) return 1; // if ( n == 0 || n == 1)
  else return n * factorial(n - 1);
}

int numeroCifras(int n) {
  if(n >= 0 && n < 10) return 1;
  else return 1 + numeroCifras(n / 10);
}

int sumaCifras(int n) {
  if (n >= 0 && n < 10) return n;
  else return n % 10 + sumaCifras(n / 10);
}

int semifactorial(int n) {
  if (n >= 0 && n <= 1) return 1;
  else return n * semifactorial(n - 2);
}

int fibonacci(int n) {
  if(n >= 0 && n <= 1) return n;
  else return fibonacci(n - 1) + fibonacci(n - 2);
}

int rayuela(int n) {
  if(n == 1 || n == 2) return n;
  else return rayuela(n - 1) + rayuela(n - 2);
}

int plano(int i, int j) {
    if(i == 0 || j == 0) return 1;
    else return plano(i - 1, j) + plano(i, j - 1);
}

int tableros(int x, int y) {
    if(y == 1) return x*x;
    else tableros(x-1, y-1);
}

bool capicua(int *x, int i, int j) {
    if(i == j) return true;
    else if(i == j-1) return x[i] == x[j];
    else return capicua(x, i+1, j-1) && x[i] == x[j];
}

int sumaVector(int *x, int n) {
    if(n == 0) return x[0];
    else return x[n] + sumaVector(x, n-1);
}

bool matrizSimetrica(int **x, int n) {
    if(n == 0) return true;
    else return matrizSimetrica(x, n-1) && bandaSimetrica(x, n);
}

/* --- Zona iterativa --- */

int potenciaIterativo(int x, int n) {
    int res = 1;
    for(int i = 0; i < n; i++) {
        res *= x;
    }
    return res;
}

int mcdIterativo(int a, int b) {
    while(a != b) {
        if(a > b) a -= b;
        else b -= a;
    }
    return a;
}

int tablerosIterativo(int x, int y) {
    while(y != 0) {
        x -= 1;
        y -= 1;
    }
    return x*x;
}

_Bool capicuaIterativo(int *x, int n) {
    bool check = true;
    for(int i = 0; i < n - i && check; i++) {
        check &= x[i] == x[n - i];
    }
    return check;
}

int sumaVectorIterativo(int *x, int n) {
    int res = 0;
    for(int i = 0; i < n; i++) res += x[i];
    return res;
}

bool matrizSimetricaIterativo(int **x, int n) {
    bool check = true;
    for(int i = 0; i < n && check; i++) {
        for(int j = 0; j < n - 1 && check; i++) { // equivalente a bandaSimetrica(int**, int)
            check &= x[j][n-i] == x[n-i][j]; 
        }
    }
}

bool bandaSimetrica(int **x, int n) {
    for(int i = 0; i < n-1; i++) {
        if(x[i][n] != x[n][i]) return false;
    }
    return true;
}

