#include <stdio.h>
int main(void){
   int a,b,c,co;
   int i;
   scanf("%d", &a);
   scanf("%d", &b);
   scanf("%d", &c);
   co = 0;
   for(i = 1;co < c;i ++){
      co = co + a;
      if(i % 7 == 0){
         co = co + b;
      }
      if(co >= c){
         break;
      }
   }
   printf("%d", i);
   return 0;
}
