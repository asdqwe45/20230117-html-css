// #1
// 함수 표현식

const a = function () {
  console.log("aa");
};
// 화살표 함수
const b = () => console.log("bb");
const c = () => console.log("cc");

b();
c();


// #2
const sum1=(a,b)=>{return a+b};
sum1(3,4);

// return이 생략된 형태로 가능
const sum2=(a,b)=>a+b;
sum2(3,4);

// 실습
const t=(a)=>a*a;
t(10);


// #3


