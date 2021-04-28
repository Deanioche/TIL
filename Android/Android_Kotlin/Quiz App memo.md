# Quiz App Memo

1. 액션 바(상단 바) 없애기
- AndroidManifest.xml에 스타일 추가
    ```xml
    <style name="NoActionBarTheme" parent="Theme.AppCompat.Light.NoActionBar">
        <!-- Primary brand color. -->
        <item name="colorPrimary">@color/purple_500</item>
        <item name="colorPrimaryVariant">@color/purple_700</item>
        <item name="colorOnPrimary">@color/white</item>

    </style>
    ```
    - parent : Theme.AppCompat.Light.NoActionBar를 상속해준다.
    - 액션 바가 없더라도 컬러는 넣어주어야 한다.