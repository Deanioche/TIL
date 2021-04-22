# Timetable_seekBar

```java
@Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        ListView listView = findViewById(R.id.timeTable);
        SeekBar seekBar = findViewById(R.id.seekBar);

        ArrayList<Integer> nameList = new ArrayList<Integer>(asList(1, 2, 3, 4, 5, 6, 7, 8, 9));
        ArrayList<Integer> list = new ArrayList<Integer>(nameList);

        ArrayAdapter<Integer> arrayAdapter = new ArrayAdapter<Integer>(this, android.R.layout.simple_list_item_1, nameList);// 배열을 ListView에 담을 수 있게 바꿔줌.
        listView.setAdapter(arrayAdapter); // 배열 삽입

        seekBar.setMax(20);
        seekBar.setProgress(1);

        listView.setOnItemClickListener(new AdapterView.OnItemClickListener() { // setOn'Item'ClickListener
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) { // position = index of the list. id = similar with position
                //parent.setVisibility(View.GONE); // Disappear

                Toast.makeText(getApplicationContext(), nameList.get(position) + " has been Tapped", Toast.LENGTH_SHORT).show(); // this.MainActivity 대신 getApplicationContext()도 가능
            }
        });

        seekBar.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {

                int min = 1;

                if (progress < min) { // setMin of seekBar
                    progress = min;
                    seekBar.setProgress(min);
                }
                for (int i = 0; i < list.size(); i++) {

                    nameList.set(i, list.get(i) * progress);
                }

                listView.setAdapter(new ArrayAdapter<Integer>(MainActivity.this, android.R.layout.simple_list_item_1, nameList));

                listView.setAdapter(arrayAdapter);
                
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {

            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {

            }
        });
    }
```

![ezgif com-gif-maker](https://user-images.githubusercontent.com/66513003/115649451-4b470480-a362-11eb-8c1c-4792535c83ff.gif)