#include<stdio.h>
int main(void) {
   int n, m;
   scanf("%d %d", &n, &m);
   int a[10000];
   for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
   }
   int temp;
   for (int i = 1; i <= m; i++) {
      for (int j = 0; j < n - 1; j++) {
         if (a[j] % i > a[j + 1] % i) {
            temp = a[j + 1];
            a[j + 1] = a[j];
            a[j] = temp;
         }
      }
   }
   for (int i = 0; i < n; i++) {
      printf("%d\n", a[i]);
   }
   return 0;
}
