#include <stdio.h>
int main() {
   char str[4096];
   scanf("%s", str);
   int a = str[strlen(str) - 1] - '0';
   if (a & 1) {
      puts("0");
   }
   else {
      puts("1");
   }
   return 0;
}
