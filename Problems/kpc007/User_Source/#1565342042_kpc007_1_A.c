#include <stdio.h>
int main() {
   long long  a;
   scanf("%lld", &a);
   if (a & 1) {
      puts("0");
   }
   else {
      puts("1");
   }
   return 0;
}
