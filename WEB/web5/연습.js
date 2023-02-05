let name="key";

name1="control";

console.log(name);

// var : 재선언과 값 변경 가능
// let : 변경 가능
// conts: 다 불가능 선언 시 바로 초기화 해야됨

const i=1;
const name="Lee";
const a=true;
const b=false;
console.log(typeof i);
console.log(typeof name);
console.log(typeof a);
console.log(typeof b);
console.log(typeof undefined);
console.log(typeof null);

// 정수, 실수 : number
// string : ch[]
// boolean : true,false
// typeof(undefined) : undefined 의도치 않게 비어있음
// typeof(null) : object  의도적으로 비워 둠.

const c=[1,2,3,4,5,6,7,8,9,10];
console.log(c[9]);

const Person={

  name:['Bob','Smith'],

age:32,

gender:'male',

interest:['music','skiing'],

bio:function(){
  alert(this.name[0]+' '+this.name[1]+' is '+
  this.age+' years old. He likes '+this.interest[0]+' and '+
  this.interest[1]+ '.');
},

greeting:function(){
  alert('Hi! I\'m '+this.name[0]+'.');
}

};

console.log(Person.name);
console.log(Person.name[0]);
console.log(Person.age);
console.log(Person.bio());
console.log(Person.greeting());

function retA(){
 Person.greeting();
}

const d=retA;
console.log(d());

// 안되는 경우
const e=retA();
console.log(e());

const people={
  name:["Lee","Kim","Park"],
  age:[20,21,22],
  hobby:["soccer","swimming","table tennis"]
};

// 객체에 추가 변경
people.hometown=["Gwang-ju","Seoul","Sang-ju"];
people.hometown[2]="Mok-po";

for(let i=0;i<3;i++)
{
  console.log("name : "+people.name[i]+"\n"+
  "age : "+people.age[i]+"\n"+
  "hobby : "+people.hobby[i]+"\n"+
  "hometown : "+people.hometown[i])
}

const people1={
  name:["Lee","Kim","Park"],
  age:[20,21,22],
  hobby:["soccer","swimming","table tennis"]
};
const people2={
  name:["Lee","Kim","Park"],
  age:[20,21,22],
  hobby:["soccer","swimming","table tennis"]
};

console.log(people1===people2); // false

const people3=people1;

console.log(people1===people3); // true



const people4={
  name:["Lee","Kim","Park"],
  age:[20,21,22],
  hobby:["soccer","swimming","table tennis"]
};

people4.age[3]=12;
console.log(people4.age[3]);