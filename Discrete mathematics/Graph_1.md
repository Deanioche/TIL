# 그래프 1

## **1. 기본사항**
1. 주요용어
2. 그래프 탐색

#

## **1. 주요 용어**

<img src="https://user-images.githubusercontent.com/66513003/117992595-066b2800-b37a-11eb-9800-49d196e8c28d.png" width="400">

- (꼭지)점 : `vertex`, node, station

- 선(변) : `edge`, link, line

- `𝑮 = (𝑽, 𝑬)`
    - 두 개의 집합을 튜플로 표현

- `𝑽 = {𝒗|𝒗는 꼭지점}, 𝑬 = {𝒆|𝒆는 변}`
    - V는 꼭지점들의 집합, E는 변들의 집합.

- 변은 두 꼭지점을 연결.
    - 변에 의해 `발생(incident)`되었다.

- 연결된 두 꼭지점은 서로 `인접(adjacent)`한다.

- `병렬 변(parallel edge)` : 두 꼭지점을 연결하는 변의 수가 `복수` 일 때.

- `루프(loop)` : 동일한 꼭지점을 연결하는 변

- `고립된 꼭지점(isolated vertex)` : 어떠한 변도 연결되지 않은 꼭지점

### **# 예제**   1
<img src="https://user-images.githubusercontent.com/66513003/117994070-3961eb80-b37b-11eb-9e97-0bf153f153a0.png
" width="250">

### **# 예제**     2
<img src="https://user-images.githubusercontent.com/66513003/117994387-75954c00-b37b-11eb-913f-7e347d05771d.png" width="400">
    - 1번과 2번은 둘다 V1과 V3 사이에 Edge가 존재하므로 동일. (직, 곡선 여부 안따짐)
    - 3번은 1번을 90도 시계방향 회전시킨 것과 동일.
    - 4번은 V2와 V4 사이에 Edge가 있으므로 다름. `(E = (v2, v4)) != (E = (v1, v3))`

- `동형(isomorphic)`  
    꼭지점과 변의 이름만 제외하고는 모두 동일한 그래프들을 서로 `동형`이라고 한다.
    
- `방향 그래프(directed graph)`  
    변이 방향을 가지고 있는 그래프

- `무향 그래프(undirected graph)`  
    변이 방향을 가지고 있지 않은 그래프

<img src="https://user-images.githubusercontent.com/66513003/117995417-43381e80-b37c-11eb-82c5-ea8005e24404.png
" width="300">

- `단순 그래프`  
    `루프`와 `병렬 변`을 가지지 않는 `무향` 그래프.  
<img src="https://user-images.githubusercontent.com/66513003/117995638-724e9000-b37c-11eb-8a1e-907dcd8fb432.png
" width="200">

- `𝑮 = (𝑽, 𝑬) , 𝑯 = (𝑽′, 𝑬′)`가 그래프
    1.  `𝑽′ ⊆ 𝑽, 𝑬′ ⊆ 𝑬`  
        ⇒ 𝑯를 𝑮의 `부분 그래프(subgraph)`
    2. `𝑽′= 𝑽, 𝑬′ ⊆ 𝑬`  
        ⇒ 𝑯를 𝑮의 `신장 부분 그래프(spanning subgraph)`  
        꼭지점 개수가 같은 그래프.

    <img src="https://user-images.githubusercontent.com/66513003/117996471-22bc9400-b37d-11eb-89ea-9414429f8414.png
    " width="200">

- 1번 그래프가 `𝑮 = (𝑽, 𝑬), 𝑯 = (𝑽′, 𝑬′)`일 때,
- 2번 : 부분 그래프
    - v 개수가 1번보다 적으므로 `𝑽′ ⊆ 𝑽`
    - e 개수가 적으므로 `𝑬′ ⊆ 𝑬`

- 3번 : 신장 부분 그래프
    - v 개수는 1번과 같음 `𝑽′= 𝑽`
    - e 개수가 적음 `𝑬′ ⊆ 𝑬`

### **# 예제**     
<img src="https://user-images.githubusercontent.com/66513003/118068341-2849c680-b3dd-11eb-9e09-74d9829d282e.png" width="400">

- G - (V, E) 집합으로 구성
- V = {v1, v2, v3}
- E = {e1, e2, e3}
- e1 = (v1, v2)
- e2 = (v2, v3)
- e3 = (v1, v3)

#

- 𝑮 = 𝑽, 𝑬 , 𝒗 ∈ 𝑽
    - 그래프 G가 있을 때, 한 꼭지점(v)에 대한 `차수(degree)` `[deg(v)]`
    v에 인접한 변의 개수
    - G의 `총 차수(total degree) [deg(G)]`  
    G에 속한 모든 꼭지점의 차수의 합  
        ∴ deg 𝑮 = σ𝒗 ∈ 𝑽 𝐝𝐞𝐠 𝒗

- 방향 그래프에서
    - 𝒗 의 `진입차수(in-degree)` : 𝒗 로 들어오는 변의 수
    - 𝒗 의 `진출차수(out-degree)` : 𝒗 에서 나가는 변의 수

### **# 예제**    
<img src="https://user-images.githubusercontent.com/66513003/118069115-888d3800-b3de-11eb-88c6-f6a21caae516.png" width="400">
- G의 총 차수는?
```
    𝒅𝒆𝒈 𝒂 = 𝟑
    𝒅𝒆𝒈 𝒃 = 𝟓
    𝒅𝒆𝒈 𝒄 = 𝟑
    𝒅𝒆𝒈 𝒅 = 𝟑
    ∴ 𝒅𝒆𝒈 𝑮 = 𝟏𝟒
```

### *정리*
<img src="https://user-images.githubusercontent.com/66513003/118069683-8d062080-b3df-11eb-87e9-59ace65ff44e.png" width="400">

#### **그래프에서 차수가 홀수인 꼭지점의 수는 짝수이다.**

<br>

### **# 예제**  

<img src="https://user-images.githubusercontent.com/66513003/118070039-29c8be00-b3e0-11eb-9184-59bea5c4d4cf.png" width="400">

- in-deg(𝒗𝟏) = 4
- in-deg(𝒗𝟐) = 1
- in-deg(𝒗𝟑) = 0
- out-deg(𝒗𝟏) = 1
- out-deg 𝒗𝟐 = 1
- out-deg(𝒗𝟑) = 3

#

## **2. 그래프 탐색**

`𝑮 ( 𝑽, 𝑬 ), 𝒗𝟎, 𝒗𝒌 ∈ 𝑽`

𝒗𝟎에서 𝒗𝒌까지의 `워크(walk)`
- 𝒗𝟎에서 시작하여 𝒗𝒌에 도착하는 꼭지점과 변들을
순서대로 나열한 것.
<img src="https://user-images.githubusercontent.com/66513003/118070543-15d18c00-b3e1-11eb-8384-c2f47e8acb82.png
" width="200">


- W = 𝒗𝟎𝒆𝟏𝒗𝟏𝒆𝟐𝒗𝟐 ⋯ 𝒆𝒌𝒗𝒌
➔ 𝒗𝟎 → 𝒗𝟏 → 𝒗𝟐 → ⋯ → 𝒗𝒌
➔ 𝒆𝟏𝒆𝟐𝒆𝟑 ⋯ 𝒆𝒌

- 𝒗𝟎 : `시작점`, 𝒗𝒌 : `종점`, 𝒗𝟏, 𝒗𝟐 ⋯ 𝒗𝒌−𝟏 : `내부점`

- 𝒌 : W의 `길이(length)`

- 𝒗𝟎 = 𝒗𝒌일 때 W는 `닫혀있다(closed)`
    - 출발점으로 돌아온다.

- 워크 W의 변들이 모두 서로 다르면
W를 `트레일(trail)`
    - 한붓 그리기가 안되면 트레일이 아님.

- `트레일` W의 꼭지점이 모두 다르면
W를 `경로(path)`

### **`path ⊂ trail ⊂ walk`**
- `닫혀있는 Path`는 다음과 같이 부르기도 한다.
    - closed path
    - cycle
    - circuit

### **# 예제**
<img src="https://user-images.githubusercontent.com/66513003/118071056-fbe47900-b3e1-11eb-8c4d-07891c20c5d1.png" width="400">

- 𝒗𝟏에서 𝒗𝟒까지의
    1.  워크 : 𝒆𝟏𝒆𝟐𝒆𝟐𝒆𝟑𝒆𝟒
    1.  트레일 : 𝒆𝟏𝒆𝟐𝒆𝟑𝒆𝟒
    1.  경로 : 𝒆𝟏𝒆𝟑𝒆𝟒

#

`𝑮 = (𝑽, 𝑬), 𝑾 = 𝒗𝟎𝒆𝟏𝒗𝟏𝒆𝟐𝒗𝟐 ⋯ 𝒆𝒌𝒗𝒌 : 워크`

- 𝒗𝟎𝒆𝟏𝒗𝟏𝒆𝟐𝒗𝟐 ⋯ 𝒆𝒌𝒗𝒌는 워크 일 때

- W가 트레일이고 𝒗𝟎 = 𝒗𝒌이면
W는 `닫힌 트레일`
- W가 경로이고 𝒗𝟎 = 𝒗𝒌이면
W는 `닫힌 경로`로서 `사이클(cycle)`
- 길이가 k인 사이클을 `k-사이클`

### **# 예제**

<img src="https://user-images.githubusercontent.com/66513003/118071056-fbe47900-b3e1-11eb-8c4d-07891c20c5d1.png" width="400">

𝒗𝟏에서 𝒗𝟏까지의
1. 닫힌 워크 : 𝒆𝟏𝒆𝟐𝒆𝟐𝒆𝟑𝒆𝟒𝒆𝟓
    - 트레일은 되지 않음
1. 닫힌 트레일 : 𝒆𝟏𝒆𝟐𝒆𝟑𝒆𝟒𝒆𝟓
    - 한번 지난 경로(변)는 다시 지나지 않으므로 트레일
1. 닫힌 경로(사이클) : 𝒆𝟏𝒆𝟑𝒆𝟒𝒆𝟓
    - 한번 지난 꼭지점은 또다시 가지 않음

#

𝑮 = (𝑽, 𝑬) : 그래프, 𝒖, 𝒗 ∈ 𝑽

- 𝒖에서 𝒗로 가는 경로가 존재하면
⇒ 𝒖와 𝒗는 서로 `연결(connected)`되어 있다.
    - 발생
    - 인접 : 한 개의 Edge만 연결되어있음
    - 연결 : 꼭지점 u와 v사이를 여러번 거쳐도 됨. 단, 꼭지점과 Edge는 모두 달라야 함.

- 𝑽의 꼭지점들은 서로 연결되고 다른 집합과 겹치지 않는
꼭지점들의 집합 𝑽𝟏, 𝑽𝟐, ⋯ 𝑽𝒏으로 나눌 수 있음  
    - V1 = {v1, v2, v3}
    - V2 - {v4, v5}
    - 𝑽𝟏, 𝑽𝟐, ⋯ 𝑽𝒏을 𝑮의 `연결성분`이라고 한다.

- ∀𝒖 , ∀𝒗 ∈ 𝑽, 𝒖에서 𝒗로 가는 경로가 존재하면  
    - 𝑮는 `연결 그래프(connected graph)`
    - 𝑮는 오직 `하나의 연결 성분으로 구성`

### **# 예제 1**

<img src="https://user-images.githubusercontent.com/66513003/118073299-8929cc80-b3e6-11eb-98fd-eb8e5946105d.png" width="400">

1. 무작위로 꼭지점 두개를 선택했을 때, `연결` 되어있는지 (그 사이에 path가 존재하는지)
    - 모든 꼭지점이 하나의 연결 성분이므로 `연결 그래프`이다.

2. 세개의 연결 성분으로 나뉜다.
    - 연결 그래프가 아님.

### **# 예제 2**

다음 그래프등 중에서 단순 연결 그래프를 찾으시오.

<img src="https://user-images.githubusercontent.com/66513003/118073579-15d48a80-b3e7-11eb-9d4a-ad16098ce56c.png" width="400">

- `단순 그래프`의 조건
    1. 루프가 없음.
    2. 병렬변이 없음.
    3. 방향이 없음.

1. 연결 그래프. 모든 꼭지점이 하나의 연결 성분으로 되어있음.
그러나 병렬변이 존재. (v1,v3)

2. 연결그래프이지만 병렬변이 존재.

3. `연결그래프 + 단순`

4. 단순이지만 연결이 아님

#

### **완전 그래프**

`𝑮 = 𝑽, 𝑬 : 그래프`

- ∀𝒖, ∀𝒗 ∈ 𝑽, ∃𝒆 = (𝒖, 𝒗) ∈ 𝑬  
⇒ 𝑮는 `완전 그래프(complete graph)`

    - 전체 꼭지점 집합인 V에서 어떤 꼭지점 2개를 꺼내든 Edge(∃𝒆)가 존재할 경우. 

- 𝑲𝒏 ∶ 𝑽 = 𝒏인 완전 그래프

- `완전 그래프`는 임의의 두 꼭지점을 연결하는
변이 `항상 존재`하는 그래프
- `모든 꼭지점이 변으로 직접 연결`되어야함.

### **# 예제**
완전 그래프 𝑲𝟏, 𝑲𝟐, 𝑲𝟑, 𝑲𝟒, 𝑲𝟓, 𝑲𝟔는 다음과 같다.

<img src="https://user-images.githubusercontent.com/66513003/118074301-99db4200-b3e8-11eb-9ffe-9c551305b52a.png" width="400">

- Kn에서 n은 꼭지점의 갯수
    - G = (V, E)일 때, |V| = n
    - |V|는 V의 원소의 개수

1. K1은 꼭지점이 1개, 변이 0개지만 완전그래프
2. K2는 모든 꼭지점이 변으로 이어지므로 완전그래프
3. 완전그래프
4. `모든 꼭지점으로 직접 연결`되므로 완전그래프
5. 위와 같음
6. 위와 같음

- 참고
<img src="https://user-images.githubusercontent.com/66513003/118074352-ab244e80-b3e8-11eb-83f9-22bdc48706b8.png
" width="300">

#

### **이분 그래프**

`𝑮 = 𝑽, 𝑬 : 그래프`

- 𝑽는 연결성분 𝑽𝟏과 𝑽𝟐로 `분할`되어 있고
모든 변들이 𝑽𝟏의 꼭지점과 𝑽𝟐의 꼭지점을
`인접`시키는 경우
    - V1과 V2사이에 Edge가 딱 하나 존재.
    <img src="https://user-images.githubusercontent.com/66513003/118075115-52ee4c00-b3ea-11eb-8da8-d943e9683043.png" width="100">

- 𝑮를 `이분 그래프(bipartite graph)`

<img src="https://user-images.githubusercontent.com/66513003/118074811-b4fa8180-b3e9-11eb-8355-f9df54721625.png" width="400">

### **# 예제**

<img src="https://user-images.githubusercontent.com/66513003/118075418-ede72600-b3ea-11eb-86e4-7269c0de239c.png" width="400">

- 꼭지점 집합 V1과 V2 의 사이에는 각각 변을 하나씩만 잇는다. (인접)
- V1끼리, V2끼리는 연결되지 않는다.
- = `이분 그래프`

#

### **완전 이분 그래프**

`𝑮 = 𝑽, 𝑬 : 이분 그래프 (𝑽𝟏 ۩ 𝑽𝟐 = 𝑽)`

- ∀𝒗𝟏 ∈ 𝑽𝟏, ∀𝒗𝟐 ∈ 𝑽𝟐, ∃𝒆 = (𝒗𝟏, 𝒗𝟐) ∈ 𝑬
    - 𝑮를 `완전(complete) 이분 그래프`
    - ∀𝒗𝟏 : V1에 있는 모든 원소
    - ∀𝒗𝟏, ∀𝒗𝟐중에 아무거나 하나씩 꺼내면 반드시 Edge(∃𝒆)가 있어야 한다.
- 𝑲𝒎,𝒏 ∶ 𝑽𝟏 = 𝒎, 𝑽𝟐 = 𝒏인
완전 이분 그래프

<img src="https://user-images.githubusercontent.com/66513003/118075620-5930f800-b3eb-11eb-8b4d-e50c19cbbde5.png" width="400">
- G가 이분그래프일때, E의 모든 edge(∀e)에 대해서 edge에 속하는 v1은 V1에, v2는 V2에 속해야 한다.

### **# 예제**
<img src="https://user-images.githubusercontent.com/66513003/118076069-54b90f00-b3ec-11eb-980a-4586fb1838d1.png
" width="200">
- 점선이 존재 할경우 모든 V1 요소와 V2요소가 연결되므로 `완전 이분 그래프`가 된다.

#

### **k-정규 그래프**

`𝑮 = 𝑽, 𝑬 : 그래프`

- 𝑮의 모든 꼭지점들이 `동일한 수의 인접한 꼭지점`을 갖는 경우
𝑮를 `정규 그래프(regular graph)`라고 부름.

- 정규 그래프 𝑮는 `모든 꼭지점이 동일한 차수`를 가짐.

- 즉, ∀𝒗 ∈ 𝑽, 𝐝𝐞𝐠 𝒗 = 𝒌

    - 𝑮를 `𝒌-정규 그래프(k-regular graph)`


### **# 예제**
정규그래프

<img src="https://user-images.githubusercontent.com/66513003/118076397-00625f00-b3ed-11eb-8170-57c8cd1473e8.png" width="400">

- 3-정규 그래프는 K4 `(완전 그래프)`

<img src="https://user-images.githubusercontent.com/66513003/118076405-05bfa980-b3ed-11eb-87ca-68643941ccfa.png" width="400">

#

## **그래프의 표현**
1. 발생 행렬
2. 인접 행렬
3. 인접 리스트 (Linked list)

### **발생 행렬(incidenc matrix : Mi)**

`𝑮 = 𝑽, 𝑬 : 그래프`

- 꼭지점을 행으로 변을 열로 하여 변과 꼭지점 사이의
발생관계를 표현한 행렬 ⇒ `발생 행렬` 𝑴𝑰 = (𝒂𝒊𝒋)
    - aij는 i번째 행에 j번째 열의 요소
- |𝑽| × |𝑬| 크기의 부울행렬
- 𝒂𝒊𝒋 = 1 (𝒗𝒊가 𝒆𝒋에 의해 발생되는 경우)
𝒂𝒊𝒋 = 0 (그 밖의 경우)

### **# 예제**
다음 그래프를 발생행렬로 나타내시오.

<img src="https://user-images.githubusercontent.com/66513003/118076949-20dee900-b3ee-11eb-85f8-f0733c632e0b.png" width="400">

- |𝑽| × |𝑬| 크기의 행렬이 된다.

### **인접 행렬(adjacency matrix : Ma)**

`𝑮 = 𝑽, 𝑬 : 그래프`

- 꼭지점을 행과 열로 하여 꼭지점과 꼭지점 사이의
인접관계를 표현한 행렬
    - `인접행렬` 𝑴𝑨 = (𝒂𝒊𝒋)
- |𝑽| × |𝑽| 크기의 행렬
- 𝒂𝒊𝒋 = 𝒗𝒊에서 𝒗𝒋로의 연결 개수

### **# 예제**
방향그래프의 경우

<img src="https://user-images.githubusercontent.com/66513003/118077263-bc705980-b3ee-11eb-82c5-86d4630bcf9b.png" width="400">

### **인접 리스트(adjacency list)**

`𝑮 = 𝑽, 𝑬 : 그래프`

- 각 꼭지점에 인접하는 꼭지점들을
차례로 연결 리스트로 표현한 것

- 인접리스트
<img src="https://user-images.githubusercontent.com/66513003/118077497-21c44a80-b3ef-11eb-9607-0ddfb77f43e6.png" width="400">

- null은 끝
- 순서는 상관 없이, 연결성만 보여주는 리스트
