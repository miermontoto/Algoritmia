int combinatorio(int n, int k) {
  if(k == 0 || k == n) return 1;
  else return combinatorio(n-1, k-1) + combinatorio(n-1, k);
}

int combinatorioDyn(int n, int k) {
  // ...
}
