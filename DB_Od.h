#ifndef DB_OD
#define DB_OD
#include "order.h"
using namespace std;

class DB_Od {
  Order odList[40];
public:
  DB_Od(){
    odList[0] = Order("1111", "1111", "예시쇼핑몰", "파란티셔츠", "top", 15000, 'S', false);
    odList[1] = Order("1111", "1111", "예시쇼핑몰", "파란티셔츠", "top", 15000, 'M', false);
    odList[2] = Order("1111", "1111", "예시쇼핑몰", "파란티셔츠", "top", 15000, 'L', false);
    odList[3] = Order("1111", "1111", "예시쇼핑몰2", "까만바지", "bottom", 15000, 'S', false);
    odList[4] = Order("1111", "1111", "예시쇼핑몰2", "까만바지", "bottom", 15000, 'M', false);
    odList[5] = Order("1111", "1111", "예시쇼핑몰2", "까만바지", "bottom", 15000, 'L', false);

    Order od_ex;
    for(int i=6; i<40; i++){ odList[i] = od_ex; }
  }

  int getOdidx_byCus(string cusPh, int idx) {
    while(true) {
      if(odList[idx].getCusPh()==cusPh && odList[idx].getDone()==false){ break; }
      else if(odList[idx].getPdName()=="x"){ idx=-1; break; }
      else idx++;
    }
    return idx;
  }

  void showOdList(int odidxArr[]) {
    int idx, i=0;
    while(odidxArr[i]!=-1){
      idx = odidxArr[i];
      cout<<i+1<<". "<<odList[idx].getPdName()<<endl;
      i++;
    }
  }

  int getLastidx() {
    int idx = 0;
    while(true){
      if(odList[idx].getPdName() == "x")
        break;
      idx++;
    }
    return idx;
  }

  void addOrder(Order od, int idx) {
    odList[idx] = od;
  }

  string getPdName(int idx){
    return odList[idx].getPdName();
  }
  string getPdCate(int idx){
    return odList[idx].getPdCate();
  }

  int getPdPrice(int idx) {
    return odList[idx].getPdPrice();
  }

  void setDone(int idx) {
    odList[idx].setDone();
  }

  bool getDone(int idx) {
    return odList[idx].getDone();
  }

  string getShName(int idx) {
    return odList[idx].getShName();
  }
};
#endif