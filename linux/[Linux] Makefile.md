# **Makefile**

## **make = 파일 관리 유틸리티**
> 파일 간의 종속관계를 파악하여 **Makefile( 기술파일 )**에 적힌 대로 컴파일러에 명령하여 SHELL 명령이 순차적으로 실행될 수 있게 한다.

## **make 사용의 장점**
> - 각 파일에 대한 반복적 명령의 자동화로 인한 시간 절약.
> - 프로그램의 종속 구조를 빠르게 파악 할 수 있으며 관리가 용이.
> - 단순 반복 작업 및 재작성을 최소화.


# **규칙**

![image](https://user-images.githubusercontent.com/66513003/146716927-23d953de-c808-4417-82a9-d51b1fa3d6ea.png)

```Makefile
# 메이크파일의 주석 : #부터 다음 개행까지는 주석으로 처리됩니다.
# 목표 파일 과 의존성 사이에는 ':'이 와야합니다.
# 레시피는 반드시 수평탭을 통한 들여쓰기를 해야합니다(space 안됨)
목표 파일 : 전제 조건
	레시피 

# 예시
target : target.c
	gcc target.c
```

- 좌측 "target"은 규칙(Rule)의 이름. 
- 우측 "target.c"는 Rule의 의존성이자, **호출 전제조건**. 

	- target.c라는 이름의 파일 또는 Rule이 존재해야 동작한다.

	- 만약 전제조건이 Rule인 경우, 해당 규칙(target.c)을 먼저 호출한 뒤, 성공하면 target이 실행된다.

	- 파일명을 지정하는 경우, 공백(space)으로 여러 파일을 지정할 수 있다. 
		- 와일드 카드도 가능 -> *.c

- "gcc target.c"는 규칙 호출시 동작할 코드로, 레시피(recipe)라 한다. 반드시 하나 이상의 TAB이 들어간다.

- make는 인자 없이 실행했을 때, Makefile에서 **가장 먼저 나오는(가장 위에 있는)** Rule을 실행한다.

- '리링크' 방지란?
	- '리링크'에서 링크는 컴파일 단계 중 링크 단계의 동작이다.
	- Makefile은 목표 파일과 의존성의 Time Stamp(최근 수정시간)을 비교해서 의존성이  파일보다 더 최신인 경우 해당 recipe를 실행한다.


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
___

## **대입** [ref](https://jayy-h.tistory.com/20)
- NAME1 = string: 재귀적 확장 매크로, 대입문에 post-defined variable이 사용될 경우 이를 계속적으로 스캔하며 대입한다.
- NAME2 := string: 단순 확장 매크로, 대입문에 pre-defined variable만이 대입된다.
- NAME3 += string: 기존의 매크로에 공백을 두고 덧 붙인다.
- NAME4 ?= string: NAME4가 기존에 정의되어있지 않은 경우 이 명령을 통해 정의하고, 그렇지 않다면 무시한다.

___

## **# 함수**

- **dir** : 입력된 파일의 디렉토리 부분(상대경로)만 출력.
	```Makefile
	$(dir hello.c world.c) # src/ ./
	```
- **notdir** : 입력된 파일의 파일명 출력.
	```Makefile
	$(notdir hello.c world.c) # hello.c world.c
	```
- **suffix** : 입력된 파일의 확장자 출력
	```Makefile
	$(suffix hello.c world.c) # .c .c
	```
- **basename** : 입력된 파일의 확장자 빼고 전부 출력
	```Makefile
	$(basename hello.c world.c) # src/hello world
	```
- **addsuffix** : 입력된 이름에 접미사를 붙인다.
	```Makefile
	$(addsuffix .txt, hello world) # hello.txt world.txt
	```
- **addprefix** : 입력된 이름 앞에 접두사를 붙인다.
	```Makefile
	$(addprefix txt/, hello world) # txt/hello txt/world
	```

- 그 외 [ref](https://jayy-h.tistory.com/20)
	```Makefile
	# 현재 디렉토리의 전체 파일 출력
	p :
		echo $(wildcard *)

	# 현재 디렉토리의 전체 .c 파일 출력
	p :
		echo $(wildcard *.c)

	# 현재 디렉토리의 전체 .c 파일 출력
	p :
		echo $(shell ls *.c)

	# FF에 현재 디렉토리의 모든 .c파일을 담고
	# 모든 파일의 .c 부분을 .o 로 바꿔 출력
	FF = $(wildcard *.c)
	p :
		echo $(FF:.c=.o)
	```

	- $(shell 실행할 셸 명령): 셸 명령을 수행하고 결과를 리턴한다.
	- $(wildcard *.c): *.c와 일치하는 파일들을 공백으로 구분하여 대입
	- $(SRCS:.c=.o): 대입 참조기법을 사용해 .c가 .o로 바뀐다.

## **# 치환 함수**

```Makefile
OBJECTS = \
		main.o \
		hello.o
PP = $(OBJECTS:.o=.pp) # main.pp hello.pp
```


## 파일 줄바꿈
```Makefile
SRCS = \
		ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
```
- 같은 줄에 써야 하는걸 다음줄에 적고 싶을땐 "\"을 붙인다.
- 실행될 땐 요렇게 실행된다.
	```Makefile
	SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ...
	```
___

## **# 자동 변수**

- `$?` : 전제조건에 담긴 모든 의존성 또는 파일의 이름.
	```Makefile
	p : all clean
		echo $(?)
	# all, clean 규칙 호출 후, echo "all clean"
	```

- `$<` : 첫번째 의존성의 이름.
	```Makefile
	p : first.o second.o third.o
		echo $(<) # first.o
	
	p : all
		echo $(<) # all 규칙 호출 후, echo "all"
	```

- `$*` : 현재 타겟보다 최근에 변경된 종속 항목의 이름(확장자 제외) (확장자 규칙에서만 사용 가능)

- `$@` : 현재 타겟의 이름
	```Makefile
	print :
		echo $(@) # print
	```

- `$(@D)` : 후행 슬래시가 제거 된 대상 파일 이름의 디렉토리 부분.

- `$%` : 현재 타겟이 라이브러리 모듈일 때, .o 파일에 대응되는 이름

- `$^` : 모든 전제 조건의 이름입니다(사이에 공백이 있음).
	```Makefile
	p : all
		echo $(^) # all 규칙이 호출된 뒤, "all" 출력
	```
		 현재 타겟의 종속 항목 리스트 (확장자 규칙에서 사용 불가)


- `%.o: %.c` : .o와 대응되는 .c를 발견 시 아래 명령어를 수행한다.
	- 여기서 `%`는 해당하는 파일의 확장자를 제외한 파일명
___

## **makefile에서 미리 정의된 매크로**

- Makefile에서 미리 정의 되어있는 환경 변수
- `make -p`로 확인할 수 있다.
- 주요 매크로
	- DEFS  Define 추가 할때 사용한다. 
	- CFLAGS gcc의 옵션을 추가 할때 사용한다. 
```sh
# default
CC = cc
# environment
_ = /usr/bin/make
# default
CHECKOUT,v = +$(if $(wildcard $@),,$(CO) $(COFLAGS) $< $@)
# environment
MANAGERPID = 1220
# environment
CLUTTER_IM_MODULE = ibus
# environment
LESSOPEN = | /usr/bin/lesspipe %s
# environment
LC_NAME = ko_KR.UTF-8
# default
CPP = $(CC) -E
# default
LINK.cc = $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(TARGET_ARCH)
# default
MAKE_HOST := x86_64-pc-linux-gnu
# environment
PATH = /usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin
# default
LD = ld

# Implicit Rules

%: %.o
#  recipe to execute (built-in):
    $(LINK.o) $^ $(LOADLIBES) $(LDLIBS) -o $@

%.c:

%: %.c
#  recipe to execute (built-in):
    $(LINK.c) $^ $(LOADLIBES) $(LDLIBS) -o $@

%.ln: %.c
#  recipe to execute (built-in):
    $(LINT.c) -C$* $<

%.o: %.c
#  recipe to execute (built-in):
    $(COMPILE.c) $(OUTPUT_OPTION) $<

%.cc:

%: %.cc
#  recipe to execute (built-in):
    $(LINK.cc) $^ $(LOADLIBES) $(LDLIBS) -o $@

%.o: %.cc
#  recipe to execute (built-in):
    $(COMPILE.cc) $(OUTPUT_OPTION) $<
```

 
___

## make 뒤에 first.o 파일 넣어 실행시

- 자동으로 cc -c -o first.o first.c 가 실행되는데, Makefile에 "cc"가 변수로서 지정되어 있지 않으면 다음과 같이 변환에 실패한다.
	```py
	# Makefile에 CC = gcc가 없는 경우
	process_begin: CreateProcess(NULL, cc -c -o first.o first.c, ...) failed.
	make (e=2):     .
	<builtin>: recipe for target 'first.o' failed
	mingw32-make: *** [first.o] Error 2
	```

- Makefile에 "CC = gcc"로 설정해주면 정상 동작한다.
	```Makefile
	# Makefile 전체 내용
	CC = gcc
	```
	```sh
	$ mingw32-make first.o 		 # <- 명령어 입력
	gcc    -c -o first.o first.c # <- 실행되는 명령어 
	```
	- 위와 같이 gcc 명령어로 컴파일된다.
___


## **가짜 목표 파일(Phony target)**

[ref_docs](https://www.gnu.org/software/make/manual/make.html#Phony-Targets)

- **.PHONY**에 명시된 이름들은 파일명이 아닌 명령어로 보게 함.
- 이름이 같은 파일과 충돌 방지
- 성능 향상 효과

```Makefile
.PHONY: all bonus clean fclean re
```
___

## 쉘 스크립트 사용하기

```Makefile
e :
	@if [ -e *.o ]; then echo "y"; fi
	@if [ -e *.exe ]; then echo "t"; fi

e :
	@if [ -e *.o ] || [ -e *.exe ]; then \
		rm -rf *.o *.exe; \
	fi

e :
	@if [ -e *.o ] || [ -e *.exe ]; then \
		rm -rf *.o *.exe; \
	fi
	echo "rm -rf *.o *.exe";
```
___

## 아카이브 archive 메모

```sh
# STEP1. 오브젝트 파일 생성 [ *.c -> *.o ]
gcc -c first.c second.c third.c

# STEP2. 오브젝트 파일로 정적 라이브러리 파일 생성 [ *.o -> *.a ]
ar rcs libft.a first.o second.o third.o
```

### **ar 유틸리티**
- 사용법 :: ar [옵션들] [라이브러리 이름] [오브젝트 파일들]

**# 주요 옵션**

- **r** : 새로운 오브젝트 파일이면 아카이브에 추가, 기존 파일이면 치환함.
- **c** : 라이브러리 파일이 존재하지 않아도 경고 메시지를 출력하지 않음.
- **s** : 아카이브 인덱스를 생성 
			→ 아카이브 인덱스를 생성하지 않으면 링크 속도가 느려지고, 시스템 환경에 따라서는 에러가 발생.