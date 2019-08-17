#include<stdio.h>
int main(void)
{
   unsigned long long int x, y;
   scanf("%lld %lld", &x, &y);
   while(1){
      if (x < y) {
         x = x * 2;
      }
      else if (x > y) {
         y = y *= 2;
      }
      else {
         printf("%lld\n", x);
         break;
      }
   }
   return 0;
}
