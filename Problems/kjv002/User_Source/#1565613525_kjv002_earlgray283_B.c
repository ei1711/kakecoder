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
   int n,m;
   int a[2000];
   scanf("%d %d",&n,&m);
   for(int i=0;i<n;i++){
      scanf("%d",&a[i]);
   }
   for(int i=1;i<=m;i++){
      for(int j=0;j<n-1;j++){
         if(a[j]%i>a[j+1]%i){
            swap(&a[j],&a[j+1]);
         }
      }
   }
   for(int i=0;i<n;i++){
      printf("%d\n",a[i]);
   }
   return 0;
}
