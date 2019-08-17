#include <stdio.h>
#include <stdlib.h>
typedef long long ll;
ll n;
ll arr[128];
ll right_value;
ll dp[32][128];
ll solve(ll sum, ll idx);
int main() {
   for (int i = 0; i < 32; i++) for (int j = 0; j < 128; j++) dp[i][j] = -1;
   scanf("%lld", &n);
   for (int i = 0; i < n - 1; i++) scanf("%lld", arr + i);
   scanf("%lld", &right_value);
   printf("%lld\n", solve(arr[0], 1));
   return 0;
}
ll solve(ll sum, ll idx) {
   if (sum > 20 || sum < 0 || (idx >= n - 1 && sum != right_value)) return 0;
   if (idx == n - 1 && sum == right_value) return 1;
   if (dp[sum][idx] != -1) return dp[sum][idx];
   return dp[sum][idx] = solve(sum + arr[idx], idx + 1) + solve(sum - arr[idx], idx + 1);
}
