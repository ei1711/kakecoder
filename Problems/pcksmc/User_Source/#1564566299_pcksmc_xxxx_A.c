#include<stdio.h>
int main(){
   int n,m,i,x;
   scanf("%d %d",&n,&m);
   for(i=0:i<n;i++){
      scanf("%d",&x);
      if(m==x){
         if(i<1000)
         printf("%d\n",i+1);
         else
         printf("2\n");
      }
   }
   return 0;
}
