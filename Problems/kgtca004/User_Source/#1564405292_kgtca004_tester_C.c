#include<stdio.h>
int main(){
   int n,x,y;
   scanf("%d",&n);
   scanf("%d %d",&x,&y);
   int a2=2*(n-1)+n-x;
   int d=a2-(n-x);
   int ni;
   if((x+y)<n){
      printf("%d\n",n-x);
      return 0;
   }
   if((y+x-n)%d){
      ni=(y+x-n)/d+1;
   }else{
      ni=(y+x-n)/d;
   }
   printf("%d\n",(n-x)+d*ni);
   return 0;
}
