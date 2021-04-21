# 리소스 id 받기


여러 버튼의 onClick에 buttonTapped메소드를 입력.

1. View의 id

```java
    public void buttonTapped(View v) {

        int id = v.getId(); // 해당 View의 id값 반환

        String ourId = v.getResources().getResourceEntryName(id); 
        // 받은 id의 별명 반환 
        // ex : android:id="@+id/hello" 에서 hello를 반환

        int resourceId = getResources().getIdentifier(ourId, "raw", "com.android.myapplication"); // (파일명, 파일이 들어있는 패키지(폴더)명, 프로젝트의 패키지명)
        // 패키지 안의 raw폴더에서 파일명이 ourId와 일치하는 파일의 id 반환

        MediaPlayer mplayer = MediaPlayer.create(this, resourceId); 

        mplayer.start();

    }
```
![image](https://user-images.githubusercontent.com/66513003/115581329-e01a1580-a302-11eb-9e79-d28168a5125f.png)