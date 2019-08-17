#include<stdio.h>
int main() {
   int n;
   int a, b, c, d;
   int team[10000];
   scanf("%d", &n);
   for (int i = 0; i < n; i++) {
      team[i] = 0;
   }
   for (int i = 0; i < n * (n - 1) / 2; i++) {
      scanf("%d %d %d %d", &a, &b, &c, &d);
      if (c > d) {
         team[a - 1] += 3;
      }
      else if (c < d) {
         team[b - 1] += 3;
      }
      else {
         team[b - 1] += 1;
         team[a - 1] += 1;
      }
   }
   int rank = 1;
   for (int i = 0; i < n; i++) {
      rank = 1;
      for (int j = 0; j < n; j++) {
         if (team[i] < team[j]) {
            rank++;
         }
      }
      printf("%d\n", rank);
   }
   return 0;
}