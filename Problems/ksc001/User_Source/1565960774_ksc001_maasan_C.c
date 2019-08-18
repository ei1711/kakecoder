#include<stdio.h>
int main(void){
   int x[10000],i,n;
   for(i=0;x[i]=='\n';i++){
      scanf("%d",&x[i]);
   }	
   n=i+1;
   for(i=1;i<n;i++){
      x[0]=x[0]*x[0+i];
   }
   if(x[0]%2==0){
      printf("Odd");
   }else{
      printf("Even");
   }
}
