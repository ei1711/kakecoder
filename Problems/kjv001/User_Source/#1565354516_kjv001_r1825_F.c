#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define int long long
int dp[110][24];
int a[110];
int n;
int dfs ( int pos, int sum ) {
   if ( ~dp[pos][sum] ) return dp[pos][sum];
   if ( pos == n-1 ) {
      return sum == a[n-1];
   }
   int rec = 0;
   if ( sum - a[pos] >= 0  ) rec += dfs ( pos+1, sum - a[pos] );
   if ( sum + a[pos] <= 20 ) rec += dfs ( pos+1, sum + a[pos] );
   return dp[pos][sum] = rec;
}
signed main(){
   scanf("%lld", &n);
   for ( int i = 0; i < n; i++ ) {
      scanf("%lld", &a[i]);
   }
   memset(dp, -1, sizeof(dp));
   printf("%lld\n", dfs(1, a[0]));
   return 0;
}
