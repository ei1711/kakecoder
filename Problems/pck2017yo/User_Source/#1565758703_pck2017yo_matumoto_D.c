#include<stdio.h>
int main(void)
{
   int a[100],b[100];
   int n,in,out;
   int time[1001]={0};
   scanf("%d %d",&in,&out);
   scanf("%d",&n);
   for(int i=0;i<n;i++){
      scanf("%d %d",&a[i],&b[i]);
   }
   for(int i=0;i<n;i++){
      for(int j=a[i]+1;j<=b[i]-1;j++){
         time[j]=1;
      }
   }
   int flag=0;
   for(int i=in;i<out;i++){
      if(time[i]==1){
         flag=1;
         break;
      }
   }/*
   for(int i=0;i<15;i++){
      printf("%d ",time[i]);
   }
   printf("\n");*/
   if(flag==1){
      printf("1\n");
   }
   else{
      printf("0\n");
   }
   return 0;
}
