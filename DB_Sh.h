#ifndef DB_SH_H
#define DB_SH_H

#include "shop.h"

class DB_Sh{
  Shop shList[20];
public:
  DB_Sh(){
    shList[0] = Shop("예시쇼핑몰", "https://어쩌고저쩌고.com", "이 쇼핑몰에는 상의를 팔고 있습니다.", "판매자", "MK-3311-");
    shList[1] = Shop("예시쇼핑몰2", "https://어쩌고냠냠.com", "이 쇼핑몰에는 하의를 팔고 있습니다.", "판매자", "MK-3322-");
    shList[2] = Shop("마켓3-3", "https://어쩌고", "쇼핑몰 설명", "판매자", "MK-3333-");
    shList[3] = Shop("마켓4-1", "https://어쩌고", "쇼핑몰 설명", "정다윈", "MK-4411-");
    shList[4] = Shop("마켓4-2", "https://어쩌고", "쇼핑몰 설명", "정다윈", "MK-4422-");
    shList[5] = Shop("마켓4-3", "https://어쩌고", "쇼핑몰 설명", "정다윈", "MK-4433-");
    Shop sh_ex;
    for(int i=6; i<20; i++){
      shList[i] = sh_ex;
    }
  }

  string checkSameInfo(string name, string homepage, int &nowIndex) {
    int i=0;
    string s;
    while(i<20) {
      if(shList[i].getName() == "x") {
        nowIndex = i;
        s = "OK";
        break;
      }
      if(name == shList[i].getName()) {
        s = "Name";
        break;
      }
      else if(homepage == shList[i].getHomepage()) {
        s = "Homepage";
        break;
      }
      i++;
    }
    return s;
  }

  void newSh(int idx, Shop sh) {
    shList[idx] = sh;
  }
  
  int getShidx_bySm(ShopManager nowSm, int idx) {
    while(true) {
      if(shList[idx].getManager()==nowSm.getName()){
        break;
      }
      else if(shList[idx].getName()=="x"){
        idx=-1;
        break;
      }
      else idx++;
    }
    return idx;
  }

  void showShList_cus() {
    int idx=0;
    while(true){
      if(shList[idx].getName()=="x") break;
      cout<<idx+1<<". "<<shList[idx].getName()<<endl;
      idx++;
    }
  }

  void showShList_sm(int shidxArr[]) {
    int idx, i=0;
    cout<<"판매자님의 쇼핑몰 리스트"<<endl;
    while(shidxArr[i]!=-1){
      idx = shidxArr[i];
      cout<<i+1<<". "<<shList[idx].getName()<<endl;
      i++;
    }
  }

  bool deleteSh(int idx) {
    while(shList[idx].getName()!="x") {
      shList[idx] = shList[idx+1];
      idx++;
    }
    return true;
  }

  string getName(int idx) {
    return shList[idx].getName();
  }

  int getLastidx() {
    int idx = 0;
    while(true){
      if(shList[idx].getName() == "x")
        break;
      idx++;
    }
    return idx;
  }

  int getidx(string shn){
    int idx=0;
    while(true){
      if(shList[idx].getName()==shn) break;
      idx++;
    }
    return idx;
  }

  string getCoupon(int point, int idx){
    return shList[idx].getCouponCode(point);
  }
  
};

#endif