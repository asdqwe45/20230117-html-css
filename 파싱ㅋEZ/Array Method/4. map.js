const array=[1,2,3,4,5,6];

const resultA=array.map(data=>{data}); //undefined로 된다.
const resultB=array.map(data=>{return data}); // 정상
const resultC=array.map(data=>data); // 정상

const result2=array.map(data=>{
  return data+1;
});

console.log(result2);

// 실습

const arr=[1,2,3,4,5];
const resultX=arr.map(data=>{
  return data*data;
});
console.log(resultX);

const arr2=["a","bcd","ef","g"];
const resultLen=arr2.map(data=>{
  return data.length;
});
console.log(resultLen);









