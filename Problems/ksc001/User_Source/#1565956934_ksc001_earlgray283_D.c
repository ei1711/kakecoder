#include<stdio.h>
typedef long long int ll;
int main(){
   ll n,x,y;
   scanf("%lld",&n);
   scanf("%lld %lld",&x,&y);
   /*
   if(n-x>=y){
      printf("%d\n",n-x);
      return 0;
   }
   */
   ll a=n-x;
   ll d=(n-1)*2;
   ll tmp=(-a+y+d)%d?(-a+y+d)/d+1:(-a+y+d)/d;
   printf("%lld\n",a+d*(tmp-1));
   return 0;
}
