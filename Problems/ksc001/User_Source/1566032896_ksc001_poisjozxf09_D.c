#include <stdio.h>
#include <stdint.h>
int main() {
   int64_t n;
   int64_t x, y;
   int64_t s, d;
   scanf("%lld", &n);
   scanf("%lld %lld", &x, &y);
   s = n - x;
   d = 2 * n - 2;
   y -= s;
   if (y > 0) {
      printf("%lld\n", s + ((y + d - 1) / d) * d);
   }
   else {
      printf("%lld\n", s);
   }
   return 0;
}
