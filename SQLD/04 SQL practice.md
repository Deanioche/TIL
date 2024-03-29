# SQL practice

**# RANK**
```SQL
RANK() over (ORDER BY SAL DESC)
```
- ORDER BY로 랭크를 정할 기준을 정한다.
- 같은 랭크가 `여러 행` 나올 수도 있으므로, 랭크별 한 행씩만 출력해야한다면 주의.

```SQL
SELECT SAL, RANK() over (ORDER BY SAL DESC) AS RK
FROM EMP
WHERE SAL < 1300;
```

- 결과
    | |SAL|RK|
    |--|--|--|
    |1|1250.00|1|
    |2|1250.00|1|
    |3|1100.00|3|
    |4|950.00|4|
    |5|800.00|5|

#

```SQL
SELECT *
FROM EMP
    WHERE SAL > (SELECT SAL FROM
    (SELECT SAL, RANK() over (ORDER BY SAL DESC) AS RK
    FROM EMP
    WHERE SAL < 1300)
WHERE RK = 1);
    -- ORA-01427: 단일 행 하위 질의에 2개 이상의 행이 리턴되었습니다.
```
- RANK 분석 함수는 동일 순위를 허용하므로 서브 쿼리에서 `다중 행`이 반환될 수 있다. 이로 인해 위 주석과 같은 에러가 발생한다.

#
- 값이 같으면 동일한 순위를 부여하고 그 다음 순위는 건너뛴다. 
- 공동1등일 경우(1, 1, 3, 4, ...)
```SQL
SELECT EMPNO, ENAME, TRUNC(SAL, 0) AS SAL, RANK() OVER (ORDER BY SAL) AS C1
FROM EMP
WHERE DEPTNO = 30;
```
- 결과
    | EMPNO | ENAME | SAL | C1 |
    | :--- | :--- | :--- | :--- |
    | 7900 | JAMES | 950 | 1 |
    | 7521 | WARD | 1250 | 2 |
    | 7654 | MARTIN | 1250 | 2 |
    | 7844 | TURNER | 1500 | 4 |
    | 7499 | ALLEN | 1600 | 5 |
    | 7698 | BLAKE | 2850 | 6 |

___

**# DENSE_RANK**
```SQL
SELECT EMPNO, ENAME, TRUNC(SAL, 0) AS SAL, DENSE_RANK() OVER (ORDER BY SAL) AS C1
FROM EMP
WHERE DEPTNO = 30;
```

- 결과
    | EMPNO | ENAME | SAL | C1 |
    | :--- | :--- | :--- | :--- |
    | 7900 | JAMES | 950 | 1 |
    | 7521 | WARD | 1250 | 2 |
    | 7654 | MARTIN | 1250 | 2 |
    | 7844 | TURNER | 1500 | 3 |
    | 7499 | ALLEN | 1600 | 4 |
    | 7698 | BLAKE | 2850 | 5 |


___

**# PERCENT_RANK()**
```SQL
SELECT EMPNO, ENAME, TRUNC(SAL, 0) AS SAL, PERCENT_RANK() OVER (ORDER BY SAL) AS C1
FROM EMP
WHERE DEPTNO = 30;
```

- 결과
    | EMPNO | ENAME | SAL | C1 |
    | :--- | :--- | :--- | :--- |
    | 7900 | JAMES | 950 | 0 |
    | 7521 | WARD | 1250 | 0.2 |
    | 7654 | MARTIN | 1250 | 0.2 |
    | 7844 | TURNER | 1500 | 0.6 |
    | 7499 | ALLEN | 1600 | 0.8 |
    | 7698 | BLAKE | 2850 | 1 |

___

**# ROW_NUMBER()**
```SQL
SELECT EMPNO, ENAME, TRUNC(SAL, 0) AS SAL, ROW_NUMBER() OVER (ORDER BY SAL) AS C1
FROM EMP
WHERE DEPTNO = 30;
```

- 결과
    | EMPNO | ENAME | SAL | C1 |
    | :--- | :--- | :--- | :--- |
    | 7900 | JAMES | 950 | 1 |
    | 7521 | WARD | 1250 | 2 |
    | 7654 | MARTIN | 1250 | 3 |
    | 7844 | TURNER | 1500 | 4 |
    | 7499 | ALLEN | 1600 | 5 |
    | 7698 | BLAKE | 2850 | 6 |

___

**# EXISTS** 
    - EXISTS(서브 쿼리)는 서브 쿼리의 결과가 "한 건이라도 존재하면" TRUE 없으면 FALSE를 리턴한다.

```sql
drop table T1;
CREATE TABLE T1 (C1 NUMBER);

INSERT INTO T1 VALUES (1);
INSERT INTO T1 VALUES (2);
INSERT INTO T1 VALUES (3);

DROP TABLE T2;
CREATE TABLE T2 (C1 NUMBER);

INSERT INTO T2 VALUES (1);
INSERT INTO T2 VALUES (2);

SELECT COUNT(*) FROM T1 A WHERE EXISTS(SELECT 1 FROM T2 X WHERE X.C1 = C1); -- 3
SELECT COUNT(*) FROM T1 A WHERE EXISTS(SELECT 1 FROM T2 X WHERE X.C1 = X.C1); -- 3
SELECT COUNT(*) FROM T1 A WHERE EXISTS(SELECT 1 FROM T2 X WHERE X.C1 = A.C1); -- 2
```

- 서브쿼리에서 `X.C1 = C1`는 `X.C1 = X.C1`과 동일하다.

___

**# 분석함수**

```SQL
SELECT
    분석함수 OVER([PARTITION BY 칼럼] [ORDER BY 칼럼] [WINDOWING 절])
FROM 테이블;
```

```SQL
SELECT
    DEPTNO
     ,EMPNO
     ,ENAME
     ,(SELECT DNAME FROM DEPT WHERE EMP.DEPTNO = DEPT.DEPTNO) || ' : ' || COUNT(ENAME) over ( PARTITION BY DEPTNO)  || '명' AS R1
     ,TRUNC(AVG(SAL)OVER(PARTITION BY DEPTNO),2)
     ,SUM(SAL) OVER(PARTITION BY DEPTNO ORDER BY SAL DESC) AS SUM_SAL
FROM EMP;
```
-PARTITION BY 는 GROUP BY와 비슷한 역할

___

**# RPAD(), LPAD()**

```sql
select LPAD(RPAD(SUBSTR('12345',-3, 2), 3, '#'), 5, '*')as R1 from DUAL; -- **34#
```

___

**# 스칼라 서브쿼리 인라인 뷰**

```SQL
SELECT  A.DEPTNO, A.DNAME
    , (SELECT MAX(X.SAL) FROM EMP X WHERE X.DEPTNO = A.DEPTNO) AS MAX_SAL
    , (SELECT MAX (X.COMM) FROM EMP X WHERE X.DEPTNO = A.DEPTNO) AS MAX_COMM
FROM DEPT A
ORDER BY 1;

SELECT A.DEPTNO, A.DNAME, B.MAX_SAL, B.MAX_COMM
    FROM DEPT A
    , (SELECT DEPTNO, MAX(SAL) AS MAX_SAL, MAX(COMM) AS MAX_COMM
        FROM EMP
        GROUP BY DEPTNO) B
    WHERE A.DEPTNO = B.DEPTNO(+)
    ORDER BY 1;
```

- 1번 SQL은 SQL과 COMM의 부서별 최대 값을 계산하기 위해 스칼라 서브 쿼리로 EMP테이블을 2번 조화했다.
- 2번 쿼리는 EMP 테이블의 조회 횟수를 줄이기 위해 1번 쿼리의 스칼라 서브 쿼리를 인라인 뷰로 변경했다. 이런 경우 메인 쿼리를 기분으로 인라인 뷰를 `아우터 조인`해야 동일한 결과를 보장할 수 있다.
- 다만, DEPT에 입력된 모든 DEPTNO가 EMP 테이블과 조인할 때 적어도 한 건 이상 성공하는 `필수(MANDATORY) 관계`라면, 스칼라 서브 쿼리를 인라인 뷰로 전환하면서 이너 조인을 사용해도 된다. (선택관계 -> `모두 NULL일 가능성도 있음`)

- 동일 쿼리를 만드는 문제에서는 NULL값이 들어가도 되는지 안되는지를 꼭 확인할것.
- 1번 SQL에서 스칼라 서브쿼리는 SELECT A.DEPTNO, A.DNAME의 결과의 개수에 영향을 미치지 못하므로, A.DEPTNO, A.DNAME의 결과는 일단 `모두` 출력된다. 즉, `스칼라 서브쿼리로 출력되는 컬럼의 결과로 NULL이 1개 이상 존재할 수도 있다는 의미`이다.
- 이는 A.DEPTNO, A.DNAME을 포함하는 테이블 A(별칭)은 `아우터 조인`을 한다는 뜻이 된다.
- 따라서, 아우터조인이 아닌 쪽이 (+) 기호를 받으므로 `A.DEPTNO = B.DEPTNO(+)`가 된다.


___

**# 집합 연산자**
- UNION ALL
    - 두 집합의 합집합.
- UNION
    - 두 집합의 합집합에서 중복을 제거
- MINUS
    - 차집합 반환
- INTERSECT
    - 교집합 반환

#

```SQL
-- 집합 연산자
DROP TABLE T1;
CREATE TABLE T1(C1 NUMBER);

INSERT INTO T1 VALUES (1);
INSERT INTO T1 VALUES (1);
INSERT INTO T1 VALUES (2);

DROP TABLE T2;
CREATE TABLE T2(C1 NUMBER);

INSERT INTO T2 VALUES (1);
INSERT INTO T2 VALUES (3);

SELECT C1 FROM T1
INTERSECT
SELECT C1 FROM T2; -- 1 중복 값도 제거된다.

SELECT C1 FROM T1
MINUS
SELECT C1 FROM T2; -- 2 중복 값도 제거된다.

SELECT C1 FROM T1
UNION
SELECT C1 FROM T2; -- 1, 2, 3 중복 값도 제거된다.

SELECT C1 FROM T1
UNION ALL
SELECT C1 FROM T2; -- 1, 1, 2, 1, 3
```

- `소트 부하`를 해소하기 위해 MINUS 연산자를 NOT EXIST 서브 쿼리로 변경할 수 있다. MINUS 연산은 차집합을 구할 뿐만 아니라 `중복 값도 제거`하므로 NOT EXISTS를 사용한 2번 쿼리에서도 같은 결과를 업드려면 DISTINCT 키워드를 함께 사용해야 한다.

___

**# ROLL UP**

- ROLLUP은 지정한 표현식의 계층별 소계와 총계를 집계한다. 칼럼을 뒤쪽부터 하나씩 제거하는 방식이다. ROLLUP (C1, C2)는 (C1, C2), C1, ()로 집계된다. 선택지의 그룹 함수는 아래와 같이 동작한다. (C1, C2)는 C1, C2의 소계, ()는 총계를 의미한다. 출력된 결과집합을 보면 (C2, C1), C2, ()로 집계했다.

```SQL
DROP TABLE T1;
CREATE TABLE T1 (C1 VARCHAR(2), C2 DATE, C3 NUMBER);

INSERT INTO T1 VALUES ('A', '20500101', 1);
INSERT INTO T1 VALUES ('A', '20500102', 1);
INSERT INTO T1 VALUES ('B', '20500101', 1);
INSERT INTO T1 VALUES ('B', '20500102', 1);
INSERT INTO T1 VALUES ('C', '20500101', 1);
INSERT INTO T1 VALUES ('C', '20500102', 1);

SELECT C1, C2, SUM(C3)
    FROM T1
    GROUP BY ROLLUP (C2, C1);
```

|/|C1|C2|SUM|
|-|-|:-----------------:|-|
|1|A|2050-01-01 00:00:00|1|
|1|B|2050-01-01 00:00:00|1|
|1|C|2050-01-01 00:00:00|1|
|1| |2050-01-01 00:00:00|3|
|1|A|2050-01-02 00:00:00|1|
|1|B|2050-01-02 00:00:00|1|
|1|C|2050-01-02 00:00:00|1|
|1| |2050-01-02 00:00:00|3|
|1| |                   |6|

```SQL
SELECT C1, C2, SUM(C3)
    FROM T1
    GROUP BY(C2, C1);
```

|/|C1|C2|SUM|
|-|-|:-----------------:|-|
|1|C|2050-01-01 00:00:00|1|
|1|B|2050-01-02 00:00:00|1|
|1|A|2050-01-02 00:00:00|1|
|1|A|2050-01-01 00:00:00|1|
|1|B|2050-01-01 00:00:00|1|
|1|C|2050-01-02 00:00:00|1|

___

**# CUBE**
- CUBE는 지정한 표현식의 모든 조합을 집계한다.

```SQL
SELECT b.dname, a.job, SUM(a.sal) sal, COUNT(a.empno) emp_count
FROM emp a,
     dept b
WHERE a.deptno = b.deptno
GROUP BY CUBE (b.dname, a.job)
ORDER BY 1;
```
- CUBE 결과
    | DNAME | JOB | SAL | EMP\_COUNT |
    | :--- | :--- | :--- | :--- |
    | ACCOUNTING | CLERK | 1300 | 1 |
    | ACCOUNTING | MANAGER | 2450 | 1 |
    | ACCOUNTING | PRESIDENT | 5000 | 1 |
    | ACCOUNTING | `NULL` | `8750` | `3` |
    | RESEARCH | ANALYST | 6000 | 2 |
    | RESEARCH | CLERK | 1900 | 2 |
    | RESEARCH | MANAGER | 2975 | 1 |
    | RESEARCH | `NULL` | `10875` | `5` |
    | SALES | CLERK | 950 | 1 |
    | SALES | MANAGER | 2850 | 1 |
    | SALES | SALESMAN | 5600 | 4 |
    | SALES | `NULL` | `9400` | `6` |
    | NULL | **ANALYST** | 6000 | 2 |
    | NULL | **CLERK** | 4150 | 4 |
    | NULL | **MANAGER** | 8275 | 3 |
    | NULL | **PRESIDENT** | 5000 | 1 |
    | NULL | **SALESMAN** | 5600 | 4 |
    | NULL | `NULL` | `29025` | `14` |

- 부서별 통계, JOB별 통계, 총합이 출력됨

- ROLLUP
    | DNAME | JOB | SAL | EMP\_COUNT |
    | :--- | :--- | :--- | :--- |
    | ACCOUNTING | CLERK | 1300 | 1 |
    | ACCOUNTING | MANAGER | 2450 | 1 |
    | ACCOUNTING | PRESIDENT | 5000 | 1 |
    | ACCOUNTING | `NULL` | `8750` | `3` |
    | RESEARCH | ANALYST | 6000 | 2 |
    | RESEARCH | CLERK | 1900 | 2 |
    | RESEARCH | MANAGER | 2975 | 1 |
    | RESEARCH | `NULL` | `10875` | `5` |
    | SALES | CLERK | 950 | 1 |
    | SALES | MANAGER | 2850 | 1 |
    | SALES | SALESMAN | 5600 | 4 |
    | SALES | `NULL` | `9400` | `6` |
    | NULL | `NULL` | `29025` | `14` |

- 부서별 통계와 총합만 출력됨

___

**# GROUPING SETS**

- GROUPING SETS()는 지정한 행 그룹으로 행을 집계한다.
```SQL
SELECT C1, C2, SUM(C3) AS C3
    FROM T1
    GROUP BY GROUPING SETS ( (C1, C2), C1);
```

| C1 | C2 | C3 |
| :--- | :--- | :--- |
| A | 2050-01-01 00:00:00 | 1 |
| A | 2050-01-02 00:00:00 | 1 |
| A | NULL | 2 |
| B | 2050-01-01 00:00:00 | 1 |
| B | 2050-01-02 00:00:00 | 1 |
| B | NULL | 2 |
| C | 2050-01-01 00:00:00 | 1 |
| C | 2050-01-02 00:00:00 | 1 |
| C | NULL | 2 |

```SQL
-- CUBE와 동일한 GROUPING SETS 표현
SELECT C1, C2, SUM(C3) AS C3
    FROM T1
    GROUP BY GROUPING SETS ( (C1, C2), C1, C2, ())
    ORDER BY 1, 2;

-- CUBE 
SELECT C1, C2, SUM(C3) AS C3
FROM T1
GROUP BY CUBE (C1, C2)
ORDER BY 1, 2;
```

```SQL
-- ROLLUP과 동일한 GROUPING SETS 표현
SELECT C1, C2, SUM(C3) AS C3
    FROM T1
    GROUP BY GROUPING SETS ( (C1, C2), C1, ())
    ORDER BY 1, 2;
    
-- ROLLUP
SELECT C1, C2, SUM(C3) AS C3
FROM T1
GROUP BY ROLLUP (C1, C2)
ORDER BY 1;
```

- 총합만 보기
```sql
--GROUPING SETS

SELECT C1, C2, SUM(C3) AS C3
    FROM T1
    GROUP BY GROUPING SETS ( (C1, C2), ())
    ORDER BY 1, 2;

SELECT C1, C2, SUM(C3) AS C3
    FROM T1
    GROUP BY ROLLUP ((C1, C2))
    ORDER BY 1;
```

___

**# RANGE**

```SQL
SELECT EMPNO, ENAME, SAL, SUM(SAL) OVER ( ORDER BY SAL) AS C1
    FROM EMP
    WHERE DEPTNO = 20;

SELECT EMPNO, ENAME, SAL, SUM(SAL) OVER ( ORDER BY SAL RANGE UNBOUNDED PRECEDING ) AS C1
FROM EMP
WHERE DEPTNO = 20;
-- 위 아래 결과는 같음.
```

- 기본적으로 `RANGE UNBOUNDED PRECEDING` 속성이 디폴트로 되어있다.

- 결과
    | EMPNO | ENAME | SAL | C1 |
    | :--- | :--- | :--- | :--- |
    | 7369 | SMITH | 800 | 800 |
    | 7876 | ADAMS | 1100 | 1900 |
    | 7566 | JONES | 2975 | 4875 |
    | 7788 | SCOTT | `3000` | `10875` |
    | 7902 | FORD | `3000` | 10875 |

- 값이` 동일한 결과`는 모두 더해서 출력된다.
- RANGE는 조회된 행의 값이 기준이기에 같다면 묶어서 합산 후 연산을 한다.

___

**# RANGE BETWEEN `50 PRECEDING` AND `100 FOLLOWING`**

- 지정한 컬럼 값의 `-50 ~ + 100` 사이에 해당하는 컬럼이 존재하면 결과에 포함시킨다.
- PRECEDING : 이전의
- FOLLOWING : 다음의


```SQL
SELECT EMPNO, ENAME, SAL
    , COUNT(*) OVER (
        ORDER BY SAL RANGE BETWEEN 50 PRECEDING AND 100 FOLLOWING ) AS C1
FROM EMP
WHERE DEPTNO = 20;
```

- 결과
    | EMPNO | ENAME | SAL | C1 |
    | :--- | :--- | :--- | :--- |
    | 7369 | SMITH | 800.00 | 1 |
    | 7876 | ADAMS | 1100.00 | 1 |
    | 7566 | JONES | 2975.00 | 3 |
    | 7788 | SCOTT | 3000.00 | 3 |
    | 7902 | FORD | 3000.00 | 3 |
    - C1은 해당 행의 SAL컬럼의 값의 `-50 ~ +100 범위`에 존재하는 행의 갯수이다.
    - 2975의 경우 3000인 행 두개가 범위에 포함되므로 3개
    - 3000또한 2975가 포함되므로 3개

```SQL
SELECT EMPNO, ENAME, SAL
     , SUM(SAL) OVER (
    ORDER BY SAL RANGE BETWEEN 2200 PRECEDING AND 2200 FOLLOWING ) AS C1
FROM EMP
WHERE DEPTNO = 20;
```
- 결과
    | EMPNO | ENAME | SAL | C1 |
    | :--- | :--- | :--- | :--- |
    | 7369 | SMITH | 800.00 | 10875 |
    | 7876 | ADAMS | 1100.00 | 10875 |
    | 7566 | JONES | 2975.00 | 10875 |
    | 7788 | SCOTT | 3000.00 | 10875 |
    | 7902 | FORD | 3000.00 | 10875 |
    - 위 아래로 `+-2200범위`에 모든 컬럼이 포함되므로 전체 행 SUM(SAL)한 값이 나온다.

___

**# ROW**

- RANGE는 출력할 값의 범위안에 해당하는 행들을 그룹으로 지정하지만
- ROW는 행으로 범위를 지정한다.

#

```SQL
SELECT EMPNO, ENAME, SAL
            , SUM(SAL) OVER (
    ORDER BY SAL ROWS UNBOUNDED PRECEDING ) AS C1
FROM EMP
WHERE DEPTNO = 20;
```

- ROWS UNBOUNDED PRECEDING 은 행의 범위를 제한하지 않고 먼저 출력된 행들의 값을 모두 포함한다.
- 결과
    | EMPNO | ENAME | SAL | C1 |
    | :--- | :--- | :--- | :--- |
    | 7369 | SMITH | 800.00 | 800 |
    | 7876 | ADAMS | 1100.00 | 1900 |
    | 7566 | JONES | 2975.00 | 4875 |
    | 7788 | SCOTT | 3000.00 | 7875 |
    | 7902 | FORD | 3000.00 | 10875 |

- 행이 내려감에 따라 C1컬럼의 값에 해당 시점까지의 모든 SAL값이 더해진다.

#

```SQL
SELECT EMPNO, ENAME, SAL
            , SUM(SAL) OVER (
    ORDER BY SAL ROWS 1 PRECEDING ) AS C1
FROM EMP
WHERE DEPTNO = 20;
```

- 결과
    | EMPNO | ENAME | SAL | C1 |
    | :--- | :--- | :--- | :--- |
    | 7369 | SMITH | 800.00 | 800 |
    | 7876 | ADAMS | 1100.00 | 1900 |
    | 7566 | JONES | 2975.00 | 4075 |
    | 7788 | SCOTT | 3000.00 | 5975 |
    | 7902 | FORD | 3000.00 | 6000 |
    - `ROWS 1 PRECEDING` 은 `이전 행 하나`라는 의미가 되므로
    - 바로 이전 행의 SAL값만 더해져 출력된다.

#

```SQL
SELECT EMPNO, ENAME, SAL
            , SUM(SAL) OVER (
    ORDER BY SAL ROWS between 1 PRECEDING and 1 following ) AS C1
FROM EMP
WHERE DEPTNO = 20;
```

- 결과
    | EMPNO | ENAME | SAL | C1 |
    | :--- | :--- | :--- | :--- |
    | 7369 | SMITH | 800.00 | 1900 |
    | 7876 | ADAMS | 1100.00 | 4875 |
    | 7566 | JONES | 2975.00 | 7075 |
    | 7788 | SCOTT | 3000.00 | 8975 |
    | 7902 | FORD | 3000.00 | 6000 |
    - `ROWS between 1 PRECEDING and 1 following`이므로 바로 앞 행과 바로 뒷 행의 값이 더해진다.
    - 1번째 행은 SAL = 800에 이전 행은 존재하지 않으며 다음 행의 SAL은 1100이므로 1900.
    - 2번째 행은 SAL = 1100에 이전 행 SAL = 800, 다음 행 = SAL 2975이므로 모두 합해져 4875가 된다.

#

```SQL
SELECT EMPNO, ENAME, SAL
            , SUM(SAL) OVER (
    ORDER BY SAL ROWS between CURRENT ROW  and UNBOUNDED FOLLOWING ) AS C1
FROM EMP
WHERE DEPTNO = 20;
```
- 결과
    | EMPNO | ENAME | SAL | C1 |
    | :--- | :--- | :--- | :--- |
    | 7369 | SMITH | 800.00 | 10875 |
    | 7876 | ADAMS | 1100.00 | 10075 |
    | 7566 | JONES | 2975.00 | 8975 |
    | 7788 | SCOTT | 3000.00 | 6000 |
    | 7902 | FORD | 3000.00 | 3000 |
    - `ROWS between CURRENT ROW  and UNBOUNDED FOLLOWING` 은 `현재행`부터 `마지막행`까지를 범위로 지정한다.
    - 그러므로 1행인 SAL=800에서는 마지막행까지 모두 더해진 값이 출력되고,
    - 마지막행인 SAL = 3000 은 해당 행의 값만 출력된다.

___

**# SELECT 행의 처리 순서**

FROM -> WHERE -> GROUP BY -> HAVING -> SELECT -> ORDER BY

___

**# ROWNUM 슈도 칼럼**
- ROWNUM 슈도 칼럼은 행이 반환되는 순서대로 순번을 반환한다. 1부터 시작하고 행이 반환될때마다 순번이 증가한다.

#

- 게시판 페이징 
```SQL
SELECT *
    FROM (SELECT A.*, ROWNUM AS RN
          FROM (SELECT EMPNO, ENAME, SAL
                FROM EMP
                ORDER BY SAL DESC) A
         WHERE ROWNUM <= 10)
WHERE RN >= 6;

-- 바인드 변수를 사용하는 경우
SELECT *
    FROM(SELECT A.*, ROWNUM AS RN
        FROM (SELECT EMPNO, ENAME, SAL
            FROM EMP
            ORDER BY SAL DESC) A
        WHERE ROWNUM <= 5 * 2) -- 5(=페이지 행 수) * 2(=페이지 번호) = 10
WHERE RN >= (5 * (2 - 1)) + 1; -- (5[=페이지 행 수] * (2[=페이지 번호] - 1)) + 1 = 6
```

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

**# ROW LIMITING**
- ROW LIMITING 절은 ORDER BY 절 다음에 기술하며, ORDER BY 절과 함께 수행된다. ROW와 ROWS는 구분하지 않아도 된다.
- `OFFSET` 건너뛸 행의 개수를 지정
- `FETCH` 반호나할 행의 개수나 백분율을 지정
- `ONLY` 지정된 행의 개수나 백분율 만큼 행을 반환
- `WITH TIES` 마지막 행에 대한 동순위를 포함해서 반환.

```SQL
SELECT ROW_NUMBER() over ( ORDER BY SAL DESC ) AS RN, ENAME, SAL
    FROM EMP
    ORDER BY SAL DESC FETCH FIRST 3 ROWS ONLY;

-- 위 쿼리와 같음
SELECT *
    FROM ( SELECT ROW_NUMBER() over ( ORDER BY SAL DESC ) AS RN, ENAME, SAL
        FROM EMP)
WHERE RN <= 3; 

-- 중복값 포함 ONLY -> WITH TIES
SELECT ROW_NUMBER() over ( ORDER BY SAL DESC ) AS RN, ENAME, SAL
    FROM EMP
    ORDER BY SAL DESC FETCH FIRST 10 ROWS WITH TIES; 
```
| RN | ENAME | SAL |
| :--- | :--- | :--- |
| 1 | KING | 5000.00 |
| 2 | SCOTT | 3000.00 |
| 3 | FORD | 3000.00 |

- ORDER BY SAL DESC 정렬한 결과를 `첫 3행`만 출력.

```SQL
SELECT ROW_NUMBER() over ( ORDER BY SAL DESC ) AS RN, ENAME, SAL
    FROM EMP
    ORDER BY SAL DESC OFFSET 3 ROW;
```
- ORDER BY SAL DESC 정렬한 결과에서 `첫 3행`을 `건너뛰고` 출력.

| RN | ENAME | SAL |
| :--- | :--- | :--- |
| 4 | JONES | 2975.00 |
| 5 | BLAKE | 2850.00 |
| 6 | CLARK | 2450.00 |
| 7 | ALLEN | 1600.00 |
| 8 | TURNER | 1500.00 |
| 9 | MILLER | 1300.00 |
| 10 | WARD | 1250.00 |
| 11 | MARTIN | 1250.00 |
| 12 | ADAMS | 1100.00 |
| 13 | JAMES | 950.00 |
| 14 | SMITH | 800.00 |

___

**# 순환 관계 모델**

- 한 테이블 내 레코드끼리 관계(SELF JOIN)를 갖는 데이터 모델을 `순환 관계 모델`이라고 한다.

```SQL
-- SELF JOIN
SELECT B.EMPNO, B.ENAME
    FROM EMP A, EMP B
    WHERE  A.ENAME = 'JONES'
    AND B.MGR = A.EMPNO;
```
| EMPNO | ENAME |
| :--- | :--- |
| 7902 | FORD |
| 7788 | SCOTT |
- 같은 테이블을 조인시켜서 JONES 사원이 MANAGER로서 담당하는 사원 리스트를 출력한다.

___

**# START WITH ~ CONNECT BY**

- WHERE 절 다음에 기술하지만, `실행 순서`는 WHERE 절보다 앞선다.
- `START WITH` 조건을 만족하는 데이터를 시작 으로 `CONNECT BY` 조건을 만족하는 데이터를 찾은 후, 최종적으로 WHERE 조건으로 필터링한다.
- `START WITH` 절은 생략이 가능한다.
- `PRIOR` 연산자는 직전 상위 노드의 값을 반환.

```SQL
SELECT EMPNO, ENAME, MGR
    FROM EMP
    START WITH ENAME = 'JONES'
    CONNECT BY MGR = PRIOR EMPNO; 
-- ENAME = 'JONES'인 행부터 시작해서 MGR = PRIOR EMPNO인 행 전부 출력.
```
| EMPNO | ENAME | MGR | JOB |
| :--- | :--- | :--- | :--- |
| 7566 | JONES | 7839 | MANAGER |
| 7788 | SCOTT | 7566 | ANALYST |
| 7876 | ADAMS | 7788 | CLERK |
| 7902 | FORD | 7566 | ANALYST |
| 7369 | SMITH | 7902 | CLERK |

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

#

```SQL
SELECT EMPNO, ENAME, MGR , JOB
FROM EMP
START WITH ENAME = 'JONES'
CONNECT BY MGR = PRIOR EMPNO
AND JOB <> 'ANALYST';
```
- JOB = 'ANALYST'인 행을 제외 후 출력.
- ANALYST가 제외되며 ANALYST와 연결된 CLERK도 출력되지 않음.

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

| EMPNO | ENAME | MGR | LV |
| :--- | :--- | :--- | :--- |
| 7566 | JONES | 7839 | 1 |
| 7788 | SCOTT | 7566 | 2 |
| 7902 | FORD | 7566 | 2 |
| 7876 | ADAMS | 7788 | 3 |
| 7369 | SMITH | 7902 | 3 |

- CTE 구문을 이용해 START WITH / CONNECT BY 구문의 LEVEL 슈도 컬럼처럼 계층 레벨(LV)을 출력한다.
- 부모 노드의 LV값에 1을 더하면 계층의 깊이를 계산할 수 있다.

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

#

**PIVOT시 열이름 결정**

```SQL
SELECT *
    FROM (SELECT JOB, DEPTNO, SAL FROM EMP)
    PIVOT (SUM (SAL) AS SAL FOR DEPTNO IN (10 AS D10));
```
| JOB | D10\_SAL |
| :--- | :--- |
| ANALYST | NULL |
| SALESMAN | NULL |
| CLERK | 1300 |
| MANAGER | 2450 |
| PRESIDENT | 5000 |
- PIVOT 괄호 안에 `SUM (SAL) AS SAL`, `10 AS D10`으로 별칭이 두개가 지어져 있다.
- 테이블 출력시 이 두 별칭이 연결되어 `D10_SAL`이 된다.
- 열 명으로 지정한 `D10`이 먼저 나오고 그 다음 행에 출력되는 결과값인 `SAL`이 붙는다.

___

**# UNPIVOT**
- 열을 행으로 전환.
- `INCLUDE NULLS` 키워드를 기술하면 UNPIVOT된 열의 값이 널인 행도 결과에 포함된다. 기본값은 NULL을 포함시키지 않는 EXCLUDE이다.

| D10\_SAL | D20\_SAL | D30\_SAL |
| :--- | :--- | :--- |
| NULL | 6000 | NULL |
| 1300 | 1900 | 950 |
| 2450 | 2975 | 2850 |
| 5000 | NULL | NULL |
| NULL | NULL | 5600 |
에서 아래 SQL문을 실행하면,

```SQL
SELECT JOB, DEPTNO, SAL
    FROM T1
    UNPIVOT (SAL FOR DEPTNO IN(D10_SAL, D20_SAL, D30_SAL))
    WHERE JOB = 'CLERK'
    ORDER BY JOB, DEPTNO;
```
의 결과는
| JOB | DEPTNO | SAL |
| :--- | :--- | :--- |
| CLERK | D10_SAL | 1300|   
| CLERK | D20_SAL | 1900|
| CLERK | D30_SAL | 950 |
이 된다.

- IN절 값에 별칭을 지정하지 않으면 컬럼명이 그대로 출력된다.

___

**# 정규표현식**
    - REGEXP_SUBSTR 함수는 source_char에서 일치한 pattern을 반환한다.
```sql
REGEXP_SUBSTR (source_char, apttern [, position [, occurrence [, match_param [, subexpr]]]])
```

- source_char : 검색문자열
- pattern : 검색패턴
- position : 검색 시작 위치 (기본값은 1)
- occurrence : 패턴 일치 횟수 (기본값은 1)
- match_paran : 일치 옵션
- subexpr : 서브 표현식 (0은 전체 패턴, 1 이상은 서브 표현식, 기본값은 0)

```SQL
SELECT REGEXP_SUBSTR('ABC', 'A.+') AS C1, -- C1 탐욕적(최대)
        REGEXP_SUBSTR('ABC', 'A.+?') AS C2 -- C2 비탐욕적(최소)
        FROM DUAL;
```

| C1 | C2 |
| :--- | :--- |
| ABC | AB |

- C1열은 탐욕적(최대), C2열은 비탐욕적(최소) 방식으로 패턴을 일치시킨다. 마침표(.)는 모든 문자, 더하기(+)는 1회 또는 그 이상의 횟수로 일치함을 의미하므로 C1은 ABC, C2는 AB가 일치한다.

#

```SQL
SELECT REGEXP_SUBSTR('ABD', 'AB|CD') AS C1,
       REGEXP_SUBSTR('ABD', 'A(B|C)D') AS C2
FROM DUAL;
```
| C1 | C2 |
| :--- | :--- |
| AB | ABD |

- OR(|)은 대체 문자를 구분하고, 표현식을 소괄호로 묶은 서브 표현식은 하나의 단위로 처리된다.
- C1열은 AB 또는 CD가 일치하고, 
- C2열은 서브표현식으로 인해 ABD 또는 ACD가 일치한다.

#

- [char..] 대괄호 안에 입력된 char(문자 하나) 중 하나와 일치하는 문자열로 나눔
- [^char..] 대괄호 안에 입력된 char(문자 하나) 가 포함되지 않은 문자열로 나눔

```SQL
SELECT REGEXP_SUBSTR('문1자2열3', '([^자]+)', 1, 1) AS C1
FROM DUAL; -- 문1

SELECT REGEXP_SUBSTR('문1자2열3', '([^자]+)', 1, 2) AS C1
FROM DUAL; -- 2열3
```
- '문1자2열'을 '자'를 제거하고 이 기준으로 나누면
- '문1', '2열3'이 남게된다.

```SQL
SELECT REGEXP_SUBSTR('문1자2열3', '([^자]+)', 2, 1) AS C1
FROM DUAL; -- 1

SELECT REGEXP_SUBSTR('문1자2열3', '([^자]+)', 2, 2) AS C1
FROM DUAL; -- 2열3
```

- 앞 숫자를 고치면 문자열의 시작 인덱스를 변경할 수 있는데 아래껀 왜 안되는지 모르겠다.

- 뒷숫자 (나눠진 문자열 집합의 원소 인덱스)
```SQL
SELECT REGEXP_SUBSTR('문A1자B2열C3', '([^123]+)', 1, 1) AS C1
FROM DUAL; -- 문A

SELECT REGEXP_SUBSTR('문A1자B2열C3', '([^123]+)', 1, 2) AS C1
FROM DUAL; -- 자B

SELECT REGEXP_SUBSTR('문A1자B2열C3', '([^123]+)', 1, 3) AS C1
FROM DUAL; -- 열C
```

- 앞숫자 (문자열의 인덱스?)
```SQL
SELECT REGEXP_SUBSTR('문A1자B2열C3', '([^123]+)', 2, 1) AS C1
FROM DUAL; -- A

SELECT REGEXP_SUBSTR('문A1자B2열C3', '([^123]+)', 3, 1) AS C1
FROM DUAL; -- 자B

SELECT REGEXP_SUBSTR('문A1자B2열C3', '([^123]+)', 4, 1) AS C1
FROM DUAL; -- 자B

SELECT REGEXP_SUBSTR('문A1자B2열C3', '([^123]+)', 5, 1) AS C1
FROM DUAL; -- B

SELECT REGEXP_SUBSTR('문A1자B2열C3', '([^123]+)', 6, 1) AS C1
FROM DUAL; -- 열C

-- 7 상동

SELECT REGEXP_SUBSTR('문A1자B2열C3', '([^123]+)', 8, 1) AS C1
FROM DUAL; -- C
```

___

**# REGEXP_REPLACE**
```SQL
SELECT REGEXP_REPLACE('1A2B3C4D', '\D') AS C1 FROM DUAL; -- 1234
SELECT REGEXP_REPLACE('1A2B3C4D', '\D', '_') AS C1 FROM DUAL; -- 1_2_3_4_

SELECT REGEXP_REPLACE('1A2B3C4D', '\d') AS C1 FROM DUAL; -- ABCD
SELECT REGEXP_REPLACE('1A2B3C4D', '\d', '_') AS C1 FROM DUAL; -- _A_B_C_D
```

- `'\D'` 는 문자, `'\d'`는 숫자를 나타냄.

___

## **# 핵심 문제**

**# 1**

- 논리 조건
    - AND 조건은 모든 조건이 TRUE여야 TRUE.
    - OR 조건은 하나라도 TRUE면 TRUE.
    - NOT 조건
        |    | =  |<>  |>   |>=  |<   |<=  |AND |OR  |
        |:--:|:--:|:--:|:--:|:--:|:--:|:--:|:--:|:--:|
        |NOT|<>|=|<=|<|>=|>|OR|AND|

#
```SQL
-- 1
DROP TABLE T1;
CREATE TABLE T1 (C1 NUMBER);

INSERT INTO T1 VALUES (1);
INSERT INTO T1 VALUES (2);
INSERT INTO T1 VALUES (3);

DROP TABLE T2;
CREATE TABLE T2 (C1 NUMBER);

INSERT INTO T2 VALUES (1);
INSERT INTO T2 VALUES (NULL);

SELECT COUNT(*) FROM T1 WHERE C1 NOT IN (SELECT C1 FROM T2); -- 0
```

- 쿼리의 NOT IN 서브쿼리는 C1 NOT IN (1, NULL) 조건으로 해석된다.
- NOT IN 조건을 OR 조건으로 변경하면 NOT (C1 = 1 OR C1 = NULL) 조건이 되고,
- NOT 조건을 분해하면 C1 <> 1 AND C1 <> NULL 조건이 된다.
- C1 <> NULL 조건은 NULL이므로 결국 C1 <> 1 AND NULL 조건으로 해석된다.
- AND NULL 조건은 모든 조건이 NULL이 되므로 결과로 0이 반환된다.

| 순서 | 조건 |
|:-----:|:------:|
|1| C1 NOT IN (1, NULL)|
|2| NOT (C1 = 1 OR C1 = NULL)|
|3| C1 <> 1 AND C1 <> NULL|
|4| C1 <> 1 AND NULL|

___

**# 2**

```SQL
-- 2
DROP TABLE T1;
CREATE TABLE T1 (C1 VARCHAR(1), C2 NUMBER);

DROP TABLE T2;
CREATE TABLE T2 (C1 VARCHAR(1), C2 NUMBER);

SELECT C1, C2 FROM T1
UNION ALL
SELECT C1 FROM T2;
-- ORA-01789: 질의 블록은 부정확한 수의 결과 열을 가지고 있습니다.

SELECT C1, C2 FROM T1
UNION ALL
SELECT C2, C1 FROM T2;
-- ORA-01790: 대응하는 식과 같은 데이터 유형이어야 합니다

SELECT C1, C2 FROM T1 ORDER BY C1
UNION ALL
SELECT C1, C2 FROM T2 ORDER BY C1; -- ORDER BY 가 두번입력됨.
-- ORA-00933: SQL 명령어가 올바르게 종료되지 않았습니다

(SELECT C1, C2 FROM T1)
UNION ALL
(SELECT C1, C2 FROM T2);
-- 정상 작동
```
- 3번에서 에러가 발생하는 이유는 집합 연산자를 사용한 SQL은 SQL의 끝에 ORDER BY 절을 `1번만 기술`할 수 있기 때문

___

**# 3**

```SQL
DROP TABLE T1;
CREATE TABLE T1(C1 NUMBER, C2 NUMBER);

INSERT INTO T1 VALUES (1, 1);
INSERT INTO T1 VALUES (1, 2);
INSERT INTO T1 VALUES (2, 1);
INSERT INTO T1 VALUES (2, 2);

DROP TABLE T2;
CREATE TABLE T2(C1 NUMBER, C2 NUMBER);

INSERT INTO T2 VALUES (1, 1);
INSERT INTO T2 VALUES (1, 2);
INSERT INTO T2 VALUES (2, 1);

SELECT * FROM T1 WHERE (C1 = 1 OR C2 = 1);

SELECT * FROM T1 WHERE C1 = 1
UNION ALL
SELECT * FROM T1 WHERE C2 = 1 AND C1 <> 1;
```

| C1 | C2 |
| :--- | :--- |
| 1 | 1 |
| 1 | 2 |
| 2 | 1 |


- 단일 테이블에 대한 OR 조건은 UNION ALL이나 UNION 집합 연산자로 변경할 수 있다.
- C1 = 1 조건을 만족하는 집합과 C2 = 1 조건을 만족하는 집합 간에는 중복 행이 UNION ALL 집합 연산자를 사용하는 경우 중복 제거를 위해 C1 <> 1 조건을 추가해야 한다.

___

**# 4**

```SQL
DROP TABLE T1;
CREATE TABLE T1 (C1 VARCHAR(2), C2 DATE, C3 NUMBER);

INSERT INTO T1 VALUES ('A', '20500101', 1);
INSERT INTO T1 VALUES ('A', '20500102', 1);
INSERT INTO T1 VALUES ('B', '20500101', 1);
INSERT INTO T1 VALUES ('B', '20500102', 1);
INSERT INTO T1 VALUES ('C', '20500101', 1);
INSERT INTO T1 VALUES ('C', '20500102', 1);
```

```SQL
SELECT C1, C2, SUM(C3) AS C3
    FROM T1
    GROUP BY ROLLUP((C1, C2)); 
    -- ORDER BY C1, C2, 총합만 출력됨
```

| C1 | C2 | C3 |
| :--- | :--- | :--- |
| A | 2050-01-01 00:00:00 | 1 |
| A | 2050-01-02 00:00:00 | 1 |
| B | 2050-01-01 00:00:00 | 1 |
| B | 2050-01-02 00:00:00 | 1 |
| C | 2050-01-01 00:00:00 | 1 |
| C | 2050-01-02 00:00:00 | 1 |
| NULL | NULL | 6 |

```SQL
SELECT C1, C2, SUM(C3) AS C3
FROM T1
GROUP BY ROLLUP((C2, C1)); 
-- ORDER BY C2, C1, 총합만 출력됨
```

| C1 | C2 | C3 |
| :--- | :--- | :--- |
| A | 2050-01-01 00:00:00 | 1 |
| B | 2050-01-01 00:00:00 | 1 |
| C | 2050-01-01 00:00:00 | 1 |
| A | 2050-01-02 00:00:00 | 1 |
| B | 2050-01-02 00:00:00 | 1 |
| C | 2050-01-02 00:00:00 | 1 |
| NULL | NULL | 6 |

```SQL
SELECT C1, C2, SUM(C3) AS C3
FROM T1
GROUP BY C1, ROLLUP(C2); 
-- ORDER BY C1, C2, C1 기준 합계만 출력됨
```

| C1 | C2 | C3 |
| :--- | :--- | :--- |
| A | 2050-01-01 00:00:00 | 1 |
| A | 2050-01-02 00:00:00 | 1 |
| A | NULL | 2 |
| B | 2050-01-01 00:00:00 | 1 |
| B | 2050-01-02 00:00:00 | 1 |
| B | NULL | 2 |
| C | 2050-01-01 00:00:00 | 1 |
| C | 2050-01-02 00:00:00 | 1 |
| C | NULL | 2 |

```SQL
SELECT C1, C2, SUM(C3) AS C3
FROM T1
GROUP BY C2, ROLLUP(C1); 
-- ORDER BY C2, C1, C2 기준 합계만 출력됨
```

| C1 | C2 | C3 |
| :--- | :--- | :--- |
| A | 2050-01-01 00:00:00 | 1 |
| B | 2050-01-01 00:00:00 | 1 |
| C | 2050-01-01 00:00:00 | 1 |
| NULL | 2050-01-01 00:00:00 | 3 |
| A | 2050-01-02 00:00:00 | 1 |
| B | 2050-01-02 00:00:00 | 1 |
| C | 2050-01-02 00:00:00 | 1 |
| NULL | 2050-01-02 00:00:00 | 3 |

- 
___

**# 5**


- GROUPING 함수는 표현식이 행 그룹에 포함되면 0, 포함되지 않으면 1을 반환한다. 결과의 GP열은 C2가 행 그룹에 포함되지 않은 행에 0을 반환한다. 3, 4번은 에러가 발생한다.

```SQL
SELECT C1, C2, SUM(C3) AS C3,
    GROUPING(C1) AS GP
    FROM T1
    GROUP BY ROLLUP (C1, C2);
```

| C1 | C2 | C3 | GP |
| :--- | :--- | :--- | :--- |
| A | 2050-01-01 00:00:00 | 1 | 0 |
| A | 2050-01-02 00:00:00 | 1 | 0 |
| A | NULL | 2 | 0 |
| B | 2050-01-01 00:00:00 | 1 | 0 |
| B | 2050-01-02 00:00:00 | 1 | 0 |
| B | NULL | 2 | 0 |
| C | 2050-01-01 00:00:00 | 1 | 0 |
| C | 2050-01-02 00:00:00 | 1 | 0 |
| C | NULL | 2 | 0 |
| NULL | NULL | 6 | 1 |

```SQL
SELECT C1, C2, SUM(C3) AS C3,
       GROUPING(C2) AS GP
FROM T1
GROUP BY ROLLUP (C1, C2);
```

| C1 | C2 | C3 | GP |
| :--- | :--- | :--- | :--- |
| A | 2050-01-01 00:00:00 | 1 | 0 |
| A | 2050-01-02 00:00:00 | 1 | 0 |
| A | NULL | 2 | 1 |
| B | 2050-01-01 00:00:00 | 1 | 0 |
| B | 2050-01-02 00:00:00 | 1 | 0 |
| B | NULL | 2 | 1 |
| C | 2050-01-01 00:00:00 | 1 | 0 |
| C | 2050-01-02 00:00:00 | 1 | 0 |
| C | NULL | 2 | 1 |
| NULL | NULL | 6 | 1 |

```SQL
SELECT C1, C2, SUM(C3) AS C3,
       GROUPING(C1, C2) AS GP
FROM T1
GROUP BY ROLLUP (C1, C2);
-- ORA-00909: 인수의 개수가 부적합합니다

SELECT C1, C2, SUM(C3) AS C3,
       GROUPING(C2, C1) AS GP
FROM T1
GROUP BY ROLLUP (C1, C2);
-- ORA-00909: 인수의 개수가 부적합합니다
```

___


**# 6**
```SQL
SELECT EMPNO, ENAME, SAL, COMM, FIRST_VALUE(COMM) over (ORDER BY SAL) AS C1
    FROM EMP
    WHERE DEPTNO = 30;
```

| EMPNO | ENAME | SAL | COMM | C1 |
| :--- | :--- | :--- | :--- | :--- |
| 7900 | JAMES | 950.00 | NULL | NULL |
| 7521 | WARD | 1250.00 | 500.00 | NULL |
| 7654 | MARTIN | 1250.00 | 1400.00 | NULL |
| 7844 | TURNER | 1500.00 | NULL | NULL |
| 7499 | ALLEN | 1600.00 | 300.00 | NULL |
| 7698 | BLAKE | 2850.00 | NULL | NULL |

- FIRST_VALUE 함수는 위도우 첫 행의 컬럼 값을 반환한다.
- IGNORE ULLS 키워드를 기술하면 제외한 첫 행의 값을 반환한다.

___

**# 7**
```SQL
SELECT EMPNO, ENAME, SAL, LAG(SAL, 2) OVER ( ORDER BY SAL ) AS C1
    FROM EMP
    WHERE DEPTNO = 20; -- SAL을 2행 뒤로 
```
| EMPNO | ENAME | SAL | C1 |
| :--- | :--- | :--- | :--- |
| 7369 | SMITH | 800.00 | NULL |
| 7876 | ADAMS | 1100.00 | NULL |
| 7566 | JONES | 2975.00 | 800 |
| 7788 | SCOTT | 3000.00 | 1100 |
| 7902 | FORD | 3000.00 | 2975 |

```SQL
SELECT EMPNO, ENAME, SAL, LAG(SAL, 2, 0) OVER ( ORDER BY SAL ) AS C1
FROM EMP
WHERE DEPTNO = 20;
```
| EMPNO | ENAME | SAL | C1 |
| :--- | :--- | :--- | :--- |
| 7369 | SMITH | 800.00 | 0 |
| 7876 | ADAMS | 1100.00 | 0 |
| 7566 | JONES | 2975.00 | 800 |
| 7788 | SCOTT | 3000.00 | 1100 |
| 7902 | FORD | 3000.00 | 2975 |

```SQL
SELECT EMPNO, ENAME, SAL, LEAD(SAL, 2) OVER ( ORDER BY SAL ) AS C1
FROM EMP
WHERE DEPTNO = 20;
```
| EMPNO | ENAME | SAL | C1 |
| :--- | :--- | :--- | :--- |
| 7369 | SMITH | 800.00 | 2975 |
| 7876 | ADAMS | 1100.00 | 3000 |
| 7566 | JONES | 2975.00 | 3000 |
| 7788 | SCOTT | 3000.00 | NULL |
| 7902 | FORD | 3000.00 | NULL |

```SQL
SELECT EMPNO, ENAME, SAL, LEAD(SAL, 2, 0) OVER ( ORDER BY SAL ) AS C1
FROM EMP
WHERE DEPTNO = 20;
```
| EMPNO | ENAME | SAL | C1 |
| :--- | :--- | :--- | :--- |
| 7369 | SMITH | 800.00 | 2975 |
| 7876 | ADAMS | 1100.00 | 3000 |
| 7566 | JONES | 2975.00 | 3000 |
| 7788 | SCOTT | 3000.00 | 0 |
| 7902 | FORD | 3000.00 | 0 |

- LAG 함수
    - 현재 행에서 OFFSET 이전 행의 칼럼 값을 반환한다.
    - OFFSET은 행 기준이며 기본값은 1이다.
    - 이전 행이 없을 때 반환할 값을 DEFAULT 인자로 지전할 수 있으며, 기본값을 NULL이다.
- 쿼리 결과는 2행 이전 행의 SAL을 조회한다. 2행 이전 행이 없는 행에서 0이 반환되었으므로 DEFAULT 인자에 0을 지정한 것을 알 수 있다.

___

**# 8**

```SQL
SELECT * FROM (SELECT A.EMPNO, A.ENAME, A.SAL, A.DEPTNO, B.DNAME
              FROM EMP A, DEPT B
              WHERE B.DEPTNO(+) = A.DEPTNO
              ORDER BY SAL DESC)
    WHERE ROWNUM <= 3;

SELECT A.*, B.DNAME
    FROM (SELECT EMPNO, ENAME, SAL, DEPTNO FROM EMP ORDER BY SAL DESC) A, DEPT B
    WHERE ROWNUM <= 3
    AND B.DEPTNO(+) = A.DEPTNO;
```

| EMPNO | ENAME | SAL | DEPTNO | DNAME |
| :--- | :--- | :--- | :--- | :--- |
| 7839 | KING | 5000.00 | 10 | ACCOUNTING |
| 7788 | SCOTT | 3000.00 | 20 | RESEARCH |
| 7902 | FORD | 3000.00 | 20 | RESEARCH |

- 1번 SQL은 DEPT 테이블을 조인해서 SAL 역순으로 정렬한 후 상위 3개를 선택했고, 
- 2번 SQL은 SAL 역순으로 정렬한 결괒비합으로 DEPT 테이블과 조인하면서 상위 3개를 선택했다.
- 1번 SQL은 14행, 2번 SQL은 3행이 조인된다. M:1 아우터 조인인 경우 2번 SQL처럼 TOP-N 처리 후 조인하는 편이 성능 측면에서 유리하다.

- EMP 아우터 조인 14회, WHERE ROWNUM <= 3이 조인보다 먼저 나오므로 3회

___

**# 9**

```SQL
SELECT EMPNO, ENAME, SAL, DEPTNO
    FROM EMP
    ORDER BY SAL DESC; -- 14행

SELECT A.*, ROWNUM AS RN
    FROM (SELECT EMPNO, ENAME, SAL, DEPTNO
        FROM EMP
        ORDER BY SAL DESC ) A
WHERE ROWNUM <= 10; -- 10행

SELECT A.*
    FROM (SELECT A.*, ROWNUM AS RN
        FROM (SELECT EMPNO, ENAME, SAL, DEPTNO
            FROM EMP
            ORDER BY SAL DESC) A
        WHERE ROWNUM <= 10 ) A
    WHERE RN >= 6; -- 5행
```
- 3번째 쿼리는 6 ~ 10 번째 결과가 출력되므로 총 5행이 출력된다.

___

**# 10**

```SQL
SELECT *
FROM EMP
WHERE JOB <> 'ANALYST'
START WITH ENAME = 'JONES'
CONNECT BY MGR = PRIOR EMPNO; -- 3
```

- `START WITH ~ CONNECT BY` 절은 WHERE 절보다 뒤에 작성되지만 실행순서는 WHERE 절보다 앞선다.
- 그러므로 일단 `START WITH ~ CONNECT BY` 조건에 맞는 모든 절이 불러와지고
- 그 다음에 `JOB <> 'ANALYST'` 조건이 실행되므로
- ANALYST행에 의해 불러와진 CLERK 행은 남게된다.
- 따라서 JONES와 두 CLERK이 남아 총 3이 출력된다.

___

**# 11**

```SQL
WITH W1 (EMPNO, ENAME, MGR) AS (
    SELECT EMPNO, ENAME, MGR
    FROM EMP
    WHERE ENAME = 'JONES'
    UNION ALL
    SELECT C.EMPNO, C.ENAME, C.MGR
    FROM W1 P, EMP C
    WHERE P.EMPNO = C.MGR)
SELECT EMPNO, ENAME, MGR
FROM W1;
```

- 관리자가 앞서 읽은 사원의 사원번호와 일치하는 데이터를 찾아 하위 노드로 전개해야 하므로 조인식을 C.MGR = P.EMPNO로 기술해야 한다.
- 가장 먼저 읽은 JONES의 사원번호(EMPNO)는 7566이다. 관리자(MGR)가 앞서 읽은 JONES의 사원번호 7566과 일치하는 사원은 SCOTT과 FORD다. 예를 하나 더 들면, 관리자가 앞서 읽은 SCOTT의 사원번호 7788과 일치하는 사원은 ADAMS이다.
___

**# 12**

```SQL
SELECT  *
    FROM (SELECT JOB, TO_CHAR (HIREDATE, 'YYYY') AS YYYY, DEPTNO, SAL
        FROM EMP
        WHERE DEPTNO IN (10, 30))
    PIVOT (SUM(SAL) FOR DEPTNO IN(10, 30))
    ORDER BY JOB, YYYY;
```

| JOB | YYYY | 10 | 30 |
| :--- | :--- | :--- | :--- |
| CLERK | 1981 | NULL | 950 |
| CLERK | 1982 | 1300 | NULL |
| MANAGER | 1981 | 2450 | 2850 |
| PRESIDENT | 1981 | 5000 | NULL |
| SALESMAN | 1981 | NULL | 5600 |

___

**# 13**

| JOB | D10\_SAL | D20\_SAL | D30\_SAL |
| :--- | :--- | :--- | :--- |
| ANALYST | NULL | 6000 | NULL |
| CLERK | 1300 | 1900 | 950 |
| MANAGER | 2450 | 2975 | 2850 |
| PRESIDENT | 5000 | NULL | NULL |
| SALESMAN | NULL | NULL | 5600 |


에서 

```SQL
SELECT *
    FROM T1
    UNPIVOT INCLUDE NULLS
        (SAL FOR DEPTNO IN (D10_SAL AS 10, D20_SAL AS 20, D30_SAL AS 30))
    WHERE JOB = 'ANALYST';
```
의 결과는 
| JOB | DEPTNO | SAL |
| :--- | :--- | :--- |
| ANALYST | 10 | NULL |
| ANALYST | 20 | 6000 |
| ANALYST | 30 | NULL |

이다.

- 일반적으로 COUNT 함수는 NULL을 포함시키지 않지만, 
- 위 쿼리에는 `INCLUDE NULLS`가 기술되어 있기 때문에 NULL을 포함해 연산한다.
- 그러므로 아래 쿼리의 결과는 3이다.

```SQL
SELECT COUNT(*) AS CNT
    FROM T1
    UNPIVOT INCLUDE NULLS
        (SAL FOR DEPTNO IN (D10_SAL AS 10, D20_SAL AS 20, D30_SAL AS 30))
    WHERE JOB = 'ANALYST'; -- 3
```

___

**# 14**
```SQL
SELECT REGEXP_SUBSTR('12AB34CD', '[A-Z]+$') AS C1 FROM DUAL; -- CD
```
- [A-Z]는 영문 대문자,
- `+`는 1회 또는 그 이상의 횟수로 일치,
- `$`는 문자열의 끝을 의미하므로
- 이 표현식에 일치하는 문자는 `CD`이다.

___

**# 15**
```SQL
SELECT REGEXP_SUBSTR('AABABCABCD', '(AB)C\1') AS C1 FROM DUAL; -- ABCAB
```

- 첫 번째 일치한 표현식이 AB이고, C 이후에 첫 번째 일치한 표현식을 AB 일치하므로 ABCAB가 일치한다.


```SQL
SELECT REGEXP_SUBSTR('ABCABCABCABC','(AB)C\1') AS C1 FROM DUAL; -- ABCAB
SELECT REGEXP_SUBSTR('ABCABCABCABC','(AB)C(ABC)\1') AS C1 FROM DUAL; -- ABCABCAB
SELECT REGEXP_SUBSTR('ABCABCABCABC','(AB)C(ABC)\2') AS C1 FROM DUAL; -- ABCABCABC
```
- 역참조`'(AB)C\1'` 는 `'(AB)C(AB)'`와 일치.
- `'(AB)C(ABC)\1'`는 `'(AB)C(ABC)(AB)'`와 일치.
- `'(AB)C(ABC)\2'`는 `'(AB)C(ABC)(ABC)'`와 일치.

#

**# 역참조**
- 역참조를 사용하면 일치함 서브 표현식을 다시 참조할 수 있다. 반복되는 패턴을 검색하거나 서브 표현식의 위치를 변경하는 용도로 사용할 수 있다.

- \n : n번째 서브 표현식과 일치, n은 1에서 9사이의 정수

___