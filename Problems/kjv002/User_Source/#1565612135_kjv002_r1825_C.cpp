#include <bits/stdc++.h>
using namespace std;
struct Team {
   int id, score;
};
Team t[110];
bool cmp ( const Team &a, const Team &b ) {
   return a.score > b.score;
}
int rnk[110];
signed main ( ) {
   int n;
   cin >> n;
   for ( int i = 0; i < n; i++ ) {
      t[i].id = i;
      t[i].score = 0;
   }
   for ( int i = 0; i < n*(n-1)/2; i++ ) {
      int a, b, ap, bp;
      cin >> a >> b >> ap >> bp;
      a--;
      b--;
      if ( ap < bp ) {
         t[b].score += 3;
      }
      else if ( ap > bp ) {
         t[a].score += 3;
      }
      else {
         t[a].score++;
         t[b].score++;
      }
   }
   sort(t, t+n, cmp);
   for ( int i = 0; i < n; i++ ) {
      if ( i && t[i-1].score == t[i].score ) rnk[t[i].id] = rnk[t[i-1].id];
      else rnk[t[i].id] = i+1;
   }
   for ( int i = 0; i < n; i++ ) {
      cout << rnk[i] << endl;
   }
   return 0;
}
