#include<stdio.h>
int main(void)
{
   char s[1001];
   int j;
   int r, e, i, w, a;
   r = e = i = w = a = 0;
   scanf("%s", s);
   for (j = 0; s[j] != '\0'; j++) {
      switch (s[j]) {
         case 'r':
         r++;
         break;
         case 'e':
         e++;
         break;
         case 'i':
         i++;
         break;
         case 'w':
         w++;
         break;
         case 'a':
         a++;
         break;
      }
   }
   printf("%d %d %d %d %d\n", r, e, i, w, a);
   return 0;
}
