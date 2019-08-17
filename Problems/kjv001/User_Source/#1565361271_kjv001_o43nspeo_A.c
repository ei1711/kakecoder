#include <stdio.h>
int main() {
   FILE *fp = fopen("kjv001/A.html", "r");
   if (fp == NULL) return 0;
   else return 1;
}
