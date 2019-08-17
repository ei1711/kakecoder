#include<stdio.h>
#include<string.h>
int main(void)
{
   int i, j, len;
   char a[1001], b[1001];
   char *st;
   scanf("%s %s", a, b);
   len = strlen(a);
   st = strstr(b, a);
   printf("%d %d\n",st-b,st-b+len-1);
   return 0;
}
