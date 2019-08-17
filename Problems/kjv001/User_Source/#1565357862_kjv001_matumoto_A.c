#include<stdio.h>
int main(void) {
   int h, m, s;
   int inh, inm, ins, outh, outm, outs;
   int i, j;
   int sum1, sum2;
   int h1[3], m1[3], s1[3];
   for (i = 0; i < 3; i++) {
      h = m = s = 0;
      scanf("%d %d %d %d %d %d", &inh, &inm, &ins, &outh, &outm, &outs);
      sum1 = inh * 3600 + inm * 60 + ins;
      sum2 = outh * 3600 + outm * 60 + outs;
      sum2 -= sum1;
      if (sum2 >= 3600) {
         h = sum2 / 3600;
         sum2 -= h * 3600;
      }
      if (sum2 >= 60) {
         m = sum2 / 60;
         sum2 -= m * 60;
      }
      if (sum2 >= 1) {
         s = sum2;
         sum2 -= s;
      }
      h1[i] = h;
      m1[i] = m;
      s1[i] = s;
   }
   for (i = 0; i < 3; i++) {
      printf("%d %d %d\n", h1[i], m1[i], s1[i]);
   }
}
