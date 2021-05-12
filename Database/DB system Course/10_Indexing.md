# 인덱싱

## **목차**
1. 인덱스의 이해
2. 순서 인덱스
3. B+트리 인덱스

<br>
<br>
<br>

# **1. 인덱스의 이해**
## 인덱스의 필요

1. 데이터 검색에서 발생하는 비효율적인 데이터 입출력 문제를 해결하기 위한 목적으로 시작
    - 인덱스 : DBMS에서 요청된레코드에 빠르게 접근할 수 있도록 지원하는 데이터와 관련된 부가적인 구조
    - 인덱싱 : 인덱스를 구성하고 생성하는 작업
2. 인덱스의 탐색키를 이용하여 해당 레코드각 저장된 블럭을 디스크 저장장치 또는 메모리에서 파악하여 해당 블럭을 빠르게 적재.
    - 탐색키 : 파일에서 레코드를 찾는데 사용되는 컬럼이나 컬럼의 집합.

## 인덱싱의 종류
    1. 인덱스의 종류
        - 순서 인덱스 : 특정 값에 대해 정렬된 순서 구조.
        - 해시 인덱스 : 버킷의 범위 안에서 값의 균일한 분포에 기초한 구조로 해시 함수가 어떤 값이 어느 버킷에 할당되는지 결정.

    2. 인덱스의 평가기준
        - 접근시간 : 데이터를 찾는데 걸리는 시간.
        - 유지 비용 : 새로운 데이터 삽입 및 기존 데이터 삭제 연산으로 인한 인덱스 구조 갱신 비용
        - 공간 비용 : 인덱스 구조에 의해 사용되는 부가적인 공간 비용.

<br>
<br>
<br>

# **2. 순서인덱스**

## 순서 인덱스의 특징
1. 탐색키로 정렬된 순차 파일에 대하여 레코드에 대한 빠른 접근이 가능하도록 구성한 인덱스
    - 탐색키를 정렬하여 해당 탐색키와 탐색키에 대한 레코드와의 연계를 통하여 인덱스 생성 (종이 사전 또는 성경책의 검색 구조와 유사)
    - 순서 인덱스의 종류
        - 밀집 인덱스
        - 희소 인덱스
        - 다단계 인덱스

## 인덱스 엔트리의 구조

- 탐색키 값 : 인덱스 엔트리가 어떤 레코드를 대상으로 만들어졌는지에 대한 정보.
- 블럭 ID : 해당 레코드가 어느 블럭에 저장되어 있는지.
- 오프셋 : 해당 레코드가 블럭 내부의 어느 위치에 있는지.

<img src="https://user-images.githubusercontent.com/66513003/116651717-c0e44d80-a9be-11eb-97a1-3dea50c96d4c.png" width="400"/>

20140001에 대한 정보는
b2 블럭의 30바이트째 위치를 가리킴.

## 밀집 인덱스
1. `모든` 레코드에 대해 `탐색키 값, 포인터` 쌍을 유지.

## 희소 인덱스
1. 인덱스의 엔트리가 `일부`의 탐색키 값만을 유지.

- 검색하려는 대상 탐색키와 희소인덱스의 탐색키값을 비교해 가장 근접한 키중 작은 값을 따라가 그다음부터 순서대로 찾음.

<img src="https://user-images.githubusercontent.com/66513003/116652608-8380bf80-a9c0-11eb-9576-4fa07647da6e.png" width="400"/>

- COM31 검색시, 근접한 키중 낮은값을 찾아 COM11 -> COM12 -> COM31 순으로 검색한다.

- 밀집인덱스는 검색시 바로 탐색키를 따라서 대상을 찾기때문에 빠르지만 차지하는 메모리가 크고,

- 희소인덱스는 탐색키를 듬성듬성 저장해 메모리 소모는 적지만 그만큼 검색에 더 많은 연산이 필요하다.

## 다단계 인덱스의 필요

1. 4kb 크기의 한 블럭에 100개의 엔트리가 삽입될 때, 100,000,000 개의 레코드에 대한 순서 인덱스
    - 1,000,000개의 블럭 = 4GB의 공간 필요

2. 인덱크 크기에 따른 검색 성능
    - 인덱스 크기 < 메모리 크기
        - 디스크 I/O이 줄어 탐색 시간이 축소.
    - 인덱스 크기 > 메모리 크기
        - 저장된 블럭을 여러번나누어 읽어야 하기 때문에 디스크 I/0비용이 증가하여 탐색 시간이 증가.

## 다단계 인덱스
1. 내부 인덱스와 외부 인덱스로 구성
    - 외부 인덱스를 내부 인덱스보다 희소한 이덱스로 구성하여 엔트리의 포인터가 내부 인덱스 블럭을 지칭.
    - 포인터가 가리키는 블럭을 스캔하여 원하는 레코드 보다 작거나 같은 탐색키 값 중에 가장 큰 값을 가지는 레코드를 탐색

<br>
<br>
<br>

# 3. **B+ 트리 인덱스**
- B+ 트리의 구조
- B+ 트리의 구성 요소
- B+ 트리 기반 검색
- 탐색키 삽입과 삭제

## 이진 탐색 트리 (binary search tree)

<img src="https://user-images.githubusercontent.com/66513003/116653870-0145ca80-a9c3-11eb-9ded-06e54f9992f7.png" width="400"/>

## B+트리의 구조

- 이진 탐색 트리를 확장해 놓은 구조
- 하나의 노드에 여러개의 탐색키가 들어가고
그 하부에는 또 다시 여러개의 자식 노드를 가짐.
- 최 하부의 노드가 서로를 가리키는 일종의 연결 리스트 형태로 되어 있다는 특징을 가짐.

<img src="https://user-images.githubusercontent.com/66513003/116654073-626d9e00-a9c3-11eb-9320-c5de99190a6c.png" width="400"/>

1. 루트 노드로 부터 모든 단말 노드에 이르는 경로의 길이가 같은 높이 균형 트리
    - 순서 인덱스는 파일이 커질수록 데이터 탐색에 있어서 접근 비용이 커지는 문제점을 해결하기 위해 제안.
    - 상용 DBMS에서도 널리 사용되는 대표적인 순서 인덱스.

2. B+트리 노드 구조


<img src="https://user-images.githubusercontent.com/66513003/116654678-9bf2d900-a9c4-11eb-824b-63b910df4da4.png" width="400"/>

- (n-1)개의 탐색키
- 하위노드는 n개
- n = 차수 = 팬아웃(fanout) = 어떤 노드에 하위노드의 개수

1. 인덱스 세트 : 루트노드와 중간노드로 구성
    - 단말노드에 있는 탐색키 값을 신속하게 찾아갈 수 있도록 경로를 제공하는 목적으로 사용
    -  [n/2] ~ n 사이의 개수를 자식으로 소유

2. 순차 세트 : 단말 노드로 구성
    - 모든 노드가 순차적으로 서로 연결
    - 단말 노드는 적어도 (n-1)/2개의 탐색키를 포함
    - 탐색키에 대한 `실제 레코드`를 지칭하는 포인터를 제공

<img src="https://user-images.githubusercontent.com/66513003/116655207-a8c3fc80-a9c5-11eb-9986-153a2c76098f.png" width="400"/>

- 단말 노드는 직접 메모리와 연결

## B+ 트리 상에서의 삽입, 삭제
1. 레코드 삽입, 삭제시 B+ 트리 수정
    - 레코드 삽입 
        - 노드에서 유지해야 할 탐색키와 포인터 수 증가로 인해 노드를 분할해야 하는 경우가 발생.
        - 검색과 같은 방법을사용하여 삽입되는 레코드의 탐색키 값이 속할 단말 노드를 탐색.
            - 해당 단말 노드에 <탐색키, 포인터> 쌍을 삽입.
            - 삽입 시 탐색키가 순서를 유지.

    - 레코드 삭제
        - 노드에서 유지해야 할 탐색키 값과 포인터 수 감소로 형제 노드와 키를 재분배 또는 병합해야 하는 경우가 발생.
        - 삭제될 레콛의 탐색키를 통해 삭제될 탐색키와 포인터를 포함한 단말 노드를 탐색.
            - 같은 탐색키 값을 가지는 다중 인트리가 존재할 경우, 삭제될 레코드를 가리키는 엔트리를 찾을 때까지 탐색 후 단말 노드에서 제거
            - 단말 노드에서 제거된 엔트리의 오른쪽에 있는 엔트리들은 빈 공간이 없도록 왼쪽으로 이동
    - 높이 균형 유지
        -노트가 분할되거나 병합되면서 높이의 균형이 맞지 않는 경우가 발생.

## 노드가 분할되는 삽입

1. COM24 삽입
<img src="https://user-images.githubusercontent.com/66513003/116657694-d0b55f00-a9c9-11eb-8594-d61d596dd2e1.png" width="400"/>

- 삽입 대상 노드에 저장할 공간 부족 -> 노드 분할
    - COM12를 하나의 단말 노드로 구성
    - COM24와 COM31이 하나의 단말 노드로 구성

## 탐색키의 삭제

1. COM44 삭제
<img src="https://user-images.githubusercontent.com/66513003/116658185-8da7bb80-a9ca-11eb-8477-01f14b650150.png" width="400"/>

2. COM12 삭제
<img src="https://user-images.githubusercontent.com/66513003/116658719-61406f00-a9cb-11eb-855e-fdc342e59b02.png" width="400"/>

    - COM12가 있는 단말 노드를 검색하고 탐색키를 삭제
        - 해당 단말 노드는 삭제 후 탐색키가 존재하지 않음.
        - [(N-1)/2]개보다 탐색키가 적으므로 다른 노드와 별도의 재구조화 작업이 필요
        - COM24가 COM12가 있던 노드로 이동.