#include<stdio.h>
int main(void)
{
   int n;
   scanf("%d",&n);
   //9 土　２　土
   n=n%7;
   switch(n){
      case 1:
      printf("金\n");
      break;
      case 2:
      printf("土\n");
      break;
      case 3:
      printf("日\n");
      break;
      case 4:
      printf("月\n");
      break;
      case 5:
      printf("火\n");
      break;
      case 6:
      printf("水\n");
      break;
      case 7:
      printf("木\n");
      break;
   }
   return 0;
}
