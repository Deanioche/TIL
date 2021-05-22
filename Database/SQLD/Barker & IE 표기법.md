# **Barker 표기법**

**속성 (Attribute)**

<img src="https://user-images.githubusercontent.com/66513003/119123802-ed91ff00-ba6a-11eb-9086-203904191636.png
" width="400">

- `*` : 해당 속성에 어떤 값을 반드시 지적해야 하는 경우 (Mandatory)
- `o` : 해당 속성에 어떤 값이 존재 할수도 있고 존재하지 않을 수도 있는 경우 (Optional)

**관계(Relationship)**

<img src="https://user-images.githubusercontent.com/66513003/119124189-5a0cfe00-ba6b-11eb-9cca-0df71ebc84fd.png
" width="400">

- 엔터티와 엔터티간 상관 관계의 조건
    - 필수 조건
        - 필수 사항은 실선으로 표시하고 상대 엔터티에 대해 해당 엔터티에 조건을 만족하는 엔터티가 반드시 존재할 경우에 표시한다.
    - 선택 조건
        - 선택 사항은 점선으로 표시하고 상대 엔터티에 대해 해당 엔터티에 조건을 만족하는 엔터티가 존재할 수도, 존재하지 않을 수도 있을 경우 표시한다.

<img src="https://user-images.githubusercontent.com/66513003/119124443-a22c2080-ba6b-11eb-8619-a484770ff965.png
" width="400">

**식별자(Unique Identifier)**

- 식별자란 하나의 엔터티에 구성되어 있는 여러 개의 속성 중에 엔터티를 대표할 수 있는 속성을 의미하며
하나의 엔터티는 반드시 하나의 식별자가 존재해야 한다.

- 보통 `식별자`와 `키(Key)`를 동일시 생각하고 있는 경우가 있는데,
식별자는 `논리 데이터 모델링` 단계에서 사용하고 키는 `물리 데이터 모델링` 단계에서 사용한다.

- 식별자 앞에는 # 기호를 표시하고 여러 개# 기호를 반복적으로 표시한다.

<img src="https://user-images.githubusercontent.com/66513003/119124793-064ee480-ba6c-11eb-87f2-135ea93a80ee.png
" width="400">

#

# **IE 표기법**

**엔터티(Entity)와 속성(Attribute)**  

<img src="https://user-images.githubusercontent.com/66513003/119125302-955bfc80-ba6c-11eb-8d5d-6b64ee7cd7cb.png
" width="200">
<img src="https://user-images.githubusercontent.com/66513003/119125335-9f7dfb00-ba6c-11eb-979d-126563bd7861.png
" width="200">

**관계(Relationship)**

<img src="https://user-images.githubusercontent.com/66513003/119125198-79585b00-ba6c-11eb-9caa-be94e7655a6a.png
" width="600">

**식별자(Unique Identifier)**

<img src="https://user-images.githubusercontent.com/66513003/119125481-c6d4c800-ba6c-11eb-93ee-c4d37c30971f.png
" width="300">

- 식별관계
    - 부모 엔터티의 식별자를 자식 엔터티의 식별자로 상속하는 관계
    - IE 표기법 : 관계선 전체를 실선으로 표현
    - Barker 표기법 : 자식 쪽 관계선에 UID Bar(수직 실선) 표시