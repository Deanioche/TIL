## **top**

___

현재 실행 중인 개별 프로세스의 실시간 정보를 주기적으로 보여줌

ps 명령의 동적/대화식 버전

기본적으로 CPU 사용량이 많은 프로세스를 먼저 보여줌

## **옵션**
- -p delay는 초 단위로 주기를 지정
- -p pids와 -u user는 특정 프로세스나 사용자 프로세스로 한정
- -S는 ‘총 CPU 사용 시간(자식 프로세스 포함)’을 출력

실행 중 사용할 수 있는 명령 키
    ![image](https://user-images.githubusercontent.com/66513003/132176825-00bb854e-925b-4bac-84dc-dd77ab0563d3.png)

## **top 화면**

![image](https://user-images.githubusercontent.com/66513003/132178445-f1cea679-4332-43c0-bf85-1efc3011771a.png)

시스템 정보
- up : uptime
- load average : cpu 부하량
- Tasks : 프로세스들 상태

프로세스 목록
- PR & NI : 우선순위 (PR : 0 ~ 39, NI : -19 ~ 20)
- VIRT : 프로세스의 가상 메모리 사용량
- RES : 메모리 사용량
- SHR : 공유 메모리 사용량
- S : 프로세스 상태
    - R - 실행 상태 & 실행 가능한 상태
    - T - 지연 상태
    - S - 멈춤 
    - D - 멈춤
- %CPU & %MEM : 점유율
- time : 누적 사용 시간
___

## **kill**

프로세스에 시그널을 보내는 명령

- 다른 프로세스에게 시그널을 보내도록 커널에게 요청하는 것
- 시그널은 프로세스를 관리 방법이고 프로세스 간 통신 수단
- 여러 종류의 시그널이 존재하며 기본 시그널은 TERM임

- kill [-signal ] pids
- kill [-s signal ] pids
    - signal은 시그널의 이름 또는 시그널 번호
    - kill pids 명령은 TERM 시그널을 보냄
    - kill -STOP 3188은 해당 PID를 가진 프로세스에게 멈춤 시그널을 보냄

## **killall**

특정 프로세스에 한꺼번에 시그널을 보내는 명령

- killall [options ] [-s signal ] [-u user] names
    - 프로그램이나 프로세스의 이름을 사용
    - killall -i -s 9 -u kdhong bash는 확인을 거쳐 kdhong 계정의 bash 프로세스에게 KILL 시그널을 보냄

- 시그널의 종류
    ![image](https://user-images.githubusercontent.com/66513003/132177626-684514e9-0efe-4e21-a9fd-ccced22e8765.png)

___

## **nice와 renice 명령**

- ‘nice 우선순위(NI) 값’을 조정하는 명령
- NI 값은 -20(가장 높음) ~ 19(가장 낮음)
    - 우선순위가 높으면 CPU를 점유할 확률이 높음
    - 기본 NI 값은 0임

- ### **nice [option] [command]**
    - 명령을 실행할 때 NI 값을 조정하는 명령
    - 일반 사용자는 NI 값을 0 이상으로만 지정할 수 있음
- 옵션
    - -n adjustment 또는 –adjustment 는 조정 수치 만큼 NI 값을 조정
    - nice –n +5 top 또는 nice -+5 top은 NI 값을 5 증가 시켜 우선순위를 낮춤

- ### **renice priority [options]**

- 실행 중인 프로세스의 NI 값(절댓값)을
바꾸는 명령

- 일반 사용자는 자신이 소유한 프로세스의
우선순위를 낮출 수만 있음

- 옵션
    - -p pids 는 프로세스를 지정
    - -g gids 는 GID를 지정
    - -u users 는 사용자를 지정
    - renice 10 –u jjpark는 관리자(또는 본인)가 jjpark 계정이 소유한 모든 프로세스의 NI 값을 10으로 조정함

___

## **nohup 명령**

HUP 시그날과 무관하게 명령이 스스로 종료될 때까지 계속 수행시키는 명령
- 로그아웃을 하거나 터미날 창을 끝내면 프로세스에 HUP 시그널이 보내짐

nohup 명령을 실행하는 경우 명령 행의 끝에 ‘&’를 붙여 백그라운드로 실행해야 함

- 예
    - nohup find -size +100k > log.txt &
    - 표준 출력과 표준 에러 출력이 필요한 경우 ~/nohup.out에 출력됨

## **프로세스 관리를 위한 GUI**

데스크톱 메뉴에서 ‘프로그램>시스템 도구>시스템 정보’를 실행
- ‘시스템 정보‘ 창에서 모든 또는 자신이 소유한 프로세스의 상태를 보고[편집] 메뉴에서 상태를 제어할 수 있음
