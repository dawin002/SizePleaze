#ifndef DB_PD_H
#define DB_PD_H

#include "product.h"

class DB_Pd{
  Product pdList[20];
public:
  DB_Pd(){
    pdList[0] = Product("파란티셔츠", "top", 15000, "예시쇼핑몰", "사이즈 데이터와 평가 데이터가 입력되어있는 제품입니다.", "https://helloworld!.com");
    pdList[1] = Product("빨간남방", "top", 2000, "예시쇼핑몰", "사이즈 데이터만 입력되어있는 제품입니다.", "http//goodbyeword.com");
    pdList[2] = Product("상의3", "top", 3000, "예시쇼핑몰", "옷정보", " _buyLink");
    pdList[3] = Product("까만바지", "bottom", 4000, "예시쇼핑몰2", "사이즈와 평가 데이터가 입력되어 있는 제품입니다.", " _buyLink");
    pdList[4] = Product("하의2", "bottom", 5000, "예시쇼핑몰2", "옷정보", " _buyLink");
    pdList[5] = Product("하의3", "bottom", 6000, "예시쇼핑몰2", "옷정보", " _buyLink");
    for(int i=0; i<5; i++){
      if(i!=2){pdList[i].setSml('S');pdList[i].setSml('M');pdList[i].setSml('L');}
    }
    Product pd_ex;
    for(int i=6; i<20; i++){ pdList[i] = pd_ex; }
  }
  
  string checkSameInfo(string name, int &nowIndex) {
    int i=0;
    string s;
    while(i<20) {
      if(pdList[i].getName() == "x") {
        nowIndex = i;
        s = "OK";
        break;
      }
      else if(name == pdList[i].getName()) {
        s = "Name";
        break;
      }
      i++;
    }
    return s;
  }

  void addPd(int idx, Product pd) {
    pdList[idx] = pd;
  }

  int getPdidx_bySh(string shName, int idx) {
    while(true) {
      if(pdList[idx].getShop()==shName){ break; }
      else if(pdList[idx].getName()=="x"){ idx=-1; break; }
      else idx++;
    }
    return idx;
  }

  int getPdidx_byCa(string cate, int idx) {
    while(true) {
      if(pdList[idx].getCate()==cate) { break; }
      else if(pdList[idx].getName()=="x") { idx=-1; break; }
      else idx++;
    }
    return idx;
  }

  void showPdList_sm(int pdidxArr[]) {
    int idx, i=0;
    while(pdidxArr[i]!=-1){
      idx = pdidxArr[i];
      cout<<i+1<<". "<<pdList[idx].getName()<<endl;
      i++;
    }
  }

  void showPdList_cus(int pdidxArr[]) {
    int idx, i=0;
    while(pdidxArr[i] != -1){
      idx = pdidxArr[i];
      cout<< i+1<<". "<<pdList[idx].getName()<<" / "<<pdList[idx].getPrice()<<"원 / "<<pdList[idx].getInfo()<<endl;
      i++;
    }
  }

  bool deletePd(int idx) {
    while(pdList[idx].getName()!="x") {
      pdList[idx] = pdList[idx+1];
      idx++;
    }
    return true;
  }

  int getLastidx() {
    int idx = 0;
    while(true){
      if(pdList[idx].getName() == "x")
        break;
      idx++;
    }
    return idx;
  }

  string getName(int idx) { return pdList[idx].getName(); }
  string getCategory(int idx) {return pdList[idx].getCate(); }
  int getPrice(int idx) { return pdList[idx].getPrice(); }
  string getInfo(int idx) { return pdList[idx].getInfo(); }
  string getBuylink(int idx) { return pdList[idx].getBuylink(); }
  void setPdSml(int idx, char sml){ pdList[idx].setSml(sml); }
  
};

#endif