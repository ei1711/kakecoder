#include<stdio.h>
#include<string.h>
int main(void)
{
   int i, j;
   char a[100001], b[100001];
   int co = 0, len1, len2;
   scanf("%s %s", a, b);
   len1 = strlen(a);
   len2 = strlen(b);
   for (i = 0;i<len1; i++) {
      for (j = 0; j<len2; j++) {
         if (a[i] == b[j] && a[i]!='\0') {
            co++;
            b[i] = a[i] = '\0';
         }
      }
   }
   printf("%d\n", co);
   return 0;
}
