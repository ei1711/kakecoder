#include<stdio.h>
int main(void)
{
   int x,y;
   int min;
   scanf("%d %d",&x,&y);
   int tempx,tempy;
   tempx=x;
   tempy=y/1.5;
   if(tempx<tempy){
      min=tempx;
   }
   else{
      min=tempy;
   }
   printf("%d\n",min*2+1);
   return 0;
}
