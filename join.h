#include <iostream>
#include "DB_Cus.h"
#include "DB_Sm.h"
using namespace std;

class Join {
  int type;
  string ID, PW, name, phone;
  string sameInfo;
  int now_index;
public :
  int join(DB_Cus &dbcu, DB_Sm &dbsm, int &mem_type){
    cout<<"==============================================="<<endl;
    cout<<"   << 회원가입>>"<<endl;
    cout<<"==============================================="<<endl;
    while(true) {
      cout<<"사용자 유형을 입력해 주십시오."<<endl<<"소비자 : 1, 판매자 : 2"<<endl<<"사용자 유형 : ";
      cin>>type;
      if(type!=1 && type!=2) {
        cout<<"타입 입력 오류. 다시 입력해 주십시오."<<endl;
        continue;
      }
      cout<<"==============================================="<<endl;
      cout<<"회원가입 정보를 입력해 주십시오."<<endl<<"ID       : ";
      cin.ignore();
      getline(cin,ID);
      cout<<"Password : ";
      getline(cin,PW);
      cout<<"사용자 이름 : ";
      getline(cin,name);
      cout<<"전화번호  : ";
      getline(cin,phone);

      if(type == 1) {
        sameInfo = dbcu.checkSameInfo(ID, phone, now_index);
        if(sameInfo == "OK") {
          mem_type = type;
          Customer c(ID, PW, name, phone);
          dbcu.newCus(now_index, c);
          cout<<"==============================================="<<endl;
          cout<<"소비자 회원가입 성공"<<endl;
          cout<<"사용자명 : ";
          return now_index;
        }
        else if(sameInfo == "ID") {
          cout<<"ID 가 중복되었습니다. 다시 입력해 주십시오."<<endl;
          continue;
        }
        else if(sameInfo == "Phone") {
          cout<<"전화번호가 중복되었습니다. 다시 입력해 주십시오."<<endl;
          continue;
        }
        else {
          mem_type = -1;
          return -1;
        }
      }

      else if(type == 2) {
        sameInfo = dbsm.checkSameInfo(ID, phone, now_index);
        if(sameInfo == "OK") {
          mem_type = type;
          ShopManager s(ID, PW, name, phone);
          dbsm.newSm(now_index, s);
          cout<<"==============================================="<<endl;
          cout<<"판매자 회원가입 성공"<<endl;
          cout<<"사용자명 : ";
          return now_index;
        }
        else if(sameInfo == "ID") {
          cout<<"ID 가 중복되었습니다. 다시 입력해 주십시오.";
          continue;
        }
        else if(sameInfo == "phone") {
          cout<<"전화번호가 중복되었습니다. 다시 입력해 주십시오.";
          continue;
        }
        else {
          mem_type = -1;
          return -1;
        }
      }
    }
    return now_index;
  }

};