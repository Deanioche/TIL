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

## - **NATURAL 조인에 사용된 열은 식별자를 가질 수 없음**

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
