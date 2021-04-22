# Timer

Timer 1
```java
    Handler handler = new Handler();
    // 핸들러는 코드의 실행을 지연시키거나 일정 시간마다 반복 시킬 수 있다.

    Runnable run = new Runnable() {
        @Override
        public void run() {

            // Insert code to be run every second.

            Log.i("Runnable has run!", " 1 sec passed");

            handler.postDelayed(this, 1000); //run method run() every 1s.

        }
    };

    handler.post(run);
```

Timer 2
- 타이머 종료 후 제거됨.
```java
    new CountDownTimer(10000, 1000) { // 10sec, 1 tick : 1sec
        @Override
        public void onTick(long millisUntilFinished) { // millisUntilFinished : ms left to finish

            // Countdown is counting down (every second)

            Log.i("sec left", String.valueOf(millisUntilFinished/1000));
        }

        @Override
        public void onFinish() {

            // When counter is finished. (after 10 second);
            Log.i("Done!","Countdown timer finished");
        }

    }.start(); // CountDownTimer() object is destroyed after finish;
```