#include<stdio.h>
int main(void)
{
   int n;
   scanf("%d",&n);
   //9 土　２　土
   n=n%7;
   switch(n){
      case 1:
      printf("fri\n");
      break;
      case 2:
      printf("sat\n");
      break;
      case 3:
      printf("sun\n");
      break;
      case 4:
      printf("mon\n");
      break;
      case 5:
      printf("tue\n");
      break;
      case 6:
      printf("wed\n");
      break;
      case 7:
      printf("thu\n");
      break;
   }
   return 0;
}
