# Memo

**# DECODE 함수 써보기**
https://gent.tistory.com/227

#

**# OUTER JOIN 표시**
```sql
a.id = b.id (+) -- LEFT OUTER

A.id(+) = b.id  -- RIGHT OUTER
```

https://blog.edit.kr/entry/Oracle-%EC%BF%BC%EB%A6%AC%EC%A4%91%EC%97%90-%EC%9D%98-%EC%9D%98%EB%AF%B8

#

**# USING 절 에러**
```SQL
SELECT A.C1, B.C2
    FROM T1 A JOIN T2 B
    USING (C1);
    -- # 에러 ORA-25154: USING 절의 열 부분은 식별자(A.)를 가질 수 없음
```

#

## - **`NATURAL 조인에 사용된 열은 식별자를 가질 수 없음`**

- NATURAL JOIN에 사용된 열은 식별자(A. B.)을 가질 수 없음!!

```sql

select A.C1, B.C1
from T1 A NATURAL JOIN T2 B;
    -- # 에러 ORA-25155: NATURAL 조인에 사용된 열은 식별자를 가질 수 없음
```

- 테이블 A와 B에 각각 C1과 C2 컬럼이 있지만, natural join은 그 모든 컬럼을 비교해 합치므로 결과는 C1, C2 컬럼 `하나씩만` 출력된다.
- 그러므로 컬럼은 `식별자를 가질 수 없다`.

#

**# 조건 우선순위**
|우선순위|조건|
|--|--|
|1|연산자|
|2|비교조건 (=, <>, >, <, >=, <=)|
|3|IN 조건, LIKE 조건, BETWEEN 조건, NULL 조건|
|4|논리조건(NOT)|
|5|`논리조건(AND)`|
|6|논리조건(OR)|

#

## `# AVG(C1 + C2)`
- 우선 행별로 C1 + C2 연산이 이루어 진다.
- 여기서 어느 한쪽이 NULL이면 결과값은 NULL.
- AVG(모든 결과값)을 하면 결과값이 NULL인 행은 연산에서 제외되므로
- NULL이 아닌 행들의 평균값이 나온다. (NULL행은 평균값 계산의 나눗셈에서도 제외된다.)

#

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

#
