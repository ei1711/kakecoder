#include <stdio.h>
int main(void) {
   long int xy, c;
   int x, y, i;
   scanf("%d", &x);
   scanf("%d", &y);
   c = 0;
   xy = x * y;
   for (i = 1; i <= xy; i++) {
      if (i % xy == 0) {
         c = c + 1;
      }
   }
   printf("%ld", c);
   return 0;
}
