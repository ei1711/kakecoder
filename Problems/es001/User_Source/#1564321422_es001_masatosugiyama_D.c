#include <stdio.h>
int main(void) {
   int n, t, ans;
   scanf("%d", &n);
   scanf("%d", &t);
   ans = 8 + n - 1;
   ans = ans * t;
   printf("%d", ans);
   return 0;
}
