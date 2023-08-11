#ifndef DB_SM_H
#define DB_SM_H

#include "shopmanager.h"

class DB_Sm{
  ShopManager smList[20];
public:
  DB_Sm(){
    smList[0] = ShopManager("dawin002", "1234", "정다윈", "010-5516-8443");
    smList[1] = ShopManager("2222", "2222", "판매자", "2222");
    ShopManager sm;
    for(int i=2; i<20; i++){
      smList[i] = sm;
    }
  }

  int checkUser(string id, string pw){
    int i=0;
    int index=-1;
    while(i<20){
      if(smList[i].getType() == -1) {
        index = -1;
        break;
      }
      if(id == smList[i].getId()) {
        if(pw == smList[i].getPw()) {
          index = i;
          break;
        }
      }
      i++;
    }
    return index;
  }

  ShopManager& setNowSm(int idx) {
    return smList[idx];
  }

  string checkSameInfo(string id, string phone, int &nowIndex) {
    int i=0;
    string s;
    while(i<20) {
      if(smList[i].getType() == -1) {
        nowIndex = i;
        s = "OK";
        break;
      }
      if(id == smList[i].getId()) {
        s = "ID";
        break;
      }
      else if(phone == smList[i].getPhone()) {
        s = "Phone";
        break;
      }
      i++;
    }
    return s;
  }

  void newSm(int idx, ShopManager s) {
    smList[idx] = s;
  }

};

#endif