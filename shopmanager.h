#ifndef SHOPMANAGER_H
#define SHOPMANAGER_H

using namespace std;

class ShopManager {
  int mem_type;
  string id;
  string pw;
  string name;
  string phone;
public:
  ShopManager() { mem_type = -1; }
  ShopManager(string _id, string _pw, string _name, string _phone){
    mem_type = 2;
    id = _id;
    pw = _pw;
    name = _name;
    phone = _phone;
  }
  int getType() { return mem_type; }
  string getId() { return id; }
  string getPw() { return pw; }
  string getName() { return name; }
  string getPhone() { return phone; }
};

#endif