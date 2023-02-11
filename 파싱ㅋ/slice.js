const names=["jony","sylvie","nana"];


//slice(시작인덱스,끝인덱스 전까지) 원본이 안 잘린다.
// const newNames=names.slice(1,2);
// console.log(names);
// console.log(newNames);



//splice(시작인덱스,개수) 원본이 잘린다.
const newNames=names.splice(1,1);
console.log(names);
console.log(newNames);

var index=names.indexOf(item);
if(index!==-1){{``````````````````````````````````````````````````}
names.splice(index,1);
}