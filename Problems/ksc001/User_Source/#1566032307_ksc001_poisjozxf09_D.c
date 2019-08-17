#include <stdio.h>
#include <stdint.h>
int main() {
   int64_t n;
   int64_t x, y;
   int64_t l, r, m;
   int64_t s;
   int64_t d;
   scanf("%lld", &n);
   scanf("%lld %lld", &x, &y);
   d = 2ll * n - 2ll;
   s = n - x;
   l = 0ll; r = 1ll << 40ll;
   while (r - l > 1ll) {
      m = (r + l) / 2ll;
      if (s + d * m >= y) {
         r = m;
      }
      else {
         l = m;
      }
   }
   printf("%lld\n", s + d * r);
   return 0;
}
