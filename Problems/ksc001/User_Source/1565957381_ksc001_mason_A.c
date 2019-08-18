#include<stdio.h>
int main(void){
   int a,b;
   scanf("%d %d",&a,&b);
   if(a%b==0){
      printf("%d",a/b);
   }else if(a%b>=1){
      printf("%d",a/b+1);
   }
}
