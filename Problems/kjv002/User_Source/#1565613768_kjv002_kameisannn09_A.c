#include<stdio.h>
int main(void) {
   int a, b, c;
   scanf("%d %d %d", &a, &b, &c);
   int sum = 0;
   int cnt = 0;
   for (int i = 1; sum < c; i++) {
      sum = sum + a;
      if (i % 7 == 0) {
         sum = sum + b;
      }
      cnt++;
   }
   printf("%d\n", cnt);
   return 0;
}
