# add video

```xml
    <VideoView
    android:id="@+id/videoView"
    android:layout_width="wrap_content"
    android:layout_height="wrap_content"
    android:layout_margin="20dp"
    app:layout_constraintBottom_toBottomOf="parent"
    app:layout_constraintEnd_toEndOf="parent"
    app:layout_constraintStart_toStartOf="parent"
    app:layout_constraintTop_toTopOf="parent" 
    />
```


```java
    VideoView vv = findViewById(R.id.videoView);

    vv.setVideoPath("android.resource://" + getPackageName() + "/" + R.raw.we_loved);

    MediaController mc = new MediaController(this); // 미디어 컨트롤러 추가

    mc.setAnchorView(vv);

    vv.setMediaController(mc);

    vv.start();
```
![image](https://user-images.githubusercontent.com/66513003/115525992-91e92000-a2ca-11eb-8efa-9b15d7725a4d.png)
