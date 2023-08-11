#ifndef CUSTOMER_H
#define CUSTOMER_H

using namespace std;

class Customer {
  int mem_type;
  string id;
  string pw;
  string name;
  string phone;
  int restPoint;
  int t_vertical_L;
  int t_shoulder_W;
  int t_arm_L;
  int b_vertical_L;
  int b_waist_W;
  int b_hip_W;
  int b_thigh_W;
  
public:
  Customer() { mem_type = -1; }

  Customer(string _id, string _pw, string _name, string _phone){
    mem_type = 1;
    id = _id;
    pw = _pw;
    name = _name;
    phone = _phone;
    restPoint=0;
    t_shoulder_W=0;
    t_arm_L=0;
    t_vertical_L=0;
    b_vertical_L=0;
    b_waist_W=0;
    b_hip_W=0;
    b_thigh_W=0;
  }

  // 예시 DB 구현용 생성
  Customer(string _id, string _pw, string _name, string _phone, int _restPoint, int _t_vertical_L, int _t_shoulder_W, int _t_arm_L, int _b_vertical_L, int _b_waist_W, int _b_hip_W, int _b_thigh_W){
    mem_type = 1;
    id = _id;
    pw = _pw;
    name = _name;
    phone = _phone;
    restPoint = _restPoint;
    t_shoulder_W = _t_shoulder_W;
    t_arm_L = _t_arm_L;
    t_vertical_L = _t_vertical_L;
    b_vertical_L = _b_vertical_L;
    b_waist_W = _b_waist_W;
    b_hip_W = _b_hip_W;
    b_thigh_W = _b_thigh_W;
  }

  int getType() { return mem_type; }
  string getId() { return id; }
  string getPw() { return pw; }
  string getName() { return name; }
  string getPhone() { return phone; }
  int getPoint() { return restPoint; }
  void addPoint(int point) { restPoint += point; }
  void setPoint(int point) { restPoint = point; }
  int getSize_tvl() { return t_vertical_L; }
  int getSize_tsw() { return t_shoulder_W; }
  int getSize_tal() { return t_arm_L; }
  int getSize_bvl() { return b_vertical_L; }
  int getSize_bww() { return b_waist_W; }
  int getSize_bhw() { return b_hip_W; }
  int getSize_btw() { return b_thigh_W; }
  void setSize_tvl(int tvl) { t_vertical_L = tvl; }
  void setSize_tsw(int tsw) { t_shoulder_W = tsw; }
  void setSize_tal(int tal) { t_arm_L = tal; }
  void setSize_bvl(int bvl) { b_vertical_L = bvl; }
  void setSize_bww(int bww) { b_waist_W = bww; }
  void setSize_bhw(int bhw) { b_hip_W = bhw; }
  void setSize_btw(int btw) { b_thigh_W = btw; }
};

#endif