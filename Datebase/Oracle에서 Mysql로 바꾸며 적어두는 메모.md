# Oracle에서 Mysql로 바꾸며 적어두는 메모

## 1. mybatis Mapper.xml 파일들 수정

오라클에서는 테이블명만 적어주면 되었지만
Mysql에선 테이블명 앞에 사용하는 db명도 적어줘야 한다.  
`use webboard_db;` 라고 했으면

```sql
	<update id="initiateServer">
		update webboard_db.server set start_count = start_count + 1 where SERVER_NAME = 'simple'
	</update>

	<select id="print_server_count" resultType="int">
		select start_count from webboard_db.server where SERVER_NAME = 'simple'
	</select>
```
이렇게 표기해야 한다.

<br>
<br>

## 2. 갑자기 프로젝트 내의 클래스들을 import 못하는 오류
 `Cannot resolve symbol ${className}`  
 - 해결법  
 IntelliJ의 메뉴에서 `File → Invalidate Caches / Restart…`
 ##### 참조 : https://jsonobject.tistory.com/256

<br>
<br>

## 3. java.sql.SQLSyntaxErrorException: Unknown database '{Database 이름}'
사용할 DB명을 찾을수 없다는 오류.

applicationContext.xml의 DataSource Bean이나 db.properties 파일안에 입력해둔 url부분에 

`jdbc.url=jdbc:mysql://localhost:3306/webboard_db?useSSL=false&useUnicode=yes&characterEncoding=utf8&serverTimezone=Asia/Seoul`

포트 뒤 `webboard_DB`가 사용할 DB 이름이다.
이게 mysql에서 `use {DB이름}` 로 지정해둔 DB명과 일치하지 않으면 위와같은 에러가 발생한다.