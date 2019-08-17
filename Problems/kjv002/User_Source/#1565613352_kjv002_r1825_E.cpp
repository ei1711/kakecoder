#include <bits/stdc++.h>
using namespace std;
struct Zip {
   char type;
   int length;
};
vector<Zip> zip;
signed main ( ) {
   int n;
   string s;
   cin >> s;
   n = s.size();
   for ( int i = 0; i < n; i++ ) {
      int len = 1;
      char now = s[i];
      while ( len+i < n && s[len+i] == now ) {
         len++;
      }
      Zip newZip;
      newZip.type = now;
      newZip.length = len;
      zip.push_back(newZip);
      i += len-1;
   }
   int ans = 0;
   for ( int i = 2; i < zip.size(); i++ ) {
      if ( zip[i-2].type == 'J' && zip[i-1].type == 'O' && 
      zip[i].type == 'I') {
         int J = zip[i-2].length;
         int O = zip[i-1].length;
         int I = zip[i-0].length;
         if ( O <= J && O <= I ) {
            ans = max ( ans, O );
         }
      }
   }
   cout << ans << endl;
}
