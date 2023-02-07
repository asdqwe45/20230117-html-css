// 파싱 기존의 데이터 셋을 새로운 데이터 셋으로 만드는 일

const students = [
  {
    name: "김도훈",
    age: 26,
    address: "경남 창원시",
  },
  {
    name: "김기홍",
    age: 27,
    address: "광주광역시",
  },
  {
    name: "김택우",
    age: 30,
    address: "인천광역시",
  },
];

// Array.forEach  array여야만 한다.
// 길이를 알 필요가 없다.
// return 값이 없다. => 돌면서 할 일 하겠다.
// students.forEach((student)=>{
// console.log(student.name);
// });

// map은 새로운 배열을 만들고 싶을 때 쓴다.
// map은 원형의 데이터를 손상시키지 않게 백업해 둘 수 있다.
// const names=students.map((student)=>{
// return student.name;
// });
// console.log(names);

// filter는 길이가 다르다.
// 조건에 맞는 새로운 배열을 만든다. => 그래서 길이가 다름.
// 조건은 return안에 있다.
// filter로 조건에 맞는 객체만 가져올  수 있다.
// 객체 내의 요소를 가져올 수 없다.

// const under30people=students.filter((student)=>{
//   return student.age<30;
// });

// const under30people=students.filter((student)=>student.age<30);

// const under30names=under30people.map((student)=>{
//   return student.name;
// })

// console.log(under30names);

// 다시 쓸거라서 함수로 만들었따.
function sampleFunc(student) {
  return student.age < 30;
}

const under30people = students.filter(simpleFunc);

const under30names = under30people.map((student) => student.name);

console.log(under30names);

// 실습
const arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];

const isEvenArray = arr.filter((Num) => Num % 2 === 0);

const isEvenArray10 = isEvenArray.map((Num) => Num * 10);

console.log(isEvenArray10);
