#include<stdio.h>
int main(void)
{
   int a, b, c, d=0, i=0,j=0;
   scanf("%d %d %d", &a, &b, &c);
   while (1) {
      i += 1;
      d += a;
      if (i == 7) {
         d += b;
         j += i;
         i = 0;
      }
      if (d >= c) {
         printf("%d\n", j + i);
         break;
      }
   }
   return 0;
}
