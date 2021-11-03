int rayuela(int n, int* rbfr) {
  if(n == 1 || n == 2) return n;
  else return rbfr[n - 2] + rbfr[n - 3];
}

int main() {
  int n = 8;
  int* rbfr = (int*) malloc (n*sizeof(int));;
  for(int i = 0; i < n; i++) {
    rbfr[i] = rayuela(i + 1, rbfr);
  }

  int result = rbfr[n];
  return 0;
}

int rayuelaDynIterativo(int n) {
  int* rbfr = (int*) malloc (n*sizeof(int));
  rbfr[0] = 1;
  rbfr[1] = 2;
  for(int i = 2; i < n, i++) {
    rbfr[i] = rbfr[i - 1] + rbfr[i - 2];
  }

  return rbfr[n-1];
}

int rayuelaDynIterativo2(int n) {
  int a = 1, b = 2;
  if(n <= 2) return a;

  for(int i = 3; i < n; i++) {
    b = a + b;
    a = b - a;
  }

  return b;
}
