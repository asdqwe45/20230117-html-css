// destructing

const abc={
  name:"치킨",
  typeOfMenu:"후라이드"
}

console.log(abc.name); // 치킨 

const {typeOfMenu}=abc;  // 필요한 것만 가져올 때 ... 방대한 자료를 다 가져오기는 비효율!! like include <stdio.h>
//console.log(name);   // 변수를 name으로 짓지말라는 주의!!
console.log(typeOfMenu);

//
const arr3=[1,2];

const {one,two}=arr3;

console.log(one);  // 1

// return 2개 받고 싶을 때
const sampleFunc=()=>{
  return [1,2];
}

const [one1,two2]=sampleFunc();

console.log(one); // 1
console.log(two); // 2