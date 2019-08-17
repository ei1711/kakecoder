#include<stdio.h>
int main(void) {
   int n;
   scanf("%d", &n);
   if (n == 0) {
      printf("%d\n", n);
   }
   else {
      for (int i = 0; i < n; i++) {
         if ((i + 1) % 3 == 0 && (i + 1) % 5 == 0) {
            printf("Fizz Buzz\n");
         }
         else if ((i + 1) % 3 == 0) {
            printf("Fizz\n");
         }
         else if ((i + 1) % 5 == 0) {
            printf("Buzz\n");
         }
         else {
            printf("%d\n", i + 1);
         }
      }
   }
   return 0;
}
