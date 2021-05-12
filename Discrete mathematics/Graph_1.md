# 그래프 1

## **1. 기본사항**
- 그래프소개
- 주요용어
- 그래프 탐색

#

## **주요 용어**

<img src="https://user-images.githubusercontent.com/66513003/117992595-066b2800-b37a-11eb-9800-49d196e8c28d.png
" width="100">

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

- 예제 1
<img src="https://user-images.githubusercontent.com/66513003/117994070-3961eb80-b37b-11eb-9e97-0bf153f153a0.png
" width="250">

- 예제 2
<img src="https://user-images.githubusercontent.com/66513003/117994387-75954c00-b37b-11eb-913f-7e347d05771d.png
" width="400">
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
" width="400">

- `𝑮 = (𝑽, 𝑬) , 𝑯 = (𝑽′, 𝑬′)`가 그래프
    1.  `𝑽′ ⊆ 𝑽, 𝑬′ ⊆ 𝑬`  
        ⇒ 𝑯를 𝑮의 `부분 그래프(subgraph)`
    2. `𝑽′= 𝑽, 𝑬′ ⊆ 𝑬`  
        ⇒ 𝑯를 𝑮의 `신장 부분 그래프(spanning subgraph)`  
        꼭지점 개수가 같은 그래프.

<img src="https://user-images.githubusercontent.com/66513003/117996471-22bc9400-b37d-11eb-89ea-9414429f8414.png
" width="400">

- 1번 그래프가 `𝑮 = (𝑽, 𝑬), 𝑯 = (𝑽′, 𝑬′)`일 때,
- 2번 : 부분 그래프
    - v 개수가 1번보다 적으므로 `𝑽′ ⊆ 𝑽`
    - e 개수가 적으므로 `𝑬′ ⊆ 𝑬`

- 3번 : 신장 부분 그래프
    - v 개수는 1번과 같음 `𝑽′= 𝑽`
    - e 개수가 적음 `𝑬′ ⊆ 𝑬`