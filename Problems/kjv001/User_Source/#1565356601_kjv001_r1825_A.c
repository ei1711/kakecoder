#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define int long long
signed main(){
   for ( int i = 0; i < 3; i++ ) {
      int b[2][3];
      for ( int j = 0; j < 2; j++ ) {
         for ( int k = 0; k < 3; k++ ) {
            scanf("%lld", &b[j][k]);
         }
      }
      int left = b[1][0] *60*60 + b[1][1] * 60 + b[1][2];
      int join = b[0][0] *60*60 + b[0][1] * 60 + b[0][2];
      int a = left - join;
      int h = a / 3600;
      a %= 3600;
      int m = a / 60;
      a %= 60;
      printf("%lld %lld %lld\n", h, m, a);
   }
   return 0;
}
