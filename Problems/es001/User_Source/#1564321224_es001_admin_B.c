#include <stdio.h>
int main(void) {
   char S[1000];
   int R, E, I, W, A;
   int i;
   R = 0;
   E = 0;
   I = 0;
   W = 0;
   A = 0;
   scanf("%s", S);
   for (i = 0; i < 1000; i++) {
      if (S[i] == 'r') {
         R = R + 1;
      }
      else if (S[i] == 'e') {
         E = E + 1;
      }
      else if (S[i] == 'i') {
         I = I + 1;
      }
      else if (S[i] == 'w') {
         W = W + 1;
      }
      else if (S[i] == 'a') {
         A = A + 1;
      }
      else if (S[i] == '\0') {
         break;
      }
   }
   printf("%d\n", R);
   printf("%d\n", E);
   printf("%d\n", I);
   printf("%d\n", W);
   printf("%d\n", A);
   return 0;
}
