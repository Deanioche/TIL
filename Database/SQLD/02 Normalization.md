# SQLD - 정규화

**01**

<img src="https://user-images.githubusercontent.com/66513003/119106881-b36c3180-ba59-11eb-860d-acbc4a40d86b.png
" width="400">

- 사원 엔터티는 1정규화 대상이다.
- 사원 엔터티의 전화번호목록 속성은 여러개의 값을 포함한 다가속성(Multivalued Attrivute)이다. 다가속성을 포함한 엔터티는 비정규형이며, 1정규화를 수행해야 하는 대상이다.

#

**# 정규형**

|정규형|설명|
|--|:--|
|1정규형(1NF)| 속성의 원자성(atomicity)와 관련이 있다. '010-4567-8979, 010-2541-3652' 들의 다중 값(multiple value), 전화번호1, 전화번호2와 같은 반복 그룹(repeating group)이 이에 해당한다.|
|2정규형(NF2)| 부분 종속과 관련이 있다. 부분 종속(partial dependency)은 일반 속성이 식별자의 일부 속성에만 종속되는 것이다. |
|3정규형(NF3)| 이행 종속과 관련이 있다. 이행 종속(transitive dependency)은 일반 속성이 다른 일반 속성에 종속되는 것이다.|

#

**02**

<img src="https://user-images.githubusercontent.com/66513003/119109679-5756dc80-ba5c-11eb-9fec-bbe639916478.png
" width="150">

- 사원 엔터티는 1정규화 대상임.
- 사원 엔터티는 유사한 속성을 나열한 반복속성을 포함하고 있다. 전화번호1, 전화번호2, 속성을 단일 값을 갖는 속성이지만 유사 속성을 반복하여 사용하는 것은 넓은 의미의 다가속성(Multivalued Attribute)으로 볼 수 있다. 반복 속성을 포함한 사원 엔터티는 아래와 같이 전화번호1, 전화번호2 속성을 별도 엔터티로 분리하여 1정규화를 수행할 수 있다.

<img src="https://user-images.githubusercontent.com/66513003/119110649-5a9e9800-ba5d-11eb-8a14-884769b1a4ec.png
" width="400">

#

**# 관계와 조인의 이해**

**03 다음 데이터 모델에서 모든 사원의 사번, 이름, 부서명을 출력하는 쿼리**

<img src="https://user-images.githubusercontent.com/66513003/119111437-0647e800-ba5e-11eb-8b03-f7ab60f37b30.png
" width="400">

```sql
SELECT A. 사번, A. 이름, B. 부서명
FROM 사원 A, 부서 B
WHERE B. 부서번호 = A. 부서번호;
```

- 부서울 기준으로 사원은 선택 관계(사원 쪽 관계선에 O 표시)이므로 사원 없는 부서가 존재할 수 있다. 사원을 기준으로 부서는 필수 관계(부서 쪽 관계선에 O 표시가 없음)이므로 부서 없는 사원은 존재할 수 없다. 즉, 사원의 부서번호 속성은 NOT NULL이다.

- 부서 없는 사원은 존재하지 않으므로 
```sql
WHERE B. 부서번호(+) = A. 부서번호;
```
은 불필요한 아우터 조인이다. 아우터 조인을 하든 안하든 결과는 같다. 사원의 부서번호는 NOT NULL이므로

```sql 
AND A. 부서번호 IS NOT NULL
```
위 조건도 불필요하다.
```sql
WHERE B. 부서번호 = A. 부서번호(+);
```
은 사원 없는 부서 정보까지 출력하므로 문제에서 요구하는 결과 집합과 다르다.

#

**04 다음 데이터 모델에서 `모든` 사원의 사번, 이름, 부서명을 출력하는 쿼리**

<img src="https://user-images.githubusercontent.com/66513003/119113632-40b28480-ba60-11eb-8fd6-8d456d345829.png
" width="400">

```sql
1.
SELECT A. 사번, A. 이름, B. 부서명
FROM 사원 A, 부서 B
WHERE B. 부서번호(+) = A. 부서번호;

2.
SELECT A. 사번, A. 이름, B. 부서명
FROM 사원 A LEFT OUTER JOIN 부서 B
WHERE B. 부서번호 = A. 부서번호;

3.
SELECT A. 사번, A. 이름,
    (SELECT X. 부서명 FROM 부서 X WHERE X.부서)
FROM 사원 A, 부서 B
WHERE B. 부서번호 = A. 부서번호;
```

- 부서를 기준으로 사원은 필수 관계(사원 쪽 관계선에 O표시 가 없음)이므로 사원 없는 부서는 존재할 수 없다. 사원을 기준으로 부서는 선택 관계 (부서 쪽 관계선에 O표시)이므로 부서 없는 사원이 존재할 수 있다. 즉, 사원의 부서번호는 NULL 허용 속성이다.

- 사원과 부서를 다음과 같이 단순히 조인하면 부서 없는 사원이 결과 집합에서 누락된다. 
```sql
SELECT A. 사번, A. 이름, B. 부서명
FROM 사원 A, 부서 B
WHERE B. 부서번호 = A. 부서번호;
```
- 모든 사원을 결과 집합에 포함하려면 1,2번 쿼리와 같이 아우터 조인(OUTER JOIN)하거나 3번과 같이 부서명을 스칼라 서브쿼리(Scalar Subquery)로 조회해야 한다.

