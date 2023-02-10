async function setRenderBackground() {
  // body의 background 주소를 넣어도 OK

  // 일부러 axios 요청으로 이미지를 받아오기

  const result = await axios.get("https://picsum.photos/1280/720", {
    responseType: "blob",
  });
  console.log(result.data);
  // URL.createObjectURL -> 임시 URL을 만든다(페이지 내에서만 유효)
  // 받아온 데이터를 임시 URL을 만들어서 그 URL에 body에 넣는다.
  const imageURL = URL.createObjectURL(result.data);
  document.querySelector("body").style.backgroundImage = `url(${imageURL})`;
}

// const setRenderBackground= async ()=>{} 화살표함수 async

function setTime() {
  const timer = document.querySelector(".timer");

  setInterval(() => {
    // date함수
    const date = new Date();
    timer.textContent = `${date.getHours()}:${date.getMinutes()}:${date.getSeconds()}`;
  }, 1000);
}

function getMemo() {
  //localStorage로부터 가져와서 memo에 넣어주는 작업
  const memo = document.querySelector(".memo");
  memo.textContent=localStorage.getItem('todo');
}

function setMemo() {
  const memoInput = document.querySelector(".memo-input");
  // console.log(e.code);
  // console.log(e.target);
  // console.log(e.target.value);

  memoInput.addEventListener("keyup", function (e) {
    if (e.code === "Enter"&&e.target.value )  {
      // 메모를 저장
      // getMemo로 분리
      
      const memo = document.querySelector(".memo");
      memo.textContent = e.target.value;
      
      //메모가 날아가지않도록 저장
      // 백엔드 -> DB에 저장해서 가져오는 작업
      // 브라우저에더 간단한 저장소 개념이 있다. localStorage
      // localStrage.setItem('키','넣을 값')
      localStorage.setItem('todo',e.target.value);
      // localStorage.getItem('키')  -> 값을 가져온다.
      // getMemo로 분리
      getMemo();
      e.target.value="";

    }
  });
}

function deleteMemo(){
  // 이벤트위임
  document.addEventListener('click',function (e){
    console.log(e.target);

    if(e.target.classList.contains('memo')){
      localStorage.removeItem('todo');
    }
  })
}


async function allRender() {
  // 시작화면 세팅
  setRenderBackground();
  setTime();
  setMemo();
  getMemo();

  //5초마다 해당 콜백함수 반복
  setInterval(() => {}, 5000);
}

allRender();
