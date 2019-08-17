#include<stdio.h>
#include<string.h>
int main(void)
{
   //非負整数って口頭で言われてもイメージ湧かん
   char x[20];
   int n;
   int len;
   scanf("%s %d", x, &n);
   len = strlen(x);
   printf("%c\n", x[len - n]);
   return 0;
}
