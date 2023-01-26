const arr=[1,2,3,1,2,3,1,2,3];
const k={
  count:0,
  exist:0
};
for (let i=0;i<arr.length;i++){
  if(arr[i]==1)k.count++;
}
console.log(k.count);

const arr2=["A","E","W","Q","A"];
for (let i=0;i<arr2.length;i++){
  if(arr2[i]==="A")k.exist++;
}
if(k.exist!==0)console.log("O");
else console.log("X");