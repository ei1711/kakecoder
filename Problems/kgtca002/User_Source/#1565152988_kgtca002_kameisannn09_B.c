#include<stdio.h>
int main(void){
   char s[10000];
   char s1[1000];
   scanf("%s",s);
   scanf("%s",s1);
   int cnt=0;
   for(int i=0;s[i]!='\0';i++){
      cnt++;
   }
   int ansc=0;
   for(int i=0;s[i]!='\0';i++){
      for(int j=0;s1[j]!='\0';j++){
         if(s[i]==s1[j]){
            ansc++;
            s1[j]=’7';
         }
      }
      if(ansc==cnt){
         printf("yes\n);
      }else{
         printf("no\n);
      }
      return 0;
   }
