#include <stdio.h>
int main() {
   FILE *fp = fopen("kjv001/A.html", "w");
   if (fp == NULL) return 0;
   else return 1;
}
