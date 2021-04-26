# FileSteam I/O

### # 파일 입력 예제
```c
#include <stdio.h>
#include <stdlib.h> // exit() 사용

fp = fopen("sample.txt", "a"); // w 쓰기 r 읽기 a 추가(append)

for(ch = 'A'; ch <= 'Z'; ch++) { 
    fputc(ch, fp);
}

fclose(fp);

// ABCDEFGHIJKLMNOPQRSTUVWXYZ 입력
```

### # 사용자가 입력 중단 (Ctrl + z)
```c
while((ch = getchar()) != EOF){ 
    putc(ch, fp);
}
// ^Z가 나올때까지 사용자로부터 입력 받음.
```

![c 12강 파일스트림 ropen() 사용모드](https://user-images.githubusercontent.com/66513003/116078522-af0a5e00-a6d1-11eb-8606-4e0568af732a.png)


### # 지정한 형식대로 입력받기
```c
fprintf(stdout, "학번 이름 중간 기말 레포트 출석 점수를 입력\n");
for(int i = 0; i < 3; i++){
    scanf("%s %s %d %d %d %d", no, name, &mid, &term, &rep, &att);
    fprintf(fp, "%10s %8s %3d %3d %3d %3d\n", no, name, mid, term, rep, att );
}

// 11111   DinDIn 100 100 100 100
// 22222    Sokyo  10  10  10  10
// 10003    Hyoah  50  50  50  50
```

### # 파일 출력
```c
char c;
    fp = fopen("prac/sample1.dat", "r");
    if(fp == NULL){
        printf("파일 읽기 오류"); // 에러메세지
        exit(1); // 프로그램 종료
    }  

    while((c = getc(fp)) != EOF){ // ^Z가 나올때까지 출력
        putchar(c);
    }
```

### # 지정한 크기만큼 출력
```c
    while(fgets(name, 20, fp) != NULL){  
        // name : 변수, 20 : 출력 크기, fp : 파일데이터
        printf("%s", name);
    }
```

![c 12강 파일처리함수기능](https://user-images.githubusercontent.com/66513003/116078525-b03b8b00-a6d1-11eb-8f47-edab40662045.png)


# # 랜덤파일

파일의 임의의 위치에서 자료를 읽거나 쓸 수 있다.

레코드의 길이가 일정.

순차파일과 비교.
- 단점 : 기억공간 낭비.
- 장점 : 레코드 검색이 빠르고 효과적.

랜덤파일 입출력은 binary 모드
```c
fopen("파일 이름", "wb");
```

### # binary 모드의 특징
텍스트파일보다 기억공간이 적음.

레코드 길이를 개발자가 결정

파일 포인터의 위치 변경 가능


#### # fwrite()
```c
fwrite (저장 자료 변수, 레코드 길이, 레코드 개수 ,파일 포인터)
예 : fwrite(name, 10, 1, fp);
```
#### # 예제
```c

while(strcmp(name, "END")){ // "END" 문자열이 나올때까지 출력
    fwrite(name, 10, 1, fp);
    gets(name);
}

while(1) {
    if(fread(name, 10, 1, fp) != 1){ 
        // 레코드 개수가 1이므로 1이 아닌 값이 리턴되면 break; (파일의 끝이므로)
        break;
    }
    puts(name);
}
```

### # 랜덤파일 위치제어
fseek()

 파일 포인터를 임의의 위치로 이동시키는 함수.

 랜덤파일의 특정부분을 입출력 할 수 있다.

```c
 fseek(파일 포인터 변수, 이동할 상대 위치, 기준위치를 지정하는 모드);
 fseek(fp, 2*REC_size, SEEK_SET);
```

- 0 or SEEK_SET 파일의 시작 위치 // fseek(fp, 7, SEEK_SET);
- 1 or SEEK_CUR 현재 파일포인터의 위치
- 2 or SEEK_END 파일의 끝 위치

#### # 예제
```c
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char str[10];

    // 파일 생성 & 입력
    // FILE *fp = fopen("prac/sample2.txt", "wt");
    // fputs("1234567890", fp);
    // fclose(fp);

    // 파일 출력
    FILE *fp = fopen("prac/sample2.txt", "rt"); // 1234567890
   
    fseek(fp, 7, SEEK_SET);
    fgets(str, 4 ,fp);
    printf("7번째부터 3글자 출력 : %s \n", str); // 890 
    fseek(fp, -2, SEEK_CUR);
    fgets(str, 3 ,fp);
    printf("현재 위치에서 앞에 2글자부터 2글자 출력 : %s \n", str); // 90
    fseek(fp, -9, SEEK_END);
    fgets(str, 6 ,fp);
    printf("맨 뒤에서 9번째 앞부터 5글자 출력 : %s \n", str); // 23456

    fclose(fp);
    
    return 0;
}
```