#include <bits/stdc++.h>
using namespace std;
// logつけたらTLEした
char mas[3030][3030];
int ar[3030];
signed main ( ) {
   int h, w;
   cin >> h >> w;
   for ( int i = 0; i < h; i++ ) {
      cin >> mas[i];
   }
   long long ans = 0;
   for ( int i = h-1; i >= 0; i-- ) {
      int u = 0;
      for ( int j = w-1; j >= 0; j-- ) {
         if ( mas[i][j] == 'I' ) ar[j]++;
         if ( mas[i][j] == 'O' ) u++;
         if ( mas[i][j] == 'J' ) ans += u*ar[j];
      }
   }
   cout << ans << endl;
   return 0;
}
