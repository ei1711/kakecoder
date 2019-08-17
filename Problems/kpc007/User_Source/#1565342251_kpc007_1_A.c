#include <stdio.h>
int main() {
   char str[4096];
   scanf("%s", str);
   int a = str[strlen(str) - 1] - '0';
   if (a & 1) {
      puts("1");
   }
   else {
      puts("0");
   }
   return 0;
}
