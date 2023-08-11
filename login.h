#include <iostream>
#include "DB_Cus.h"
#include "DB_Sm.h"
using namespace std;

class Login {
  int type;
  string ID, PW;
  int now_index;
public :
  int login(DB_Cus &dbcu, DB_Sm &dbsm, int &mem_type) {
    while(true) {
      cout<<"==============================================="<<endl;
      cout<<"   << 로그인 >>"<<endl;
      cout<<"==============================================="<<endl;
      cout<<"사용자 유형을 입력해 주십시오."<<endl<<"소비자 : 1 \n판매자 : 2"<<endl<<"사용자 유형 : ";
      cin>>type;
      if(type!=1 && type!=2) {
        cout<<"타입 입력 오류. 다시 입력해 주십시오"<<endl;
        continue;
      }
      cout<<"==============================================="<<endl;
      cout<<"로그인 정보 입력"<<endl<<"ID       : ";
      cin.ignore();
      getline(cin,ID);
      cout<<"Password : ";
      getline(cin,PW);
      if(type == 1) {
        now_index = dbcu.checkUser(ID, PW);
        if(now_index == -1) {
          mem_type = -1;
          return -1;  // 일치 정보 못찾음
        }
        else {  // 소비자 로그인
          mem_type = type;
          cout<<"==============================================="<<endl;
          cout<<"소비자 로그인 성공"<<endl;
          cout<<"사용자명 : ";
          return now_index;
        }
      }
      else if(type == 2) {
        now_index = dbsm.checkUser(ID, PW);
        if(now_index == -1) {
          mem_type = -1;
          return -1;  // 일치 정보 못찾음
        }
        else {  // 판매자 로그인
          mem_type = type;
          cout<<"==============================================="<<endl;
          cout<<"판매자 로그인 성공"<<endl;
          cout<<"사용자명 : ";
          return now_index;
        }
      }
    }
  }
};