# SizePleaze
온라인 쇼핑몰 의류 사이즈 추천 프로그램

<img width="400" alt="image" src="https://github.com/dawin002/SizePleaze/assets/77649724/7b42016e-2bd3-4398-8df4-16c53c4ae431">

## 0. 순서

1. [Summary](#1-Summary)
2. [프로젝트 목표](#2-프로젝트-목표)
3. [주요 기능 - All users](#3-주요-기능---All-users)
4. [주요 기능 - Customer](#4-주요-기능---Customer)
5. [주요 기능 - Shop manager](#5-주요-기능---Shop-manager)
6. [프로그램 체험 하기](#6-프로그램-체험-하기)


## 1. Summary
온라인 의류 쇼핑몰에서 소비자의 제품 사이즈 선택을 돕는 사이즈 추천 프로그램입니다.

소비자가 자신의 신체 사이즈를 등록하면 판매자가 등록한 제품의 실측 사이즈와 해당 제품 구매자의 사이즈 평가를 참고해 소비자에게 가장 알맞을 것으로 예측되는 사이즈를 추천합니다.

## 2. 프로젝트 목표

- 입력받은 소비자의 의류 제품 사이즈를 쇼핑몰 제품 사이즈 표에 대입해 소비자에게 가장 알맞은 사이즈를 추천합니다.
- 실제 착용감에 의해 느껴지는 사이즈를 평가받고 이 데이터를 고려해 정확한 제품 사이즈를 추천합니다.
- 의류 제품의 사이즈 평가 항목을 간소화하고 사이즈 평가 참여시 적립금을 지급해 소비자의 제품 평가 데이터를 수집합니다.
- 소비자의 의류 제품 사이즈 선택을 돕고 잘못된 사이즈 주문으로 인한 환불/교환 감소를 통해 소비자와 판매자의 금전적, 시간적 비용을 절약합니다.

## 3. 주요 기능 - All users

- 모든 사용자에게 동일하게 제공되는 기능입니다.

### Start system (시스템 시작 기능)

사용자가 프로그램을 실행했을 때 볼 수 있는 메인 화면입니다.

<img width="400" alt="image" src="https://github.com/dawin002/SizePleaze/assets/77649724/c73b2dfb-ec0d-42a7-8b70-d7523cdce0ba">

- 로그인 또는 회원가입을 통해 서비스를 시작할 수 있습니다.

### Login (로그인 기능)

사용자가 서비스 이용하기 위해 로그인 하는 기능입니다.

<img width="400" alt="image" src="https://github.com/dawin002/SizePleaze/assets/77649724/24574424-3c88-41e9-b36b-5be4309cdd82">

- 사용자에게 ID와 Password를 입력받아 일치하는 회원 정보를 찾습니다.
- 일치하는 회원 정보가 있는 경우:
  - 이름과 회원 유형을 받아 출력합니다.
  - 회원 유형에 해당하는 메뉴 기능을 실행합니다. (소비자 메뉴 / 판매자 매뉴)
- 일치하는 회원 정보가 없는 경우:
  - 일치하는 회원 정보가 없다는 메시지를 출력합니다.
  - 로그인 기능을 다시 실행합니다.

### Join (회원 가입 기능)

새로운 회원 정보 등록을 위해 사용자에게 정보를 입력받아 저장하는 기능입니다.

<img width="400" alt="image" src="https://github.com/dawin002/SizePleaze/assets/77649724/33742f2e-38d6-4cd0-ab2c-be482d6bc537">

- 사용자에게 회원 정보를 입력받습니다.
- 회원 정보를 저장하고 Start system 기능을 실행합니다.
- 중복된 ID, 전화번호, 쇼핑몰 주소가 존재하는 경우:
  - 어떤 정보가 중복되었는지 출력합니다.
  - 회원 가입 기능으로 돌아옵니다.

## 4. 주요 기능 - Customer

소비자 유형의 사용자에게 제공되는 기능입니다.

### Customer menu (소비자 메뉴)

소비자 유형으로 로그인한 사용자가 이용할 수 있는 기능을 선택하는 기능입니다.

<img width="400" alt="image" src="https://github.com/dawin002/SizePleaze/assets/77649724/8ce70fe1-0431-473d-ae87-70f7f881fb68">

- 소비자가 사용할 수 있는 기능 리스트를 출력합니다.
- 실행할 기능 번호를 입력받습니다.
- 입력받은 번호에 해당하는 기능을 실행합니다.

### Enter size (사이즈 등록)

소비자가 자신의 의류 제품 실측 사이즈를 등록하는 기능입니다.

<img width="400" alt="image" src="https://github.com/dawin002/SizePleaze/assets/77649724/138adff3-221f-44db-9d85-7f1495adcbff">

- 상의와 하의의 부위별 실측 사이즈를 양식에 맞게 입력합니다.
- 특정 부위의 사이즈를 잘 모르는 경우:
  - -1을 입력받아  저장합니다.
  - 사이즈 추천에서  저장값이 -1인 경우 해당 부위를 제외하고 계산해 추천합니다.

### Pick shop (쇼핑몰 선택)

소비자가 방문할 쇼핑몰을 선택할 수 있는 기능입니다.

<img width="400" alt="image" src="https://github.com/dawin002/SizePleaze/assets/77649724/5815c6b9-8adc-4478-a7a8-ec2a69230e80">

- 전체 쇼핑몰 리스트를 출력합니다.
  - 쇼핑몰의 이름과 간단한 소개를 출력합니다.
- 방문할 쇼핑몰의 번호를 입력받습니다.
- 번호에 해당하는  쇼핑몰의 제품 선택 기능을 불러옵니다.

### Pick category (카테고리 선택)

소비자가 제품 카테고리를 선택할 수 있는 기능입니다.

<img width="400" alt="image" src="https://github.com/dawin002/SizePleaze/assets/77649724/58585b11-c04c-4e88-9270-f611efbe45c4">

- 선택 가능한 카테고리 리스트를 출력합니다.
- 카테고리 번호를 입력받습니다.
- 번호에 해당하는 카테고리의 제품 선택 기능을 불러옵니다.

### Pick product (제품 선택)

소비자가 제품을 선택할 수 있는 기능입니다.

<img width="400" alt="image" src="https://github.com/dawin002/SizePleaze/assets/77649724/70a8c379-9837-4c71-957f-13923ee61743">

- 쇼핑몰 선택에서 제품 선택 기능이 실행된 경우:
  - 선택한 쇼핑몰에 해당하는 제품 리스트를 불러옵니다.
- 카테고리 선택에서 제품 선택 기능이 실행된 경우:
  - 선택한 카테고리에 해당하는 제품 리스트를 불러옵니다.
- 제품 리스트를 출력합니다.
  - (상품명 / 가격 / 간단한 설명) 양식으로 출력합니다.
- 조회할 제품 번호를 입력받습니다.
- 번호에 해당하는 제품의 사이즈 추천 기능을 불러옵니다.

### Recommend size (사이즈 추천)

소비자에게 맞는 제품 사이즈를 추천하는 기능입니다.

<img width="400" alt="image" src="https://github.com/dawin002/SizePleaze/assets/77649724/5d4a97fb-5daa-45fa-b31d-58d9e24cfab4">

- 제품명을 출력합니다.
- 제품의 사이즈 평가 정보를 요약해 출력합니다.
- 소비자의 신체에 가장 알맞는 사이즈를 계산해 추천합니다.
- 제품의 구매 링크를 보여줍니다.
- 이전 단계로 돌아갈 수 있는 번호를 입력받습니다.

### Use point (적립금 사용)

소비자가 적립금을 사용할 수 있는 기능입니다.

<img width="400" alt="image" src="https://github.com/dawin002/SizePleaze/assets/77649724/90c03a1e-a746-4a4c-81a6-641ed7e16e33">

- 소비자의 현재 적립금을 출력합니다.
- 사용 희망 금액을 입력받습니다.
  - 입력 금액이 적립금보다 큰 경우 잔액 부족 메시지를 출력하고 다시 입력받습니다.
- 적립금을 사용할 수 있는 쇼핑몰 리스트를 출력합니다.
  - 적립금은 이전에 제품을 한 번 이상 구매했던 쇼핑몰에서만 사용 가능합니다.
- 소비자에게 적립금을 사용할 쇼핑몰 번호를 입력 받습니다.
- 사용 희망 금액에 해당하는 쿠폰 번호를 출력합니다.

### Eveluate size (사이즈 평가)

소비자가 구매한 제품의 사이즈를 평가할 수 있는 기능입니다.

<img width="400" alt="image" src="https://github.com/dawin002/SizePleaze/assets/77649724/e2be4ff9-29fb-49a3-a809-cb0db2432339">

- 소비자가 구매한 제품 리스트를 출력합니다.
- 소비자가 사이즈를 평가할 제품의 번호를 입력합니다.
- 상의/하의를 구분해 다른 문항의 평가를 받습니다.
  - 상의 사이즈 평가 문항:
    - 총장, 어깨 너비, 팔 길이
  - 하의 사이즈 평가 문항:
    - 총장, 어깨 너비, 팔 길이
  - 각 부위별 사이즈를 작다(1) ~ 크다(5) 범위로 평가받습니다.
- 평가 받은 사이즈를 데이터 베이스에 저장합니다.
- 적립금 지급 기능을 실행합니다.

### Give point (적립금 지금)

사이즈 평가의 보상으로 적립금을 지급하는 기능입니다.

<img width="400" alt="image" src="https://github.com/dawin002/SizePleaze/assets/77649724/a3c71c1e-ffc5-4b57-b1f5-9a65dd6466c6">

- 소비자가 구매한 제품 정보(제품명, 가격)을 출력합니다.
- 적립률과 계산한 적립 금액을 출력합니다.
- 지금까지 누적된 소비자의 적립 금액을 출력합니다.

## 5. 주요 기능 - Shop manager

판매자 유형의 사용자에게 제공되는 기능입니다.

### Shop manager menu (판매자 메뉴)

판매자 유형의 사용자가 이용할 수 있는 기능을 선택하는 기능입니다.

<img width="400" alt="image" src="https://github.com/dawin002/SizePleaze/assets/77649724/041a68a2-6b17-48fe-b000-668dd6f6abb6">

- 판매자가 사용할 수 있는 기능 리스트를 출력합니다.
- 실행할 기능 번호를 입력받습니다.
- 입력받은 번호에 해당하는 기능을 실행합니다.

### Manage shop (쇼핑몰 관리)

판매자가 쇼핑몰 등록이나 쇼핑몰 삭제 기능을 선택하는 기능입니다.

<img width="400" alt="image" src="https://github.com/dawin002/SizePleaze/assets/77649724/5e699801-530b-4647-bc3f-7975435a0086">

- 쇼핑몰을 관리할 수 있는 기능 리스트를 출력합니다.
- 실행할 기능 번호를 입력받습니다.
- 입력받은 번호에 해당하는 기능을 실행합니다.

### Add shop (쇼핑몰 등록)

판매자가 쇼핑몰을 등록하는 기능입니다.

<img width="400" alt="image" src="https://github.com/dawin002/SizePleaze/assets/77649724/72d4e54f-b4e4-4213-b666-933ca56457e1">

- 판매자에게 쇼핑몰 정보를 입력 받습니다.
- 쇼핑몰 정보를 데이터 베이스와 비교해 중복된 정보가 있는지 검사합니다.
- 쇼핑몰 정보를 데이터 베이스에 추가합니다.

### Delete shop (쇼핑몰 삭제)

판매자가 쇼핑몰을 삭제하는 기능입니다.

<img width="400" alt="image" src="https://github.com/dawin002/SizePleaze/assets/77649724/ad23e7c4-8a31-4528-9a69-9bd2002405f9">

- 판매자가 관리하는 쇼핑몰 리스트를 출력합니다.
- 삭제할 쇼핑몰의 번호를 입력받습니다.
- 선택한 쇼핑몰을 삭제할지 재확인합니다.
- YES를 입력한 경우:
  - 해당 쇼핑몰을 데이터 베이스에서 삭제합니다.
  - 해당 쇼핑몰이 삭제되었다는 메시지를 출력합니다.
- NO를 입력한 경우:
  - 쇼핑몰 삭제 기능을 종료합니다.

### Manage product (제품 관리)

판매자가 제품 등록이나 제품 삭제 기능을 선택하는 기능입니다.

<img width="400" alt="image" src="https://github.com/dawin002/SizePleaze/assets/77649724/572804b1-9193-4d6c-a066-e53a4c55984e">

- 제품을 관리할 수 있는 기능 리스트를 출력합니다.
- 실행할 기능 번호를 입력받습니다.
- 입력받은 번호에 해당하는 기능을 실행합니다.

### Add product (제품 등록)

판매자가 제품을 등록하는 기능입니다.

<img width="400" alt="image" src="https://github.com/dawin002/SizePleaze/assets/77649724/2a703043-0928-4dd2-a70f-a8b1b87837f2">

- 판매자가 관리하는 쇼핑몰 리스트를 출력합니다.
- 어떤 쇼핑몰에 제품을 등록할지 입력받습니다.
- 제품의 카테고리를 입력받습니다.
- 제품 정보를 입력받습니다.(이름, 가격, 구매 링크)
- 중복된 제품 이름이 존재하는지 검사합니다.
- 제품 정보를 데이터 베이스에 추가합니다.

<img width="400" alt="image" src="https://github.com/dawin002/SizePleaze/assets/77649724/2b569b1f-48f0-45b2-9377-9c7fae338ebd">

- 제품의 영문 사이즈를 입력받습니다.
- 제품의 실측 사이즈를 입력받습니다.
  - 제품의 카테고리에 따라 다른 실측 사이즈를 입력받습니다.
  - 상의: 어깨 너비, 팔 길이, 총 기장
  - 하의: 허리 너비, 엉덩이 너비, 총 기장
- 제품의 사이즈 정보를 데이터 베이스에 추가합니다.
- 제품의 사이즈를 추가로 입력받습니다.
  - 영문 사이즈 입력부터 다시 실행합니다.
  - -1을 입력한 경우 제품 등록 기능을 종료합니다.

### Delete product (제품 삭제)

판매자가 제품을 삭제하는 기능입니다.

<img width="400" alt="image" src="https://github.com/dawin002/SizePleaze/assets/77649724/5d7bfb01-6d6e-40fb-a5a0-e21af9242b50">

- 판매자가 관리하는 쇼핑몰 리스트를 출력합니다.
- 삭제할 제품이 등록된 쇼핑몰 번호를 입력받습니다.
- 해당 쇼핑몰에 등록된 제품 리스트를 출력합니다.
- 삭제할 제품 번호를 입력받습니다.
- 선택한 제품을 삭제할지 재확인합니다.
- YES를 입력한 경우:
  - 해당 제품을 데이터 베이스에서 삭제합니다.
  - 해당 제품이 삭제되었다는 메시지를 출력합니다.
- NO를 입력한 경우:
  - 제품 삭제 기능을 종료합니다.

### Manage order (주문 관리)

판매자가 적립금 지급을 위한 주문 정보를 등록하는 기능입니다.

<img width="400" alt="image" src="https://github.com/dawin002/SizePleaze/assets/77649724/32a8cf3f-d851-435a-8d00-d86e8e0325f6">

- 판매자에게 제품을 구매한 구매자의 정보를 입력합니다.
- 판매자가 관리하는 쇼핑몰 리스트를 출력합니다.
- 판매한 제품이 등록된 쇼핑몰 번호를 입력받습니다.
- 쇼핑몰에 등록된 제품 리스트를 출력합니다.
- 판매한 제품 번호를 입력받습니다.
- 판매한 제품의 가격과 사이즈를 입력받습니다.
- 사이즈 평가를 위한 사이즈 정보와 적립금 지급을 위한 제품 가격을 데이터 베이스에 저장합니다.

## 6. 프로그램 체험 하기

### 프로그램 실행 방법

아래 replit(온라인 IDE) 링크를 통해 프로그램을 실행할 수 있습니다. 
(실행을 위해서 replit 계정이 필요합니다...)

https://replit.com/join/uhphjfmfvq-dawin002

링크로 이동해 화면 상단 중앙의 run 버튼을 클릭하면 프로그램이 실행됩니다.

### 기본 제공 예시 데이터

소비자 계정
- ID : 1111
- PW : 1111
- 전화번호 : 1111

판매자 계정
- ID : 2222
- PW : 2222
- 전화번호 : 2222

사이즈 추천을 받을 수 있는 제품
- "예시쇼핑몰" 의 "파란티셔츠"
- "예시쇼핑몰2" 의 "까만바지"
 
데이터 베이스에 등록된 정보는 왼쪽 베젤의 DB 클래스들에서 확인 가능합니다.
- (실시간으로 입력된 데이터는 코드에 입력되지 않습니다.)

### 체험할 수 있는 기능

판매자가 등록한 주문 정보는 소비자의 주문 정보와 연동되어 소비자가 해당 제품의 사이즈 평가를 수행할 수 있고 사이즈 평가의 결과가 사이즈 추천에 적용되게 구현하였습니다.

주요 기능 목록에 적혀있는 기능은 모두 수행 가능하며 다음 기능들을 체험해 보는 것을 추천드립니다.

- 제공된 계정으로 로그인하거나 회원 가입으로 새로운 계정을 만들어 로그인할 수 있습니다.

- 프로그램 실행자의 실제 사이즈를 입력해 예시 제품의 사이즈 추천을 받을 수 있습니다.

- 제품 사이즈 평가를 수행하면 제품의 사이즈 추천이 실시간으로 변경되는 것을 확인할 수 있습니다.
  - 기존 등록된 사이즈 추천 정보가 존재하기 때문에 추천되는 영문 사이즈 변경을 위해서는 제품 사이즈 평가를 여러번 수행해야 할 수 있습니다.

- 메뉴에서 로그아웃 후 다른 계정으로 로그인하면 다음과 같이 변경한 데이터가 적용된 것을 확인할 수 있습니다.
  - 판매자로 쇼핑몰/제품 등록 후 소비자로 쇼핑몰/제품 조회 가능
  - 판매자로 주문 관리(==등록) 후 소비자로 제품 사이즈 평가 가능
  - 소비자로 사이즈 평가 후 다른 소비자로 제품 사이즈 추천이 변경된 것을 확인 가능

### 체험시 주의사항

- 소비자가 제품 사이즈를 평가하기 위해서는 판매자가 주문 정보를 등록해야 합니다.

- 판매자가 주문 정보를 입력할 때 소비자의 이름과 전화번호를 정확히 입력해야 합니다.

- 데이터 베이스는 프로그램 내부에 코드로 대체되어 프로그램이 종료되면 초기값(예시 데이터)로 돌아갑니다.

- 메뉴선택 등 정수 입력시에 문자를 입력하시는 에러는 예외처리 하지 못해서 프로그램이 종료될 수 있습니다.
  - 해당 경우 외에는 예외처리를 대부분 해두어 예외가 발생해도 괜찮습니다.
 
- 로그아웃 선택 후 다시 0을 입력하면 프로그램이 종료되어 체험시 등록한 정보가 데이터 베이스에서 삭제됩니다.
