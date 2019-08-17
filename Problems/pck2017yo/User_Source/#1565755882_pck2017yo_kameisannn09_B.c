#include<stdio.h>
int main(void){
   int a,b,c;
   scanf("%d %d %d",&a,&b,&c);
   if(a<c){
      int sa=c-a;
      if(b>sa){
         printf("%d\n",sa);
      }else{
         printf("NA\n");
      }
   }else{
      printf("0\n");
   }
   return 0;
}
