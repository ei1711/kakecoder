#include <stdio.h>
int main(void){
   int a,b,n,s[100],f[100];
   int i;
   int flg;
   scanf("%d", &a);
   scanf("%d", &b);
   scanf("%d", &n);
   for(i = 0;i < n;i ++){
      scanf("%d", &s[i]);
      scanf("%d", &f[i]);
   }
   flg = 1;
   for(i = 0;i < n;i ++){
      if(s[i] > a && s[i] < b){
         flg = 0;
         break;
      }
      else if(f[i] > a && f[i] < b){
         flg = 0;
         break;
      }
      else if(s[i] <= a && f[i] <= b){
         flg = 0;
         break;
      }
   }
   if(flg == 1){
      printf("1\n");
   }
   else if(flg == 0){
      printf("0\n");
   }
   return 0;
}
