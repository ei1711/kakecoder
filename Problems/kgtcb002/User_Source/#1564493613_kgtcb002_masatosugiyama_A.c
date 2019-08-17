#include <stdio.h>
int main(void)
{
   int x, y, ans;
   scanf("%d", &x);
   scanf("%d", &y);
   ans = x - y;
   if (ans >= 0) {
      printf("%d", ans);
   }
   else {
      printf("%d", 0 - ans);
   }
   return 0;
}
