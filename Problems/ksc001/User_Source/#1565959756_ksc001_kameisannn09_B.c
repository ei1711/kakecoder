#include<stdio.h>
int main(void) {
   char s1[10000];
   char s2[10000];
   scanf("%s", s1);
   scanf("%s", s2);
   int cnt = 0;
   for (int i = -0; s1[i] != '\0'; i++) {
      for (int j = 0; s2[j] != '\0'; j++) {
         if (s1[i] == s2[j]) {
            cnt++;
            break;
         }
      }
   }
   printf("%d\n", cnt);
   return 0;
}
