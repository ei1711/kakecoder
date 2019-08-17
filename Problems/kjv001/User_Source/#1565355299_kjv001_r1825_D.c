#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
char tar[110];
int cnt;
signed main(){
   int n;
   scanf("%d", &n);
   scanf("%s", tar);
   for ( int i = 0; i < n; i++ ) {
      char sign[110];
      scanf("%s", sign);
      int m = strlen(sign);
      int flg = 0;
      for ( int j = 0; j < m; j++ ) {
         if ( sign[j] == tar[0] ) {
            for ( int k = j+1; k < m; k++ ) {
               if ( sign[k] == tar[1] ) {
                  int add = k-j;
                  int o = 2;
                  for ( int l = k+add; l < m; l+=add ) {
                     if ( sign[l] != tar[o] ) break;
                     o++;
                     if ( o == strlen(tar) ) {
                        break;
                     }
                  }
                  flg += strlen(tar) == o;
               }
            }
         }
      }
      if ( flg ) cnt++;
   }
   printf("%d\n", cnt);
   return 0;
}
