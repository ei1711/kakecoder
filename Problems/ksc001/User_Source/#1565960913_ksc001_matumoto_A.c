#include<stdio.h>
int main(void)
{
   int a, b;
   scanf("%d %d", &a, &b);
   int n;
   n = a / b;
   if (a % b != 0) {
      n++;
   }
   printf("%d\n", n);
   return 0;
}
