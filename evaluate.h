#ifndef EVALUATE_H
#define EVALUATE_H
using namespace std;

class Evaluate {
  string pdName;
  string category;
  int t_tight;
  int t_length;
  int b_tight;
  int b_length;
public:
  Evaluate() { pdName = 'x'; }

  Evaluate(string _pdName, string _category) {
    pdName = _pdName;
    category = _category;
    t_tight = 0;
    t_length = 0;
    b_tight = 0;
    b_length = 0;
  }

  // 평가 DB 예시 생성자
  Evaluate(string _pdName, string _category, int _t_tight, int _t_length, int _b_tight, int _b_length) {
    pdName = _pdName;
    category = _category;
    t_tight = _t_tight;
    t_length = _t_length;
    b_tight = _b_tight;
    b_length = _b_length;
  }

  string getPdName() { return pdName; }
  string getCate() { return category; }

  void setTL(int evs) { t_length = evs; }
  void setTT(int evs) { t_tight = evs; }
  void setBL(int evs) { b_length = evs; }
  void setBT(int evs) { b_tight = evs; }
  int getTL() { return t_length; }
  int getTT() { return t_tight; }
  int getBL() { return b_length; }
  int getBT() { return b_tight; }
};

#endif