#include <stdio.h>
int main(void) {
   char S[2000], SG[2000];
   int i, j, s, e, f;
   f = 0;
   scanf("%s", SG);
   scanf("%s", S);
   for (i = 0; S[i] != '\0'; i++) {
      if (S[i] == SG[0]) {
         f = 1;
         for (j = 0; SG[j] != '\0'; j++) {
            if (S[i + j] != SG[j]) {
               f = 0;
               break;
            }
         }
         if (f == 1) {
            printf("%d ", i);
            printf("%d", i + j - 1);
            break;
         }
      }
   }
}
