#include <stdio.h>
int main(void)
{
   int n, m, h1, d1, i, ans, h[1000], d[1000];
   h1 = 0;
   d1 = 0;
   scanf("%d", &n);
   for (i = 0; i < n; i++) {
      scanf("%d", &h[i]);
   }
   scanf("%d", &m);
   for (i = 0; i < m; i++) {
      scanf("%d", &d[i]);
   }
   for (i = 0; i < n; i++) {
      if (h[i] < h1) {
         h1 = h[i];
      }
   }
   for (i = 0; i < m; i++) {
      if (d[i] < d1) {
         d1 = d[i];
      }
   }
   ans = h1 + d1;
   printf("%d", ans);
   return 0;
}
