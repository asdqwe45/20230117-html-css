// const studentInfo={
//   name:"이자룡",
//   age: 31,
//   address:"경기도 군포시",
//   family:["나","와이프","고양이"],
//   skill:{
//     client:["vue.js","vanilla","react"],
//     server:["django","php","node.js"],
//     db:["sqlite","mongo","mysql","postgresql"]
//   },
// sayHi:()=>console.log("hi!!!!") // 객체안에 존재하는 함수 : 매서드
// };

// studentInfo.sayHi();

// const a=[1,2,3];
// console.log(typeof a);

const studentInfo2=new Object(); //{}

console.log(studentInfo);

const studentInfo3=new Array; //[]
console.log(studentInfo2);


// prototype!!!!!
StudentInfo4={
  name:String,
  age: Number,
  address:String,
  family:Array,
  skill: Object,
sayHi:Function
};

const student1=new StudentInfo4("jony",30);
// student1의 타입은
// StudentInfo가 된다!!
// 소문자는 함수, 대문자로 썼다는 것은 타입이다.
// 생성자가 jony와 30을 넣어준다.








