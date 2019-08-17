#include<stdio.h>
int main(void)
{
   int n, m, i, k,t=0, s[101];
   scanf("%d %d", &n, &m);
   for (i = 0; i < n; i++) {
      scanf("%d", &s[i]);
   }
   for (k = 1; k <= m; k++) {
      for (i = 0; i < n-1; i++) {
         if (s[i] % k > s[i + 1] % k) {
            t= s[i];
            s[i] = s[i + 1];
            s[i + 1] = t;
         }
      }
   }
   for (i = 0; i < n; i++) {
      printf("%d\n", s[i]);
   }
   return 0;
}
