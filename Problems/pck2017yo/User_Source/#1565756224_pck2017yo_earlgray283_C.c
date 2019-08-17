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
   int x;
   scanf("%d",&x);
   switch(x%7){
      case 0:
      printf("thu\n");
      break;
      case 1:
      printf("fri\n");
      break;
      case 2:
      printf("sat\n");
      break;
      case 3:
      printf("sun\n");
      break;
      case 4:
      printf("mon\n");
      break;
      case 5:
      printf("tue\n");
      break;
      case 6:
      printf("wed\n");
      break;
   }
   return 0;
}
