#include <stdio.h>
int main() {
   int a, b;
   scanf("%d %d", &a, &b);
   if (b == 0) {
      puts("div0. fuck.");
      return 1;
   }
   printf("%d\n", (a + b - 1) / b);
   return 0;
}
