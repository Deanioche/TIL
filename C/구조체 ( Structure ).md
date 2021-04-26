# 구조체

### # 구조체 생성

```c
struct person
{
    char *name;
    int age;
    char sex;
}; // 메모리 12 (4 + 4 + 4)

struct person x = {"personX", 23, 'M'};
struct person y;
strcpy(y.name, "personY");
y.age = 35;
y.sex = 'W';
y.name = "personY2";

printf("%s %d %c size : %d\n", x.name, x.age, x.sex, sizeof(x)); // 12
printf("%s %d %c size : %d\n", y.name, y.age, y.sex, sizeof(y)); // 12

// 메모리는 구조체 멤머중 가장 큼 자료형의 크기로 할당됨
// person에서는 int 기준으로 변수당 최소 4byte가 먹힘
 ```

 ### # 구조체 배열

 ```c
struct personArr
{
    char name[10];
    int age;
    char sex;
}; // 16 (12 + 4 + 4)

struct personArr pArr[3] = {{"응애1", 11, 'A'}, {"응애2", 22, 'B'}, {"응애3", 33, 'C'}};

strcpy(pArr[0].name, "김철수");
pArr[0].sex = 'N';

printf("%s %d %c size : %d\n", pArr[0].name, pArr[0].age, pArr[0].sex, sizeof(pArr[0]));
printf("%s %d %c size : %d\n", pArr[1].name, pArr[1].age, pArr[1].sex, sizeof(pArr[1]));
printf("%s %d %c size : %d\n", pArr[2].name, pArr[2].age, pArr[2].sex, sizeof(pArr[2]));
```

### # 구조체 포인터 변수 선언
```c
struct ptPerson
{
    char name[12];
    int age;
    char sex;
};
struct ptPerson man[3] = {{"ptPerson1", 111, 'A'}, {"ptPerson2", 222, 'B'}, {"ptPerson3", 333, 'C'}};
struct ptPerson *pt;

// *가 . 보다 연산 우선순위가 낮으므로 괄호 필요
//(*pt).name
// 또는 포인터 연산자 사용
//pt -> name

pt = man; // 구조체 포인터 변수에 man 구조체 시작주소 대입
printf("%s %d %c\n", pt->name, pt->age, pt->sex);
pt++;
printf("%s %d %c\n", (*pt).name, (*pt).age, (*pt).sex);
pt++;
printf("%s %d %c\n", pt->name, pt->age, pt->sex);
```

### # 구조체 포인터를 파라미터로 

```c
// 파라미터에 구조체 자체가 아닌 주소값만을 전달함으로써 메모리 절약 효과
struct num calc(struct num *);
struct num {
    int x;
    int y;
    int sum;
    int mul;
};

void main() {
    struct num number1;
    number1.x = 10;
    number1.y = 20;
    calc(&number1); // 주소값 전달
    printf("x : %d, y : %d, sum : %d, mul : %d \n", number1.x, number1.y, number1.sum, number1.mul);
    getchar();
}
struct num calc(struct num *number2){
    number2 -> sum = number2 -> x + number2 -> y;
    number2 -> mul = number2 -> x * number2 -> y;

}
//x : 10, y : 20, sum : 30, mul : 200 
```

### # 구조체 피트필드
```c
// 기억공간을 byte단위가 아닌 bit단위로 사용

// int의 경우 4byte 총 32bit를 사용할 수 있지만
// 값으로 1을 저장하면 1bit만 사용되므로 31bit가 낭비된다.

struct useBitField
{
    unsigned a : 1; // 1bit
    unsigned b : 2; // 2bit
    unsigned int c : 3; // 3bit
    unsigned int d : 7; // 7bit
};

// 1byte 총 8bit 중에
// 1+2+3 = 6bit만 사용되고 나머지 2bit는 버려진다.

// 비트필드의 자료형은 int나 unsigned로 선언
// 비트필드에서 포인터나 배열은 사용 안됨.
// 피트필드의 전체 크기는 시스템이 제공하는 int크기 이내여야 함.

// 하나의 비트필드가 2개의 int 사이에 걸쳐 저장될 수는 없음.
// 첫번째 int에서 31bit가 사용되고 1 bit가 남았을 때,
// 2bit 이상이 저장되면 새로운 int 메모리를 2bit만큼 사용하고 첫번째 int의 나머지 1bit는 그냥 버려진다.

int main(int argc, char const *argv[])
{
    struct useBitField test;
    test.a = 1; // 2^1 - 1
    test.b = 3; // 2^2 - 1
    test.c = 7; // 2^3 - 1
    test.d = 127; // 2^7 - 1

    printf("%d %d %d %d", test.a, test.b, test.c, test.d); // 1 3 7 127

    return 0;
}
```

