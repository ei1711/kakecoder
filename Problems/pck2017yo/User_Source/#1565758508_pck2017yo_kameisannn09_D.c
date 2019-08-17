#include<stdio.h>
int main(void){
   int a,b;
   int n;
   scanf("%d %d %d",&a,&b,&n);
   int s[1000];
   int f[1000];
   for(int i=0;i<n;i++){
      scanf("%d",&s[i]);
      scanf("%d",&f[i]);
   }
   int in[1000]={};
   for(int i=0;i<n;i++){
      for(int j=s[i];j<=f[i]-1;j++){
         in[j]=1;
      }
   }
   //for(int i=0;i<11;i++){
      //  printf("%d\n",in[i]);
      //}
      for(int i=a;i<=b-1;i++){
         if(in[i]==1){
            printf("1\n");
            return 0;
         }
      }
      printf("0\n");
      return 0;
   }
