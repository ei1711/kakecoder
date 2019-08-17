#include<stdio.h>
int main(void){
   int h[10],m[10],s[10],h2[10],m2[10],s2[10],i;
   for(i=0;i<3;i++){
      scanf("%d %d %d %d %d %d",&h[i],&m[i],&s[i],&h2[i],&m2[i],&s2[i]);
   }
   for(i=0;i<3;i++){
      h2[i]-=h[i];
      if(m2[i]<m[i]){
         h2[i]-=1;
         m2[i]+=60;
      }
      m2[i]-=m[i];
      if(s2[i]<s[i]){
         if(h2[i]!=0){
            h2[i]-=1;
            m2[i]+=60;
         }
         if(m2[i]!=0){
            m2[i]-=1;
            s2[i]+=60;
         }
      }
      s2[i]-=s[i];
   }
   for(i=0;i<3;i++){
      printf("%d %d %d\n",h2[i],m2[i],s2[i]);
   }
}
