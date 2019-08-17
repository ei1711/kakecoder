#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int max ( int a, int b ) {
   if ( a < b ) return b;
   return a;
}
int rui[100100];
signed main(){
   int n, k;
   scanf("%d %d", &n, &k);
   for ( int i = 1; i <= n; i++ ) {
      scanf("%d", &rui[i]);
      rui[i] += rui[i-1];
   }
   int ans = rui[k];
   for ( int i = k+1; i <= n; i++ ) {
      ans = max ( ans, rui[i] - rui[i-k] );
   }
   printf("%d\n", ans);
   return 0;
}
