#include<stdio.h>
int main(void){
   int n;
   scanf("%d",&n);
   int sa;
   int ans;
   if(n>=9){
      sa=n-9;
      ans=sa%7;
      if(ans==0){
         printf("sat\n");
      }
      if(ans==1){
         printf("sun\n");
      }
      if(ans==2){
         printf("mon\n");
      }
      if(ans==3){
         printf("tue\n");
      }
      if(ans==4){
         printf("wed\n");
      }
      if(ans==5){
         printf("thu\n");
      }
      if(ans==6){
         printf("fri\n");
      }
   }else{
      sa=9-n;
      ans=sa%7;
      if(ans==0){
         printf("sat\n");
      }
      if(ans==1){
         printf("fri\n");
      }
      if(ans==2){
         printf("thu\n");
      }
      if(ans==3){
         printf("wed\n");
      }
      if(ans==4){
         printf("tue\n");
      }
      if(ans==5){
         printf("mon\n");
      }
      if(ans==6){
         printf("sun\n");
      }
   }
   return 0;
} 
