#include<stdio.h>
int main(void) {
   int n, k;
   int a[100000];
   int sum[100000];
   int ans = 0;
   scanf("%d %d", &n, &k);
   for (int i = 0; i < n; i++) {
      sum[i] = 0;
   }
   for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
   }
   for (int i = 0; i < n; i++) {
      if (i != 0) {
         sum[i] = a[i] + sum[i - 1];
      }
      else {
         sum[i] = a[i];
      }
   }
   int sa = 0;
   for (int i = k; i < n; i++) {
      //printf("sum=%d %d\n", sum[i],sum[i-k]);
      sa = sum[i] - sum[i - k];
      if (sa > ans) {
         ans = sa;
      }
   }
   printf("%d\n", ans);
   return 0;
}
