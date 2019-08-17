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
   int n,a[200],b[200],c[200],d[200];
   scanf("%d",&n);
   for(int i=0;i<n*(n-1)/2;i++){
      scanf("%d %d %d %d",&a[i],&b[i],&c[i],&d[i]);
   }
   int score[200]={};
   for(int i=0;i<n*(n-1)/2;i++){
      if(c[i]>d[i]){
         score[a[i]-1]+=3;
      }else if(c[i]==d[i]){
         score[a[i]-1]++;
         score[b[i]-1]++;
      }else{
         score[b[i]-1]+=3;
      }
      //printf("score[%d]=%d score[%d]=%d\n",a[i]-1,score[a[i]-1],b[i]-1,score[b[i]-1]);
   }
   int rank=1;
   for(int i=0;i<n;i++){
      rank=1;
      for(int j=0;j<n;j++){
         if(i==j)continue;
         if(score[i]<score[j]){
            rank++;
         }
      }
      printf("%d1\n",rank);
   }
   return 0;
}
