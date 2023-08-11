#ifndef SHOP_H
#define SHOP_H
#include <string>
using namespace std;

class Shop {
  string name;
  string homepage;
  string explain;
  string manager;
  string couponCode;
public:
  Shop() { name = "x"; }
  Shop(string _name, string _homepage, string _explain, string _manager, string _couponCode){
    name = _name;
    homepage =_homepage;
    explain = _explain;
    manager = _manager;
    couponCode = _couponCode;  // 얘 입력하는거 넣기
  }
  string getName() { return name; }
  string getHomepage() { return homepage; }
  string getExplain() { return explain; }
  string getManager() { return manager; }
  string getCouponCode(int point) {
    return couponCode + to_string(point);
  }
  
};

#endif