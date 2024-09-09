#include <stdio.h>

int main(void) {
  int k, a, b, c, L[1000] = {};

  printf("Digite quatro números inteiros (formato: n n n n):\n");
  scanf("%d %d %d %d", &k, &a, &b, &c);

  L[0] = k;
  int i = 0;
  while (i < 999) {
    L[i + 1] = ((L[i] * a) % b) + c;
    i++;
  }

  i = 0;
  int passos = 0;
  int loop = 0;
  while (L[i] != 0) {
    int pos = i;
    if (L[i] > 0) {
      passos = passos + L[i];
      i = i + L[i];
      L[pos] = (L[pos] - 1);
    } else if (L[i] < 0) {
      passos = passos - L[i];
      i = i + L[i];
      L[pos] = (L[pos] + 1);
    }
    while (i > 999) {
      i = i - 1000;
    }
    while (i < 0) {
      i = i + 1000;
    }
    loop++;
  }
  printf("Acabou! Parou na posição %d depois de dar %d passos! Loop == %d", i, passos, loop);
}
