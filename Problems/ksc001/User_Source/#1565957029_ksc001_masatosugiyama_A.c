#include <stdio.h>
int main(void){
   int a,b,ans;
   scanf("%d", &a);
   scanf("%d", &b);
   ans = a / b;
   if(a % b != 0){
      ans = ans + 1;
   }
   printf("%d\n", ans);
   return 0;
}
