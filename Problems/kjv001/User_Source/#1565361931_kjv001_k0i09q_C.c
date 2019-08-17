#include <stdio.h>
int main() {
   FILE *fp = fopen("kjv001/Problems/B.html", "r");
   if (fp == NULL) return 1;
   else return 0;
}
