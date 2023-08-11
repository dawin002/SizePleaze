class MenuSm {
  int menuNum;
  int now_index;
  int new_index;
public:
  void pickMenu(DB_Sh &dbsh, DB_Pd &dbpd, DB_Sz &dbsz, DB_Od &dbod, ShopManager &nowSm) {
    while(true) {
      cout<< "===============================================" <<endl;
      cout<< "   << 판매자 메뉴 >>"<<endl;
      cout<< "===============================================" <<endl;
      cout<<"1. 쇼핑몰 관리\n2. 제품 관리\n3. 주문 관리\n0. 로그아웃"<<endl<<">>";
      cin>>menuNum;
      if(menuNum==1) { manageShop(dbsh, nowSm); }
      else if(menuNum==2) { manageProduct(dbsh, dbpd, dbsz, nowSm); }
      else if(menuNum==3) { manageOrder(dbsh, dbpd, dbod, nowSm); }
      else if(menuNum==0) { break; }
      else { cout<<"메뉴 입력 에러. 다시 입력하세요."<<endl; }
    }
  }


  void manageShop(DB_Sh &dbsh, ShopManager &nowSm){ // 쇼핑몰 관리
    while(true) {
      cout<< "===============================================" <<endl;
      cout<< "   << 쇼핑몰 관리 메뉴 >>"<<endl;
      cout<< "===============================================" <<endl;
      cout<<"1. 쇼핑몰 등록\n2. 쇼핑몰 삭제\n0. 뒤로 가기"<<endl<<">>";
      cin>>menuNum;
      if(menuNum==1){ addShop(dbsh, nowSm); break; }
      else if(menuNum==2){ deleteShop(dbsh, nowSm); break; }
      else if(menuNum==0){ break; }
      else { cout<<"메뉴 입력 에러. 다시 입력하세요."<<endl; }
    }
  }

  void manageProduct(DB_Sh &dbsh, DB_Pd &dbpd, DB_Sz &dbsz, ShopManager &nowSm){ // 제품 관리
    while(true) {
      cout<< "===============================================" <<endl;
      cout<< "   << 제품 관리 메뉴 >>"<<endl;
      cout<< "===============================================" <<endl;
      cout<<"1. 제품 등록\n2. 제품 삭제\n0. 뒤로 가기"<<endl<<">>";
      cin>>menuNum;
      if(menuNum==1){ addProduct(dbsh, dbpd, dbsz, nowSm); break; }
      else if(menuNum==2){ deleteProduct(dbsh, dbpd, nowSm); break; }
      else if(menuNum==0){ break; }
      else { cout<<"메뉴 입력 에러. 다시 입력하세요."<<endl; }
    }
  }

  // 쇼핑몰 추가
  void addShop(DB_Sh &dbsh, ShopManager &nowSm){
    string na, hp, ex, cp, mn, sameInfo;
    cout<< "===============================================" <<endl;
    cout<<"   << 쇼핑몰 등록 >>"<<endl;
    cout<< "===============================================" <<endl;
    while(true){
      cout<<"등록할 쇼핑몰 정보 입력"<<endl;
      cout<<"쇼핑몰 이름 : ";
      cin.ignore();
      getline(cin,na);
      cout<<"홈페이지 주소 : ";
      getline(cin,hp);
      cout<<"간단한 설명 : ";
      getline(cin,ex);
      cout<<"쿠폰 고유번호 : ";
      getline(cin,cp);
      mn = nowSm.getName();

      sameInfo = dbsh.checkSameInfo(na, hp, now_index);
      if(sameInfo == "OK") {
        Shop sh(na, hp, ex, mn, cp);
        dbsh.newSh(now_index, sh);
        cout<<sh.getName()<<" 쇼핑몰이 추가되었습니다."<<endl;
        break;
      }
      else { cout<< "중복된 " <<sameInfo<< " 정보가 있습니다. 다시 입력해주세요."<<endl; }
    }
  }

  // 쇼핑몰 삭제
  void deleteShop(DB_Sh &dbsh, ShopManager &nowSm) {
    int shidxArr[20];
    int i=0; int idx=0;
    cout<< "===============================================" <<endl;
    cout<< "   << 쇼핑몰 삭제 >>" <<endl;
    cout<< "===============================================" <<endl;
    while(true) {
      idx = dbsh.getShidx_bySm(nowSm, idx);
      shidxArr[i] = idx;
      if(shidxArr[i]==-1) break;
      i++; idx++;
    }
    dbsh.showShList_sm(shidxArr);
    cout<<"삭제할 쇼핑몰 선택 (삭제하지 않으려면 0 입력.)"<< endl<<">>";
    cin>>i;
    if(i==0) cout<<"쇼핑몰 삭제 취소"<<endl;
    else{
      i--;
      idx = shidxArr[i];
      cout<< "===============================================" <<endl;
      cout<< "삭제될 쇼핑몰 : "<<dbsh.getName(idx)<<endl;
      if(askAgain()){
        cout<<"쇼핑몰 "<<dbsh.getName(idx);
        dbsh.deleteSh(idx);
        cout<<" 삭제 성공"<<endl;
      }
      else { cout<<"쇼핑몰 삭제 취소"<<endl; }
    }
  }

  // 다시묻기
  bool askAgain() {
    int y;
    while(true) {
      cout<< "정말 삭제하시겠습니까?"<< endl<< "YES:1 || NO:2"<<endl<<">>";
      cin>>y;
      if(y==1) { return true; }
      else if(y==2) { return false; }
      else { cout<<"잘못 된 입력입니다. 다시 입력하세요."<<endl; }
    }
  }

  // 제품 추가
  bool addProduct(DB_Sh &dbsh, DB_Pd &dbpd, DB_Sz &dbsz, ShopManager &nowSm){
    cout<< "===============================================" <<endl;
    cout<< "   << 제품 등록 >>" <<endl;
    cout<< "===============================================" <<endl;
    int shidxArr[20];
    int pr, i=0, idx=0;
    string sh, ca, na, inf, bl, sameInfo;
    // 제품 등록할 쇼핑몰 선택
    while(true) {
      idx = dbsh.getShidx_bySm(nowSm, idx);
      shidxArr[i] = idx;
      if(shidxArr[i]==-1) break;
      i++; idx++;
    }
    dbsh.showShList_sm(shidxArr);
    cout<<"제품을 등록할 쇼핑몰 선택 (취소하려면 0 입력.)"<< endl;
    int n=i;
    cin>>i;
    if(i==0) {
      cout<<"제품 등록 취소"<<endl;
      return false;
    }
    else if(i>n){
      cout<<"잘못된 입력 범위입니다."<<endl;
      return false;
    } 
    i--;
    idx = shidxArr[i];
    sh = dbsh.getName(idx);
    // 제품 카테고리 선택
    cout<< "===============================================" <<endl;
    while(true){
      cout<<"등록할 제품의 카테고리 선택"<<endl<<"상의:1, 하의:2"<<endl<<">>";
      cin>>i;
      if(i==1) {ca="top"; break;}
      else if(i==2) {ca="bottom"; break;}
      else cout<<"잘못 된 카테고리 선택. 다시 입력"<<endl;
    }
    // 제품 정보 입력
    cout<< "===============================================" <<endl;
    while(true) {
      cout<<"제품의 정보를 입력하세요."<<endl<<"제품 이름 : ";
      cin.ignore();
      getline(cin, na);
      cout<<"제품 가격 : ";
      cin>>pr;
      cout<<"제품 설명 : ";
      cin.ignore();
      getline(cin, inf);
      cout<<"제품 구매 링크 : ";
      getline(cin, bl);
      sameInfo = dbpd.checkSameInfo(na, now_index);
      if(sameInfo == "Name") {
        cout<<"제품 이름이 중복되었습니다. 다시 입력하세요."<<endl;
        continue;
      } else break;
    }
    // 같은 정보 확인 후 등록
    if(sameInfo == "OK") {
      Product pd(na, ca, pr, sh, inf, bl);
      dbpd.addPd(now_index, pd);
      cout<<"다음 페이지에서 사이즈를 입력하세요."<<endl;
    }
    // 제품 사이즈 등록
    enterSize(dbsz, dbpd, na, ca, now_index);
    cout<<"제품읠 등록이 완료되었습니다."<<endl;
    return true;
  }

  // 제품 사이즈 입력 및 사이즈 객체 생성
  void enterSize(DB_Sz &dbsz, DB_Pd &dbpd, string name, string category, int now_index){
    cout<< "===============================================" <<endl;
    cout<< "   << 제품 사이즈 등록 >>" <<endl;
    cout<< "===============================================" <<endl;
    char c = ' ';
    while(true) {
      cout<<"등록할 제품 사이즈를 입력하세요.(S / M / L)"<<endl<<"사이즈 : ";
      cin>>c;
      if(c=='X'||c=='x') break;
      else if(c=='s') c='S'; else if(c=='m') c='M';  else if(c=='l') c='L';
      if(c!='S'&&c!='M'&&c!='L') {
        cout<< "사이즈 입력이 잘못되었습니다. 다시 입력하세요."<<endl;
        continue;
      }
      dbpd.setPdSml(now_index, c);
      Size sz(name, c);
      if(category=="top") { sz.setTopSize(); }
      else { sz.setBottomSize(); }
      new_index = dbsz.getLastidx();
      dbsz.addSize(sz, new_index);
      cout<< "===============================================" <<endl;
      cout<< "제품 사이즈 "<< c<< " 등록 완료"<<endl;
      cout<< "종료를 원하는 경우 사이즈에 \"X\" 입력."<<endl<<"추가로 ";
    }
  }

  // 제품 삭제
  void deleteProduct(DB_Sh &dbsh, DB_Pd &dbpd, ShopManager &nowSm) {
    // 쇼핑몰 선택
    
    int shidxArr[20];
    int i=0; int idx=0;
    string shn;
    while(true) {
      idx = dbsh.getShidx_bySm(nowSm, idx);
      shidxArr[i] = idx;
      if(shidxArr[i]==-1) break;
      i++; idx++;
    }
    cout<< "===============================================" <<endl;
    cout<< "   << 제품 삭제 >>" <<endl;
    cout<< "===============================================" <<endl;
    dbsh.showShList_sm(shidxArr);
    cout<<"삭제할 제품이 있는 쇼핑몰 선택"<< endl<<">>";
    cin>>i;
    i--;
    idx = shidxArr[i];
    shn = dbsh.getName(idx);
    // 삭제할 제품 선택
    int pdidxArr[20];
    i=idx=0;
    while(true) {
      idx = dbpd.getPdidx_bySh(shn, idx);
      pdidxArr[i] = idx;
      if(pdidxArr[i]==-1) break;
      i++; idx++;
    }
    cout<< "===============================================" <<endl;
    cout<<"쇼핑몰 "<<shn<<"의 제품 리스트"<<endl;
    dbpd.showPdList_sm(pdidxArr);
    cout<<"삭제할 제품 선택 (삭제하지 않으려면 0 입력.)"<<endl<<">>";
    cin>>i; i--;
    if(i==-1) cout<<"제품 삭제 취소"<<endl;
    
    else {
      cout<< "===============================================" <<endl;
      idx = pdidxArr[i];
      cout<<"삭제될 제품 : "<<dbpd.getName(idx)<<endl;
      if(askAgain()) {
        cout<<"제품 "<<dbpd.getName(idx);
        dbpd.deletePd(idx);
        cout<<" 삭제 성공"<<endl;
      }
      else { cout<<"제품 삭제 취소"<<endl; }
    }
  }

  // 주문등록
  void manageOrder(DB_Sh dbsh, DB_Pd dbpd, DB_Od &dbod, ShopManager nowSm){
    string cusNa, cusPh, shn, pdn, pdCa;
    char pdsml;
    int pdPr, i=0, shidx=0, pdidx=0;
    int shidxArr[20];
    int pdidxArr[20];
    cout<< "===============================================" <<endl;
    cout<< "   << 주문 등록 >>" <<endl;
    cout<< "===============================================" <<endl;
    cout<<"주문 정보를 입력하세요."<<endl;
    cout<<"구매자 정보를 입력하세요."<<endl;
    cin.ignore();
    cout<<"이름 : ";  getline(cin, cusNa);
    cout<<"전화번호 : ";  getline(cin, cusPh);
    // 판매한 제품의 쇼핑몰 선택
    while(true) {
      shidx = dbsh.getShidx_bySm(nowSm, shidx);
      shidxArr[i] = shidx;
      if(shidxArr[i]==-1) break;
      i++; shidx++;
    }
    cout<< "===============================================" <<endl;
    dbsh.showShList_sm(shidxArr);
    cout<<"판매한 제품의 쇼핑몰 선택"<<endl<<">>";
    cin>>i; i--;
    shidx = shidxArr[i];
    shn = dbsh.getName(shidx);
    // 판매한 제품 선택
    i=0;
    while(true) {
      pdidx = dbpd.getPdidx_bySh(shn, pdidx);
      pdidxArr[i] = pdidx;
      if(pdidxArr[i]==-1) break;
      i++; pdidx++;
    }
    cout<< "===============================================" <<endl;
    cout<<"쇼핑몰 "<<shn<<"의 제품 리스트"<<endl;
    dbpd.showPdList_sm(pdidxArr);
    cout<<"판매한 제품 선택"<< endl<<">>";
    cin>>i;
    pdidx = pdidxArr[--i];
    pdn = dbpd.getName(pdidx);
    pdCa = dbpd.getCategory(pdidx);
    pdPr = dbpd.getPrice(pdidx);
    while(true){
      cout<< "===============================================" <<endl;
      cout<<"판매한 제품의 사이즈 입력 (S, M, L 중)"<<endl<<"사이즈 : ";
      cin>>pdsml;
      if(pdsml=='s') pdsml='S';
      else if(pdsml=='m') pdsml='M';
      else if(pdsml=='l') pdsml='L';
      if(pdsml!='S' && pdsml!='M' && pdsml!='L')
        cout<< "사이즈 입력이 잘못되었습니다. 다시 입력하세요."<<endl;
      else break;
    }
    Order od(cusNa, cusPh, shn, pdn, pdCa, pdPr, pdsml, false);
    i = dbod.getLastidx();
    dbod.addOrder(od, i);
    cout<<"주문 정보 등록이 완료되었습니다."<<endl;
  }

};