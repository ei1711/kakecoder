#include<stdio.h>
int main(void)
{
   int x,y;
   int min;
   scanf("%d %d",&x,&y);
   double tempx,tempy;
   tempx=(double)x/1.0;
   tempy=(double)y/1.5;
   if(tempx<tempy){
      min=(int)tempx;
   }
   else{
      min=(int)tempy;
   }
   printf("%d\n",min*2+1);
   return 0;
}
