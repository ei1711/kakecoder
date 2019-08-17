#include<stdio.h>
int main(void) {
   char s[100001];
   scanf("%s", s);
   int cr = 0, ce = 0, ci = 0, cw = 0,ca = 0;
   for (int i = 0; s[i] != '\0'; i++) {
      if (s[i] == 'r') {
         cr++;
      }
      if (s[i] == 'e') {
         ce++;
      }
      if (s[i] == 'i') {
         ci++;
      }
      if (s[i] == 'w') {
         cw++;
      }
      if (s[i] == 'a') {
         ca++;
      }
   }
   printf("%d ",cr);
   printf("%d ", ce);
   printf("%d ", ci);
   printf("%d ", cw);
   printf("%d\n", ca);
   return 0;
}
