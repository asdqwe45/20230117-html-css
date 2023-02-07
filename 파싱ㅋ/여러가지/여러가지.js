//부정의 의미
// undefined
// null
// 0
// ''(빈문자열)
// false

// 긍정의 의미
// 부정의 의미를 제외한 것
// 빈배열과 빈 객체는 긍정!!!!!!!!!!!!!

const dataFromServer = [
  {
    name: "jony",
    age: 30,
  },
  {
    name: "sylvie",
    age: 30,
  },
  {
    name: "nana",
    age: 1,
  },
];

//있다!
if (dataFromServer) {
  console.log("있다!");
} else {
  console.log("없다");
}

const dataFromServer2 = [];
// 없다
if (dataFromServer2.length) {
  console.log("있다!");
} else {
  console.log("없다");
}

const dataFromServer3 = [];
// 있다!
if (dataFromServer3 !== []) {
  console.log("있다!");
} else {
  console.log("없다");
}


//
const arr1 = [1, 2, 3];
const arr2 = [1, 2, 3];

console.log(arr1 === arr2); // false 주소가 다르기 떄문에 비교가 안된다.


//
const sampleObject = {};
// 있다고 나옴 조심해!!
if (sampleObject === {}) { // !를 쓰면 가동석이 떨어짐 긍정이 더 가독성이 좋음!!! 
  console.log("데이터 없음");
} else {
  console.log("데이터 있음");