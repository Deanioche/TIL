# **Singleton Pattern**

프로세스 실행 중에 오직 하나의 객체만 생성되도록 강제하는 디자인 패턴.

싱글톤이 적용된 클래스의 객체를 여러개 생성해도 모두 하나의 객체만을 가리키게 된다.

결국, 해당 객체는 단 하나만 만들어지게 되는 것.


## **# 싱글톤 클래스 정의**

싱글톤 클래스는 static 변수(instance)가 존재한다.

싱글톤 클래스에서 내부 static 변수가 정의되어 있지 않다면, 

static 변수에 현재 객체(this)를 할당해주고, 이 변수를 return해준다.

```js
class Singleton{
    static instance;
    if(!Singleton.instance){
        Singleton.instance = this;
    }
    return Singleton.instance;
}
```

이제 클라이언트 코드에서 여러 싱글톤 객체를 만들어 주고 비교해보면,

두 객체는 동일한 것을 확인할 수 있다.

```js
let s1 = new Singleton();
let s2 = new Singleton();

if(s1 === s2){
    console.log("same"); // 출력됨.
}else{
    console.log("diff");
}
```

프로세스가 실생되면, 

프로세스의 실행부터 종료까지 유지되는 정적(static) 인스턴스가 생성되며, 이 인스턴스는 undefined, 즉 아무것도 가리키지 않는다.

클라이언트 동작에 따라 s1 객체가 선언되며 생성자(constructor)가 호출되면 static 인스턴스는 Singleton 객체를 가리키게 된다.

다음으로 s2 객체가 선언될 때는, static 인스턴스가 이미 값을 가지고 있으므로 바로 그 값을 반환한다. 여기서 값이란 s1때 생성된 Singleton 객체이다.

결론적으로, s1과 s2는 같은 객체를 가리키기 때문에 둘은 싱글톤이다(같다)라고 표현할 수 있다.

이후로 아무리 Singleton 객체를 생성해도, 모두 같은 객체를 가리키게 된다.

## **예제**

```js
class SingleCat {
    static instance;
    constructor(name) {
        this.name = name;
        if (!SingleCat.instance) {
            SingleCat.instance = this;
        }
        return SingleCat.instance;
    }

    speak() {
        console.log(this.name, 'meow!');
    }
}

let cat1 = new SingleCat('Nabi');
let cat2 = new SingleCat('Kitty');

if (cat1 === cat2)
    console.log("same cat!"); // 출력됨.
else
    console.log("different cat!");

cat1.speak(); // Nabi meow!
cat2.speak(); // Nabi meow!
```

___

## **# 싱글톤 패턴이 사용되는 경우**

- 하나의 객체가 많은 리소스를 차지할 때.
- 객체가 외부 네트워크와 연결되는데 이 네트워크가 동시에 단 하나만 연결되어야 할 때.

___

## [**# ref_link**](https://youtu.be/-oy5jOd5PBg)