# linux memo

___


## **클라우드 서버 방화벽 해제**

**사이트에 연결할 수 없음 ~.~.~.~에서 응답하는 데 시간이 너무 오래 걸립니다.(timeout)**

오라클 클라우드에서 리눅스로 node.js 서버를 실행하고,
웹 브라우저에서 접속을 시도할때 timeout으로 연결이 실패한다면
방화벽이 해제되어 있거나 해당 포트의 연결이 허용되어 있는지 확인한다.

```py
# 80 포트 열기
sudo iptables -I INPUT 1 -p tcp --dport 80 -j ACCEPT

# 포트 상태 확인
sudo iptables --list
```

https://pythonblog.co.kr/blog/30/