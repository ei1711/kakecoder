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
   static char str[2000000];
   scanf("%s",str);
   int cnt,next,flg;
   char tmp;
   static int list[2000000]={},list_i=0;
   static char listc[2000000]={};
   next=1;
   while(1){
      flg=0;
      cnt=1;
      tmp=str[next-1];
      for(int i=next;str[i-1]==str[i];i++){
         cnt++;
         next=i+1;
         if(str[next]=='\0'){
            break;
         }
      }
      //printf("flg:%d cnt:%d next:%d\n",flg,cnt,next);
      next++;
      list[list_i]=cnt;
      listc[list_i]=tmp;
      list_i++;
      //if(flg)break;
      if(str[next-1]=='\0'){
         break;
      }
   }
   int max=-1;
   for(int i=1;i<list_i-1;i++){
      if(listc[i-1]=='J'&&listc[i]=='O'&&listc[i+1]=='I'){
         if(list[i-1]>=list[i]&&list[i]<=list[i+1]){
            if(max<list[i])max=list[i];
         }
      }
   }
   if(max==-1)printf("0\n");
   else printf("%d\n",max);
   return 0;
}
