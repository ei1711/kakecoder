#include<stdio.h>
int main(void) {
   int a, b;
   scanf("%d %d", &a, &b);
   int ans = 0;
   ans = a / b;
   a -= ans * b;
   if (a > 0) {
      ans++;
   }
   printf("%d\n", ans);
   return 0;
}
