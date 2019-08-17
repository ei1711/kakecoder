#include<stdio.h>
int main(void)
{
   int n, i, j;
   int a[10000], b[10000], c[10000], d[10000];
   int sc[100] = { 0 };
   int ran[100] = { 0 };
   scanf("%d", &n);
   for (i = 0; i < n*(n-1)/2; i++) {
      scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
   }
   for (i = 0; i < n*(n-1)/2; i++) {
      if (c[i] > d[i]) {
         sc[a[i]-1] += 3;
      }
      else if (c[i] < d[i]) {
         sc[b[i]-1] += 3;
      }
      else {
         sc[a[i]-1]++;
         sc[b[i]-1]++;
      }
   }
   for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
         if (i == j) {
            continue;
         }
         if (sc[i] < sc[j]) {
            ran[i]++;
         }
      }
   }
   for (i = 0; i < n; i++) {
      printf("%d\n", ran[i]+1);
   }
   return 0;
}
