#include <iostream>
#include "login.h"
#include "join.h"
#include "DB_Cus.h"
#include "DB_Sm.h"
#include "DB_Sh.h"
#include "DB_Pd.h"
#include "DB_Sz.h"
#include "DB_Od.h"
#include "DB_Ev.h"
#include "menuCus.h"
#include "menuSm.h"
using namespace std;

class StartSystem {
  int menuNum;
  int mem_type;
  int mem_index;
public :
  void run() {
    DB_Cus dbcu;
    DB_Sm dbsm;
    DB_Sh dbsh;
    DB_Pd dbpd;
    DB_Sz dbsz;
    DB_Od dbod;
    DB_Ev dbev;
    cout<<"==============================================="<<endl;
    cout<<"개인 맞춤형 의류 사이즈 추천 프로그램"<<endl;
    cout<<"Size Plesze 시작"<<endl<<"21610880 정다윈"<<endl;
    while(true){
      cout<<"==============================================="<<endl;
      cout<<"   << 메인 메뉴 >>"<<endl;
      cout<<"==============================================="<<endl;
      cout<<"1. 로그인\n2. 회원가입\n0. 프로그램 종료"<<endl<<">>";
      cin>>menuNum;
      if(menuNum==1) {  // 로그인
        Login l;
        mem_index = l.login(dbcu, dbsm, mem_type);
        if(mem_type==1) { // 소비자 로그인
          Customer &nowCus = dbcu.setNowCus(mem_index);
          cout<<nowCus.getName()<<endl;
          MenuCus mc;
          mc.pickMenu(dbsh, dbpd, dbsz, dbod, dbev, nowCus);
        }
        else if(mem_type==2) {  // 판매자 로그인
          ShopManager &nowSm = dbsm.setNowSm(mem_index);
          cout<<nowSm.getName()<<endl;
          MenuSm ms;
          ms.pickMenu(dbsh, dbpd, dbsz, dbod, nowSm);
        }
        else if(mem_type==-1) {
          cout<<"로그인 실패 : ID 나 Password 가 틀렸습니다."<<endl;
          continue;
        }
        // 여기 로그아웃 만들수있을듯 브레이크문만 없애면 될듯
        //break;
      }
      else if(menuNum==2) { // 회원가입
        Join j;
        mem_index = j.join(dbcu, dbsm, mem_type);
        if(mem_type==1) { // 소비자 회원가입
          Customer &nowCus = dbcu.setNowCus(mem_index);
          cout<<nowCus.getName()<<endl;
          MenuCus mc;
          mc.pickMenu(dbsh, dbpd, dbsz, dbod, dbev, nowCus);
        }
        else if(mem_type==2) {  // 판매자 회원가입
          ShopManager &nowSm = dbsm.setNowSm(mem_index);
          cout<<nowSm.getName()<<endl;
          MenuSm ms;
          ms.pickMenu(dbsh, dbpd, dbsz, dbod, nowSm);
        }
        else if(mem_type==-1) {
          cout<<"Unknown error."<<endl;
          continue;
        }
        //break;
      }
      else if(menuNum==0) { break; }
      else { cout<<"메뉴 선택 오류. 다시 입력해 주십시오."<<endl; }
    }
    cout<<"==============================================="<<endl;
    cout<< "Size Pleaze 종료."<<endl;
    cout<<"==============================================="<<endl;
  }

};