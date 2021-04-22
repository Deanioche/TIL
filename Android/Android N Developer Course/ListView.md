# ListView

```java
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        ListView listView = findViewById(R.id.myListVIew);
        
        ArrayList<String> nameList = new ArrayList<String>(asList("Nice", "Awful", "Great", "Paul"));
        nameList.addAll(asList("me", "my", "you", "your", "Bob"));

        ArrayAdapter<String> arrayAdapter = new ArrayAdapter<String>(this, android.R.layout.simple_list_item_1, nameList);// 배열을 ListView에 담을 수 있게 바꿔줌.
        listView.setAdapter(arrayAdapter); // 배열 삽입

        listView.setOnItemClickListener(new AdapterView.OnItemClickListener() { // setOn'Item'ClickListener
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) { // position = index of the list. id = similar with position
                //parent.setVisibility(View.GONE); // Disappear

                Toast.makeText(getApplicationContext(), nameList.get(position) + " has been Tapped", Toast.LENGTH_SHORT).show(); // this.MainActivity 대신 getApplicationContext()도 가능
            }
        });
    }
```
![image](https://user-images.githubusercontent.com/66513003/115644087-ecc95880-a358-11eb-8bc9-6873f0ec743a.png)