#include <stdio.h>
int main() {
   FILE* fp = fopen("kjv001/Problems/A.html");
   if (fp == NULL) return 0;
   else return 1;
}