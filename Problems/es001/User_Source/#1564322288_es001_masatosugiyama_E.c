#include <stdio.h>
int main(void) {
   int n, i, j, c, f;
   scanf("%d", &n);
   c = 0;
   for (i = 2; i <= n; i++) {
      f = 0;
      for (j = 2; j < i; ++j) {
         if (i % j == 0) {
            f = 1;
            break;
         }
      }
      if (f == 0) {
         c = c + i;
      }
   }
   printf("%d", c);
   return 0;
}
