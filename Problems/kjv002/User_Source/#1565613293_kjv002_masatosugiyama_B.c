#include <stdio.h>
int main(void){
   int i, j;
   int tmp;
   int n,m,a[100];
   scanf("%d", &n);
   scanf("%d", &m);
   for(i = 0;i < n;i ++){
      scanf("%d", &a[i]);
   }
   for(i = 1;i <= m;i ++){
      for(j = 0;j < n - 1;j ++){
         if(a[j] % i > a[j + 1] % i){
            tmp = a[j + 1];
            a[j + 1] = a[j];
            a[j] = tmp;
         }
      }
   }
   for(i = 0;i < n;i ++){
      printf("%d\n", a[i]);
   }
   return 0;
}
