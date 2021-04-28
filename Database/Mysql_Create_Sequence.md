# Mysql에서 시퀀스 사용법

Oracle은 자체적으로 시퀀스 기능을 갖고 있어 편리하지만
Mysql은 시퀀스 기능이 존재하지 않으므로 사용하려면 직접 기능을 만들어야 한다.

## **시퀀스 생성 절차**
1. 시퀀스를 사용 할 테이블 생성

2. 시퀀스를 생성 할 프로시저 생성

3. 생성 한 시퀀스의 다음 값을 가져오는 함수 생성

4. 시퀀스를 생성 할 프로시저 실행

5. 최종적으로 nextval 사용


## **1. 시퀀스를 사용할 테이블 생성**

```sql
CREATE TABLE SEQUENCES
(
    NAME VARCHAR(32), 
    CURRVAL BIGINT UNSIGNED
)
    ENGINE = InnoDB;
```

시퀀스로 사용 할 테이블을 생성한다.  
`NAME = 시퀀스명, CURRVAL = 순서`

## **2. 시퀀스를 생성 할 프로시저 생성**

```sql
DELIMITER $$
    CREATE PROCEDURE `create_sequence` (IN the_name text)
    MODIFIES SQL DATA
    DETERMINISTIC
    BEGIN
        DELETE FROM sequences WHERE name = the_name;
        INSERT INTO sequences VALUES(the_name, 0);
   END;
```
IN으로 생성할 시퀀스의 이름을 받는다.  
이미 생성 되어있는 같은 이름의 시퀀스가 있다면, 시퀀스를 지우고 새로 생성한다.

## **3. 생성 한 시퀀스의 다음 값(nextVal)을 가져오는 함수 생성**
```sql
DELIMITER $$
    CREATE FUNCTION `nextval` (the_name VARCHAR(32))
    RETURNS BIGINT UNSIGNED
    MODIFIES SQL DATA
    DETERMINISTIC
    BEGIN
        DECLARE ret BIGINT UNSIGNED;
        UPDATE sequences SET currval = currval +1 WHERE name = the_name;
        SELECT currval INTO ret FROM sequences WHERE name = the_name LIMIT 1;
        RETURN ret;
   END;
```

오라클에서의 nextVal 기능이다.  
오라클은 `시퀀스명.nextval` 으로 하지만,
MySql은  `nextval('시퀀스명')`으로 사용할 수 있다.


## **4. 시퀀스를 생성 할 프로시저 실행**

```sql
CALL create_sequence('Test');
```

프로시저를 호출해서 Test 라는 이름의 시퀀스를 생성한다.  
Test라는 시퀀스에 0 값이 할당된다.

## **5. 최종적으로 nextval 사용**

```sql
SELECT nextval('Test') FROM DUAL
```
 
INSERT문을 사용할 때 nextval 함수를 사용하면 된다.
 
사용 예)
```sql
INSERT INTO USER_INFO
(
    NUM
  , USER_ID
)
VALUES
(
    (SELECT nextval('Test') FROM DUAL)
  , '아이디'
)
```

## **# 시퀀스에서 Test 삭제**
```sql
DELETE FROM sequences WHERE name = 'Test';
```

### 출처 : https://proudin.tistory.com/28