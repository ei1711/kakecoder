#include<stdio.h>
int main(void){
   int cnt=2;
   int x,y;
   scanf("%d %d",&x,&y);
   if(x%2==0&&y%2==0){
      cnt++;
   }
   int syou;
   int amari;
   if(x>=y){
      syou=x/y;
      amari=x%y;
   }else{
      syou=y/x;
      amari=y%x;
   }
   syou=syou*2;
   amari=amari*2;
   cnt+=amari+syou;
   printf("%d\n",cnt);
   return 0;
}
