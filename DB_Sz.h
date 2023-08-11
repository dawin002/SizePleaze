#ifndef DB_SZ_H
#define DB_SZ_H

#include "size.h"

class DB_Sz{
  Size szList[50];
public:
  DB_Sz(){
    szList[0] = Size("파란티셔츠", 'S', 750, 450, 500, 0, 0, 0, 0);
    szList[1] = Size("파란티셔츠", 'M', 800, 500, 550, 0, 0, 0, 0);
    szList[2] = Size("파란티셔츠", 'L', 850, 550, 600, 0, 0, 0, 0);
    szList[3] = Size("빨간남방", 'S', 750, 450, 500, 0, 0, 0, 0);
    szList[4] = Size("빨간남방", 'M', 800, 500, 550, 0, 0, 0, 0);
    szList[5] = Size("빨간남방", 'L', 850, 550, 600, 0, 0, 0, 0);
    szList[6] = Size("까만바지", 'S', 0, 0, 0, 850, 400, 500, 300);
    szList[7] = Size("까만바지", 'M', 0, 0, 0, 900, 450, 550, 350);
    szList[8] = Size("까만바지", 'L', 0, 0, 0, 950, 500, 600, 400);
    szList[9] = Size("하의2", 'S', 0, 0, 0, 900, 400, 500, 300);
    szList[10] = Size("하의2", 'M', 0, 0, 0, 900, 450, 550, 350);
    szList[11] = Size("하의2", 'L', 0, 0, 0, 900, 500, 600, 400);
    Size sz_ex;
    for(int i=11; i<50; i++){ szList[i] = sz_ex; }
  }

  int getLastidx() {
    int idx = 0;
    while(true){
      if(szList[idx].getPdName() == "x")
        break;
      idx++;
    }
    return idx;
  }

  void addSize(Size sz, int idx) {
    szList[idx] = sz;
  }
  
  int getSzidx_byPd(string pdName, int szidx) {
    while(true) {
      if(szList[szidx].getPdName()==pdName){
        break;
      }
      else if(szList[szidx].getPdName()=="x"){
        break;
      }
      else szidx++;
    }
    return szidx;
  }

  int getOCHA(Customer nowCus, int szidx){
    int OCHA, sumOCHA = 0;
    if(szList[szidx].getSize_tvl()!=0 && nowCus.getSize_tvl()!=-1) {
      OCHA = nowCus.getSize_tvl() - szList[szidx].getSize_tvl();
      if(OCHA<0) OCHA = 0 - OCHA;
      sumOCHA += OCHA;
    }
    if(szList[szidx].getSize_tsw()!=0 && nowCus.getSize_tsw()!=-1) {
      OCHA = nowCus.getSize_tsw() - szList[szidx].getSize_tsw();
      if(OCHA<0) OCHA = 0 - OCHA;
      sumOCHA += OCHA;
    }
    if(szList[szidx].getSize_tal()!=0 && nowCus.getSize_tal()!=-1) {
      OCHA = nowCus.getSize_tal() - szList[szidx].getSize_tal();
      if(OCHA<0) OCHA = 0 - OCHA;
      sumOCHA += OCHA;
    }
    if(szList[szidx].getSize_bvl()!=0 && nowCus.getSize_bvl()!=-1) {
      OCHA = nowCus.getSize_bvl() - szList[szidx].getSize_bvl();
      if(OCHA<0) OCHA = 0 - OCHA;
      sumOCHA += OCHA;
    }
    if(szList[szidx].getSize_bww()!=0 && nowCus.getSize_bww()!=-1) {
      OCHA = nowCus.getSize_bww() - szList[szidx].getSize_bww();
      if(OCHA<0) OCHA = 0 - OCHA;
      sumOCHA += OCHA;
    }
    if(szList[szidx].getSize_bhw()!=0 && nowCus.getSize_bhw()!=-1) {
      OCHA = nowCus.getSize_bhw() - szList[szidx].getSize_bhw();
      if(OCHA<0) OCHA = 0 - OCHA;
      sumOCHA += OCHA;
    }
    if(szList[szidx].getSize_btw()!=0 && nowCus.getSize_btw()!=-1) {
      OCHA = nowCus.getSize_btw() - szList[szidx].getSize_btw();
      if(OCHA<0) OCHA = 0 - OCHA;
      sumOCHA += OCHA;
    }
    return sumOCHA;
  }

  char getsml(int bestidx){
    return szList[bestidx].getsmlSize();
  }
  
};

#endif