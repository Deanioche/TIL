# **Linux Package Manager**

- linux terminal 에서의 앱스토어 같은 역할 (npm, pip 등...)

- `Package list`를 최신버전으로 업데이트
    ```js
    sudo apt-get update
    // upgrade와는 다르니 주의
    ```
    

- 패키지 검색
    ```
    sudo apt-cache search (패키지명)
    ```

- 모든 패키지 업데이트
    ```js
    sudo apt-get upgrade
    // update가 아님
    ```

- 패키지 삭제
    ```
    sudo apt-get remove (패키지명)
    ```

___

### **Nano 편집기**

- 설치
    ```
    sudo apt-get install nano
    ```

___

### **htop 작업관리자**    
top은 리눅스에 기본으로 설치되어있는 작업관리자.  
htop은 시각적으로 개선된 버전.

- 설치
    ```
    sudo apt-get install htop
    ```

- 업데이트
    ```js
    sudo apt-get upgrade htop
    // update가 아님
    ```

- 실행
    ```
    sudo htop
    ```
    <img src="https://user-images.githubusercontent.com/66513003/128873151-cddaa290-66b6-4a84-9585-e56192626d2c.png" width="400">

___

### **git**

- 설치
    ```
    sudo apt-get install git
    ```

___