#include<stdio.h>
#include<string.h>
int main(void)
{
   int i, j;
   int n, t;
   scanf("%d %d", &n, &t);
   n = n - 1;
   n = n + 8;
   n *= t;
   printf("%d\n", n);
   return 0;
}
