# 관리 구문

**# DML**

**UPDATE**
```SQL
DROP TABLE T1;
CREATE TABLE T1 (C1 NUMBER, C2 NUMBER, C3 NUMBER);

INSERT INTO T1 VALUES (1, 1, 1);

DROP TABLE T2;
CREATE TABLE T2 (C1 NUMBER, C2 NUMBER, C3 NUMBER);

INSERT INTO T2 VALUES (2, 3 ,4);

UPDATE T1 A
    SET (A.C2, A.C3) = (SELECT X.C2, X.C3
        FROM T2 X
        WHERE X.C1 = A.C1); -- 1, NULL, NULL

UPDATE T1 A
    SET (A.C2, A.C3)
    = (SELECT X.C2, X.C3
        FROM T2 X
        WHERE X.C1 = A.C1) 
    WHERE EXISTS(SELECT 1 FROM T2 X WHERE X.C1= A.C1); -- 1, 1, 1

MERGE
    INTO T1 T
    USING T2 S
        ON (T.C1 = S.C1)
    WHEN MATCHED THEN -- T.C1 = S.C1이 TRUE면
    UPDATE SET T.C2 = S.C2,
            T.C3 = S.C3; -- 1, 1, 1
```

#
**DELETE**

```SQL
DELETE FROM T1 C1 NOT IN (SELECT C2 FROM T2);
```

- NULL이 반환되는 서브 쿼리에 NOT IN 조건을 사용했다. 
- NOT IN은 일치하는 데이터가 하나도 없는지를 확인하는 연산자다. 그런데 NOT IN 서브 쿼리가 반환하는 집합에 NULL이 있으면 메인 쿼리와 일치하는 데이터가 하나도 없는지, 참/거짓을 확인할 수 없게 된다. 따라서 NULL을 포함하는 NOT IN 서브 쿼리를 사용하면 `항상 공집합`을 반환한다. 서브쿼리와 일치하는 데이터가 하나도 없는지, 참/거짓을 확인할 수 없는 상태이므로 T1행은 하나도 삭제되지 않는다.

___

**# TCL**

- 트랜잭션의 네가지 특징. ACID
    - 원자성 : 트랜잭션의 작업은 `모두 수행되거나 모두 수행되지 않아야` 함.
    - 일관성 : 트랜잭션이 완료되면 `데이터 무결성`이 일관되게 보장되어야 함.
    - 고립성 : 트랜잭션이 `다른 트랜잭션`으로부터 고립된 상태로 수행되어야 함.
    - 지속성 : 트랜잭션이 완료되면 `장애가 발생하더라도` 변경 내용이 지속되어야 함.

- `COMMIT -> 지속성`

#

- 테이블
```SQL
CREATE TABLE T1 (C1 NUMBER);
INSERT INTO T1 VALUES (1);
COMMIT;
```

- S1 ,S2 오라클 세션이 존재.
- S1세션에서 UPDATE를 수행한 후 아직 COMMIT을 하지 않았으므로, S2 세션에서 UPDATE의 WHERE절 조건에 맞는 데이터가 없어, 실행되지 않는다.

- 만약 SQL Server라면
- S1세션의 UPDATE가 끝나길 기다렸다가 데이터의 값이 바뀐 사실을 확인하고 S2에서 UPDATE를 수행한다.

#

```SQL
CREATE TABLE T1 (C1 NUMBER);

INSERT INTO T1 VALUES(1);
INSERT INTO T1 VALUES(2);
ALTER TABLE T1 ADD C2 NUMBER; -- 암시적 COMMIT
INSERT INTO T1 VALUES (3, 3);
ROLLBACK;
```

- DDL문은 `암시적으로 COMMIT을 수행`한다.
- `ALTER TABLE T1 ADD C2 NUMBER` 구문은 암시적으로 COMMIT을 수행하므로 `INSERT INTO T1 VALUES (3, 3)` 구문만 `ROLLBACK` 된다.
- 따라서, T1 테이블의 전체 건수는 2건이다.

___

**# 에러가 발생하는 CREATE TABLE 구문**

```SQL
-- 에러
CREATE TABLE 1T (C1 NUMBER); 
CREATE TABLE T-1 (C1 NUMBER);
CREATE TABLE T 1 (C1 NUMBER);
```

```SQL
-- 정상 실행
CREATE TABLE T$1 (C1 NUMBER);
```

- 테이블 명은 `문자`로 시작해야 하며 `공백을 허용하지 않는다.`
- 특수 문자는 `#, $, _`만 사용할 수 있다.
- `큰따옴표(")`로 오브젝트 명을 감싸면 제약을 회피할 수 있으나 권장되지 않는다.

#

**# 데이터 타입의 크기 축소**

```SQL
CREATE TABLE T1 (C1 NUMBER(2));
INSERT INTO T1 VALUES (1);
COMMIT;

ALTER TABLE T1 MODIFY C1 NUMBER(1); -- 에러 발생
-- ORA-01440: 정도 또는 자리수를 축소할 열은 비어 있어야 합니다
ALTER TABLE T1 MODIFY C1 NUMBER(3);
ALTER TABLE T1 MODIFY C1 NOT NULL;
ALTER TABLE T1 MODIFY C1 NULL;
```
- `NUMBER 타입`은 이미 값을 하나라도 입력한 경우 데이터 타입의 크기를 `축소`할 수 없다.

#

**# 외래키로 연결되어 있는 테이블 DROP**

```SQL
CREATE TABLE T1 (C1 NUMBER, CONSTRAINT T1_PK PRIMARY KEY(C1));
CREATE TABLE T2 (C1 NUMBER, CONSTRAINT T1_FK FOREIGN KEY(C1) REFERENCES T1(C1));

ALTER TABLE T1 RENAME COLUMN C1 TO C2;
ALTER TABLE T2 RENAME COLUMN C1 TO C2;
DROP TABLE T1; --에러
-- ORA-02449: 외래 키에 의해 참조되는 고유/기본 키가 테이블에 있습니다
DROP TABLE T2;
```

- FK 제약조건에 의해 참조되는 테이블을 제거하려면 먼저 FK 제약 조건을 제거해야 한다.
- FK 제약을 명시적으로 제거하지 않고 아래처럼 CASCADE CONSTRAINTS 절을 지정하는 방법도 있다.

```SQL
DROP TABLE T1 CASCADE CONSTRAINTS;
```

#

**# PRIMAY KEY 와 UNIQUE의 차이**

- PRIMARY KEY 는 `UNIQUE 속성` + `NOT NULL`이다.`
- UNIQUE는 같은 값은 1개만 입력할 수 있지만 `NULL은 무한정` 입력할 수 있다.
- SQL Server는 UNIQUE에 NULL도 1개만 입력할 수 있다.

___

**# DCL**

```SQL
SQLPLUS U1/U1

ORA-01045: 사용자 U1는 CREATE SESSION 권한을 가지고 있지 않음; 로그온이 거절되었습니다.
```

- 사용자로 `로그인` 하기 위해서는 `CREATE SESSION 시스템 권한`이 필요한다. ORA-01045 에러는 접속 권한이 없어 로그인이 거절됐을 때 발생한다. SYS 또는 SYSTEM 사용자로 접속해서 아래 명령어로 권한을 부여하면 로그인이 가능하다.

```SQL
GRANT CREATE SESSION TO U1, U2;
```

#

**# 다른 사용자의 스키마에 테이블 생성 권한**
```SQL
-- U1 사용자
CREATE TABLE U2.T1 (C1 NUMBER);
-- 권한이 불충분합니다.

GRANT CREATE ANY TABLE TO U1;
-- 권한이 부여되었습니다.
```
- 다른 스키마에 테이블을 생성하기 위해서는 CREATE ANY TABLE 시스템 권한이 필요하다.
- 권한을 부여받지 않으면 기본적으로 자신의 스키마에만 테이블을 생성할 수 있다.

#

**# TABLESPACE 권한부여**

- U2 사용자
```SQL 
INSERT INTO T1 VALUES (1);
-- 테이블 스페이스 'USERS'에 대한 권한이 없습니다.

GRANT UNLIMITED TABLESPACE TO U2;
-- 권한이 부여되었습니다.
```

- 테이블에 행을 삽입하기 위해서는 테이블이 생성된 테이블스페이스에 대한 QUATA 설정이나, UNLIMITED TABLESPACE 시스템 권한이 필요하다.

```SQL
-- U2 계정에게 USERS 테이블스페이스에 대한 100MB 한도 설정
ALTER USER U2 QUOTA 100M ON USERS;

-- U2 계정에세 USERS 테이블스페이스에 대한 무제한 권한 설정
ALTER USER U2 QUOTA UNLIMITED ON USERS;

-- U2 계정에게 모든 테이블 스페이스에 대한 무제한 권한 부여
GRANT UNLIMITED TABLESPACE TO U2;
```

#

**# 테이블의 모든 권한 부여**
```SQL
GRANT ALL ON T1 TO U1;
```

- GRANT 명령어로 권한을 부여할 때 ON절에는 대상 오브젝트를 지정하고, TO절에는 대상 계정을 지정한다. `GRANT ALL ON T1 TO U1` 구문으로 U1 사용자에 T1 테이블의 모든 권한을 부여할 수 있다.

#

**# GRANT 할 수 없는 오브젝트 권한**

```SQL
GRANT ALTER ON T1 TO U1;
GRANT EXECUTE ON T1 TO U1; -- 에러
GRANT INDEX ON T1 TO U1;
GRANT REFERENCES ON T1 TO U1;
```

- EXECUTE 권한은 PL/SQL 오브젝트에 대한 권한이다. GRANT 문을 수행하면 에러가 발생한다.

#

**# 롤 생성**
```SQL
CREATE ROLL R1;
-- 롤이 생성되었습니다.

GRANT ALL ON T1 TO R1;
GRANT R1 TO U1;
```

___

**# 핵심 문제**

**# 1**
```SQL
DROP TABLE T1;
CREATE TABLE T1(C1 NUMBER, C3 NUMBER);

INSERT INTO T1 VALUES (1, 1);

DROP TABLE T2;
CREATE TABLE T2(C1 NUMBER, C2 NUMBER);

INSERT INTO T2 VALUES (1, 1);
INSERT INTO T2 VALUES (2, 1);
INSERT INTO T2 VALUES (3, 1);
INSERT INTO T2 VALUES (4, 1);

INSERT INTO T1
    SELECT A.C1, A.C2
    FROM T2 A
    WHERE NOT EXISTS (SELECT 1 FROM T1 X WHERE X.C1 = A.C1);

SELECT * FROM T1;
```
| C1 | C3 |
| :--- | :--- |
| 1 | 1 |
| 2 | 1 |
| 4 | 1 |
| 3 | 1 |

___

**# 2**

```SQL
DROP TABLE T1;
CREATE TABLE T1(C1 NUMBER, C2 NUMBER);

INSERT INTO T1 VALUES (1, 1);

DROP TABLE T2;
CREATE TABLE T2(C1 NUMBER, C2 NUMBER);

INSERT INTO T2 VALUES (1, 1);
INSERT INTO T2 VALUES (1, 2);
INSERT INTO T2 VALUES (1, 3);

UPDATE (SELECT A.C2 AS AC2, B.C2 AS BC2 
    FROM T1 A
        , (SELECT C1, MAX(C2) AS C2 FROM T2 GROUP BY C1) B -- (1, 3) B
    WHERE B.C1 = A.C1) -- 1 = 1로 1행 일치
SET AC2 = BC2; -- 1(AC2) <- 3(BC2)

SELECT * FROM T1;
```

| C1 | C2 |
| :--- | :--- |
| 1 | 3 |

- 가장안쪽 서브쿼리 결과 (1, 3) B
- 바깥 쿼리 AC2 = NULL, BC2 = 3
- SET AC2 = 3이 됨.
___

**# 3**
```SQL
DROP TABLE T1;
CREATE TABLE T1(C1 NUMBER, C2 NUMBER);

INSERT INTO T1 VALUES (1, 1);

DROP TABLE T2;
CREATE TABLE T2(C1 NUMBER, C2 NUMBER);

INSERT INTO T2 VALUES (2, 2); -- ORA-30926 에러 방지를 위해 (1,2) -> (2,2)로 바꿈
INSERT INTO T2 VALUES (2, 3); -- ORA-30926 에러 방지를 위해 (1,3) -> (2,2)로 바꿈
INSERT INTO T2 VALUES (1, 4);

MERGE
    INTO T1 T
    USING T2 S
    ON (T.C1 = S.C1) -- 이 조건에 해당하는 행이 여러개일 경우
    -- ORA-30926: 원본 테이블의 고정 행 집합을 가져올 수 없습니다 에러 발생
    WHEN MATCHED THEN
    UPDATE SET T.C2 = S.C2;
 --   WHEN NOT MATCHED THEN
--    INSERT VALUES (S.C1, S.C2);

SELECT * FROM T1; -- T1(1,1) T2(1,4) 일치하므로 C2가 바뀜 1 -> 4
```
___

**# 4**
- ㄴ UPDATE를 시작하는 시점에 C1 = 2인 레코드는 없으므로 실행X
- SQL SERVER라면 S2세션은 ㄱ UPDATE가 끝날때까지 기다렸다가 정상 실행된다.

- S2세션의 ㄷ UPDATE를 시작하는 시점에는 S1세션에서 C1이 1 -> 2로 변경되고 COMMIT된 시점으로
- ㄷ이 정상 실행된다. 2 -> 4
- S1의 ㄹ UPDATE는 현재 레코드의 LOCK 은 S2가 획득한 시점이므로 대기상태가 된다.
- S2 세션이 ROLLBACK되면 S1이 LOCK을 획득하고 ㄹ이 실행된다. C1 = 4 -> 2 -> 5
- 최종값은 5.

___

**# 5**
```SQL
DROP TABLE T1;
CREATE TABLE T1 (C1 NUMBER(1)); -- 데이터 크기 확인!!

DROP TABLE T2;
CREATE TABLE T2 (C1 NUMBER);

INSERT INTO T2 VALUES (8);
INSERT INTO T2 VALUES (9);
INSERT INTO T2 VALUES (10);
 COMMIT;

INSERT INTO T1 VALUES (7);
INSERT INTO T1 SELECT * FROM T2;
    -- ORA-01438: 이 열에 대해 지정된 전체 자릿수보다 큰 값이 허용됩니다.
DELETE FROM T1 WHERE C1 = 9;

SELECT * FROM T1; -- 7
```

**# 6**

- ㄴ이 블로킹 된 후 S1세션에서 COMMIT을 수행했으므로 S2 세션에서는 ORA-00001 : 무결성 제약 조건에 위배됩니다. 라는 에러가 발생한다. ㄹ은 블로킹 된 후 S2 세션에서 ROLLBACK을 수행했으므로 값이 입력된다.


**# 7**
- DELETE 문은 DML문, TRUNCATE문은 DDL문이다. DDL문은 암시적으로 COMMIT을 수행하기 때문에 ROLLBACK으로 값을 되돌릴 수 없다.

**# 8**
- CHAR 타입은 최대크기에 비해 입력된 값이 작아도 뒤쪽에 공백을 채워 남은 공간을 모두 사용한다.
- VARCHAR2 타입은 입력한 값을 그대로 저장한다.
- CHAR(2)는 2바이트 다 쓰고 VARCHAR(2)는  1바이트씩 써서 C1이 B일때(4바이트) C2는 D(4바이트)

**# 9**
- REVOKE ALL ON 'TABLE' FROM 'USER'

**# 10**
- CREATE ROLE
- DROP ROLE



 





