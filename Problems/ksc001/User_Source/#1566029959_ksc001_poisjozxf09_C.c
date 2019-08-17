#include <stdio.h>
int main() {
   _Bool isOdd = 1;
   char ch;
   while (ch = getchar(), (ch != '\n' && ch != EOF)) isOdd &= ((ch - '0') % 2);
   puts("Odd");
   /*
   if (isOdd) puts("Odd");
   else puts("Even");
   */
   return 0;
}
