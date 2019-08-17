#include <stdio.h>
#define max(X, Y) ((X) > (Y) ? (X) : (Y))
int main() {
   int n;
   int arr[110];
   int ans = 0;
   scanf("%d", &n);
   for (int i = 0; i < n; i++) scanf("%d", arr + i);
   for (int i = 0; i < n; i++) {
      int cnt = 0;
      while (arr[i + cnt]) cnt++;
      ans = max(cnt + 1, ans);
   }
   printf("%d\n", ans);
   return 0;
}
