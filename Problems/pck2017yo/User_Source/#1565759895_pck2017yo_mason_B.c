#include<stdio.h>
int main(void){
   int a,b,c,d;
   scanf("%d %d %d",&a,&b,&c);
   d=a-c;
   if(-d<=b){
      if(d<0){
         printf("%d",-d);
      }if(d>=0){
         printf("0");        	 
      }
   }else if(-d>b){
      printf("NA");
   }
}
