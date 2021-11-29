# **Factory Design Pattern**

가장 기초적인 디자인 패턴.

객체를 찍어내는 공장.

이 공장은 함수로도, 클래스 객체로도 만들어 낼 수 있다.

## **# 팩토리 패턴 예시**

- **Animal객체를 상속받는 Cat, Dog 클래스**
    ```py
    class Animal():
        def speak(self):
            pass

    class Cat(Animal):
        def speak(self):
            print("Meow!")

    class Dog(Animal):
        def speak(self):
            print("Baww!")
    ```

- **팩토리 함수**

    ```py
    # argument로 들어오는 요청에 따라 적절한 Animal객체를 만들어 반환.
    def FactoryFun(animal: str) -> Animal:
        # argument로 string을 받고 있지만, 실제 코드에선 enum이 권장됨.
        # argument에 따라 요청된 객체를 만들어준다.
        if animal == "Cat":
            return Cat()
        elif animal == "Dog":
            return Dog()

    cat = FactoryFun("Cat")
    cat.speak() # meow!
    dog = FactoryFun("Dog")
    dog.speak() # Baww!
    ```


- **팩토리 객체**

    ```py
    class AnimalFactory():
        # enum prefered
        def createAnimal(self, animal: str) -> Animal:
            if animal == "Cat":
                return Cat()
            elif animal == "Dog":
                return Dog()

    factory = AnimalFactory()
    cat = factory.createAnimal("Cat")
    dog = factory.createAnimal("Dog")
    cat.speak() # Meow!
    dog.speak() # Baww!
    ```

## **# 팩토리 디자인 패턴의 장점**

복잡한 오브젝트의 생성 과정을 클라이언트가 직접 다룰 필요가 없다.

오브젝트의 복잡한 생성 과정을 팩토리 객체/함수 안에 담아놓고 클라이언트는 간단하게 위 코드에서 Cat 객체를 요청하듯 필요한 정보를 팩토리에 넘겨주기만 하면 팩토리는 필요한 객체를 만들어 리턴해준다.  

팩토리 패턴은 이후,

- **팩토리 메소드 패턴(Factory Method)**
- [**싱글톤 패턴(Singleton)**](https://urakasumi.tistory.com/264)
- **빌더 패턴(Builder)**  

등에서 응용된다.

## **# enum을 사용한 코드**

```py
from enum import Enum

class AnimalEnum(Enum):
    CAT = 1
    DOG = 2

class Animal():
    def speak(self):
        pass

class Cat(Animal):
    def speak(self):
        print("meow")

class Dog(Animal):
    def speak(self):
        print("bark")

# Factory function
# prefer enum
def FactoryFn(animal: AnimalEnum):
    if animal == AnimalEnum.CAT:
        return Cat()
    elif animal == AnimalEnum.DOG:
        return Dog()


cat = FactoryFn(AnimalEnum.CAT)
cat.speak()
dog = FactoryFn(AnimalEnum.DOG)
dog.speak()

# Factory class
class AnimalFactory():
    def createAnimal(self, animal):
        if animal == AnimalEnum.CAT:
            return Cat()
        elif animal == AnimalEnum.DOG:
            return Dog()

animal_factory = AnimalFactory()
cat = animal_factory.createAnimal(AnimalEnum.CAT)
cat.speak()
dog = animal_factory.createAnimal(AnimalEnum.DOG)
dog.speak()
```

___
## # 참조 링크

### [**Youtube link**](https://www.youtube.com/watch?v=AmwEIt0vhxA)
### [**Singleton Design pattern**](https://urakasumi.tistory.com/264)

___