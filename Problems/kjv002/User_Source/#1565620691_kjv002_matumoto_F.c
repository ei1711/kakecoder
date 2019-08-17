#include<stdio.h>
#include<string.h>
int main(void)
{
   int h, w, i, j;
   static char a[3001][3001];
   static int b[3000][3000] = { 0 };
   static int c[3000][3000] = { 0 };
   int ob, in;
   long long int ans = 0;
   scanf("%d %d", &h, &w);
   for (i = 0; i < h; i++) {
      scanf("%s", a[i]);
   }
   for (i = 0; i < h; i++) {
      ob = 0;
      for (int k = w - 1; k >= 0; k--) {
         if (a[i][k] == 'O') {
            ob++;
         }
         b[i][k] = ob;
      }
   }
   for (j = 0; j < w; j++) {
      in = 0;
      for (int k = h - 1; k >= 0; k--) {
         if (a[k][j] == 'I') {
            in++;
         }
         c[k][j] = in;
      }
   }
   /*for (i = 0; i < h; i++) {
      for (j = 0; j < w; j++) {
         printf("%d ", b[i][j]);
      }
      printf("\n");
   }
   for (i = 0; i < h; i++) {
      for (j = 0; j < w; j++) {
         printf("%d ", c[i][j]);
      }
      printf("\n");
   }*/
   for (i = 0; i < h; i++) {
      for (j = 0; j < w; j++) {
         if (a[i][j] == 'J') {
            ans += b[i][j] * c[i][j];
         }
      }
   }
   printf("%lld\n", ans);
   return 0;
}
