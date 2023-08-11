class MenuCus {
  int menuNum;
public:

  void pickMenu(DB_Sh &dbsh, DB_Pd &dbpd, DB_Sz &dbsz, DB_Od &dbod, DB_Ev &dbev, Customer &nowCus) {
    while(true) {
      cout<<"==============================================="<<endl;
      cout<<"   << 소비자 메뉴 >>"<<endl;
      cout<<"==============================================="<<endl;
      cout<<"1. 사이즈 입력\n2. 쇼핑몰 조회\n3. 카테고리 조회\n4. 적립금 사용\n5. 사이즈 평가\n0. 로그아웃"<<endl<<">>";
      cin>>menuNum;
      if(menuNum==1){ enterSize(nowCus); }
      else if(menuNum==2){pickShop(dbsh, dbpd, dbsz, dbev, nowCus);}
      else if(menuNum==3){pickCategory(dbpd, dbsz, dbev, nowCus);}
      else if(menuNum==4){usePoint(dbsh, dbod, nowCus);}
      else if(menuNum==5){evaluateSize(dbpd, dbod, dbev, nowCus);}
      else if(menuNum==0){
        cout<<"==============================================="<<endl;
        cout<<"로그아웃 되었습니다."<<endl;
        break;
      }
      else { cout<<"메뉴 선택 에러, 다시 입력해 주십시오."<<endl; }
    }
  }

  void enterSize(Customer &nowCus){
    int s;
    cout<<"==============================================="<<endl;
    cout<<"   << 사이즈 입력 >>"<<endl;
    cout<<"==============================================="<<endl;
    cout<< "본인의 몸에 가장 알맞은 옷의 부위별 실측치 입력"<<endl;
    cout<< "사이즈를 잘 모르겠는 경우 -1 입력(사이즈 추천에 반영되지 않음)"<<endl;
    cout<< "===============================================" <<endl;
    cout<< "< 상의 >"<<endl;
    cout<< "옷 전체 세로 길이 : "; cin>>s; 
    nowCus.setSize_tvl(s);
    cout<< "양쪽 어깨 봉제선 사이 너비 : "; cin>>s;
    nowCus.setSize_tsw(s);
    cout<< "어깨 봉제선부터 소매까지 길이 : "; cin>>s;
    nowCus.setSize_tal(s);
    cout<<"==============================================="<<endl;
    cout<< "< 하의 >"<<endl;
    cout<< "허리부터 발목까지 총 길이: "; cin>>s;
    nowCus.setSize_bvl(s);
    cout<< "허리 왼쪽~오른쪽 너비 : "; cin>>s;
    nowCus.setSize_bww(s);
    cout<< "엉덩이 왼쪽~오른쪽 너비 : "; cin>>s;
    nowCus.setSize_bhw(s);
    cout<< "허벅지 왼쪽~오른쪽 너비 : "; cin>>s;
    nowCus.setSize_btw(s);
    cout<< "사이즈 입력 완료"<<endl;
  }

  void pickShop(DB_Sh &dbsh, DB_Pd &dbpd, DB_Sz &dbsz, DB_Ev dbev, Customer &nowCus){
    int idx;
    string shn;
    cout<<"==============================================="<<endl;
    cout<<"   << 쇼핑몰 선택 >>"<<endl; 
    cout<< "===============================================" <<endl;
    cout<<"방문하고자 하는 쇼핑몰을 선택하세요."<<endl;
    dbsh.showShList_cus();
    cout<< "조회할 쇼핑몰 선택 >>";
    cin>>idx; idx--;
    if(idx>=dbsh.getLastidx()) {
      cout<<"잘못된 입력 범위입니다."<<endl;
    } else {
      shn = dbsh.getName(idx);
      pickProduct_sh(dbpd, dbsz, dbev, nowCus, shn);
    }
  }
  
  void pickProduct_sh(DB_Pd &dbpd, DB_Sz &dbsz, DB_Ev dbev, Customer &nowCus, string shn){
    cout<< "===============================================" <<endl;
    cout<< "   << 제품 선택 >>" <<endl;
    cout<< "===============================================" <<endl;
    cout<<"쇼핑몰 "<<shn<<"의 제품 리스트"<<endl;
    int pdidxArr[20];
    int i=0, idx=0;
    while(true) {
      idx = dbpd.getPdidx_bySh(shn, idx);
      pdidxArr[i] = idx;
      if(pdidxArr[i]==-1) break;
      i++; idx++;
    }
    dbpd.showPdList_cus(pdidxArr);
    cout<<"조회할 제품 선택 (선택하지 않으려면 0 입력.)"<< endl<< ">>";
    cin>>idx; idx--;
    if(idx==-1) cout<<"제품 선택 취소"<<endl;
    else if(idx>=dbpd.getLastidx()){
      cout<<"잘못된 입력 범위입니다."<<endl;
    } else {
      idx = pdidxArr[idx];
      pickPd(dbpd, dbsz, dbev, nowCus, idx);
    }
  }

  void pickCategory(DB_Pd &dbpd, DB_Sz &dbsz, DB_Ev dbev, Customer &nowCus){
    int c;
    cout<< "===============================================" <<endl;
    cout<< "   << 카테고리 선택 >>" <<endl;
    cout<< "===============================================" <<endl;
    cout<<"조회할 카테고리를 선택하세요."<<endl;
    cout<<"상의: 1, 하의: 2"<<endl<<">>";
    cin>>c;
    if(c==1) pickProduct_ca(dbpd, dbsz, dbev, nowCus, "top");
    else if(c==2) pickProduct_ca(dbpd, dbsz, dbev, nowCus, "bottom");
    else cout<< "잘못된 입력 범위입니다."<<endl;
  }

  void pickProduct_ca(DB_Pd &dbpd, DB_Sz &dbsz, DB_Ev dbev, Customer &nowCus, string cate){
    cout<< "===============================================" <<endl;
    cout<< "   << 제품 선택 >>" <<endl;
    cout<< "===============================================" <<endl;
    if(cate=="top") cout<<"상의 카테고리 제품 리스트"<<endl;
    else if(cate=="bottom") cout<<"하의 카테고리 제품 리스트"<<endl;
    int pdidxArr[20];
    int i=0, idx=0;
    while(true) {
      idx = dbpd.getPdidx_byCa(cate, idx);
      pdidxArr[i] = idx;
      if(pdidxArr[i]==-1) break;
      i++; idx++;
    }
    dbpd.showPdList_cus(pdidxArr);
    cout<<"조회할 제품 선택 (선택하지 않으려면 0 입력.)"<< endl<< ">>";
    cin>>idx; idx--;
    if(idx==-1) cout<<"제품 선택 취소"<<endl;
    else if(idx>=dbpd.getLastidx()){
      cout<<"잘못된 입력 범위입니다."<<endl;
    } else {
      idx = pdidxArr[idx];
      pickPd(dbpd, dbsz, dbev, nowCus, idx);
    }
  }

  void pickPd(DB_Pd &dbpd, DB_Sz &dbsz, DB_Ev dbev, Customer &nowCus, int idx){
    int i;
    cout<< "===============================================" <<endl;
    cout<< "   << 제품 조회 >>"<<endl;
    cout<< "===============================================" <<endl;
    cout<< "제품명 : "<<dbpd.getName(idx)<<endl;
    cout<< "가격 : "<<dbpd.getPrice(idx)<<endl;
    cout<< "제품 설명 : "<<dbpd.getInfo(idx)<<endl;
    recommendSize(dbpd, dbsz, dbev, nowCus, idx);
    cout<< "구매 링크 : "<<dbpd.getBuylink(idx)<<endl;
    cout<< "돌아가려면 0 입력"<<endl<<">>";
    cin>>i;
  }

  void recommendSize(DB_Pd &dbpd, DB_Sz &dbsz, DB_Ev dbev, Customer &nowCus, int pdidx){
    int szidxArr[3];
    int OCHA[3];
    int minOCHA;
    int i, szidx, bestidx;
    string pdn = dbpd.getName(pdidx);

    for(i=0, szidx=0; i<3; i++, szidx++){
      szidxArr[i] = dbsz.getSzidx_byPd(pdn, szidx);
      OCHA[i] = dbsz.getOCHA(nowCus, szidx);
    }
    minOCHA = OCHA[0];
    for(int i=1; i<3; i++) {
      if(OCHA[i] < minOCHA) {
        minOCHA = OCHA[i];
        bestidx = szidxArr[i];
      }
      else {
        bestidx = szidxArr[i-1];
      }
    }
    cout<< "===============================================" <<endl;
    cout<<"회원님에게 가장 알맞을 것으로 예측되는 사이즈는 "<<dbsz.getsml(bestidx)<<" 입니다."<<endl;
    dbev.getAvgEval(pdn);
  }

  

  void evaluateSize(DB_Pd dbpd, DB_Od &dbod, DB_Ev &dbev, Customer &nowCus){
    cout<< "===============================================" <<endl;
    cout<<"   << 사이즈 평가 >>"<<endl;
    cout<< "===============================================" <<endl;
    cout<<"배송받은 제품의 실제 착용감을 토대로 사이즈를 평가해주세요."<<endl;
    cout<< "===============================================" <<endl;
    cout<<"구매한 제품 중 평가할 제품을 선택해주세요."<<endl;
    string cusPh = nowCus.getPhone();
    int odidxArr[20];
    int i=0, odidx=0;
    while(true) {
      odidx = dbod.getOdidx_byCus(cusPh, odidx);
      odidxArr[i] = odidx;
      if(odidxArr[i]==-1) break;
      i++; odidx++;
    }
    dbod.showOdList(odidxArr);
    cout<<"평가할 제품 선택 (선택하지 않으려면 0 입력.)"<< endl<< ">>";
    int n=i+1;
    cin>>i;
    if(i>=n) cout<<"잘못된 범위의 입력입니다."<<endl;
    else if(i==0) cout<<"제품 선택 취소"<<endl;
    else {
      odidx = odidxArr[--i];
      dbev.evaluatePd(dbod, nowCus, odidx);
      givePoint(dbod, nowCus, odidx);
      dbod.setDone(odidx);
    }
  }
  
  void givePoint(DB_Od dbod, Customer &nowCus, int odidx){
    int pr = dbod.getPdPrice(odidx);
    cout<< "===============================================" <<endl;
    cout<< "   <<적립금 지급 알림>>"<<endl;
    cout<< "===============================================" <<endl;
    cout<<"사이즈 평가의 보상으로 적립금이 지급되었습니다."<<endl;
    cout<<"사이즈 평가 제품 : "<<dbod.getPdName(odidx)<<endl;
    cout<<"제품 가격 : "<<pr<<"원"<<endl;
    cout<<"적립율 : 5%"<<endl;
    pr/=20;
    cout<<"적립 금액 : "<<pr<<"원"<<endl;
    nowCus.addPoint(pr);
    cout<<"누적 적립금 : "<<nowCus.getPoint()<<"원"<<endl;
  }
  



  void usePoint(DB_Sh dbsh, DB_Od dbod, Customer &nowCus){
    int nowP, wantP, idx, shidx;
    string shn;
    string cusPh = nowCus.getPhone();
    nowP = nowCus.getPoint();
    cout<< "===============================================" <<endl;
    cout<< "   << 적립금 사용 >>" <<endl;
    cout<< "===============================================" <<endl;
    cout<<"현재 사용 가능한 적립금은 "<<nowP<<"원 입니다."<<endl;
    while(true){
      cout<<"사용하고자 하는 금액을 입력하세요."<<endl<<"입력 : ";
      cin>>wantP;
      if(nowP<wantP) {
        
        cout<<"적립금이 부족합니다. 다시 입력하세요."<<endl;
        cout<< "===============================================" <<endl;
        continue;
      }
      break;
    }
    nowCus.setPoint(nowP-wantP);
    cout<< "===============================================" <<endl;
    cout<<"적립금을 사용할 쇼핑몰을 선택하세요."<<endl;
    dbsh.showShList_cus();
    cout<< "쇼핑몰 선택 >>";
    cin>>idx; idx--;
    if(idx>=dbsh.getLastidx()) {
      cout<<"잘못된 입력 범위입니다."<<endl;
    } else {
      shn = dbsh.getName(idx);
      int shidx = dbsh.getidx(shn);
      cout<< "===============================================" <<endl;
      cout<<"쿠폰 코드 : "<<dbsh.getCoupon(wantP, shidx)<<endl;
      cout<<"적립금 잔액은 "<<nowCus.getPoint()<<"원 입니다."<<endl;
      cout<<"돌아가려면 0을 입력하세요."<<endl<<">>";
      cin>>idx;   cin.ignore();
    }
  }
};