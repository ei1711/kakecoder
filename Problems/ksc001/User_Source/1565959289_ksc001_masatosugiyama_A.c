#include <stdio.h>
int main(void){
   char s1[1000000],s2[1000000],cl[1000000];
   int i,j,k,c,f;
   scanf("%s", s1);
   scanf("%s", s2);
   for(i = 0;s1[i] != '\0';i ++){
      for(j = 0;s2[j] != '\0';j ++){
         f = 1;
         for(k = 0;cl[k] != '\0';k ++){
            if(s1[i] == cl[k] || s2[j] == cl[k]){
               f = 0;
            }
         }
         if(f == 1){
            if(s1[i] == s2[j]){
               for(k = 0;k < 1000000;k ++){
                  if(cl[k] == '\0'){
                     cl[k] = s1[i];
                     break;
                  }
               }
            }
         }
      }
   }
   for(i = 0;i < 1000000;i ++){
      if(cl[i] == '\0'){
         printf("%d\n", i + 1);
         break;
      }
   }
   return 0;
}
