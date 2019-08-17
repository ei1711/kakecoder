#include <stdio.h>
#define max(X, Y) ((X) > (Y) ? (X) : (Y))
typedef long long ll;
ll n, k;
ll a[100005];
ll sum[100005];
ll ans = -1 * (1ll << 60ll);
int main() {
   scanf("%lld %lld", &n, &k);
   for (int i = 1; i <= n; i++) scanf("%lld", a + i);
   for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
   for (int i = 0; i + k <= n; i++) ans = max(ans, sum[i + k] - sum[i]);
   printf("%lld\n", ans);
   return 0;
}
