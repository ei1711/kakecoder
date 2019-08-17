#include<stdio.h>
int main(void) {
   char s[1001];
   char sg[10001];
   scanf("%s", sg);
   scanf("%s", s);
   int i, j;
   char a1 = sg[0];
   char a2;
   int cnt = 0;
   for (i = 0; sg[i] != '\0';i++) {
      cnt++;
   }
   a2 = sg[cnt - 1];
   //printf("%c %c\n", a1, a2);
   for (i = 0; s[i] != '\0'; i++) {
      if (s[i] == a1 && s[i + cnt - 1] == a2) {
         printf("%d %d\n", i, i + cnt - 1);
         break;
      }
   }
   return 0;
}
