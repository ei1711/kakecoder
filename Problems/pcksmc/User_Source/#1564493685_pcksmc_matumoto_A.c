#include<stdio.h>
int main(void)
{
   //恋人いたらいいんですけどね
   int n, m;
   int x[10000];
   int i, j;
   scanf("%d %d", &n, &m);
   for (i = 0; i < n; i++) {
      scanf("%d", &x[i]);
   }
   for (i = 0; i < n; i++) {
      if (x[i] == m) {
         printf("%d\n", i+1);
         return 0;
      }
   }
   return 0;
}
