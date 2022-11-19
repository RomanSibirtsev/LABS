#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  int a1, a, res = 0, two, two_r, k = 0;
  scanf("%d", &a);
  a1 = a;
  for (int i = 1; a1 > 0; ++i) {
    k = i;
    a1 /= 10;
  }

  two = a % (int) pow(10, k - 1) / pow(10, k - 2);
  two_r = a % 100 / 10;

  for (int i = 0; a > 0; ++i) {
    if (i == 1) {
      res += two;
    } else if (i == k - 2) {
      res += two_r;
    } else {
      res += a % 10;
    }
      res *= 10;
    a /= 10;
  }

  res /= 10;
  a = res;
  res = 0;

  for (int i = 0; a > 0; ++i) {
    res += a % 10;
    res *= 10;
    a /= 10;
  }

  res /= 10;
  printf("%d", res);
}
