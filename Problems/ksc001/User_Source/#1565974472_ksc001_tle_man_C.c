#include<stdio.h>
int main(){
   char x[1000];
   scanf("%s",x);
   int x_pow=1;
   for(int i=0;x[i]!='\0';i++){
      x_pow*=(x[i]-0x30);
   }
   if(x_pow%2)printf("Odd\n");
   else printf("1Even\n");
   return 0;
}
