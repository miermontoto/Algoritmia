float competicionInternacional(int a, int b, float p) {
  if(a == 0) return 1;
  else if(b == 0) return 0;
  return p * competicionInternacional(a - 1, b, p) +
      (1 - p) * competicionInternacional(a, b - 1, p);
} // llamada inicial (n, n, p)

float competicionInternacionalDyn(int n, float p) {
  //if(a != b) exit(-1);
  float q = 1 - p;

  float **resultsMatrix = (double**) malloc ((n)* sizeof(double*));
  for(int k = 0; k < n; k++)
    mi_matriz[k] = (double*) malloc ((n) * sizeof(double));

  for(int j = 1; j < n; j++) {
    resultsMatrix[j][0] = 0.0;
    resultsMatrix[0][j] = 1.0;
  }
  for(int i = 1; i < n; i++) for(int j = 1; j < n; j++) {
      resultsMatrix[i][j] = p * resultsMatrix[i - 1][j] +
                              q * resultsMatrix[i][j - 1];
  }
  return resultsMatrix[n-1][n-1];
}

float competicionInternacionalDyn2(int n, float p) {
  // con un solo vector, incializado a 0, 1, 1, ..., 1
  // reemplazando el valor de las columnas y por último el v[0]
  // el valor de la fila anterior se necesita hasta completar la fila
  int *resultsArray = (double*) malloc ((n) * sizeof(double));
  resultsArray[0] = 0;
  for(int i = 1; i < n; i++) resultsArray[i] = 1;

  for(int i = 1; i < n; i++) for(int j = 1; j < n; j++) {
    resultsArray[j] = p * resultsMatrix[j] +
                        q * resultsMatrix[j - 1];
  }
  return resultsArray[n-1][n-1];
}
