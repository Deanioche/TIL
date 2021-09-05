## **Manage File System**

___

## **마운트**

파일 시스템을 전체 디렉터리 구조의 특정 디렉터리에 연결하는 것
- 저장 장치에 파티션이 존재하며, 파티션에 파일 시스템을 만들어져 있음

마운트되는 위치를 마운트 지점이라 함

![image](https://user-images.githubusercontent.com/66513003/132129883-7a3108c7-97dd-49f0-afb7-d10cc7c83806.png)

## **/etc/fstab 파일**

리눅스 시스템이 부팅될 때 자동으로 마운트할 파일 시스템의 목록을 가진설정 파일
- 각 라인마다 개별 파일 시스템의 마운트 정보가 기록되어 있음

### **라인을 구성하는 항목의 의미**
![image](https://user-images.githubusercontent.com/66513003/132129936-ea020116-b620-426e-bd52-51ca5b45948b.png)

- blkid : 파티션의 UUID 및 파티션 유형 출력 명령어
    ```
    surimi@surimi:~/dev/c$ blkid

    /dev/sda1: LABEL="cloudimg-rootfs" UUID="af6ae7c2-2062-4fe9-85a2-9a05c79e8836" TYPE="ext4" PARTUUID="cbbb4abe-9a36-4b68-b377-468b3b75d754"
    /dev/sda15: LABEL_FATBOOT="UEFI" LABEL="UEFI" UUID="EA07-73CA" TYPE="vfat" PARTUUID="26187dd3-6ae0-4a11-9566-fb1fa2ed50c5"
    ```

- 파일 시스템 유형
    - vfat : 윈도우
    - ext4 : 리눅스

## **마운트와 /etc/fstab 파일**
UUID는 파일 시스템을 유일하게 구분하는 숫자(32자리 16진수)
- 블록 디바이스의 정보를 보여주는 blkid 명령으로 확인할 수 있음

마운트 또는 언마운트를 하면 내용이 /etc/mtab 파일에 기록됨
- 옵션 없이 단순히 mount 명령을 사용하면 현재 마운트되어 있는 파일 시스템을 보여줌
- 추가로 마운트한 것이 없다면 /etc/fstab 파일의 내용과 거의 유사함

기본 마운트 옵션은 rw, suid, dev, exec, auto, nouser, async가 적용됨
- mount 명령에서 옵션 -o를 사용할 때 적용할 수 있음
- rw : 파일을 읽고 쓸 수 있게 한다.
- suid : (set uid) uid를 사용한다고 선언.
- dev : 블록 디바이스 허용 여부.
- exec : 바이너리 실행 파일이 이 파일 시스템에서 실행 될 수 있게 함.
- auto : 부팅할 때 자동 마운트
- nouser : root 외에는 마운트/ 언마운트 할 수 없음. (<-> user)
- async : 파일 입출력시 비동기적으로 수행. (<-> sync)

14:03 ~
 
