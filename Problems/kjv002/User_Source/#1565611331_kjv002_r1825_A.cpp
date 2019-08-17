#include <bits/stdc++.h>
using namespace std;
int now = 0;
int i;
signed main ( ) {
   int a, b, c;
   cin >> a >> b >> c;
   for ( i = 1; now < c; i++ ) {
      now += a;
      if ( i % 7 == 0 ) now += b;
   }
   cout << i-1 << endl;
   return 0;
}
