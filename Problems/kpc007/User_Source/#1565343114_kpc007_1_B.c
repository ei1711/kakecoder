#include <stdio.h>
int main() {
   int n;
   int c, d;
   int ans = 1;
   scanf("%d", &n);
   for (int i = 0; i < n; i++) {
      scanf("%d %d", &c, &d);
      if (c == d % 2) {
         ans -= d;
      }
      else {
         ans += d;
      }
   }
   printf("%d\n", ans);
   return 0;
}
