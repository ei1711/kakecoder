#include<stdio.h>
int main(void) {
   int n, m, i, j;
   int k[1000];
   int a[1000], b[1000], temp[1000];
   scanf("%d %d", &n,&m);
   for (i = 0; i < m; i++) {
      scanf("%d", &k[i]);
   }
   for (i = 0; i < 2 * n; i++) {
      a[i] = i + 1;
   }
   for (i = 0; i < m; i++) {//kを最初から
   /*カット*/
   if (k[i] != 0) {
      int bi = 0;
      for (int i2 = k[i]; i2 < 2 * n; i2++) {//aのkから後ろをbの最初から入れる
      b[bi++] = a[i2];
   }
   for (int i3 = 0; i3 < k[i]; i3++) {//aのkまでをtempにいれる
   temp[i3] = a[i3];
}
/*for (j = 0; j < bi; j++) {
   printf("%d ", b[j]);
}
printf("\n");
for (j = 0; j < k[i]; j++) {
   printf("%d ", temp[j]);
}
printf("\n");*/
for (int i4 = 0; i4 < bi; i4++) {//bをaの最初から入れる
a[i4] = b[i4];
}
for (int i5 = 0; i5 < k[i]; i5++) {//aのkからtempを入れる
a[bi + i5] = temp[i5];
}
}
/*シャッフル*/
else {
for (int i6 = 0; i6 < n; i6++) {//aのnまでをbに入れる
b[i6] = a[i6];
}
int tempi = 0;
for (int i7 = n; i7 < 2 * n; i7++) {//aのnからをtempに入れる
temp[tempi++] = a[i7];
}
int ai = 0;
for (int i8 = 0; i8 < n; i8++) {//bとtempを交互に入れる
a[ai++] = b[i8];
a[ai++] = temp[i8];
}
}
}
for (i = 0; i < 2 * n; i++) {
printf("%d\n", a[i]);
}
return 0;
}
