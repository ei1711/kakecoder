#include<stdio.h>
int main(){
   char x[100];
   scanf("%s",x);
   int sum=0;
   for(int i=0;x[i]!='\0';i++){
      if((x[i]-0x30)%2==0){
         printf("Even\n");
         return 0;
      }
   }
   printf("Odd\n");
   return 0;
}
