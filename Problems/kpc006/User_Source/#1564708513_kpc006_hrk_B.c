#include<stdio.h>
int main(void)
{
   unsigned long long int x, xn=0, y, yn=0, i = 2,j=2;
   scanf("%llu %llu", &x, &y);
   xn = x;
   yn = y;
   while (1) {
      if (xn < yn) {
         xn = x * i;
         i++;
      }
      else if (xn > yn) {
         yn = y * j;
         j++;
      }
      else {
         printf("%llu\n", xn);
         break;
      }
   }
   return 0;
}
