#include<stdio.h>
#include<string.h>
int main(void)
{
   int i, j;
   int n;
   int list[50000], listi = 0;
   int flag;
   scanf("%d", &n);
   list[listi++] = 2;
   for (i = 3; i <= n; i += 2) {
      flag = 0;
      for (j = 0; j < listi; j++) {
         if (i%list[j] == 0) {
            flag = 1;
            break;
         }
      }
      if (flag == 1) {
         continue;
      }
      else if (listi >= 1000) {
         list[listi++] = i;
         continue;
      }
      for (j = 3; j <= n; j+=2) {
         if (i == j) {
            continue;
         }
         if (i%j == 0) {
            flag = 1;
            break;
         }
      }
      if (flag == 0 && listi<=1000) {
         list[listi++] = i;
      }
   }
   long long int sum = 0;
   for (i = 0; i < listi; i++) {
      sum += list[i];
   }
   printf("%lld\n", sum);
   return 0;
}
