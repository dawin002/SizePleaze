#ifndef DB_EV
#define DB_EV
#include "evaluate.h"

class DB_Ev {
  Evaluate evList[40];
public:
  DB_Ev(){
    evList[0] = Evaluate("파란티셔츠", "top", 2, 4, 0, 0);
    evList[1] = Evaluate("파란티셔츠", "top", 3, 3, 0, 0);
    evList[2] = Evaluate("파란티셔츠", "top", 2, 4, 0, 0);
    evList[3] = Evaluate("파란티셔츠", "top", 1, 5, 0, 0);
    evList[4] = Evaluate("까만 바지", "bottom", 0, 0, 5, 4);
    evList[5] = Evaluate("까만 바지", "bottom", 0, 0, 4, 3);
    evList[6] = Evaluate("까만 바지", "bottom", 0, 0, 3, 3);
    evList[7] = Evaluate("까만 바지", "bottom", 0, 0, 3, 2);
    
    Evaluate ev;
    for(int i=8; i<40; i++){
      evList[i] = ev;
    }
  }

  void evaluatePd(DB_Od dbod, Customer nowCus, int odidx){
    int evs;
    int evidx;
    string pdn = dbod.getPdName(odidx);
    string cate = dbod.getPdCate(odidx);
    Evaluate ev(pdn, cate);
    cout<< "===============================================" <<endl;
    cout<<"사이즈를 평가해주세요."<<endl;
    if(cate=="top") {
      cout<<"상의 전체 길이"<<endl;
      cout<<"1:짧다, 2:조금짧다, 3:적당하다, 4:조금길다, 5:길다"<<endl;
      evs = evSize();
      ev.setTL(evs);
      cout<< "===============================================" <<endl;
      cout<<"상의 전체 너비"<<endl;
      cout<<"1:작다, 2:조금작다, 3:적당하다, 4:조금크다, 5:크다"<<endl;
      evs = evSize();
      ev.setTT(evs);
    }
    else {
      cout<<"하의 전체 길이"<<endl;
      cout<<"1:짧다, 2:조금짧다, 3:적당하다, 4:조금길다, 5:길다"<<endl;
      evs = evSize();
      ev.setBL(evs);
      cout<< "===============================================" <<endl;
      cout<<"하의 전체 너비"<<endl;
      cout<<"1:작다, 2:조금작다, 3:적당하다, 4:조금크다, 5:크다"<<endl;
      evs = evSize();
      ev.setBT(evs);
    }
    evidx = getLastidx();
    addEvaluate(ev, evidx);
    cout<<"제품 사이즈 평가를 완료했습니다."<<endl;
  }

  int getLastidx() {
    int idx = 0;
    while(true){
      if(evList[idx].getPdName() == "x") { break; }
      else { idx++; }
    }
    return idx;
  }

  void addEvaluate(Evaluate ev, int idx) {
    evList[idx] = ev;
  }

  int evSize(){
    int evs;
    while(true){
      cout<<">>";
      cin>>evs;
      if(1<=evs && evs<=5) break;
      else {
        cout<<"잘못 된 범위의 입력입니다."<<endl;
        cout<<"1 ~ 5 사이의 값을 입력하세요."<<endl;
      }
    }
    return evs;
  }

  void getAvgEval(string pdn){
    int i=0, count = 0;
    int sumTL=0, sumTT=0, sumBL=0, sumBT=0;
    double avgTL, avgTT, avgBL, avgBT;
    string a, b;
    string cate = evList[i].getCate();
    while(true){
      if(evList[i].getPdName() == "x") { i--; break; }
      else if(evList[i].getPdName() == pdn) {
        if(cate == "top") {
          sumTL += evList[i].getTL();
          sumTT += evList[i].getTT();
        } else {
          sumBL += evList[i].getBL();
          sumBT += evList[i].getBT();
        }
        count++;
      }
      i++;
    }
    if(cate=="top" && count!=0){
      avgTL = (double)sumTL / count;
      if(avgTL<1.8) a="사이즈가 작고 ";
      else if(avgTL<2.6) a="사이즈가 조금 작고 ";
      else if(avgTL<3.4) a="사이즈가 적당하고 ";
      else if(avgTL<4.2) a="사이즈가 조금 크고 ";
      else a="사이즈가 크고";

      avgTT = (double)sumTT / count;
      if(avgTT<1.8) b="길이가 짧다고";
      else if(avgTT<2.6) b="길이가 조금 짧다고";
      else if(avgTT<3.4) b="길이가 적당하다고";
      else if(avgTT<4.2) b="길이가 조금 길다고";
      else b="길이가 길다고";
    }
    else if(cate=="bottom" && count!=0){
      avgBL = (double)sumBL / count;
      if(avgBL<1.8) a="사이즈가 작고 ";
      else if(avgBL<2.6) a="사이즈가 조금 작고 ";
      else if(avgBL<3.4) a="사이즈가 적당하고 ";
      else if(avgBL<4.2) a="사이즈가 조금 크고 ";
      else a="사이즈가 크고";

      avgBT = (double)sumBT / count;
      if(avgBT<1.8) b="길이가 짧다고";
      else if(avgBT<2.6) b="길이가 조금 짧다고";
      else if(avgBT<3.4) b="길이가 적당하다고";
      else if(avgBT<4.2) b="길이가 조금 길다고";
      else b="길이가 길다고";
    }
    if(count!=0){
      cout<<"해당 제품을 구매한 "<<count<<"명의 구매자가 해당 제품이 "<< a << b <<" 평가했습니다."<<endl;
    }
  }

};

#endif