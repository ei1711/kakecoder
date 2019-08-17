#include<stdio.h>
int main(void) {
   int n, m;
   scanf("%d %d", &n, &m);
   int x[10000];
   for (int i = 0; i < n; i++) {
      scanf("%d", &x[i]);
   }
   for (int i = 0; i < n; i++) {
      if (x[i] == m) {
         printf("%d\n", i + 1);
         break;
      }
   }
   return 0;
}
