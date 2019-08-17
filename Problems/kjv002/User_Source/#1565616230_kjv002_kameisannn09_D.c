#include<stdio.h>
int main(void) {
   int n, m;
   scanf("%d %d", &n, &m);
   static int a[100000], b[100000];
   int fre[20000] = {};
   fre[0] = 1;
   for (int i = 0; i < m; i++) {
      scanf("%d", &a[i]);
      scanf("%d", &b[i]);
   }
   int cnt = 0;
   for (int i = 0; i < m; i++) {
      if (a[i] == 1) {
         fre[b[i] - 1] = 1;
         cnt++;
      }
   }
   for (int i = 0; i < m; i++) {
      if (fre[a[i] - 1] == 1 && fre[b[i] - 1] == 1) {
         continue;
      }
      if (fre[a[i] - 1] == 1) {
         if (fre[b[i] - 1] != 2) {
            fre[b[i] - 1] = 2;
            cnt++;
         }
      }
      else if (fre[b[i] - 1] == 1) {
         if (fre[a[i] - 1] != 2) {
            fre[a[i] - 1] = 2;
            cnt++;
         }
      }
   }
   printf("%d\n", cnt);
   return 0;
}
