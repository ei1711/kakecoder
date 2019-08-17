#include <stdio.h>
#include <stdint.h>
int main() {
   int64_t n;
   int64_t x, y;
   scanf("%lld", &n);
   scanf("%lld %lld", &x, &y);
   if (y > 100000000ll) {
      int64_t l, r, m;
      int64_t s;
      int64_t d;
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
   }
   else {
      int64_t p = x;
      int64_t ans = 0;
      while (1) {
         while (p < n) p++, ans++;
         if (ans >= y) break;
         while (p > 1) p--, ans++;
      }
      printf("%lld\n", ans);
   }
   return 0;
}
