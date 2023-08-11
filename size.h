#ifndef SIZE_H
#define SIZE_H
using namespace std;

class Size {
  string pdName;
  char smlSize;
  int t_vertical_L;
  int t_shoulder_W;
  int t_arm_L;
  int b_vertical_L;
  int b_waist_W;
  int b_hip_W;
  int b_thigh_W;
public:
  Size() { pdName = 'x'; }

  Size(string _pdName, char _smlSize) {
    pdName = _pdName;
    smlSize = _smlSize;
    t_shoulder_W=0;
    t_arm_L=0;
    t_vertical_L=0;
    b_vertical_L=0;
    b_waist_W=0;
    b_hip_W=0;
    b_thigh_W=0;
  }

  // 사이즈 DB 예시 생성자
  Size(string _pdName, char _smlSize, int _t_vertical_L, int _t_shoulder_W, int _t_arm_L, int _b_vertical_L, int _b_waist_W, int _b_hip_W, int _b_thigh_W) {
    pdName = _pdName;
    smlSize = _smlSize;
    t_vertical_L = _t_vertical_L;
    t_shoulder_W = _t_shoulder_W;
    t_arm_L = _t_arm_L;
    b_vertical_L = _b_vertical_L;
    b_waist_W = _b_waist_W;
    b_hip_W = _b_hip_W;
    b_thigh_W = _b_thigh_W;
  }

  string getPdName() { return pdName; }
  char getsmlSize() { return smlSize; }

  void setTopSize() {
    int s;
    cout<<"제품의 실측 사이즈를 입력하세요. (단위: mm)"<<endl;
    cout<<"어깨 너비 : "; cin>>s; setSize_tsw(s);
    cout<<"팔 길이 : "; cin>>s; setSize_tal(s);
    cout<<"총 기장 : "; cin>>s; setSize_tvl(s);
  }

  void setBottomSize() {
    int s;
    cout<<"제품의 실측 사이즈를 입력하세요. (단위: mm)"<<endl;
    cout<<"허리 너비 : "; cin>>s; setSize_bww(s);
    cout<<"엉덩이 너비 : "; cin>>s; setSize_bhw(s);
    cout<<"허벅지 너비 : "; cin>>s; setSize_btw(s);
    cout<<"총 기장 : "; cin>>s; setSize_bvl(s);
  }

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