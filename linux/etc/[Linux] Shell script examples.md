## **Shell Script examples**

___

```
#!/bin/bash
VAR="Hello, world!"
echo $VAR
echo "New Line"
printf "%s" "$VAR"
echo "No New Line"
exit 0
```

```
> sh test.sh
Hello, world!
New Line
Hello, world! No New Line
```
printf를 사용할 때, "$VAR"에서 " 쌍따옴표로 묶어주지 않으면 문자열의 공백을 표현하지 않으므로 주의해야 한다.
___

## **파라미터 변수**

```
#!/bin/bash
echo "실행 파일 이름: $0"
echo "\$1: $1"
echo "\$2: $2"
echo "\$3: $3"
echo "전체 파라미터: $*"
exit 0
```

```
> sh test.sh value1 value2 value3 value4
실행 파일 이름: test.sh
$1: value1
$2: value2
$3: value3
전체 파라미터: value1 value2 value3 value4
```

___