#include <stdio.h>
int main(void) {
   int i, as, am, ah, at, qas, qam, qah, qat, bs, bm, bh, bt, qbs, qbm, qbh, qbt, cs, cm, ch, ct, qcs, qcm, qch, qct;
   scanf("%d", &ah);
   scanf("%d", &am);
   scanf("%d", &as);
   scanf("%d", &qah);
   scanf("%d", &qam);
   scanf("%d", &qas);
   scanf("%d", &bh);
   scanf("%d", &bm);
   scanf("%d", &bs);
   scanf("%d", &qbh);
   scanf("%d", &qbm);
   scanf("%d", &qbs);
   scanf("%d", &ch);
   scanf("%d", &cm);
   scanf("%d", &cs);
   scanf("%d", &qch);
   scanf("%d", &qcm);
   scanf("%d", &qcs);
   at = (3600 * ah) + (60 * am) + as;
   bt = (3600 * bh) + (60 * bm) + bs;
   ct = (3600 * ch) + (60 * cm) + cs;
   qat = (3600 * qah) + (60 * qam) + qas;
   qbt = (3600 * qbh) + (60 * qbm) + qbs;
   qct = (3600 * qch) + (60 * qcm) + qcs;
   at = qat - at;
   bt = qbt - bt;
   ct = qct - ct;
   ah = 0;
   am = 0;
   as = 0;
   bh = 0;
   bm = 0;
   bs = 0;
   ch = 0;
   cm = 0;
   cs = 0;
   for (i = 0; at >= 3600; i++) {
      ah = ah + 1;
      at = at - 3600;
   }
   for (i = 0; at >= 60; i++) {
      am = am + 1;
      at = at - 60;
   }
   for (i = 0; at > 0; i++) {
      as = as + 1;
      at = at - 1;
   }
   for (i = 0; bt >= 3600; i++) {
      bh = bh + 1;
      bt = bt - 3600;
   }
   for (i = 0; bt >= 60; i++) {
      bm = bm + 1;
      bt = bt - 60;
   }
   for (i = 0; bt > 0; i++) {
      bs = bs + 1;
      bt = bt - 1;
   }
   for (i = 0; ct >= 3600; i++) {
      ch = ch + 1;
      ct = ct - 3600;
   }
   for (i = 0; ct >= 60; i++) {
      cm = cm + 1;
      ct = ct - 60;
   }
   for (i = 0; ct > 0; i++) {
      cs = cs + 1;
      ct = ct - 1;
   }
   printf("%d ", ah);
   printf("%d ", am);
   printf("%d\n", as);
   printf("%d ", bh);
   printf("%d ", bm);
   printf("%d\n", bs);
   printf("%d ", ch);
   printf("%d ", cm);
   printf("%d\n", cs);
   return 0;
}
