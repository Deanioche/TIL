select * from TAB;

select * from EMP;

select ENAME || JOB from EMP;

select ENAME from EMP where EMP.COMM = NULL;



--
drop table T1;
Create table T1 (C1 Date);

insert into T1 values (TO_DATE (20200616143030 , 'yyyy-mm-dd hh24:mi:ss'));

select * from T1;

UPDATE T1 set C1 = TO_DATE (20200616143030 , 'yyyy-mm-dd hh24:mi:ss') where C1 is not null;
UPDATE T1 set C1 = sysdate where C1 is not null;


-- 시간

SELECT C1 as 원본,
       TRUNC (C1, 'MM'),
       TRUNC (C1, 'hh'),
       TRUNC (C1, 'MI'),
       ADD_MONTHS(TRUNC (C1, 'MM'), -1 * 12)
from T1;

SELECT TRUNC (C1, 'MM'), -1 * 12 AS R1 from T1;
SELECT TRUNC (C1, 'DD') AS R1 from T1;

-- 정규표현식
SELECT REGEXP_REPLACE('20200616143030', '(.{4})(.{2})(.{2})(.{2})(.{2})(.{2})', '\1-\2-\3 \4:\5:\6') RESULT2
FROM DUAL; -- 2020-06-16 14:30:30

SELECT TO_DATE (20200616143030 , 'yyyy-mm-dd hh24:mi:ss') M_DATE FROM DUAL;
SELECT SYSDATE - 1 M_DAY FROM DUAL; -- 현재시간 -1일
SELECT SYSDATE - (1/24) M_TIME FROM DUAL; -- 현재시간 -1시간
SELECT SYSDATE - (1/1440) M_MINUTE FROM DUAL; -- 현재시간 -1분
SELECT SYSDATE - (1/86400) M_SECOND FROM DUAL; -- 현재시간 -1초

----
drop table T1;
Create table T1 (C1 number, C2 varchar2(2));

insert into T1 values(1, 'A');
insert into T1 values(2, 'A');
insert into T1 values(4, 'B');
insert into T1 values(4, 'C');
insert into T1 values(NULL, NULL);

select * from T1;

SELECT DECODE(C2, 'A', C1, 'B', 1) AS R1 FROM T1;

---

SELECT DEPTNO, JOB
    FROM EMP
    GROUP BY DEPTNO, JOB;

SELECT JOB, HIREDATE
FROM EMP
GROUP BY JOB;

SELECT * from EMP;

--- ORDER BY

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

---

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
      WHERE B.고객번호 = A.고객번호
        AND B.주문일자 <= A.주문일자
      GROUP BY A.고객번호, A.주문일자
        ORDER BY A.고객번호, A.주문일자;

-- OUTER JOIN
drop table 고객;
Create table 고객 (고객번호 number, 고객명 varchar(10));

insert into 고객 values (1, '김대원');
insert into 고객 values (2, '노영미');
insert into 고객 values (3, '김경진');
insert into 고객 values (4, '박하연');

drop table 주문;
Create table 주문 (주문번호 number, 고객번호 number, 주문금액 number);

insert into 주문 values (2001, 1, 40000);
insert into 주문 values (2002, 2, 15000);
insert into 주문 values (2003, 2, 7000);
insert into 주문 values (2004, 2, 8000);
insert into 주문 values (2005, 2, 20000);
insert into 주문 values (2006, 3, 5000);
insert into 주문 values (2007, 3, 9000);

COMMIT;

SELECT *
    FROM 고객 A, 주문 B
    WHERE B."고객번호"(+) = A."고객번호"
    AND B.주문금액(+) > 10000;
    -- (+)가 없는 쪽은 아우터 조인이기 때문에 조건에 맞지 않아도(NULL이 포함된 행이 생겨도) 고객테이블의 모든 행이 JOIN된다.

SELECT *
FROM 고객 A, 주문 B
WHERE A."고객번호" = B."고객번호"
  AND B.주문금액 > 10000;
    --일반  JOIN은 조건에 맞는 행만 집합에 포함시켜 출력한다. (JOIN 결과로서 NULL이 생기지 않는다)

SELECT SUM(B.주문금액) / COUNT(DISTINCT A.고객번호) AS R1
FROM 고객 A, 주문 B
WHERE B."고객번호"(+) = A."고객번호"
  AND B.주문금액(+) > 10000; -- 75000 / 4 = 18750

-- INNER JOIN
DROP TABLE T1;
CREATE TABLE T1 (C1 NUMBER, C2 VARCHAR(2));

INSERT INTO T1 VALUES (1, 'A');
INSERT INTO T1 VALUES (2, 'B');
INSERT INTO T1 VALUES (3, 'C');

DROP TABLE T2;
CREATE TABLE T2 (C1 NUMBER, C2 NUMBER);

INSERT INTO T2 VALUES (1, 1);
INSERT INTO T2 VALUES (2, 1);
INSERT INTO T2 VALUES (3, 1);
INSERT INTO T2 VALUES (3, 2);
INSERT INTO T2 VALUES (4, 1);

SELECT *
    FROM T1 A INNER JOIN T2 B
    ON B.C1 = A.C1
    WHERE A.C1 >= 2; -- A.C1가 2 이상이도 양쪽 테이블의 값이 일치하면 출력 (2, 3)

SELECT SUM(B.C2) AS R1
    FROM T1 A INNER JOIN T2 B
    ON B.C1 = A.C1
    WHERE A.C1 >= 2; -- 4

--- NATURAL JOIN

DROP TABLE T1;
CREATE TABLE T1 (C1 NUMBER, C2 VARCHAR(2));

INSERT INTO T1 VALUES (1, 'A');
INSERT INTO T1 VALUES (2, 'B');
INSERT INTO T1 VALUES (3, 'C');

DROP TABLE T2;
CREATE TABLE T2 (C1 NUMBER, C2 VARCHAR(2));

INSERT INTO T2 VALUES (1, 'A');
INSERT INTO T2 VALUES (1, 'B');
INSERT INTO T2 VALUES (2, 'B');
INSERT INTO T2 VALUES (3, 'C');
INSERT INTO T2 VALUES (3, 'A');
INSERT INTO T2 VALUES (4, 'B');

SELECT *
FROM T1 A NATURAL JOIN T2 B; -- 두 테이블의 교집합만 출력

SELECT SUM(C1) AS R1
FROM T1 A NATURAL JOIN T2 B; -- 6

SELECT * FROM T1 A INNER JOIN T2 B ON A.C1 = B.C1;
    -- INNER JOIN은 ON 절에 입력한 조건만 만족하면 모두 출력
SELECT * FROM T1 A NATURAL JOIN T2 B;
    -- 두 테이블의 C1컬럼과 C2컬럼의 값이 모두 일치하는지 비교 후 출력.

--

SELECT A.C1, B.C2
    FROM T1 A JOIN T2 B
    USING (C1);
    -- ORA-25154: USING 절의 열 부분은 식별자(A.)를 가질 수 없음

SELECT C1, B.C2
FROM T1 A JOIN T2 B
               USING (C1);
    -- 정상출력

SELECT *
FROM T1 A JOIN T2 B
    USING(C1);

-- RIGHT OUTER JOIN
DROP TABLE T1;
CREATE TABLE T1 (C1 NUMBER, C2 VARCHAR(2));

INSERT INTO T1 VALUES (1, 'A');
INSERT INTO T1 VALUES (2, 'B');
INSERT INTO T1 VALUES (3, 'C');
INSERT INTO T1 VALUES (4, 'D');

DROP TABLE T2;
CREATE TABLE T2 (C1 NUMBER, C2 VARCHAR(2));

INSERT INTO T2 VALUES (1, 'A');
INSERT INTO T2 VALUES (2, 'B');
INSERT INTO T2 VALUES (3, 'B');
INSERT INTO T2 VALUES (3, 'C');
INSERT INTO T2 VALUES (5, 'C');

-- LEFT OUTER JOIN
SELECT A.C1, B.C1
    FROM T1 A LEFT OUTER JOIN T2 B -- 오른쪽 테이블은 왼쪽 테이블에 대해 일치하는 행만, 왼쪽 테이블은 일치하는 행 모두 출력 + 일치하지 않는 행도 출력.
    ON B.C1 = A.C1
    AND B.C1 >= 3;

-- FULL OUTER JOIN
SELECT A.C1, A.C2, B.C1, B.C2
FROM T1 A FULL OUTER JOIN T2 B -- 일치 여부와 상관 없이, 일단 B테이블의 A테이블에 대한 OUTER JOIN 결과가 모두 출력되고,
      ON B.C1 = A.C1           -- A테이블의 나머지가 출력된다.
      AND B.C1 >= 3;

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

select a.고객번호, sum(b.주문금액) as 합계
    from 고객 a left outer join 주문 b
    on b."고객번호" = a."고객번호"
where a."고객번호" in (3, 4)
group by a.고객번호;

-- oracle, ANSI join expression test
select sum(x.주문금액)as 합계
from 주문 x, 고객 a
where x.고객번호 = a.고객번호
  AND a."고객번호" in (3, 4);

select sum(x.주문금액) as 합계
from 주문 x join 고객 a
               on x.고객번호 = a.고객번호
                   AND a."고객번호" in (3, 4);

SELECT a.고객번호,
       (select 12 from dual) as 합계
from 고객 a
where a."고객번호" in (3,4);
--

-- 2번 문제 NATURAL JOIN 식별자

select *
from T1 A NATURAL JOIN T2 B;
    -- # 에러 ORA-25155: NATURAL 조인에 사용된 열은 식별자를 가질 수 없음

-- 4번
drop table 주문;
create table 주문 (주문번호 number, 주문일시 date, 주문금액 number);

insert into 주문 values (1, TO_DATE(20200512142020, 'YYYY-MM-DD HH24:MI:SS'), 20000);
insert into 주문 values (2, TO_DATE(20200627000000, 'yyyy-mm-dd hh24:mi:ss'), 25000);
insert into 주문 values (3, TO_DATE(20200702123030, 'yyyy-mm-dd hh24:mi:ss'), 10000);
insert into 주문 values (4, TO_DATE(20200715170000, 'yyyy-mm-dd hh24:mi:ss'), 5000);
insert into 주문 values (5, TO_DATE(20200726235900, 'yyyy-mm-dd hh24:mi:ss'), 20000);
insert into 주문 values (6, TO_DATE(20200727123030, 'yyyy-mm-dd hh24:mi:ss'), 30000);
insert into 주문 values (7, TO_DATE(20200808090015, 'yyyy-mm-dd hh24:mi:ss'), 15000);

select *
from 주문
where 주문일시 between trunc(add_months(TO_DATE(20200727143000, 'YYYY-MM-DD HH24:MI:SS'), -1), 'DD')
AND TRUNC(TO_DATE(20200727143000, 'YYYY-MM-DD HH24:MI:SS'), 'DD');

select TRUNC(ADD_MONTHS(TO_DATE(20200727143000, 'YYYY-MM-DD HH24:MI:SS'), -1), 'DD') from dual;
select TRUNC(TO_DATE(20200727143000, 'YYYY-MM-DD HH24:MI:SS') -1/24/60/60, 'DD')  from dual;

-- 7번

drop table T1;
create table T1(C1 number, C2 varchar2(2), C3 number);

insert into T1 values (1, 'A', 1000);
insert into T1 values (2, 'B', 800);
insert into T1 values (3, 'A', NULL);
insert into T1 values (4, 'B', 1200);
insert into T1 values (5, 'C', 3000);
insert into T1 values (6, 'A', 1500);

select *
From T1
where C1 >= 4; -- C1이 4, 5, 6인 결과값

select *
From T1
where C2 IN ('A', 'B')
    AND C3 NOT BETWEEN 1000 AND 2000; -- B, 800

select *
From T1
where C1 >= 4
   or C2 IN ('A', 'B')
    AND C3 NOT BETWEEN 1000 AND 2000; -- 위 두 결과값을 합친 결과(OR 연산)

-- 11번 p92
drop table T1;
CREATE TABLE T1 (C1 NUMBER, C2 NUMBER);

INSERT INTO T1 VALUES (1, 1);
INSERT INTO T1 VALUES (2, 2);
INSERT INTO T1 VALUES (3, 3);
INSERT INTO T1 VALUES (4, 1);
INSERT INTO T1 VALUES (5, 2);

SELECT 6 - A.C1 AS C1,
       CASE
        WHEN A.C1 >=4 THEN 'A'
        WHEN A.C2 IN(1,3) THEN 'B'
        ELSE 'C'
    END AS C2
    FROM T1 A
    ORDER BY C2 DESC, A.C1;
-- ORDER BY의 기준이 C2인지, A.C2인지를 확인해야 한다.
-- 만약 C2와 A.C2

