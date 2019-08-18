#include<stdio.h>
int main(void)
{
   int ai=0,a[200];
   unsigned long long int x,ans;
   scanf("%llu",&x);
   while(x>0){
      a[ai++]=x%10;
      x/=10;
   }
   ans=1;
   for(int i=0;i<ai;i++){
      ans*=a[i];
   }
   if(ans%2==0){
      printf("Even\n");
   }
   else{
      printf("Odd\n");
   }
   return 0;
}
