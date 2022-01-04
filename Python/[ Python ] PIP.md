# PIP란?

- Python 패키지 관리자 중 하나 (가장 많이 쓰임)

- Python 3.4 부터 기본으로 포함되어있음

- 주요 기능


  - 지정한 패키지를 다운로드하고 설치

    ```
    pip install <패키지명>
    ```

    - Python Package Index (PyPI) 레파지토리(http://pypi.org) 에서 지정한 패키지를 다운로드
    - 이 때, 추가로 필요한 (종속성이 있는) 다른 패키지를 자동으로 다운로드하여 함께 설치함
    - 패키지 종속성이란?  
      예를 들어 tensorflow 패키지가 동작하기 위해서는  
      사전에 numpy 패키지가 설치되어있어야하는데 이러한 관계를 패키지 종속성이라고 함
    - 예를 들어 pip로 tesorflow를 설치할 때, numpy가 없으면 numpy와 tensorflow를 모두 설치함

  - 지정한 패키지를 삭제

    ```
    pip uninstall <패키지명>
    ```

  - 설치된 패키지 목록 조회

    ```
    pip list
    ```

  - 설치된 패키지 정보 조회

    ```
    pip show <패키지명>
    ```

    - 버전, 제작자 이메일, 패키지 종속성 등의 정보를 출력

    - 출력예  
      아래 예의 cycler라는 패키지는  
      six라는 패키지를 사용하며  (필요로하며) 자기 자신은 matplotlib에서 사용된다.

      ```
      D:\> pip show cycler
      Name: cycler
      Version: 0.10.0
      Summary: Composable style cycles
      Home-page: http://github.com/matplotlib/cycler
      Author: Thomas A Caswell
      Author-email: matplotlib-users@python.org
      License: BSD
      Location: c:\programdata\miniconda3\envs\haha\lib\site-packages
      Requires: six
      Required-by: matplotlib
      ```

- 패키지란?

  - 모듈(라이브러리) 배포(설치)의 단위
  - 다른 언어에서의 ""라이브러리""라고 보면 됨

# requirements 파일

- requirements 파일이란: 현재 설치되어있는 패키지와 패키지 버전이 정리되어있는 파일

- requirements 파일 생성

  ```
  D:\> pip freeze > requirements.txt
  ```

  아래는 이렇게 생성한 requirements.txt 파일 내용 예시

  ```
  certifi==2019.9.11
  cycler==0.10.0
  kiwisolver==1.1.0
  matplotlib==3.1.1
  numpy==1.17.3
  pipdeptree==0.13.2
  pyparsing==2.4.4
  python-dateutil==2.8.1
  six==1.13.0
  wincertstore==0.2
  ```

- 이렇게 생성한 requirements.txt 파일을 이용하여 다른 PC나 환경에서  
  버전까지 맞추어 모든 패키지를 동일하게 pip install 가능 (`-r` 옵션 사용)

  ```
  (newEnv) D:\> pip install -r requirements.txt
  
  (newEnv) D:\>pip freeze
  certifi==2019.9.11
  cycler==0.10.0
  kiwisolver==1.1.0
  matplotlib==3.1.1
  numpy==1.17.3
  pipdeptree==0.13.2
  pyparsing==2.4.4
  python-dateutil==2.8.1
  six==1.13.0
  wincertstore==0.2
  ```

# pipdeptree (강추)

- 설치된 패키지 간 종속성 관계를 트리 형식으로 출력하는 프로그램

- 설치

  ```
  pip install pipdeptree
  ```

  - pip는 기본적으로 python 패키지를 설치하지만, pipdeptree 처럼 실행파일을 설치하는 패키지도 있습니다.

- 사용예

  ```
  D:\> pipdeptree
  certifi==2019.9.11
  matplotlib==3.1.1
    - cycler [required: >=0.10, installed: 0.10.0]
      - six [required: Any, installed: 1.13.0]
    - kiwisolver [required: >=1.0.1, installed: 1.1.0]
      - setuptools [required: Any, installed: 41.6.0.post20191030]
    - numpy [required: >=1.11, installed: 1.17.3]
    - pyparsing [required: >=2.0.1,!=2.1.6,!=2.1.2,!=2.0.4, installed: 2.4.4]
    - python-dateutil [required: >=2.1, installed: 2.8.1]
      - six [required: >=1.5, installed: 1.13.0]
  pipdeptree==0.13.2
    - pip [required: >=6.0.0, installed: 19.3.1]
  wheel==0.33.6
  wincertstore==0.2
  ```

- pip list 및 pip show와 비교

  ```
  D:\> pip list
  Package         Version
  --------------- -------------------
  certifi         2019.9.11
  cycler          0.10.0
  kiwisolver      1.1.0
  matplotlib      3.1.1
  numpy           1.17.3
  pip             19.3.1
  pipdeptree      0.13.2
  pyparsing       2.4.4
  python-dateutil 2.8.1
  setuptools      41.6.0.post20191030
  six             1.13.0
  wheel           0.33.6
  wincertstore    0.2
  
  D:\> pip show matplotlib
  Name: matplotlib
  Version: 3.1.1
  Summary: Python plotting package
  Home-page: https://matplotlib.org
  Author: John D. Hunter, Michael Droettboom
  Author-email: matplotlib-users@python.org
  License: PSF
  Location: c:\programdata\miniconda3\envs\haha\lib\site-packages
  Requires: cycler, kiwisolver, numpy, pyparsing, python-dateutil
  Required-by:
  
  D:\> pip show cycler
  Name: cycler
  Version: 0.10.0
  Summary: Composable style cycles
  Home-page: http://github.com/matplotlib/cycler
  Author: Thomas A Caswell
  Author-email: matplotlib-users@python.org
  License: BSD
  Location: c:\programdata\miniconda3\envs\haha\lib\site-packages
  Requires: six
  Required-by: matplotlib
  ```