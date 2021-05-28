**# ANSWER**

___

01. 데이터 독립성을 위한 ANSI/SPARK의 3단계 스키마 구성
    - 내부 스키마
    - 개념 스키마
    - 외부 스키마

- Peter chen  데이터 모델 표기법
    - 마름모로 관계 표시

- 발생 시점에 따른 엔터티 분류
    - 기본 엔터티
    - 중심 엔터티
    - 행위 엔터티

___

02. 엔터티의 특징
    - 업무에서 필요로 하는 정보.
    - 유일한 식별자로 식별 가능.
    - 연속적으로 존재하는 2개이상의 인스턴스 집합.
    - `업무 프로세스에 의해 이용`.
    - 속성이 존재.
    - 다른 엔터티와 1개 이상의 관계를 가짐.

- 관계 속성은 자식 엔터티에 생성되므로, `모든` 엔터티에 관계 속성이 `존재하지는 않음`

- `주 식별자`의 특징
    - 반드시 부모 엔터티의 식별자를 상속받을 필요는 없다.
    - 업무적으로 변하면 안된다.

- **슈퍼키**
    - 기본키(PK) < 후보키(CK) < 슈퍼키
    - 기본키가 되지 않은 후보 키들은 대리 키(AK)가 된다.
    - 후보 키의 조건
        - 유일성, 최소성
        - 조건에 맞지 않으면 `슈퍼키`

- 일반 집합 연산자
    - SELECT 연산은 `WHERE 절`이다.
    - PROJECT 연산은 `SELECT 절`이다.
    - JOIN 연산은 다양한 조인 문법               
    - DIVIDE 연산은 사용 X

___

03. **BARKER 표기법**
    - 부모 엔터티 기준으로 자식 엔터티를 `필수 관계`로 정의할 때 부모 쪽 관계선을 `실선`으로 표기.
    - 자식 엔터티 기준으로 부모 엔터티를 `필수 관계`로 정의할 때는 자식 쪽 관계선을 `실선`으로 표기하며, `선택 관계`로 정의할 때는 자식 쪽 관계선을 `점선`으로 표기한다.
    - 부모엔터티으 `식별자(PK)`를 자식 엔터티의 `식별자(FK)`로 상속하면 '식별관계', 일반속성으로 상속하면 '비식별관계'라고 하며, `식별관계`로 정의하고자 할 때 `자식 쪽` 관계선에 `UID BAR 수직 실선`을 표시한다.
    - 필수속성 *
    - 선택속성 o
    - 자식 쪽 관계선이 `점선`이면 부모 엔터티와 `선택관계`란 뜻이므로, 부모 없이 자식 인스턴스만 등록할 수 있다. (FK 컬럼에는 NULL 입력)
#

03-1. **상호배타적 관계**
    -  

___

04. **IE 표기법**
    - 관계선 전체를 `실선`으로 표기하면 `식별 관계`, `점선`으로 표기하면 `비식별 관계`
    - 관계선에 O 표시는 그쪽 은 반대편에게 있어서 선택관계란 뜻이다.
    
___

05. 정규화
    - 주문 엔터티의 고객명 속성을 일반 속성일 고객번호 속성에 종속적이다.
    - 주식별자가 아닌 `일반 속성에 종속적`이므로 3 정규형을 위반한 엔터티이다.
    
___
06. 관계를 고려한 트랜잭션 구현
    - `자식 -> 부모 필수관계`라면, 부모 레코드를 `먼저` 입력해야 한다.
    - `부모 -> 자식도 필수관계`라면, 부모와 자식 레코드 입력을 `한 트랜잭션`으로 묶어서 처리해야 한다.
    - 두번째 자식 레코드부터는 개별적으로 입력 가능.

___
07. NULL 속성
    - IS NULL, IS NOT NULL을 제외하고는
    - = NULL, <>NULL, != NULL등 수식연산은 UNKNOWN을 반환.

    

```SQL
SELECT * FROM EMP
    WHERE DEPTNO = DECODE(NULL, NULL, 20, NULL);

SELECT * FROM EMP
    WHERE DEPTNO = NVL(NULL, DEPTNO);
-- 이 두 쿼리는 NULL 입력시 부서가 NULL인 사원은 출력하지 못한다.
-- 부서가 NULL인 사원도 출력하려면, 입력된 값이 NULL일때와 아닐때, 총 두가지 조건을 걸어야 한다. P192 ㄷ, ㄹ
```
___
08. 함수
    - DECODE(DEPTNO, NULL, 20, 30);
        - DEPTNO가 NULL이면 20, 아니면 30을 반환.

    - REPLACE()
        - REPLACE(A, B, C) -> A 안의 B를 C로 치환
        - REPLACE(A, B) -> A 안의 B를 NULL로 치환

    - COALESCE(N , M, ..., Z)
        - N~ Z 까지 보며 가장 먼저 나오는 NULL이 아닌 값을 리턴
        - N ~ Z의 타입은 같아야 함.
    
    *  비교하는 데이터 형은 일치 시켜야함, 아니면
'ORA-00932 데이터 유형이 일치하지 않습니다' 와 같이 에러가 나옴

ex) 'a1' 이 숫자형일 경우
- COALESCE(a1, 'none')  --> 'error'
- COALESCE(TO_CHAR(a1), 'none')  --> 'OK'

ex) 'b1' 이 문자형일 경우
- COALESCE(b1, 0)  --> 'error'
- COALESCE(b1, '0')  --> 'OK'
    
    - NULLIF(N, M)
        - 두 인자가 같으면 NULL 아니면 N을 리턴
        - 두 인자의 타입은 같아야함

    - TRIM (LEADING 왼쪽부터 , TRAILING 오른쪽부터 트림, BOTH 양쪽 (기본))

    - DISTINCT
        - SELECT DISTINCT * ~ 일 경우
        - 출력되는 `모든 컬럼`이 중복되는 행이 존재해야 중복제거가 된다.

    - NTILE(N)
        - 출력되는 행들을 순서대로 N개 그룹으로 나눠 1부터 N까지 반환한다.
___

09. DATE
    - TODAY = '2020-06-19' 일 때,
    - TO_CHAR(TODAY, 'MM') => '06' (CHAR)
    - EXTRACT(MONTH FROM TODAY) => 6 (NUMBER)

```SQL
DROP TABLE T1;
CREATE TABLE T1 (C1 DATE);

INSERT INTO T1 VALUES ('20200930');

SELECT C1 + 0 - TO_DATE('20200801') FROM T1; -- 60
SELECT C1 + 0 - TO_DATE('20200901') FROM T1; -- 29
SELECT C1 + 2 - 5 FROM T1; -- 27
```




10. LIKE
    - 패턴일치조건
    - `%` 0개 이상의 문자와 일치
    - `_` 하나의 문자와 일치

    - LIKE `'A_C%'`인 조건은
        - 첫번째 글자가 A
        - 세번째 글자가 C
        - 그 뒤로 0개이상의 무슨 문자가 나오든 상관하지 않음.
        - 조건에 맞을시 TRUE 반환
        - 같은 'A_C%'와 비교해도 TRUE를 반환한다. (WHERE 'A_C%' LIKE 'A_C%' = TRUE)

    - ESCAPE 문자 지정
    ```SQL
    SELECT * FROM T1
    WHERE C2 LIKE '1_\%%'ESCAPE '\';
    ```
    - 첫번째 문자 1
    - 세번째 문자 %
    - 뒤로 0문자 이상

#

```SQL
SELECT REGEXP_SUBSTR('12AB34CD', '[A-Z]+$') AS C1 FROM DUAL; -- CD
```
- [A-Z]는 영문 대문자,
- `+`는 1회 또는 그 이상의 횟수로 일치,
- `$`는 문자열의 끝을 의미하므로
- 이 표현식에 일치하는 문자는 `CD`이다.

#

```SQL
SELECT REGEXP_SUBSTR('AABABCABCD', '(AB)C\1') AS C1 FROM DUAL; -- ABCAB
```
- 첫 번째 일치한 표현식이 AB이고, C 이후에 첫 번째 일치한 표현식을 AB 일치하므로 ABCAB가 일치한다.


___

11. GROUP BY

- 집계함수 (COUNT)를 GROUP BY 없이 쓰면 항상 결과를 반환한다.
- `따라서 EXISTS(SELECT COUNT(*) ~)는 FALSE가 되지 않는다.`

```SQL
SELECT DEPTNO, SUM(SAL)
 FROM EMP
    GROUP BY DEPTNO, JOB;
-- GROUP BY에 입력한 컬럼을 모두 입력하지 않아도 됨.

SELECT TO_CHAR(HIREDATE, 'YYYY'), SUM(SAL)
FROM EMP
GROUP BY HIREDATE;
-- GROUP BY에 입력한 컬럼을 SELECT에서 가공해서 출력해도 됨.

SELECT HIREDATE, SUM(SAL)
FROM EMP
GROUP BY TO_CHAR(HIREDATE, 'YYYY');
-- GROUP BY에 가공한 컬럼을 입력하면 SELECT 에도 똑같이 가공해주어야 한다.
SELECT TO_CHAR(HIREDATE, 'YYYY'), SUM(SAL)
FROM EMP
GROUP BY TO_CHAR(HIREDATE, 'YYYY');
```

- GROUP BY에 이용한 컬럼을 SELECT에 모두 입력할 필요는 없지만, 
- GROUP BY에 입력한 컬럼이 가공되었으면 SELECT 쪽도 똑같이 가공되어야 한다.

___

12. ORDER BY

- NUMBER는 숫자의 크기로 비교
- 문자열은 문자의 `아스키코드` 크기로 비교 A(65) < B(66)

- CASE로 순서랭크 지정이 가능하다.

```SQL
SELECT C1, RTRIM(C2, 'Z'), C2 FROM T1 ORDER BY CASE
    WHEN C1 <= 2 THEN 'B' -- B 1, 2
    WHEN C1 > 4 THEN 'A' -- 5 A
    ELSE 'C' -- 3,4
        END ; -- CASE로 순서랭크 지정이 가능!!
```

___

13. `NOT EXISTS, NOT IN`

    - SELECT 1, 2, 3 WHERE NOT EXISTS (1, NULL) = 2, 3
    - SELECT 1, 2, 3 WHERE NOT IN (1, NULL) = NaN

    - EXISTS는 NULL의 존재유무를 비교할 수 있지만
    - `IN`은 조건에 NULL이 들어가면 NULL과 비교하는 값은 `UNKNOWN`이 나온다.
    
___
14. GROUPING SETS
    - ROLLUP()
    - CUBE()

```SQL
SELECT C1, C2, SUM(C3) AS C3
FROM T1
GROUP BY GROUPING SETS (C1, ())
ORDER BY 1;
-- ORA-00979: GROUP BY 표현식이 아닙니다.

SELECT C1, C2, SUM(C3) AS C3
FROM T1
GROUP BY GROUPING SETS (C1, C2);
-- C1 그룹 먼저 출력 후 C2 순서로 출력, 총합x
```
| C1 | C2 | C3 |
| :--- | :--- | :--- |
| B | NULL | 2 |
| C | NULL | 2 |
| A | NULL | 2 |
| NULL | 2050-01-01 00:00:00 | 3 |
| NULL | 2050-01-02 00:00:00 | 3 |

```SQL
SELECT C1, C2, SUM(C3) AS C3
FROM T1
GROUP BY GROUPING SETS (ROLLUP (C1, C2));

-- C1 그룹별로 합계와 함께 출력 후 마지막에 총합 출력
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
| NULL | NULL | 6 |

```SQL
SELECT C1, C2, SUM(C3) AS C3
FROM T1
GROUP BY GROUPING SETS (ROLLUP (C2, C1));

-- C2 그룹별로 합계와 함께 출력 후 마지막에 총합 출력
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
| NULL | NULL | 6 |

```SQL
SELECT C1, C2, SUM(C3) AS C3
FROM T1
GROUP BY GROUPING SETS (C1, ROLLUP (C2));
-- C1그룹 먼저 출력 후 C2그룹, 총 합계 출력
```
| C1 | C2 | C3 |
| :--- | :--- | :--- |
| B | NULL | 2 |
| C | NULL | 2 |
| A | NULL | 2 |
| NULL | 2050-01-01 00:00:00 | 3 |
| NULL | 2050-01-02 00:00:00 | 3 |
| NULL | NULL | 6 |

```SQL
SELECT C1, C2, SUM(C3) AS C3
FROM T1
GROUP BY GROUPING SETS (C2, ROLLUP (C1));

-- C2 그룹 먼저 출력 후 C1, 합계 순
```
| C1 | C2 | C3 |
| :--- | :--- | :--- |
| NULL | 2050-01-01 00:00:00 | 3 |
| NULL | 2050-01-02 00:00:00 | 3 |
| A | NULL | 2 |
| B | NULL | 2 |
| C | NULL | 2 |
| NULL | NULL | 6 |

```SQL
SELECT C1, C2, SUM(C3) AS C3
FROM T1
GROUP BY GROUPING SETS (CUBE (C1, C2));

-- C1 정렬되어 출력, C1 합계출력, C2 그룹별 합계 출력, C1그룹별 합계 출력
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
| NULL | 2050-01-02 00:00:00 | 3 |
| NULL | 2050-01-01 00:00:00 | 3 |
| A | NULL | 2 |
| B | NULL | 2 |
| C | NULL | 2 |

```SQL
SELECT C1, C2, SUM(C3) AS C3
FROM T1
GROUP BY GROUPING SETS (CUBE (C2, C1));
-- C2 정렬되어 출력, C1 그룹별 합계 출력, 총 합계 출력, C2 그룹별 합계 출력
```
| C1 | C2 | C3 |
| :--- | :--- | :--- |
| A | 2050-01-01 00:00:00 | 1 |
| B | 2050-01-01 00:00:00 | 1 |
| C | 2050-01-01 00:00:00 | 1 |
| A | 2050-01-02 00:00:00 | 1 |
| B | 2050-01-02 00:00:00 | 1 |
| C | 2050-01-02 00:00:00 | 1 |
| A | NULL | 2 |
| B | NULL | 2 |
| C | NULL | 2 |
| NULL | NULL | 6 |
| NULL | 2050-01-01 00:00:00 | 3 |
| NULL | 2050-01-02 00:00:00 | 3 |

#

**GROUPING_ID**

- GROUPING_ID 함수는 GROUPING 함수의 결과 값을 연결한 값의 비트 벡터에 해당하는 숫자 값을 반환.
- 해당 행의 해당 컬럼에 NULL이 존재하면 1, NULL이 아니면 0.
- GROUPING_ID(C1, C2) 처럼 행이 여러개일시 한 행마다 한자리수씩 가진다.

#
- GROUPING_ID(C1, C2) 에서
- C1,C2 둘다 NULL일시, 11 -> 3(이진법)
- C1이 NULL, C2는 값이 존재하면, `01 -> 1`(반대로 읽힌다.)
- C2가 NULL, C1은 값이 존재하면, `10 -> 2`(반대로 읽힌다.)
- 반대로
- GROUPING_ID(C2, C1) 이면 각각
- (NULL, NULL) -> 3
- (NOT NULL, NULL) 10 -> 2
- (NULL, NOT NULL) 01 -> 1
#

```SQL
SELECT C1, C2, SUM(C3) AS C3, GROUPING_ID(C2,C1)
FROM T1
GROUP BY GROUPING SETS (ROLLUP (C1, C2))
ORDER BY 1;
```

| C1 | C2 | C3 | GROUPING\_ID\(C2,C1\) |
| :--- | :--- | :--- | :---: |
| A | 2050-01-01 00:00:00 | 1 | 0 |
| A | 2050-01-02 00:00:00 | 1 | 0 |
| A | NULL | 2 | 2 |
| B | 2050-01-01 00:00:00 | 1 | 0 |
| B | 2050-01-02 00:00:00 | 1 | 0 |
| B | NULL | 2 | 2 |
| C | 2050-01-01 00:00:00 | 1 | 0 |
| C | 2050-01-02 00:00:00 | 1 | 0 |
| C | NULL | 2 | 2 |
| NULL | NULL | 6 | 3 |

___

15. OVER ()

- 그룹함수 뒤에 OVER() 붙여서 GROUP BY를 쓸 필요 없이 출력할 컬럼을 입력 할 수 있다.
- MAX(SAL) OVER () 는 파티션을 지정하지 않았으므로 전체 데이터의 최대값을 반환.
- MIN(SAL) OVER (PARTITION BY JOB) 이므로 JOB 그룹의 SAL 최소값 반환.

___

16. CONNECT_BY_ISLEAF

- CONNECT_BY_ISLEAF 슈도 칼럼은 현재 노드가 리프 노드인 경우 1, 아니면 0을 반환
- 리프 노드 : 가장 하위 노드

```SQL
SELECT COUNT (*) AS CNT FROM EMP
    WHERE CONNECT_BY_ISLEAF = 1
    START WITH ENAME = 'JONES'
    CONNECT BY MGR = PRIOR EMPNO; -- 2
```
- 가장 하위 노드가 2개이므로

___

17. UNPIVOT

FOR (UNPIVOT 할 컬럼) IN ((컬럼1, 컬럼2, ...) AS (별칭1, 별칭2, ...))

___

18. REGEXP_INSTR 함수

- 조건에 일치하는 문자의 시작위치 인덱스 반환

<img src="https://user-images.githubusercontent.com/66513003/119948704-10289880-bfd4-11eb-8482-f0ed3126e8b3.png" width="400">

```
$       : 문자열의 끝 부분과 일치. 매칭 파라미터의 m 옵션이 활성화되면 표현식을 사용하는 모든 행의 끝과 일치
*       : 0개 이상 (zero or more) 일치
+       : 하나 이상 (one or more) 일치
?       : 0 또는 1개 일치 (zero or one)
.       : NULL을 제외한 모든 문자와 일치
| (파이프) : OR
[ ]     : [ ]에 있는 문자 중 하나를 일치시키려는 목록을 지정
[^ ]    : [ ]에 있는 문자를 제외한 모든 문자를 일치시키려는 리스트 지정 
( )     :표현식을 하위 표현식으로 그룹화하는데 사용
{m}     :m번 일치
{m,}    :적어도 m번 일치
{m,n}   :적어도 m번 일치 ~ n번 이하 일치
\n      :() 번째 하위 표현식과 일치
[..]    :하나 이상의 문자가 될 수 있는 하나의 집합요소와 일치
[::]    :문자 클래스와 일치. [:digit:], [:punct:], [:alpha:] 등
[==]    :equivalence 클래스와 일치
\d      :숫자와 일치
\D      :숫자가 아닌 것과 일치
\w      :영문자 숫자 밑줄문자(_) 와 일치
\W      :영문자 숫자 밑줄문자(_) 이외의 문자와 일치
\s      :공백문자와 일치
\S      :공백이 아닌 문자와 일치
\A      :문자열의 시작 부분과 일치, 혹은 새 행의 문자 앞에 있는 문자열의 끝 부분과 일치
\Z      :문자열의 끝과 일치
*?      :앞선 패턴이 0번 이상 발생
+?      :앞선 패턴이 한 번 이상 발생
??      :앞선 패턴이 0 또는 1번 발생
{n}?    :앞선 패턴이 n번 일치
{n,}?   :앞선 패턴이 적어도 n번 일치
{n,m}?  :앞선 패턴이 적어도 n번 ~ m번 이하 일치
```

REGEXP(검색문자열, 검색패턴, 검색시작위치(기본1), 패턴일치횟수(1), 반환 옵션(0), 일치 옵션, 서브표현식)

- 검색시작위치
    - 검색 문자열이 'abc'이면 a부터 검색

- 패턴일치횟수
    - 1이면 패턴에 일치하는 첫번째 결과 반환

- 반환 옵션
    - 0 발생한 첫 문자의 위치를 반환 (기본값)
    - 1 발생한 것의 다음 문자 위치를 반환
- 일치 옵션
    - i : 대소문자 구별하지 않음
    - c : 대소문자 구별
    - n : . 는 새줄문자와 일치
    - m : 다중라인 소스 문자열 처리 ^$로 시작과 끝을 해석

- 서브표현식
    - 0은 전체 패턴 (기본값)
    - 1 이상은 서브 표현식의 위치
        - REGEXR_STRIN('010-9234-5678', '(\d+)-(\d+)-(\d+)', 1, 1, 0, 'i', n )(n = 서브표현식) 일경우 
        - 괄호로 인해 3개의 그룹으로 나뉘므로
        - 1 => 첫번째 그룹('010')의 위치 = 1
        - 2 => 두번째 그룹('1234')의 위치 = 5
        - 3 => 세번째 그룹('2345')의 위치 = 10

___

ORA-01779 : 키-보존된 것이 아닌 테이블로 대응한 열을 수정할 수 없음.
```SQL
UPDATE( SELECT A.C2 AS AC2, B.C2 AS BC2
    FROM T1 A, T2 B
    WHERE B.C1 = A.C1)
    SET AC2 = BC2;
```
- SET AC2 = BC2; 이므로
- T1 테이블 (A)에 T2 테이블 (B)를 조인하는 거니까
- T2테이블에 PRIMARY KEY를 지정해주어야 한다.

```SQL
ALTER TABLE T2 ADD CONSTRAINT T2_PK PRIMARY KEY (C1);
```

___

**SAVEPOINT**

- SAVEPOINT는 ROLLBACK 하면 이후 SAVEPOINT도 모두 사라진다.

- SAVEPOINT 1, 2, 3이 있을때, 1로 ROLLBACK 하면 2,3은 사라진다.

___

**PK 제약**
- PK 제약이 설정된 컬럼에 여러 세션이 동시에 같은 값을 입력하려고 하면, 후행 트랜잭션이 블로킹된다.
- 그 상황에서 선행 트랜잭션이 COMMIT 하면 후행 트랜잭션의 입력은 에러를 만나면서 실패로 끝나고, 
- ROLLBACK 하면 후행 트랜잭션의 입력은 성공한다.

___

**VARCHAR2 타입**
- 이 타입은 이미 값을 입력했더라도 데이터 타입의 크기를 축소할 수 있다.
- 단, 축소하련느 그키가 가장 큰 입력 값도가 크거나 같아야 한다.
- NULL 허용여부는 반대로만  (NULL <-> NOT NULL)변경할 수 있다.
- 테이블을 생성할 때 제약조건을 입력하지 않으면 기본값이 (NULL)이므로
- ORA-01451 열이 이미 NULL로 되어 있습니다 에러가 발생한다.

___

**BYTE, CHAR**

- BYTE는 `바이트`, CHAR는 `글자 수`로 지정한다.
- BYTE(1)과 CHAR(1)로 생성한 테이블에 각각 한글 '가'를 입력하면,
- BYTE는 오류, CHAR는 입력에 성공한다.

___

**CROSS JOIN**
```SQL
DROP TABLE T1;
CREATE TABLE T1 (C1 NUMBER, C2 VARCHAR2(2));

INSERT INTO T1 VALUES (1, 'A');
INSERT INTO T1 VALUES (2, 'B');
INSERT INTO T1 VALUES (3, 'C');
INSERT INTO T1 VALUES (4, 'D');

DROP TABLE T2;
CREATE TABLE T2 (C1 NUMBER, C2 VARCHAR2(2));
S
INSERT INTO T2 VALUES (2, 'B');
INSERT INTO T2 VALUES (2, 'B');
INSERT INTO T2 VALUES (3, 'C');
INSERT INTO T2 VALUES (5, 'C');

SELECT COUNT (DISTINCT A.C1) AS CNT1, COUNT (B.C2) AS CNT2
    FROM T1 A CROSS JOIN T2 B;

SELECT A.C1, A.C2 , B.C1, B.C2
FROM T1 A CROSS JOIN T2 B;
```

- CROSS JOIN 은 조건없이 왼쪽 테이블 행수 X 오른쪽 테이블 행수 로 총갯수가 나온다. 4 X 4 = 16
- DISTINCT하면 테이블의 본래 행수가 나온다. 4

___

# FULL OUTER JOIN
    - 일단 조인이 되는건 조인시키고 남은 나머지들도 모두 포함시킨다.
    - P289 23번

____
**수행결과가 같거나/다른 SQL 문제에서**
- B <- A 조인인지
- A <- B 조인인지 확인할것!!

**X.C1 = C1**
- 서브쿼리에서 위 식은
..........0.......... 항상 TRUE
- 확인할 것!!!!

___ 


**# SORT가 발생하지 않는 연산자**
- UNION ALL
    - 이 연산자는 중복을 제거하거나 교집합을 구하지 않고 단순히 나열 순서대로 두 집합을 연결하믑로 `소트가 발생하지 않는다.`

- UNION, MINUS, INTERSECT 는 SORT 발생.

___

**DENSE_RANK**
- 동순위 부여 후 다음 건너뛰지 않고 바로 다음 랭크가 나옴.

**RANK**
- 동순위 부여 후 다음 랭크 건너 뜀.


___

**LEVEL**

- 최상위 레벨은 1.

___
**MERGE**
```SQL
DROP TABLE T1;
CREATE TABLE T1 (C1 NUMBER, C2 NUMBER);
INSERT INTO T1 VALUES (1, 1);
INSERT INTO T1 VALUES (2, 1);
INSERT INTO T1 VALUES (3, 1);
MERGE
INTO T1 T
USING T2 S
ON (S.C1 = T.C1)
WHEN MATCHED THEN
    UPDATE SET T.C2 = S.C2 WHERE S.C2 > 2
    DELETE WHERE T.C2 < 3
WHEN NOT MATCHED THEN
    INSERT (T.C1, T.C2) VALUES ( S.C1, S.C2 ) WHERE S.C2 > 4;
SELECT * FROM T1;
```

UPDATE나 INSERT가 된거만 DELETE가 됨.
   

___

DROP COLOUM이 테이블 크기가 크면 시간이 오래 걸린다.

___

**NUMBER**
- NUMBER(5, 2) 에서 (5 - 2)는 정수부 2는 소수부이다.
- 정수부는 5에서 소수부를 뺀 값이다.
- NUMBER(5, 2) 는 -999.99 ~ 999.99 의 범위
- NUMBER(2, 5) 는 -0.00099 ~ 0.00099의 범위

___

**나눗셈에서 `정수`를 구하는 문제**
 - TRUNC()로 감싸 주어야 소수가 출력이 안된다.
 - TRUNC(15000/ 2000)
    
___
**LNNVL**

 WHERE LNNVL(COMM IS NULL)
/* WHERE COMM IS NOT NULL 과 동일 */

 WHERE LNNVL(DEPTNO = 10)
/* DEPTNO가 10이 아닌 부서만 출력. 즉, WHERE DEPTNO NOT IN (10) 과 같음 *

___

사용자로 `로그인` 하기 위해서는 `CREATE SESSION 시스템 권한`이 필요한다. ORA-01045 에러는 접속 권한이 없어 로그인이 거절됐을 때 발생한다. 

```SQL
GRANT CREATE SESSION TO U1, U2;
GRANT CONNECT TO U3;
```

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