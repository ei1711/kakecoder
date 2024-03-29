#include <bits/stdc++.h>
using namespace std;
vector<int> g[512];
int dist[512];
signed main ( ) {
   int n, m;
   cin >> n >> m;
   for ( int i = 0; i < m; i++ ) {
      int a, b;
      cin >> a >> b;
      g[a].push_back(b);
      g[b].push_back(a);
   }
   memset(dist, -1, sizeof(dist));
   dist[1] = 0;
   queue<int> que;
   que.push(1);
   while ( !que.empty() ) {
      int now = que.front();
      que.pop();
      for ( int i = 0; i < g[now].size(); i++ ) {
         int next = g[now][i];
         if ( dist[next] == -1 ) {
            dist[next] = dist[now] + 1;
            que.push(next);
         }
      }
   }
   int cnt = 0;
   for ( int i = 2; i <= n; i++ ) if ( dist[i] <= 2 && ~dist[i] ) cnt++;
   cout << cnt << endl;
}
