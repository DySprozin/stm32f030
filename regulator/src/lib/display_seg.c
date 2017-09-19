#include "stm32f0xx.h"
#include "display_seg.h"
#include "def.h"

void seg_show(int d) {
  switch (d) {
   case 0: NUM0; break;
   case 1: NUM1; break;
   case 2: NUM2; break;
   case 3: NUM3; break;
   case 4: NUM4; break;
   case 5: NUM5; break;
   case 6: NUM6; break;
   case 7: NUM7; break;
   case 8: NUM8; break;
   case 9: NUM9; break;
   default: SEG_ERR;
  }
}

void seg_num(int d) {
  int d1, d2, d3;
  d1 = d/100;
  d2 = (d/10) % 10;
  d3 = d%10;
  if (d < 0) {d1 = 111; d2 = 111; d3 = 111;}
   SEG_R; 
   RESET_ALL;
   delay(200);
   seg_show(d1);
   SEG1_S;
   delay(200);
   RESET_ALL;
   SEG_R; 
   seg_show(d2);
   SEG2_S;
   delay(200);
   RESET_ALL;
   SEG_R; 
   seg_show(d3);
   SEG3_S;
   delay(200);
   RESET_ALL;
   SEG_R;
}