#include <stdio.h>
#include <string.h>
int  n, m;
char name[128];
char boards[128][128];
int  length[128];
int  ans = 0;
int main() {
   scanf("%d", &n);
   scanf("%s", name);
   for (int i = 0; i < n; i++) scanf("%s", boards[i]);
   for (int i = 0; i < n; i++) length[i] = strlen(boards[i]);
   m = strlen(name);
   for (int i = 0; i < n; i++) {
      int c = 0;
      for (int k = 1; k <= length[i] && c < m; k++) {
         for (int j = 0; j < length[i] && c < m; j++) {
            c = 0;
            for (int s = j; boards[i][s] == name[c] && c < m && s < length[i]; s += k, c++);
         }
      }
      if (c == m) {
         ans++;
      }
   }
   printf("%d\n", ans);
   return 0;
}
