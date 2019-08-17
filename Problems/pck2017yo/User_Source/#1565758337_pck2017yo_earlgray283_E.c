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
   int x,y;
   scanf("%d %d",&x,&y);
   int x1,x2,tmp;
   x1=rmax(x,y);
   x2=rmin(x,y);
   int gcd;
   while(1){
      tmp=x1%x2;
      if(tmp==0){
         gcd=x2;
         break;
      }
      x1=x2;
      x2=tmp;
   }
   x/=gcd;
   y/=gcd;
   int cnt=0;
   cnt=x+y;
   //printf("cnt:%d\n",cnt);
   cnt=cnt*gcd-1*(gcd-1);
   printf("%d\n",cnt);
   return 0;
}
