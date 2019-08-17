#include <stdio.h>
#include <string>
#include <iostream>
int main() {
   std::string str;
   std::cin >> str;
   int a = str[str.size() - 1] - '0';
   if (a & 1) {
      puts("0");
   }
   else {
      puts("1");
   }
   return 0;
}
