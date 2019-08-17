#include <bits/stdc++.h>
using namespace std;
signed main ( ) {
   int n, m;
   cin >> n >> m;
   vector<int> a;
   for ( int i = 0; i < n; i++ ) {
      int A;
      cin >> A;
      a.push_back(A);
   }
   for ( int i = 1; i <= m; i++ ) {
      for ( int j = 0; j < n-1; j++ ) {
         if ( a[j] % i > a[j+1] % i ) {
            swap(a[j], a[j+1]);
         }
      }
   }
   for ( int i = 0; i < n; i++ ) {
      cout << a[i] << endl;
   }
   return 0;
}
