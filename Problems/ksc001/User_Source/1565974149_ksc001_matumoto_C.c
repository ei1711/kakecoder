#include<stdio.h>
int main(void)
{
   int a[200],ai=0;
   unsigned long long int x,ans=1;
   scanf("%llu",&x);
   while(x>0){
      a[ai++]=x%10;
      x/=10;
   }
   for(int i=0;i<ai;i++){
      if(a[i]%2==0){
         printf("Even\n");
         return 0;
      }
   }
   printf("Odd\n");
   return 0;
}
