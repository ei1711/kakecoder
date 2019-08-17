#include <bits/stdc++.h>
using namespace std;
int z[110];
signed main ( ) {
   int n, m;
   cin >> n >> m;
   for ( int i = 0; i < n; i++ ) {
      cin >> z[i];
   }
   for ( int i = 1; i <= m; i++ ) {
      for ( int j = 0; j < n-1; j++ ) {
         if ( z[j] % i > z[j+1] % i ) {
            swap(z[j], z[j+1]);
         }
      }
   }
   for ( int i = 0; i < n; i++ ) cout << z[i] << endl;
   return 0;
}
