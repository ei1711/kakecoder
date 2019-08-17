#include <stdio.h>
struct Time { int h, m, s; };
int main() {
   struct Time a, b;
   for (int c = 0; c < 3; c++) {
      scanf("%d %d %d", &a.h, &a.m, &a.s);
      scanf("%d %d %d", &b.h, &b.m, &b.s);
      int t = (b.h * 60 * 60 + b.m * 60 + b.s) - (a.h * 60 * 60 + a.m * 60 + a.s);
      printf("%d ", t / (60 * 60)); t %= 60 * 60;
      printf("%d ", t / 60); t %= 60;
      printf("%d\n", t);
   }
   return 0;
}
