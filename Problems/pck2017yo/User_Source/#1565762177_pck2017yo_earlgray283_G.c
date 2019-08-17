/*2019/07/29 */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define MOD 1000000007
typedef long long int ll;
void llswap(ll *x,ll *y){ll temp;temp=*x;*x=*y;*y=temp;}
void swap(int *x,int *y){int tmp;tmp=*x;*x=*y;*y=tmp;}
int rmax(int x,int y){return x>y?x:y;}
int rmin(int x,int y){return x>y?y:x;}
ll llrmax(ll x,ll y){return x>y?x:y;}
ll llrmin(ll x,ll y){return x>y?y:x;}
int asc(const void *a,const void *b){return *(int*)a-*(int*)b;}
int desc(const void *a,const void *b){return *(int*)b-*(int*)a;}
/*
int asc_t(const void *a,const void *b){return ((user_t*)a)->score - ((user_t*)b)->score;}
int desc_t(const void *a,const void *b){return ((user_t*)b)->score - ((user_t*)a)->score;}
*/
int main(){
   int h,n;
   int x[100000],y[100000];
   static char map[100000][100000];
   scanf("%d %d",&h,&n);
   for(int i=0;i<h;i++){
      for(int j=0;j<4;j++){
         map[i][j]='0';
      }
   }
   for(int i=0;i<n;i++){
      scanf("%d %d",&x[i],&y[i]);
      map[h-y[i]-1][x[i]]='1';
   }
   /*
   for(int i=0;i<h;i++){
      for(int j=0;j<4;j++){
         printf("%c ",map[i][j]);
      }
      printf("\n");
   }
   */
   int cnt=0;
   for(int i=0;i<h-1;i++){
      for(int j=0;j<3;j++){
         if(map[i][j]=='0'&&map[i][j+1]=='0'&&map[i+1][j]=='0'&&map[i+1][j+1]=='0'){
            map[i][j]='1';
            map[i][j+1]='1';
            map[i+1][j]='1';
            map[i+1][j+1]='1';
            cnt++;
         }
      }
   }
   printf("%d\n",cnt);
   return 0;
}
