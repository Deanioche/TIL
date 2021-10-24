// 후위 표기식을 계산하는 연산
element evalPostfix(char *exp)
{
    int oper1, oper2, value, i = 0; // 피연산자 1, 2, 값, index
    int length = strlen(exp);       // 전체 수식의 길이
    char symbol;
    for (i = 0; i < length; i++)
    {
        symbol = exp[i];
        if (symbol != '+' && symbol != '-' && symbol != '*' && symbol != '/')
        {
            value = symbol - '0'; // symbol 정수화 후 value으로 입력
            push(value);          // 스택에 삽입
        }
        else
        {
            oper2 = pop(); // 스택에서 값 꺼내기
            oper1 = pop();
            switch (symbol)
            {
            case '+':
                push(oper1 + oper2);
                break;
            case '-':
                push(oper1 - oper2);
                break;
            case '*':
                push(oper1 * oper2);
                break;
            case '/':
                push(oper1 / oper2);
                break;
            }
        }
    }
    return pop(); // 스택에 마지막으로 삽입된 값을 꺼내 리턴
}
/*
후위 표현식에 대해 스택을 이용한 알고리즘 계산 과정
2 3 * 4 5 / – 6 –  

알고리즘 작동에 필요한 변수들이 선언되고
수식의 문자열 길이인 9가 변수 length에 저장된다.

for 반복문이 시작되며 수식이 하나씩 스택에 저장되어 후위 표현식의 연산이 진행된다.

1. 첫번째 for 반복 (i = 0)
수식의 첫번째 문자를 symbol 변수에 저장해 이 문자가 연산자인지 판별한다.
exp[0]의 값은 '2'이므로 연산자가 아니며, char 형태에서 정수형으로 변환해 value로 저장한다.
그리고 push(value)에 의해 정수 2이 스택에 삽입된다.

현재 stack : | 2 |

2. 두번째 for 반복 (i = 1)
exp[1]은 '3'이며 연산자가 아니므로 정수로 변환되어 스택에 삽입된다.

현재 stack : | 3 | 2 |

3. 세번째 for 반복 (i = 2)
exp[2]은 '*'이며 연산자이므로 if문이 동작하지 않고 else로 넘어간다.
pop()에 의해 스택에서 값이 꺼내져 변수에 값이 저장된다. oper2 = 3, oper1 = 2
그리고 switch문에서 case '*': 의 push(oper1 * oper2);가 실행되어 스택에 6이 삽입되고
break로 switch 문이 종료된다.

현재 stack : | 6 |

4. 네번째 for 반복 (i = 3)
exp[3]은 '4'이며 연산자가 아니므로 정수로 변환되어 스택에 삽입된다.

현재 stack : | 4 | 6 |

5. 다섯번째 for 반복 (i = 4)
exp[4]은 '5'이며 연산자가 아니므로 정수로 변환되어 스택에 삽입된다.

현재 stack : | 5 | 4 | 6 |

6. 여섯번째 for 반복 (i = 5)
exp[5]은 '/'이며 연산자이므로 else문으로 넘어간다.
스택에서 값이 꺼내져 변수에 저장되고 (oper2 = 5, oper1 = 4)
switch문에서 push(oper1 / oper2);이 동작해 계산된 값이 스택에 저장된다.

현재 stack : | 0.8 | 6 |

7. 일곱번째 for 반복 (i = 6)
exp[6]은 '-'이며 연산자이므로 else문으로 넘어간다.
스택에서 값이 꺼내져 변수에 저장되고 (oper2 = 0.8, oper1 = 6)
switch문에서 push(oper1 - oper2);이 동작해 계산된 값이 스택에 저장된다.

현재 stack : | 5.2 |

8. 여덟번째 for 반복 (i = 7)
exp[7]은 '6'이며 연산자가 아니므로 정수로 변환되어 스택에 삽입된다.

현재 stack : | 6 | 5.2 |

9. 일곱번째 for 반복 (i = 8)
exp[8]은 '-'이며 연산자이므로 else문으로 넘어간다.
스택에서 값이 꺼내져 변수에 저장되고 (oper2 = 6, oper1 = 5.2)
switch문에서 push(oper1 - oper2);이 동작해 계산된 값이 스택에 저장된다.

현재 stack : | -0.8 |

i = 9가 되어 for문의 조건 i < length가 false가 되므로 for문이 종료되고
return pop()에 의해 스택에 담긴 값 -0.8이 반환되며 함수가 종료된다.