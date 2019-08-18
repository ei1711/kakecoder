#include <stdio.h>
int main() {
   _Bool isOdd = 1;
   char ch;
   while (ch = getchar(), (ch != '\n' && ch != EOF)) isOdd &= ((ch - '0') % 2);
   if (isOdd) puts("Even");
   else puts("Even");
   return 0;
}
