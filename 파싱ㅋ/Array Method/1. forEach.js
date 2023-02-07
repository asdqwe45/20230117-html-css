// 배열 매소드 Array.함수(콜백함수)
// addEventListener('click', function(){}) //여기서 function이 콜백함수

// Array.foreach

const arr=[1,2,3,4];

arr.forEach((value)=>{
  console.log(value);
})

for(let i=0;i<arr.length;i++){
  console.log(arr[i]);
}

const test=(value)=>{console.log(value)};
arr.forEach(test);

let cnt=0;
const x=[4,3,5,1,6,5];
x.forEach((value)=>{
  if(value%2==1)
  cnt++;
})
console.log(cnt);

const test2=(value)=>{if(value%2==1)cnt++;};
x.forEach(test2);3
console.log(cnt);

const arr2=[1,2,3,4,5];
arr2.push(6);

const array=[-5,3,4,2,-7,-2,7];

const pplus=[];
const mminus=[];
array.forEach((value)=>{
  if(value>0){
  pplus.push(value);
  }
  else{
    mminus.push(value);
  }

})
console.log(pplus);
console.log(mminus);