#include <stdio.h>
int main(void){
   int maxdiv,div,x,y,ans;
   int i;
   scanf("%d", &x);
   scanf("%d", &y);
   if(x <= y){
      div = x;
   }
   else if(x > y){
      div = y;
   }
   for(i = div;i > 0;i --){
      if(x % i == 0 && y % i == 0){
         maxdiv = i;
         break;
      }
   }
   x = x + 1;
   y = y + 1;
   maxdiv = maxdiv + 1;
   ans = x + y;
   ans = ans - maxdiv;
   printf("%d\n", ans);
   return 0;
}
