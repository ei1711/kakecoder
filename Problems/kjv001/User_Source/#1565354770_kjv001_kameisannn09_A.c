#include<stdio.h>
int main(void) {
   int hs[3], ms[3], ss[3];
   int ht[3], mt[3], st[3];
   int i;
   for (i = 0; i < 3; i++) {
      scanf("%d %d %d %d %d %d", &hs[i], &ms[i], &ss[i], &ht[i], &mt[i], &st[i]);
   }
   int h, m, s;
   int sa;
   int in;
   int out;
   for (i = 0; i < 3; i++) {
      in = hs[i] * 3600 + ms[i] * 60 + ss[i];
      out = ht[i] * 3600 + mt[i] * 60 + st[i];
      sa = out - in;
      h = sa / 3600;
      sa = sa - h * 3600;
      m = sa / 60;
      sa = sa - m * 60;
      s = sa;
      printf("%d %d %d\n", h, m, s);
   }
   return 0;
}
