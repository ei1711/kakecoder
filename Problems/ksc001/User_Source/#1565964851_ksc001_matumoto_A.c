#include<stdio.h>
#include<string.h>
int main(void)
{
   int i, j;
   char a[100001], b[100001];
   static int ak[100000] = { 0 }, bk[100000] = { 0 };
   int co = 0;
   int lena, lenb;
   char* cp;
   scanf("%s %s", a, b);
   lena = strlen(a);
   lenb = strlen(b);
   for (i = 0; i < lena; i++) {
      ak[(int)a[i]]++;
   }
   for (i = 0; i < lenb; i++) {
      bk[(int)b[i]]++;
   }
   for (i = 0; i < 100000; i++) {
      if (ak[i] >= 1 && bk[i] >= 1) {
         if (ak[i] > bk[i]) {
            co += bk[i];
         }
         else {
            co += ak[i];
         }
      }
   }
   printf("%d\n", co);
   return 0;
}
