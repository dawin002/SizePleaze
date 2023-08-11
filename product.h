#ifndef PRODUCT_H
#define PRODUCT_H
using namespace std;

class Product {
  string name;
  string category;
  int price;
  char smlSize[3];
  string shop;
  string info;
  string buyLink;
public:
  Product() {
    name = "x";
    for(int i=0; i<3; i++) { smlSize[i] = 'x'; }
  }

  Product(string _name, string _category, int _price, string _shop, string _info, string _buyLink){
    name = _name;
    category =_category;
    price = _price;
    for(int i=0; i<3; i++) { smlSize[i] = 'x'; }
    shop = _shop;
    info = _info;
    buyLink = _buyLink;
  }
  
  void setSml(char sml){
    if(sml=='S') smlSize[0] = sml;
    else if(sml=='M') smlSize[1] = sml;
    else if(sml=='L') smlSize[2] = sml;
  }
  string getName() { return name; }
  string getShop() { return shop; }
  string getCate() { return category; }
  int getPrice() { return price; }
  string getInfo() { return info; }
  string getBuylink() { return buyLink; }

};

#endif