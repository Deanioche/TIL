import "./styles.css";

const form = document.querySelector(".myform");
const input = form.querySelector("input");
var toDoList2 = document.querySelector(".toDoList");

const list_LS = "unit";
let toDoArr = []; // 배열 생성

function deletelist(event) {
  // console.dir(event.target); 로 부모클래스(parentNode)를 찾는다.
  console.log(event.target.parentNode);
  const btn = event.target;
  const lis = btn.parentNode;
  toDoList2.removeChild(lis);
  // toDoArr 배열에 저장된 값들이 filter함수를 통해 각각 한번씩 파라미터로 들어감 for문처럼
  const cleanlist = toDoArr.filter(function (list) {
    console.log(cleanlist);
    return list.id !== parseInt(lis.id);
  });
  toDoArr = cleanlist;
  saveToLocal();
}

//배열을 로컬에 저장
function saveToLocal() {
  localStorage.setItem(list_LS, JSON.stringify(toDoArr));
}

// 입력된 문자열에 x버튼과 id를 붙여 배열에 저장하고 saveToLocal() 실행
function showList(str) {
  const ulist = document.createElement("list"); // list라는 이름의 새로운 element 생성
  const delBtn = document.createElement("btn");
  const span = document.createElement("span");
  const setId = toDoArr.length + 1; // 배열길이 +1 을 id로 지정
  span.innerText = str;
  delBtn.innerText = "❌\n";
  delBtn.addEventListener("click", deletelist);
  ulist.appendChild(span);
  ulist.appendChild(delBtn);
  ulist.id = setId;
  toDoList2.appendChild(ulist);
  const toDoInput = { str: str, id: setId };
  toDoArr.push(toDoInput); // toDoArr의 배열 안에 toDoInput을 넣는다. (array.push)
  saveToLocal();
}

// TextField에 입력되어 submit 된 값을 showlist()함수로 보낸디.
function handleSubmit(event) {
  event.preventDefault();
  const currentValue = input.value;
  showList(currentValue);
  input.value = "";
}

// 로컬에 저장된 리스트를 불러온다
function loadList() {
  const unit = localStorage.getItem(list_LS);
  // forEach : 배열인 parsedunit의 인덱스에 저장된 값을 각각 반환해준다
  // console.log(toDo.str);
  if (unit !== null) {
    const parsedUnit = JSON.parse(unit);
    parsedUnit.forEach(function (toDo) {
      showList(toDo.str); // 파라미터에 toDO로 받아준 배열 toDoInput의 str
    });
  }
}

//loadList() 실행하고 이벤트를 받는다
function init() {
  loadList();
  form.addEventListener("submit", handleSubmit); // submit 이벤트가 발생할경우 handlwSubmit 함수 실행
}

init();
