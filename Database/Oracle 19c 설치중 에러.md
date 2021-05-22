# 19c 설치에러

1. 설치중에 인스턴스 생성중 멈춤 (54 ~ 55%) 
    - 윈도우 administrator 계정으로 전환 후 관리자 권한으로 설치.

2. ORA-12505: TNS: LISTENER DOES NOT CURRENTLY KNOW OF SID GIVEN IN CONNECT DESCRIPTOR
    - "XE"였던 SID를 설치때 입력한 "orcl"로 바꿔주고 해결.

3. 그밖에 에러 해결
    - 서비스에서 oracle MTS, TNS, Service 실행중인지 확인.

4. scott 스키마 생성

- 설치과정중 고급 설정에서 추가하기

- query 직접 입력해 생성하기
    - oracle_hr_schema.sql 파일 참조