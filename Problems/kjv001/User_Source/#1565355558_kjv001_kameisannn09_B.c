#include<stdio.h>
int main(void) {
   int n;
   int a[1000];
   int cnt = 1;
   int max = 0;
   scanf("%d", &n);
   for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
   }
   for (int i = 0; i < n; i++ ) {
      if (a[i] == 1) {
         cnt = 1;
         for (int j = i; a[i] == 1; i++) {
            cnt++;
         }
      }
      if (max < cnt) {
         max = cnt;
      }
   }
   printf("%d\n", max);
   return 0;
}
