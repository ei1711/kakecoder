#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int card[220];
int stack[220];
int pos;
void init ( ) {
   pos = 0;
}
void add ( int a ) {
   stack[pos++] = a;
}
int poll ( ) {
   return stack[--pos];
}
signed main(){
   int n, m;
   scanf("%d %d", &n, &m);
   for ( int i = 0; i < 2*n; i++ ) {
      card[i] = i+1;
   }
   for ( int i = 0; i < m; i++ ) {
      int k;
      scanf("%d", &k);
      init();
      if ( k ) {
         for ( int j = k; j < n*2; j++ ) {
            add(card[j]);
         }
         for ( int j = 0; j < k; j++ ) {
            add(card[j]);
         }
         for ( int j = 2*n-1; j >= 0; j-- ) {
            card[j] = poll();
         }
      }
      else {
         for ( int i = 0; i < n; i++ ) {
            add(card[i]);
            add(card[i+n]);
         }
         for ( int j = 2*n-1; j >= 0; j-- ) {
            card[j] = poll();
         }
      }
   }
   for ( int i = 0; i < n*2; i++ ) printf("%d\n", card[i]);
   return 0;
}
