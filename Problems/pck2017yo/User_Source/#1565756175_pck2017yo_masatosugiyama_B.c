#include <stdio.h>
int main(void){
   int m,f,b;
   scanf("%d", &m);
   scanf("%d", &f);
   scanf("%d", &b);
   if(m >= b){
      printf("0\n");
   }
   else if(m < b && m + f >= b){
      printf("%d\n", b - m);
   }
   else if(m + f < b){
      printf("NA\n");
   }
   return 0;
}
