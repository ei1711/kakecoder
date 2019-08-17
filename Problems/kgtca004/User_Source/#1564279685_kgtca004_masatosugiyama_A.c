#include <stdio.h>
int main(void) {
   int x, y, z;
   int h[1000], s[1000], j[1000];
   int mh, ms, mj;
   int i;
   mh = 1000000;
   ms = 1000000;
   mj = 1000000;
   scanf("%d", &x);
   for (i = 0; i < x; i++) {
      scanf("%d", &h[i]);
   }
   scanf("%d", &y);
   for (i = 0; i < y; i++) {
      scanf("%d", &s[i]);
   }
   scanf("%d", &z);
   for (i = 0; i < z; i++) {
      scanf("%d", &j[i]);
   }
   for (i = 0; i < x; i++) {
      if (mh > h[i]) {
         mh = h[i];
      }
   }
   for (i = 0; i < y; i++) {
      if (ms > s[i]) {
         ms = s[i];
      }
   }
   for (i = 0; i < z; i++) {
      if (mj > j[i]) {
         mj = j[i];
      }
   }
   printf("a%d", mh + ms + mj);
   return 0;
}
