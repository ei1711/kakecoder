#include<stdio.h>
int main(void) {
   int n, i, j;
   int a[100];
   int co = 0, max = -1;
   scanf("%d", &n);
   for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);
   }
   for (i = 0; i < n; i++) {
      co = 0;
      if (a[i] == 1) {
         for (j = i; a[j] == 1; j++) {
            co++;
         }
      }
      if (max < co) {
         max = co;
      }
   }
   printf("%d\n", max + 1);
   return 0;
}
