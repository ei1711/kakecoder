#include <bits/stdc++.h>
using namespace std;
char mas[3030][3030];
vector<int> l[3030], k[3030];
vector<pair<int, int> > vii;
signed main ( ) {
   int h, w;
   cin >> h >> w;
   for ( int i = 0; i < h; i++ ) {
      cin >> mas[i];
      for ( int j = 0; j < w; j++ ) {
         if ( mas[i][j] == 'J' ) {
            vii.push_back(make_pair(i, j));
         }
         if ( mas[i][j] == 'O' ) {
            l[i].push_back(j);
         }
         if ( mas[i][j] == 'I' ) {
            k[j].push_back(i);
         }
      }
   }
   long long ans = 0;
   for ( int i = 0; i < vii.size(); i++ ) {
      int I = vii[i].first;
      int J = vii[i].second;
      int L = l[I].size() - (upper_bound(l[I].begin(), l[I].end(), J) - l[I].begin());
      int K = k[J].size() - (upper_bound(k[J].begin(), k[J].end(), I) - k[J].begin());
      ans += L * K;
   }
   cout << ans << endl;
}
