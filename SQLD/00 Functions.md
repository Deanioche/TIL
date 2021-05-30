# SQL 함수메모

**# LPAD(), RPAD()**

- LPAD 함수는 지정한 길이의 `빈칸`을 왼쪽부터 특정문자로 채워준다.
- 함수  :  LPAD("값", "총 문자길이", "채움문자")
- LPAD('123', 5, '#')이라면
    - 문자열 '123'의 길이는 3이므로 왼쪽부터 #을 채워 5의 길이로 만든다.
    - 결과 : '##123'

<img src="https://user-images.githubusercontent.com/66513003/119357776-ea08ad00-bce2-11eb-8714-b68f9210c0b6.png" width="400">

```sql
select LPAD(RPAD(SUBSTR('12345',-3, 2), 3, '#'), 5, '*')as R1 from DUAL; -- **34#
```

**# SUBSTR(str, n, a)**
- 문자열 str을 n번째 글자부터 a길이만큼 잘라내 반환한다.
- n이 음수면 문자열 맨 끝부터 잘라낸다.

```sql
select SUBSTR('12345', 0) from DUAL; -- 12345
select SUBSTR('12345', 1) from DUAL; -- 12345
select SUBSTR('12345', 2) from DUAL; -- 2345
select SUBSTR('12345', 6) from DUAL; -- NULL
select SUBSTR('12345', -1) from DUAL; -- 5
select SUBSTR('12345', -5) from DUAL; -- 12345
select SUBSTR('12345', -6) from DUAL; -- NULL

select SUBSTR('12345',0, 1) from DUAL; -- 1
select SUBSTR('12345',0, 5) from DUAL; -- 12345
select SUBSTR('12345',-2, 1) from DUAL; -- 4
select SUBSTR('12345',-5, 3) from DUAL; -- 123
select SUBSTR('12345',-5, 5) from DUAL; -- 12345
```

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

**# ROLL UP**
- ROLLUP은 지정한 표현식의 계층별 소계와 총계를 집계한다.

#

**# CUBE**
- CUBE는 지정한 표현식의 모든 조합을 집계한다.

#

**# GROUPING SETS**
- GROUPING SETS()는 지정한 행 그룹으로 행을 집계한다.
- ROLLUP과 CUBE를 표현할 수 있다.
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

#

___

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

