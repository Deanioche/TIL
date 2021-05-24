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

