## **cron**

___

지정된 시간에 주기적으로 자동 수행되는 작업을 수행.

crond 데몬 프로그램이 서비스를 제공
- 1분 간격으로 ‘crontab 파일’을 검사하여 수행함
- ‘crontab 파일’에는 ‘cron 작업의 수행 방법’이 기록되어 있음
- 일반적으로 ‘cron 작업‘은 셸 스크립트로 작성됨

cron 서비스를 이용한 자동 스케줄
- /etc/crontab 파일과 **/etc/cron.d/** 디렉터리에 존재하는 파일
    - 시스템 수준에서 주기적으로 수행될 작업을 설정
- crontab 명령
    - 개별 사용자는 crontab 명령을 이용하여 주기적으로 수행될 작업을설정할 수 있음

crontab 파일의 형식
- 환경 변수의 설정과 cron 작업의 수행 방법을 정의

```
$ cat /etc/cron.d/0hourly
SHELL=/bin/bash
PATH=/sbin:/bin:/usr/sbin:/usr/bin
MAILTO=root
HOME=/
01 * * * * root run-parts /etc/cron.hourly
```

**항목의 의미**  
- 분(0~59), 시(0~23), 날짜(0~31), 달(1~12), 요일(0~7)
    -  *는 매번을 의미, 간격 표시를 위해 /, 범위 표시를 위해 -와 ,를 사용할 수 있음

- 사용자, 실행할 명령
    -  사용자는 시스템 수준 crontab 파일의 경우에만 지정
    -  run-parts는 지정된 디렉터리에 있는 스크립트를 수행하는 명령

**예**  
```
0 */6 * * 1-5 /bin/mail –s ˝Hi˝ jjpark@localhost
```
-  월요일부터 금요일까지 0,6,12,18시 정각에 메일을 보냄

___

## **crontab 명령**

일반 사용자가 자신의 cron 작업을, 자신의 crontab 파일에 등록할
때 사용해야 하는 명령
- /var/spool/cron/username 파일로 만들어지나 수정 권한이 없음
```
crontab [options]
```
**옵션**
- -l은 crontab 파일의 내용을 출력함
- -e은 crontab 파일을 vi로 편집할 수 있음
    - * * * * * date >> ~/date.txt를 입력한 후 확인해 볼 것
- -r은 crontab 파일을 삭제함
- -u user는 지정된 사용자의 crontab 파일을 사용함(권한이 필요)
지정된 시간에 일회성으로 작업을 예약하려면 at 명령을 사용함