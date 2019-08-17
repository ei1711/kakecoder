#include<stdio.h>
#include<string.h>
int main(void)
{
   //松本、D飛ばすってよ
   int n, i, j, k;
   char s[101], a[101];
   char temp, min;
   int co = 0;
   scanf("%d %s", &n, s);
   strcpy(a, s);
   for (i = 0; i < n - 1; i++) {
      for (j = i+1; j < n; j++) {
         if (strcmp(&s[i], &s[j]) > 0) {
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
         }
      }
   }
   for (i = 0; i < n; i++) {
      if (a[i] != s[i]) {
         co++;
      }
   }
   printf("%d\n", co/2);
   return 0;
}
