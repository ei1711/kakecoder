#include <stdio.h>
int main(void) {
   int n, a[100], i, j, c, cmax;
   scanf("%d", &n);
   for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);
   }
   cmax = 0;
   for (i = 0; i < n; i++) {
      if (a[i] == 0 && a[i + 1] == 1) {
         c = 0;
         for (j = i + 1; j < n; j++) {
            if (a[j] == 1) {
               c = c + 1;
            }
            else {
               break;
            }
         }
         if (cmax < c + 1) {
            cmax = c + 1;
         }
      }
   }
   printf("%d\n", cmax);
   return 0;
}
