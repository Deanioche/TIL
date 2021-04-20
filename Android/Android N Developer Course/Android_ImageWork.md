# 이미지 동작들

## .animate()

    .rotation(180f) : 회전

    .alpha(0f) : 투명도

    .translationXBy(1000f) : X 좌표 이동
    .translationYBy(1000f) : Y 좌표 이동

    .scaleX(0.5f) : X축 크기 조절
    .scaleY(10f) : Y축 크기 조절

    .setDuration(2000) : 2000ms 동안 동작

```java

ImageView avatar = findViewById(R.id.imageView);

        avatar.animate()
        .translationXBy(-100f) // X축 -100픽셀 이동
        .translationYBy(-100f)  // int는 float로 자동으로 바뀌지만 일부러 f라고 명시해준다
        .alpha(0.5f) // 투명도 0.5배
        .scaleX(0.5f) // 크기 0.5배
        .scaleY(0.5f)
        .setDuration(2000) // 2초간 동작
        .rotation(1800f); // 1800도 회전
```