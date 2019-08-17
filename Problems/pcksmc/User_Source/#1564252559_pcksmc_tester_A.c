#include <stdio.h>
int main() {
   int n, m;
   int x[1000];
   int ans;
   int i;
   scanf("%d %d", &n, &m);
   for (i = 0; i < n; i++) {
      scanf("%d", &x[i]);
   }
   for (i = 0; i < n; i++) {
      if (x[i] == m) {
         ans = i + 1;
         break;
      }
   }
   printf("%d\n", ans);
   return 0;
}
