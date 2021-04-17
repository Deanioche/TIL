## MainActivity.java 임시 메모

```java
// 앱이 실행되면 MainActivity 클래스 호출
public class MainActivity extends Activity { 

    // 이벤트 동작에 쓰이는 변수들
    Toast mToast = null;
    int count;
    String str;
    SoundPool mPool;
    AudioManager mAm;

    // 앱 기동시 가장 먼저 호출되는 메소드
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState); // 상속한 onCreate 부모클래스에 정보를 보냄.
        setContentView(R.layout.activity_main); // 화면에 activity_main.xml를 띄운다.

        // Timer
        mTimer = findViewById(R.id.timer);
        mHandler.sendEmptyMessage(0); // 0이 의미??? 
        // 아래 Handler 클래스의 Delayed() 메소드의 0과 달라도 타이머가 작동함

        // Sound
        mPool = new SoundPool(1, AudioManager.STREAM_MUSIC, 0); // 효과음 출력용
        mAm = (AudioManager) getSystemService((AUDIO_SERVICE)); // 효과음 출력용

        // 클릭 이벤트에 반응할 요소들의 id 입력
        // 해당 id를 가진 요소를 클릭시 mClickListener가 호출된다.
        findViewById(R.id.shortmsg).setOnClickListener(mClickListener);
        findViewById(R.id.longmsg).setOnClickListener(mClickListener);
        findViewById(R.id.count).setOnClickListener(mClickListener);
        findViewById(R.id.customview).setOnClickListener(mClickListener);
        findViewById(R.id.mymsg).setOnClickListener(mClickListener);
        findViewById(R.id.mysound).setOnClickListener(mClickListener);
    } // onCreate


    // Timer 출력용
    Handler mHandler = new Handler() { // Hander @Deprecated 
        public void handleMessage(Message msg){
            value++;
            mTimer.setText("Timer Value = " + value);
            mHandler.sendEmptyMessageDelayed(0,1000); // 1초단위로 바뀜
        }
    };


    Button.OnClickListener mClickListener = new Button.OnClickListener() 
                                            // OnClickListener 익명클래스
    {
        public void onClick(View v) {

            TextView tv = findViewById(R.id.mysound); // id.mysound의 Text를 저장

            switch(v.getId()) {
                case R.id.shortmsg: // id.shormsg가 눌렸을시
                    Toast.makeText(MainActivity.this, "Short Time Message",
                            Toast.LENGTH_SHORT).show(); // 토스트 출력
                    break;
                case R.id.longmsg:
                    Toast.makeText(MainActivity.this, "Long Time Message",
                            Toast.LENGTH_LONG).show();
                    break;
                case R.id.count:
                    str = "Count = " + count++;
                    if(mToast != null) // 토스트 출력중이면 해당 토스트 숨김
                    {
                        mToast.cancel();
                    }
                    mToast = Toast.makeText(MainActivity.this, str,
                            Toast.LENGTH_SHORT); // 토스트 객체를 저장
                    mToast.show();
                    break;
                case R.id.customview:
                    LinearLayout linear =
                            (LinearLayout)View.inflate(MainActivity.this,
                                    R.layout.toast_view, null); // 레이아웃 객체 생성
                    Toast t2 = new Toast(MainActivity.this); // MainActivity 위에 띄울 토스트 객체 생성
                    t2.setView(linear); //객체에 레이아웃 담기
                    t2.show(); 
                    break;
                case R.id.mymsg:
                    LinearLayout myLinear =
                            (LinearLayout) View.inflate(MainActivity.this, R.layout.my_view, null);
                    Toast t3 = new Toast(MainActivity.this);
                    t3.setView(myLinear);
                    t3.show();
                    String mytxt = "응애~";
                    count += 100;
                    Toast.makeText(MainActivity.this, mytxt, Toast.LENGTH_SHORT).show();

                    tv.setText("무야~호~"); // tv객체의 text 변경
                    break;
                case R.id.mysound:
                    //mPool.play(mDing, 1, 1, 0, 0, 1);
                    mAm.playSoundEffect((AudioManager.FX_KEYPRESS_SPACEBAR)); // 사운드 재생
                    break;

            } //of switch
        } //of onClick
    };
```