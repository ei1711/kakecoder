#include <stdio.h>
int main(void)
{
   char x[5000];
   char c;
   int n, i, a, r;
   r = 0;
   scanf("%s", x);
   scanf("%d", &n);
   for (i = 0; x[i] != '\0'; i++) {
      r = r + 1;
   }
   a = i - n;
   c = x[a];
   printf("%c", c);
   return 0;
}
