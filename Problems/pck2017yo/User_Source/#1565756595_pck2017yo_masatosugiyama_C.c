#include <stdio.h>
int main(void){
   int x;
   scanf("%d", &x);
   if(x % 7 == 0){
      printf("thu\n");
   }
   else if(x % 7 == 1){
      printf("fri\n");
   }
   else if(x % 7 == 2){
      printf("sat\n");
   }
   else if(x % 7 == 3){
      printf("sun\n");
   }
   else if(x % 7 == 4){
      printf("mon\n");
   }
   else if(x % 7 == 5){
      printf("tue\n");
   }
   else if(x % 7 == 6){
      printf("wed\n");
   }
   return 0;
}
