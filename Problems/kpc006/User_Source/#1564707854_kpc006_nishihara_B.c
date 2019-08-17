#include<stdio.h>
int main(void)
{
   int X,Y,Z;
   scanf("%d",&X);
   scanf("%d",&Y);
   Z=0;
   Z=X*Y;
   if(Z<=0){
      Z=Z*(-1);
   }else{
      Z=Z;
   }
   printf("%d\n",Z);
   return 0;
}
