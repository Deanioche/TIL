# **Makefile**

## **make = 파일 관리 유틸리티**
> 파일 간의 종속관계를 파악하여 **Makefile( 기술파일 )**에 적힌 대로 컴파일러에 명령하여 SHELL 명령이 순차적으로 실행될 수 있게 한다.

## **make 사용의 장점**
> - 각 파일에 대한 반복적 명령의 자동화로 인한 시간 절약.
> - 프로그램의 종속 구조를 빠르게 파악 할 수 있으며 관리가 용이.
> - 단순 반복 작업 및 재작성을 최소화.

s
## **규칙**

```Makefile
#Syntax
targets : prerequisites
	recipe
	…
```
- targets : 스페이스로 구분된 파일 이름들, 또는 와일드카드(*)를 사용할 수 있다.
    - 보통 규칙당 한개의 타겟을 사용.
- prerequisites : 스페이스로 구분된 파일 이름들
- recipe : 레시피 줄은 'TAB' 문자로 시작한다

## **# 패턴규칙**

```Makefile
#Syntax
%.o : %.c
	recipe…

#Example
$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
```

### **# 자동 변수**

- `$@` : 규칙의 목표 파일의 파일 이름입니다.
- `$<` : 첫 번째 의존성의 이름입니다.
- `$?` : 목표 파일보다 새로운 모든 의존성의 이름 (사이에 공백이 있음)입니다.
- `$^` : 모든 전제 조건의 이름입니다(사이에 공백이 있음).
- `$(@D)` : 후행 슬래시가 제거 된 대상 파일 이름의 디렉토리 부분입니다.






## **가짜 목표 파일(Phony target)**

[ref_docs](https://www.gnu.org/software/make/manual/make.html#Phony-Targets)

- **.PHONY**에 명시된 이름들은 파일명이 아닌 명령어로 보게 함.
- 이름이 같은 파일과 충돌 방지
- 성능 향상 효과

```Makefile
.PHONY: all bonus clean fclean re
```
