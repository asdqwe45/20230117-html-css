const array=[1,2,3,4,5];
const inventory=[
  {name:"A",quantity:1},
  {name:"B",quantity:2},
  {name:"C",quantity:3}
]


// find -> 해당하는 배열의 값을 가져온다.
const result1=array.find(element=>element>4);
console.log(result1);

//name이 B인 배열의 값을 가져온다.
const result2=inventory.find(li=>li.name==="B");
console.log(result2);

// findIndex -> 해당하는 index를 가져온다.

const result3=inventory.findIndex(li=>li.name="B");
console.log(result3);

// 실습
const chicken=[
  {name:"머리",quantity:1},
  {name:"날개",quantity:2},
  {name:"닭다리",quantity:2},
  {name:"닭가슴살",quantity:1},
  {name:"닭발",quantity:2}
]

const result_chick1=chicken.find(li=>li.name==="닭다리");
const result_chick2=chicken.findIndex(li=>li.name==="닭다리");
console.log(result_chick1);
console.log(result_chick2);