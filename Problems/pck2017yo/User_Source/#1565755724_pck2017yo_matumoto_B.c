#include<stdio.h>
int main(void)
{
   int a,b,c;
   scanf("%d %d %d",&a,&b,&c);
   if(a>=c){
      printf("0\n");
   }
   else{
      c=c-a;
      if(c>b){
         printf("%d\n",b);
      }
      else{
         printf("%d\n",c);
      }
   }
   return 0;
}
