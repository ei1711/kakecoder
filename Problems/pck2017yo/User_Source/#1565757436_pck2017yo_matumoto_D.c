#include<stdio.h>
int main(void)
{
   int a[100],b[100];
   int n,in,out;
   int time[25]={0};
   scanf("%d %d",&in,&out);
   scanf("%d",&n);
   for(int i=0;i<n;i++){
      scanf("%d %d",&a[i],&b[i]);
   }
   for(int i=0;i<n;i++){
      for(int j=a[i]+1;j<b[i]-1;j++){
         time[j]=1;
      }
   }
   int flag=0;
   for(int i=in+1;i<out-1;i++){
      if(time[i]==1){
         flag=1;
         break;
      }
   }
   if(flag==1){
      printf("0\n");
   }
   else{
      printf("1\n");
   }
   return 0;
}
