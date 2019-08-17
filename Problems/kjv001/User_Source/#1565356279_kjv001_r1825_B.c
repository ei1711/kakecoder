#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int a[110];
int mx;
int max ( int a, int b ) {
   if ( a < b ) return b;
   return a;
}
signed main(){
   int n;
   scanf("%d", &n);
   for ( int i = 1; i <= n; i++ ) {
      scanf("%d", &a[i]);
      if ( a[i-1] && a[i] ) a[i] += a[i-1];
      mx = max ( mx, a[i] );
   }
   printf("%d\n", mx+1);
   return 0;
}
