#ifndef ORDER_H
#define ORDER_H

class Order {
  string cusName;
  string cusPhone;
  string shName;
  string pdName;
  string pdCate;
  int pdPrice;
  char pdsmlSize;
  bool done;

public:
  Order() { pdName = "x"; }
  Order(string _cusName, string _cusPhone, string _shName, string _pdName, string _pdCate, int _pdPrice, char _pdsmlSize, bool _done) {
    cusName = _cusName;
    cusPhone = _cusPhone;
    shName = _shName;
    pdName = _pdName;
    pdCate = _pdCate;
    pdPrice = _pdPrice;
    pdsmlSize = _pdsmlSize;
    done = _done;

  }

  string getPdName() { return pdName; }
  string getPdCate() { return pdCate; }
  string getShName() { return shName; }
  string getCusPh() { return cusPhone; }
  int getPdPrice() { return pdPrice; }
  void setDone() { done = true; }
  bool getDone() { return done; }


};
#endif