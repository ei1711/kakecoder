#include <stdio.h>
int main(void)
{
   int n, m, i;
   int x[5000];
   scanf("%d", &n);
   scanf("%d", &m);
   for (i = 0; i < n; i++) {
      scanf("%d", &x[i]);
   }
   for (i = 0; i < n; i++) {
      if (x[i] == m) {
         break;
      }
   }
   printf("%d\n", i + 1);
   return 0;
}
