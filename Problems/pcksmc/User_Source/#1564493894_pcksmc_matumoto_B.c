#include<stdio.h>
int main(void)
{
   //FizzBuzzいえあ
   int i, n;
   int a, b;
   scanf("%d", &n);
   for (i = 1; i <= n; i++) {
      a = b = 0;
      if (i % 3 == 0) {
         printf("Fizz");
         a = 1;
      }
      if (i % 5 == 0) {
         printf("Buzz");
         b = 1;
      }
      if (a == 0 && b == 0) {
         printf("%d", i);
      }
      printf("\n");
   }
   return 0;
}
