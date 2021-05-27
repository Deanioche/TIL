# Memo

### **`# 함수 사용법 검색하기`**
- RANK(), ROW_NUMBER(), DENSE_RANK(), LEAD(), LAG(), NTITLE()


**# DECODE 함수 써보기**
https://gent.tistory.com/227

___

**# OUTER JOIN 표시**
```sql
a.id = b.id (+) -- LEFT OUTER

A.id(+) = b.id  -- RIGHT OUTER
```

https://blog.edit.kr/entry/Oracle-%EC%BF%BC%EB%A6%AC%EC%A4%91%EC%97%90-%EC%9D%98-%EC%9D%98%EB%AF%B8

___

**# USING 절 에러**
```SQL
SELECT A.C1, B.C2
    FROM T1 A JOIN T2 B
    USING (C1);
    -- # 에러 ORA-25154: USING 절의 열 부분은 식별자(A.)를 가질 수 없음
```

___

## - **`NATURAL 조인에 사용된 열은 식별자를 가질 수 없음`**

- NATURAL JOIN에 사용된 열은 식별자(A. B.)을 가질 수 없음!!

```sql

select A.C1, B.C1
from T1 A NATURAL JOIN T2 B;
    -- # 에러 ORA-25155: NATURAL 조인에 사용된 열은 식별자를 가질 수 없음
```

- 테이블 A와 B에 각각 C1과 C2 컬럼이 있지만, natural join은 그 모든 컬럼을 비교해 합치므로 결과는 C1, C2 컬럼 `하나씩만` 출력된다.
- 그러므로 컬럼은 `식별자를 가질 수 없다`.

___

**# 조건 우선순위**
|우선순위|조건|
|--|--|
|1|연산자|
|2|비교조건 (=, <>, >, <, >=, <=)|
|3|IN 조건, LIKE 조건, BETWEEN 조건, NULL 조건|
|4|논리조건(NOT)|
|5|`논리조건(AND)`|
|6|논리조건(OR)|

___

## `# AVG(C1 + C2)`
- 우선 행별로 C1 + C2 연산이 이루어 진다.
- 여기서 어느 한쪽이 NULL이면 결과값은 NULL.
- AVG(모든 결과값)을 하면 결과값이 NULL인 행은 연산에서 제외되므로
- NULL이 아닌 행들의 평균값이 나온다. (NULL행은 평균값 계산의 나눗셈에서도 제외된다.)

___

**# 15**

- 스칼라 서브쿼리의 결과 건이 0건이더라도 메인 집합의 건수에는 영향을 미치지 않는다. 즉, 주문 테이블에 해당 고객의 주문 건이 없더라도 고객 테이블에서 고객번호 IN(3, 4)조건을 만족하는 모든 고객에 대해 고객번호와 주문합계금액이 출력된다. 단, 주문 테이블에 해당 고객의 주문 건이 없으면 스칼라 서브쿼리는 null을 반환한다. 

```sql
-- 15번 문제 p96
drop table 고객;
create table 고객 (고객번호 number, 고객명 varchar2(20));

insert into 고객 values (1, '김대원');
insert into 고객 values (2, '노영미');
insert into 고객 values (3, '김경진');
insert into 고객 values (4, '박하연');

drop table 주문;
create table 주문 (주문번호 number, 고객번호 number, 주문금액 number);

insert into 주문 values (2001, 1, 40000);
insert into 주문 values (2002, 2, 15000);
insert into 주문 values (2003, 2, 7000);
insert into 주문 values (2004, 2, 8000);
insert into 주문 values (2005, 2, 20000);
insert into 주문 values (2006, 3, 5000);
insert into 주문 values (2007, 3, 9000);

SELECT a.고객번호,
       (select sum(x.주문금액)
        from 주문 x
           where x.고객번호 = a.고객번호) as 합계
from 고객 a
where a."고객번호" in (3,4); -- outer join

```
- 두 SELECT의 결과
  ||고객번호|합계|
  |--|:--:|:--:|
  |1|3|14000|
  |2|4|NULL|

- SELECT 문 (스칼라 서브쿼리)
  - where 절의 조건이 가장 높은 우선순위로 들어가므로, 
    a.고객번호가 3, 4가 아닌 행은 바로 제외된다. 
  - 따라서, `b."고객번호" = a."고객번호"`로 join된 결과도 3,4만 계산이 된다.
  - 주문 테이블에는 3만 존재하므로 일단 첫번째 행은 `3, 14000`이 출력된다.
  - 그 다음으로 a.고객번호가 4의 주문금액을 주문 테이블에서 찾는데, 주문 테이블에는 고객번호가 4인 행이 존재하지 않는다.
  - 하지만 스칼라 서브쿼리는 `where a."고객번호" in (3,4)`로 잡힌 조건절의 결과의 갯수에 영향을 미치지 않으므로 주문합계금액이 존재여부에 상관없이 고객번호가 3, 4인 행이 모두 출력된다.
  - 즉, 두번째 행은 `4, NULL`.

  - 오른쪽 테이블의 해당하는 컬럼의 행에 NULL 유무에 상관없이 조건에 맞는 왼쪽 테이블의 컬럼(고객번호)이 모두 출력 결과에 포함되고,  
  그 다음 순위로 오른쪽 테이블의 컬럼이 추가되는 방식의 JOIN은 `LEFT OUTER JOIN`이다.

  - 그리고 SUM함수를 계산하려면 b.주문금액 컬럼의 행 각각의 값을 출력할 수 있는 그룹이 필요하며, `select a.고객번호, sum(b.주문금액)`으로 출력할수 있는 방법은 a.고객번호를 group by로 묶는 방법밖에 없다.

즉, 위 SELECT 문과 동일한 쿼리는
```sql
select a.고객번호, sum(b.주문금액) as 합계
    from 고객 a left outer join 주문 b
    on b."고객번호" = a."고객번호"
where a."고객번호" in (3, 4)
group by a.고객번호;
```
가 된다.

___

**# 서브 쿼리에서 식별자를 쓴 컬럼과 안쓴 컬럼 비교**
- 서브쿼리에서 `X.C1 = C1`는 `X.C1 = X.C1`과 동일하다. (P109 2.)

___

**# SELECT 행의 처리 순서**

FROM -> WHERE -> GROUP BY -> HAVING -> SELECT -> ORDER BY


___

**# [SQL Server] TOP**

- TOP ()
    - 괄호 안에는 반환할 행의 개수나 백분율 입력.
    - 뒤에 PERCENT를 붙이면 백분율만큼 행을 반환.
    - 뒤에 WITH TIES : 마지막 행에 대한 동순위를 포함해서 반환.

- TOP () WITH TIES는 RANK 분석 함수와 같은 역할을 한다.
    - 동 순위를 포함해서 출력.

- `SQL Server`에서만 사용 가능한 함수

___

**# <> 연산자**

- `'컬럼명 <> 컬럼 값'`으로 기술하며, 해당 컬럼에 해당 컬럼 값이 나오는 결과는 제외한다.

#

```SQL
SELECT EMPNO, ENAME, MGR , JOB
FROM EMP
START WITH ENAME = 'JONES'
CONNECT BY MGR = PRIOR EMPNO
AND JOB <> 'CLERK';
```

| EMPNO | ENAME | MGR | JOB |
| :--- | :--- | :--- | :--- |
| 7566 | JONES | 7839 | MANAGER |
| 7788 | SCOTT | 7566 | ANALYST |
| 7902 | FORD | 7566 | ANALYST |
- JOB = 'CLERK'인 행을 제외 후 출력.
- PRIOR는 직전 상위 노드의 값을 반환하는데 `7902 FORD 7566 ANALYST`는 왜 출력됐지?

___

**# CTE(Common Table Expression)**
- CTE의 WITH절은 UNION ALL 연산자로 구성된다.  
- UNION ALL의 상단 쿼리가 START WITH 절, 하단 쿼리가 CONNECT BY절의 역할을 수행한다.
- UNION ALL 상단에서 얻은 쿼리집합을 시작으로 하단 쿼리에서 WITH절을 재귀적으로 조인함으로써 START WITH, CONNECT BY 절과 같은 계층 구조를 얻을 수 있다.

```SQL
WITH W1 (EMPNO, ENAME, MGR, LV) AS (
    SELECT EMPNO, ENAME, MGR, 1 AS LV
    FROM EMP
    WHERE ENAME = 'JONES'
    UNION ALL
    SELECT C.EMPNO, C.ENAME, C.MGR, P.LV + 1
    FROM W1 P, EMP C
    WHERE C.MGR = P.EMPNO)
SELECT EMPNO, ENAME, MGR, LV
FROM W1;
```

___

**# PIVOT**
- PIVOT은 행을 열로 전환한다.

- PIVOT()의 괄호 안에는 집계할 열을 지정
- FOR 절은 PIVOT할 `열`을 지정
- IN 절은 PIVOT할 `열 값`을 지정

```SQL
SELECT *
    FROM (SELECT JOB, DEPTNO, SAL FROM EMP WHERE DEPTNO IN (10,20))
        PIVOT (SUM(SAL) FOR DEPTNO IN (10, 20))
ORDER BY JOB;
```
| JOB | 10 | 20 |
| :--- | :--- | :--- |
| ANALYST | NULL | 6000 |
| CLERK | 1300 | 1900 |
| MANAGER | 2450 | 2975 |
| PRESIDENT | 5000 | NULL |

____


**# 역참조**
- 역참조를 사용하면 일치함 서브 표현식을 다시 참조할 수 있다. 반복되는 패턴을 검색하거나 서브 표현식의 위치를 변경하는 용도로 사용할 수 있다.

- \n : n번째 서브 표현식과 일치, n은 1에서 9사이의 정수

___

# 
- DML - DATA-MANIPULATION LANG 
    - SELECT, UPDATE, DELETE, INSERT, MERGE
- DDL - DATA-DEFINITION LANG
    - CREATE ALTER DROP TRUNCATE RENAME
- TCL - TRANSACTION CONTROL LANG
    - COMMIT ROLLBACK SAVEPOINT
- DCL - DATA CONTROL LANG
    - GRANT REVOKE

___ 

**# 트랜잭션의 특성**

| 특징 | 설명 |
|---|:---:|
|원자성|트랜잭션의 작업은 모두 수행되거나 모두 수행되지 않아야 함|
|일관성|트랜잭션이 완료되면 데이터 무결성이 일관되게 보장되어야 함|
|고립성|트랜잭션이 다른 트랜잭션으로부터 고립된 상태로 수행되어야 함|
|지속성|트랜잭션이 완료되면 장애가 발생하더라도 변경 내용이 지속되어야 함|

____

**# 정규형**

1. 제 1 정규형
    - 모든 속성은 반드시 하나의 값을 가져야 한다.
    - M:N 관계를 M:1관계로 전환

2. 제 2 정규형
    - 모든 속성은 반드시 `기본키` 전부에 종속되어야 한다.
    - 함수의 부분 종속을 분리
        (기본키에 의해 함수적 종속성을 가지고 있지 않는 것들을 분리)
    
3. 제 3 정규형
    - 기본키가 아닌 모든 속성 간에는 서로 종속될 수 없다.
    - 모든 속성들이 기본키에 이행적 함수 종속이 아님.

___

**# P198 19번**
```SQL
DROP TABLE T1;
CREATE TABLE T1(C1 NUMBER, C2 VARCHAR2(10));

INSERT INTO T1 VALUES (1, 'ZA');
INSERT INTO T1 VALUES (2, 'BZZ');
INSERT INTO T1 VALUES (3, 'CZZ');
INSERT INTO T1 VALUES (4, 'DZZZ');
INSERT INTO T1 VALUES (5, 'ZZZE');

SELECT C1, RTRIM(C2, 'Z'), C2 FROM T1 ORDER BY CASE
    WHEN C1 <= 2 THEN 'B' -- B 1, 2
    WHEN C1 > 4 THEN 'A' -- 5 A
    ELSE 'C' -- 3,4
        END ; -- CASE로 순서랭크 지정이 가능!!
```