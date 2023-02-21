const datas=[0, 1,2,3,4];

const accResult=datas.reduce((acc,cur)=>{
  console.log(acc,cur);
  return acc+cur;
},1);   // 1은 초기값설정  
//         생략 시 datas[0]이고 cur=1로 된다. 따라서 배열 내의 값들의 합을 구함.

console.log(accResult);

// reduce를 다른 사람들이 이해하기 힘듬.


const studentInfo=[
  {
    name:"jony",
    age:30,
  },
  {
    name:"sylvie",
    age:30,
  },
  {
    name:"nana",
    age:1,
  }
];

// name 만 가진 새 배열을 만들어라.
// map
// const newStudentInfo=studentInfo.map((student)=>student.name);

// console.log(newStudentInfo);

// // reduce
// const resultName=studentInfo.reduce((acc,cur)=>{
//  acc.push(cur.name);
//  return acc;
// },[])
// console.log(resultName);

// // filter

// const over30Name=studentInfo.filter((data)=>{
//   return data.age===30;
// })

// const over30Name2=studentInfo.reduce((acc,cur)=>{
//   if(cur.age===30)
//   {
//     acc.push(cur.name);
//   }
//   return acc;
// },[]);
// console.log(over30Name2);

//
const newStudentInfo=studentInfo.map((student,idx)=>{
  console.log(student,idx);
  return student.name;
})
console.log(newStudentInfo);