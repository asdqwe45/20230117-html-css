
// 1
// const bucketLists=[
//   {id:3,text:'여행 가기',done:false},
//   {id:2,text:'치킨 먹기',done:true},
//   {id:1,text:'코딩 하기',done:false},
// ];

// // function getValues(key){
// //   const a=bucketLists.map((el)=>el[key]); // bucketLists 안에 key라는 건 없다.
// //   return a;
// // }

const getValues=(key)=>
bucketLists.map((bucketList)=>bucketList[key]); // bucketLists 안에 key라는 건 없다.

// // const ids = bucketLists.map((el) => {
// //   return el.id;
// // });
// // const texts = bucketLists.map((el) => {
// //   return el.text;
// // });
// // const dones = bucketLists.map((el) => {
// //   return el.done;
// // });

// console.log(getValues('id'));
// console.log(getValues('text'));
// console.log(getValues('done'));


// 2
// let bucketLists = [
//   { id: 3, text: "여행 가기", done: false },
//   { id: 2, text: "치킨 먹기", done: true },
//   { id: 1, text: "코딩 하기", done: false },
// ];

// const removeList = (id) => bucketLists.filter((el) => el.id !== id);

// const A=removeList(1);

// console.log(A);


// 3


let bucketLists = [
    { id: 3, text: "여행 가기", done: false },
    { id: 2, text: "치킨 먹기", done: true },
    { id: 1, text: "코딩 하기", done: false },
  ];

  const toggle = (id) => {
    const newBucketLists = structuredClone(bucketLists); // 깊은복사
    const ret = newBucketLists.filter((el) => el.id === id);  // filter는 항상 어레이를 반환한다.
    //  필터로 반환한 객체는 주소도 포함이니까 단순 변수에 값을 넣은 것이 아니다.
    if (ret[0].done) {            // 하나니까  0번 인덱스
      ret[0].done = false;
    } else {
      ret[0].done = true;
    }
    return newBucketLists;
  };

  console.log(toggle(1));

  