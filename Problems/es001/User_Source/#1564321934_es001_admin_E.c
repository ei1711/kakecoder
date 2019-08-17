#include<stdio.h>
int main(void) {
   int n;
   int i, j, k;
   double sum = 2.0;
   int plist[500000], pend;
   int flag = 0;
   pend = 0;
   plist[pend++] = 2;
   scanf("%d", &n);
   for (i = 3; i <= n; i+=2) {
      flag = 0;
      for (j = 0; j < pend; j++) {
         if (!(i % plist[j])) {
            flag = 1;
            break;
         }
      }
      if (!flag) {
         sum += (double)i;
         plist[pend++] = i;
      }
   }
   printf("%.0lf\n", sum);
   return 0;
}
