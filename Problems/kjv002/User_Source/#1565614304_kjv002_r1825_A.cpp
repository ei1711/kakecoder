#include <bits/stdc++.h>
using namespace std;
signed main ( ) {
   int a, b, c;
   cin >> a >> b >> c;
   int coin = 0;
   int day = 0;
   while ( coin < c && ++day ) {
      coin += a;
      if ( day % 7 == 0 ) coin += b;
   }
   cout << day << endl;
   return 0;
}
