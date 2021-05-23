# SQL 기본

## **관계형 데이터베이스**

**# SQL 문의 종류**

SQL문은

- DML문 (Data Manipulation Language, 데이터 조작어)
- TCL 문 (Transaction Control Language, 트랜젝션 제어어)
- DDL 문 (Data Definition Language, 데이터 정의어)
- DCL 문 (Data Control Language, 데이터 제어어)  
  으로 구분된다.

| 종류   | 구분                                  | 설명                                                                                                      |
| ------ | ------------------------------------- | --------------------------------------------------------------------------------------------------------- |
| DML 문 | SELECT, INSERT, UPDATE, DELETE, MERGE | 테이블에 저장된 데이터를 조작(조회, 입력, 수정, 삭제)하기 위한 구문                                       |
| TCL 문 | COMMIT, ROLLBACK, SAVEPOINT           | DML문에 의한 데이터의 변경 사항을 데이터베이스에 영구히 반영하거나 취소하기 위해 트랜잭션을 제어하는 구문 |
| DDL 문 | CREATE, ALTER, DROP, RENAME, TRUNCATE | 테이블, 인덱스와 같은 데이터베이스 오브젝트의 구조를 정의(생성, 변경, 삭제)하기 위한 구문                 |
| DCL 문 | GRANT, REVOKE                         | 데이터에 대한 권한을 부여하거나 취소하기 위한 구문                                                        |

#

**# 일반 집합 연산자**

- 8가지 관계형 대수 중 일반 집합 연산자는 관계형 데이터베이스에서 아래의 SQL문법으로 구현되었다.
  - UNION 연산(합집합 연산)은 집합 연산자 중 `UNION/UNION ALL` 연산자로 구현
  - INTERSECTION 연산(교집합 연산)은 집합 연산자 중 `INTERSECT` 연산자로 구현
  - DIFFERENCE 연산(차집합 연산)은 집합 연산자 중 `EXCEPT/MINUS` 연산자로 구현
  - PRODUCT 연산(곱집합 연산)은 조인 문법 중 `CROSS JOIN`으로 구현

#

**관계형 데이터베이스 테이블 구조**

- 테이블은 칼럼과 행의 2차원 구조를 가진 데이터베이스 객체다. 데이터 모델링 단계에서의 엔터티(Entity)는 관계형 데이터베이스에서 테이블(Table)로 구현되며, 속성(Attribute)은 칼럼(Column)으로 구현된다. 또한, 엔터티 간의 관계(Relationship)는 외부키 (Foreign Key)로, 식별자(Identifier)는 기본키(Primay Key)로 구현할 수 있다.

- 테이블은 데이터 모델 상의 엔터티를 관계형 데이터베이스에서 물리적으로 구현한 것이다.
- 행(Row)은 테이블에 저장된 개별 데이터를 의미한다. 데이터 모델 상에 개별 행들을 표시하진 않지만, 개념적으로는 인스턴스(Instance)와 매칭된다.
- 칼럼(Column)은 데이터 모델 상의 속성(Attribute)와 매칭된다.

#

**# DISTINCT**

- SELECT DISTINCT val1 FROM Table01;
- DISTINCT는 SELECT시 해당 컬럼의 중복값을 제외한 결과를 출력한다.
- 만약 val1이 Primary key거나 unique 속성을 가지고 있다면 중복값이 존재할수 없으므로 DISTINCT를 쓸 필요가 없다.

#

**테이블 별칭 지정**

- 테이블에 별칭을 지정할 경우 테이블명 대신 별칭을 지정해야 한다.

```sql
1.
SELECT T1.* FROM T1;

2.
SELECT A.* FROM T1 A;

3.
SELECT T1.C1 FROM T1 A; -- 에러

4.
SELECT C1 FROM T1 A;
```

3. 테이블에 별칭 A를 지정했기 때문에, SELECT 절에서 애스터리스크를 한정할 때 별칭 A를 사용해야 한다. 그러나 테이블명을 사용했으므로 `에러`.

4. 단일 테이블 조회의 경우 테이블명 또는 별칭으로 칼럼을 한정하지 않아도 에러가 발생하지 않는다.

#

**NULL이 포함된 컬럼 계산**

- (100 / 100) \* (NULL / 100) = NULL
- (NULL / 100) \* (200 / 100) = NULL
- (300 / 100) \* (400 / 100) = 12

- NULL을 포함한 칼럼에 대해 산술 연산시에는 NVL함수나 CASE 표현식, DECODE 함수 등을 통해 NULL을 특정 값 (ex. NVL(C1, 0))으로 치환 후 연산해야 한다.

#

**# ||**

```sql
select ENAME || JOB from EMP;
```

- ENAME 컬럼 결과와 JOB 컬럼 결과가 합쳐져 출력

```sql
KINGPRESIDENT
JONESMANAGER
BLAKEMANAGER
CLARKMANAGER
SCOTTANALYST
FORDANALYST
...
```

#

## **함수**

- SUBSTR(C1, 2, 4)

  - C1 컬럼의 값에서 2번째 문자부터 4개의 문자만 출력
  - (0, 1, 2, ..)가 아닌 (1, 2, 3, ...) 순서로 센다.
  - C1이 ABCDEF라면 `SUBSTR(C1, 2, 4)`의 결과는 `BCDE`

- LTRIM(C2, '0')

  - C2 컬럼의 값의 맨 왼쪽부터 '0'문자를 제거해나가며 '0'이 아닌 문자가 아닌게 나오면 남은 문자열 반환.
  - C2가 000123이라면 `LTRIM(C2, '0')`의 결과값은 `123`

- FLOOR 소수점 버림
  - FLOOR(14.5) = 14
- CEIL 올림
  - CEIL(14.5) = 15
- TRUNC(x, n) 소수점 n 자리에서 자름
  - TRUNC(15.4, 0) = 15
  - 만약 x가 DATE 형식 일경우 n은 'MM', 'YY'등을 입력해 날짜를 자를 수 있다.
- ROUND 반올림
  - ROUND(15.4) = 15

#

## **DATE**

```sql
-- 정규표현식
SELECT REGEXP_REPLACE('20200616143030', '(.{4})(.{2})(.{2})(.{2})(.{2})(.{2})', '\1-\2-\3 \4:\5:\6') RESULT2
FROM DUAL; -- 2020-06-16 14:30:30

SELECT TO_DATE (20200616143030 , 'yyyy-mm-dd hh24:mi:ss') M_DATE FROM DUAL; -- 현재시간 -1일
SELECT SYSDATE - 1 M_DAY FROM DUAL; -- 현재시간 -1일
SELECT SYSDATE - (1/24) M_TIME FROM DUAL; -- 현재시간 -1시간
SELECT SYSDATE - (1/1440) M_MINUTE FROM DUAL; -- 현재시간 -1분
SELECT SYSDATE - (1/86400) M_SECOND FROM DUAL; -- 현재시간 -1초
```

#

**CASE 표현식**

- IF THEN ELSE 논리
- 여러개의 WHEN 절 조건이 True일 경우. `먼저` 기술한 WHEN 절과 매칭되는 THEN절의 표현식(값)을 반환한다. 조건의 결과가 TRUE인 WHEN절이 없는 경우, ELSE 절의 값을 반환한다.

#

**예**
|C1|C2|
|--|--|
|1|ABC|
|2|NULL|
|3|CBA|

```sql
SELECT CASE
        WHEN C1 = 3 THEN 'A'
        WHEN SUBSTR(C2, 2, 1) = 'B' THEN 'B'
        ELSE 'C'
    END AS R1
FROM T1;
```

- row마다 CASE를 모두 비교해 가장 처음으로 만족하는 WHEN조건의 THEN결과를 반환.

- 첫 번째 행은 두 번째 WHEN 절 조건만 만족하므로, 이와 매칭되는 THEN 절의 'B' 값이 반환된다.
- 두 번째 행은 만족하는 WHEN 절이 없으므로, ELSE 절의 'C'값이 반환된다.
- 세 번째 행은 첫 번째 WHEN 절 조건과 두 번째 WHEN 절 조건을 모두 만족하지만, 우선순위에 따라 첫 번째 WHEN 절과 매칭되는 THEN 절의 'A' 값이 반환된다.

#

**WHERE**

```sql
SELECT EMPNO, ENAME
    FROM EMP
    WHERE SAL IN (1000,3000);   -- SAL이 1000 또는 3000인 값만 출력

SELECT EMPNO, ENAME
    FROM EMP
    WHERE SAL IN ANY (1000,3000);   -- SAL이 1000보다 크거나, 3000보다 큰 값만 출력

SELECT EMPNO, ENAME
    FROM EMP
    WHERE SAL NOT BETWEEN 1000 AND 3000; -- 1000과 3000 사이가 아닌 값

SELECT EMPNO, ENAME
    FROM EMP
    WHERE SAL < 1000    -- 위와 동일
    OR SAL > 3000
```

- IN (a, b, c, ...)

  - 괄호안에 든 값중 하나와 일치하면 TRUE 반환

- WHERE 절에서 값을 비교할 때 NULL이 포함된 연산은 결과에서 제외된다.
- NULL > 0 행 출력 x

#

```sql
drop table T1;
Create table T1 (C1 number, C2 varchar2(2));

insert into T1 values(1, 'A');
insert into T1 values(2, 'B');
insert into T1 values(3, 'C');
insert into T1 values(NULL, NULL);

SELECT * FROM T1
    WHERE (C1 = 1 AND C2 = 'A')
    OR (C1 = 3 AND C2 = 'C');

SELECT * FROM T1
    WHERE (C1, C2) IN ((1,'A'),(3,'C'));
```

- 두 SELECT 절의 결과는 같음.

#

**# DECODE**

- DECODE(컬럼, 조건1, 결과1, 조건2, 결과2, 조건3, 결과3..........)

<img src="https://user-images.githubusercontent.com/66513003/119258709-e0f5de00-bc05-11eb-87c2-74863e0c5805.png" width="400">

```sql
drop table T1;
Create table T1 (C1 number, C2 varchar2(2));

insert into T1 values(1, 'A');
insert into T1 values(2, 'A');
insert into T1 values(4, 'B');
insert into T1 values(4, 'C');
insert into T1 values(NULL, NULL);

select * from T1;

SELECT DECODE(C2, 'A', C1, 'B', 1) AS R1 FROM T1;

```

- 결과
  | | R1
  |--|--|
  |1|1|
  |2|2|
  |3|1|
  |4|NULL|
  |5|NULL|

#

**# GROUP BY**

```sql
SELECT JOB, HIREDATE
FROM EMP
GROUP BY JOB;

 -- 결과 : [42000][979] ORA-00979: GROUP BY 표현식이 아닙니다.
 -- HIREDATE는 Group by 에 입력되지 않은 컬럼.
```

```sql
SELECT DEPTNO, JOB
    FROM EMP
    GROUP BY DEPTNO, JOB;
-- 출력할 컬럼 둘다 group by에 들어가면 출력 가능.
```

- COUNT나 MIN 같은 그룹 함수도 사용이 가능하다.

#

**# ORDER BY**

- ASC 오름차순 정렬
- DESC 내림차순 정렬

```sql
drop table T1;
Create table T1 (C1 number, C2 varchar2(2), C3 number);

insert into T1 values(1, 'A', 1000);
insert into T1 values(2, 'A', 2000);
insert into T1 values(3, 'A', 2000);
insert into T1 values(4, 'B', 3000);
insert into T1 values(NULL, NULL, NULL);

select * from T1;

SELECT C1, C2, C3
    FROM T1
    ORDER BY 2 DESC, 3, 1 Desc;

```

- 결과
  ||C1|C2|C3|
  |--|--|--|--|
  |1|NULL|NULL|NULL|
  |2|4|B|3000|
  |3|1|A|1000|
  |4|3|A|2000|
  |5|2|A|2000|

#

**# Self Join**

```sql
DROP TABLE O1;
CREATE TABLE O1 (주문번호 NUMBER, 고객번호 NUMBER, 주문일자 DATE, 주문금액 NUMBER);

INSERT INTO O1 VALUES (501, 1, '20190501', 20000);
INSERT INTO O1 VALUES (612, 1, '20190523', 5000);
INSERT INTO O1 VALUES (728, 1, '20200311', 25000);
INSERT INTO O1 VALUES (904, 1, '20200715', 10000);
INSERT INTO O1 VALUES (404, 2, '20191208', 7000);
INSERT INTO O1 VALUES (603, 2, '20200428', 6000);
INSERT INTO O1 VALUES (807, 2, '20200527', 17000);

SELECT MIN(주문합계금액) AS 최저주문합계금액
    FROM (SELECT A.고객번호, A.주문일자, SUM(B.주문금액) AS 주문합계금액
        FROM O1 A, O1 B
        WHERE B.고객번호 = A.고객번호
        AND B.주문일자 <= A.주문일자
        GROUP BY A.고객번호, A.주문일자); -- 7000

SELECT A.고객번호, TO_CHAR(A.주문일자 , 'yyyymmdd') as 주문일자, MIN(A.주문금액) AS 주문금액, SUM(B.주문금액) AS 주문합계금액
    FROM O1 A, O1 B
    WHERE B.고객번호 = A.고객번호 -- 고객번호가 같은 행 중에서
    AND B.주문일자 <= A.주문일자  -- 행이 내려갈 때마다 더 나중의 주문일자가 포함됨.
    GROUP BY A.고객번호, A.주문일자
    ORDER BY A.고객번호, A.주문일자;

```

- 첫번째 SELECT 출력 결과
    - 7000

- 두번째 SELECT 출력 결과
  | |고객번호|주문일자|주문금액|주문합계금액|
  |--|:--:|:--:|:--:|:--:|
  |1|1|20190501|20000|20000|
  |2|1|20190523|5000|25000|
  |3|1|20200311|25000|50000|
  |4|1|20200715|10000|60000|
  |5|2|20191208|7000|7000|
  |6|2|20200428|6000|13000|
  |7|2|20200527|17000|30000|

#

**# OUTER JOIN**

- OUTER JOIN에서 아우터 집합은 조인 성공 여부에 상관 없이 무조건 결과 집합에 포함되며, 컬럼 값도 정상적으로 반환한다.
- 반대쪽 이너 집합은 조인에 성공한 데이터만 결과 집합에 포함(컬럼 값도 정상적으로 반환)되며, 조인에 실패한 이너 쪽 컬럼 값은 NULL을 반환한다.
- 조건절에 (+) 기호가 붙은 쪽이 이너 집합, (+) 기호가 붙지 않는 쪽이 아우터 집합이다.

#


