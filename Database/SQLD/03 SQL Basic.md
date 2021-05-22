# SQL 기본

## **관계형 데이터베이스**

**# SQL 문의 종류**

SQL문은 
- DML문 (Data Manipulation Language, 데이터 조작어)
- TCL 문 (Transaction Control Language, 트랜젝션 제어어)
- DDL 문 (Data Definition Language, 데이터 정의어)
- DCL 문 (Data Control Language, 데이터 제어어)  
으로 구분된다.

|종류|구분|설명|
|--|--|--|
|DML 문|SELECT, INSERT, UPDATE, DELETE, MERGE| 테이블에 저장된 데이터를 조작(조회, 입력, 수정, 삭제)하기 위한 구문|
|TCL 문|COMMIT, ROLLBACK, SAVEPOINT|DML문에 의한 데이터의 변경 사항을 데이터베이스에 영구히 반영하거나 취소하기 위해 트랜잭션을 제어하는 구문|
|DDL 문|CREATE, ALTER, DROP, RENAME, TRUNCATE|테이블, 인덱스와 같은 데이터베이스 오브젝트의 구조를 정의(생성, 변경, 삭제)하기 위한 구문|
|DCL 문|GRANT, REVOKE|데이터에 대한 권한을 부여하거나 취소하기 위한 구문|

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

