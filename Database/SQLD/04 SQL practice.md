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

#

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

#

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

#

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

#

**# RPAD(), LPAD()**

```sql
select LPAD(RPAD(SUBSTR('12345',-3, 2), 3, '#'), 5, '*')as R1 from DUAL; -- **34#
```

#

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

#

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

#

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

#

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

#

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

#

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

#
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

- 행이 내려감에 따라 C1컬럼의 값에 이전 행의 SAL값이 더해져 출력된다.

#

```SQL
SELECT EMPNO, ENAME, SAL
            , SUM(SAL) OVER (
    ORDER BY SAL ROWS 1 PRECEDING ) AS C1
FROM EMP
WHERE DEPTNO = 20;
```


