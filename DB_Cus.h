#ifndef DB_CUS_H
#define DB_CUS_H

#include "customer.h"

class DB_Cus{
  Customer cusList[20];
public:
  DB_Cus(){
    cusList[0] = Customer("1111", "1111", "교수님", "1111", 5000, 800, 500, 550, 900, 450, 550, 350);
    cusList[1] = Customer("1234", "1234", "1234", "12341234", 7500, 850, 550, 600, 950, 500, 600, 400);
    Customer cu;
    for(int i=2; i<20; i++){
      cusList[i] = cu;
    }
  }

  int checkUser(string id, string pw){
    int i=0;
    int index = -1;
    while(i<20){
      if(cusList[i].getType() == -1) {
        index = -1;
        break;
      }
      if(id == cusList[i].getId()) {
        if(pw == cusList[i].getPw()) {
          index = i;
          break;
        }
      }
      i++;
    }
    return index;
  }

  Customer& setNowCus(int idx) {
    return cusList[idx];
  }

  string checkSameInfo(string id, string phone, int &nowIndex) {
    int i=0;
    string s;
    while(i<20) {
      if(cusList[i].getType() == -1) {
        nowIndex = i;
        s = "OK";
        break;
      }
      if(id == cusList[i].getId()) {
        s = "ID";
        break;
      }
      else if(phone == cusList[i].getPhone()) {
        s = "Phone";
        break;
      }
      i++;
    }
    return s;
  }

  void newCus(int idx, Customer c) {
    cusList[idx] = c;
  }
};

#endif