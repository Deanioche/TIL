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

**EXISTS** 
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

- 1번 SQL은 SQL과 COMM의 부서별 최대 값을 계산하귀 위해 스칼라 서브 쿼리로 EMP테이블을 2번 조화했다.
- 2번 쿼리는 EMP 테이블의 조회 횟수를 줄이기 위해 1번 쿼리의 스칼라 서브 쿼리를 인라인 뷰로 변경했다. 이런 경우 메인 쿼리를 기분으로 인라인 뷰를 `아우터 조인`해야 동일한 결과를 보장할 수 있다.
- 다만, DEPT에 입력된 모든 DEPTNO가 EMP 테이블과 조인할 때 적어도 한 건 이상 성공하는 `필수(MANDATORY) 관계`라면, 스칼라 서브 쿼리를 인라인 뷰로 전환하면서 이너 조인을 사용해도 된다.

- 동일 쿼리를 만드는 문제에서는 NULL값이 들어가도 되는지 안되는지를 꼭 확인할것.
- 1번 SQL에서 스칼라 서브쿼리는 SELECT A.DEPTNO, A.DNAME의 결과의 개수에 영향을 미치지 못하므로, A.DEPTNO, A.DNAME의 결과는 일단 `모두` 출력된다. 즉, `스칼라 서브쿼리로 출력되는 컬럼의 결과로 NULL이 출력 될 수도 있다는 의미`이다.
- 이는 A.DEPTNO, A.DNAME을 포함하는 테이블 A(별칭)은 `아우터 조인`을 한다는 뜻이 된다.
- 따라서, 아우터조인이 아닌 쪽이 (+) 기호를 받으므로 `A.DEPTNO = B.DEPTNO(+)`가 된다.



