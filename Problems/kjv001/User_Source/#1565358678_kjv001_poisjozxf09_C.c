#include <stdio.h>
int n, m;
int card[210];
void cut(int k);
void riffle(void);
int main() {
   scanf("%d %d", &n, &m);
   for (int i = 0; i < 2 * n; i++) card[i] = i + 1;
   for (int i = 0; i < m; i++) {
      int k;
      scanf("%d", &k);
      if (k == 0) riffle();
      else cut(k);
   }
   for (int i = 0; i < 2 * n; i++) {
      printf("%d\n", card[i]);
   }
   return 0;
}
void cut(int k) {
   int tmp[210];
   for (int i = 0; i < 2 * n; i++) tmp[i] = card[i];
   for (int i = 0; i + k < 2 * n; i++) card[i] = card[i + k];
   for (int i = 0, j = 2 * n - k; i < k; i++, j++) card[j] = tmp[i];
}
void riffle(void) {
   int tmp[210];
   for (int i = 0; i < 2 * n; i++) tmp[i] = card[i];
   for (int i = 0, j = 0; i < n; i++, j += 2) card[j] = tmp[i], card[j + 1] = tmp[i + n];
}
