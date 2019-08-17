#include<stdio.h>
#include<string.h>
int main(void)
{
   int x, y, z, i, j, k, n, m;
   int a[51], b[51], c[51];
   int sum, temp, min;
   scanf("%d", &x);
   for (i = 0; i < x; i++) {
      scanf("%d", &a[i]);
   }
   scanf("%d", &y);
   for (i = 0; i < y; i++) {
      scanf("%d", &b[i]);
   }
   scanf("%d", &z);
   for (i = 0; i < z; i++) {
      scanf("%d", &c[i]);
   }
   scanf("%d %d", &n, &m);
   for (i = 0; i < x - 1; i++) {
      for (j = i + 1; j < x; j++) {
         if (a[i] > a[j]) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
         }
      }
   }
   for (i = 0; i < y - 1; i++) {
      for (j = i + 1; j < y; j++) {
         if (b[i] > b[j]) {
            temp = b[i];
            b[i] = b[j];
            b[j] = temp;
         }
      }
   }
   for (i = 0; i < z - 1; i++) {
      for (j = i + 1; j < z; j++) {
         if (c[i] > c[j]) {
            temp = c[i];
            c[i] = c[j];
            c[j] = temp;
         }
      }
   }
   min = 99999999;
   for (i = 0; i < x; i++) {//a
   for (j = 0; j < y; j++) {//b
   for (k = 0; k < z; k++) {//c
   sum = a[i] + b[j] + c[k];
   if (sum >= n) {
      sum -= m;
   }
   if (min > sum) {
      min = sum;
   }
}
}
}
printf("%d\n", min);
return 0;
}
