#include<stdio.h>
#include<string.h>
int main(void)
{
   static char a[1000001], joi[1000001];
   int i, j;
   int len, joilen = 0, joii, max=0;
   scanf("%s", a);
   len = strlen(a);
   for (i = 0; len >= joilen; i++) {
      joilen += 3;
      joii = 0;
      for (j = 0; j < i; j++) {
         joi[joii++] = 'J';
      }
      for (j = 0; j < i; j++) {
         joi[joii++] = 'O';
      }
      for (j = 0; j < i; j++) {
         joi[joii++] = 'I';
      }
      //printf("joi=%s\n", joi);
      if (strstr(a, joi) != NULL) {
         max = i;
      }
   }
   printf("%d\n", max);
   return 0;
}
