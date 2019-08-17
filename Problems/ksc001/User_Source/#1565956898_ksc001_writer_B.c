#include<stdio.h>
int main(){
   static char s1[200000],s2[200000];
   scanf("%s",s1);
   scanf("%s",s2);
   int flg1[26]={},flg2[26]={};
   for(int i=0;s1[i]!='\0';i++){
      flg1[s1[i]-'a']++;
   }
   for(int i=0;s2[i]!='\0';i++){
      flg2[s2[i]-'a']++;
   }
   int ans=0;
   for(int i=0;i<26;i++){
      ans+=flg1[i]>=flg2[i]?flg2[i]:flg1[i];
   }
   printf("%d\n",ans);
   return 0;
}
