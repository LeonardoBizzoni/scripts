#include <stdio.h>
#include <stdlib.h>

int mcd(int a, int b) { return a == 0 ? b : mcd(b % a, a); }

int phi(int n) {
  int res = 1;

  for (int i = 2; i < n; i++) {
    if (mcd(i, n) == 1) {
      res++;
    }
  }

  return res;
}

int main(int argc, char **argv) {
  int n = atoi(argv[1]);
  char all_phi = 'y';

  printf("phi(%d) = %d\n", n, phi(n));

  printf("Calcolare phi(n) <= %d? [Y/n] ", n);
  scanf("%c", &all_phi);

  if (all_phi == 'y' || all_phi == '\n') {
    printf("n = ");

    for (int i = 1, exit_cond = 0; exit_cond < 1000; i++) {
      if (phi(i) <= n) {
        printf("%d ", i);
        exit_cond = 0;
      } else {
        exit_cond++;
      }
    }
  }
}