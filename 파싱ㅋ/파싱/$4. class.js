// class StudentInfo {
//   constructor(name, age) {// 이게 생성자
//     this.name = name;
//     this.age = age;
//     this.address = "";
//   }// ',' 안 써도 됨.
//   sayMyName() {
//     console.log(`my name is ${this.name}`);
//   }
//   setAddress(address) { // setter
//     this.address = address;
//   }
//   getAddress() {  // getter
//     return this.address;
//   }
//   useMethod() {
//     this.sayMyName(); //하나의 객체 안에 있는 것을 쓸때 this.찍고 쓴다
//   }
// }

// const student1 = new StudentInfo("jony", 30);

// const student2 = new StudentInfo("david", 50);

const studentInfo = {
  name: "",
  age: -1,
  address: "",
  constructor:function(name,age){ // 화살표 함수로 this에 접근 X !!!!!
    this.name=name;
    this.age=age;
  },
  sayMyName: function () { // = sayMyName(){  축약해서 쓴다.
    console.log(`my name is ${this.name}`);
  },
  setAddress: (address) => (this.address = address),
  
  getAddress: () => this.address,
  useMethod: function () {
    this.sayMyName();
  },
};

student1.constructor("jony",30);
student2.constructor("david",50);
student1.sayMyName();
student1.setAddress("경기 군포시 산본동");
console.log(student1.getAddress());
student1.useMethod();

// 클래스는 내가 만든 타입이야. 그 안에 함수도 있는 타입!!
// this는 그 안에서만 가지고 논다.
//  그 객체가 여러개 필요한 경우 클래스가 좋다!!


const studentInfo2 = {
  name: "",
  age: -1,
  address: address, // = address,  축약해서 쓴다.
  
  sayMyName: function () { // = sayMyName(){  축약해서 쓴다.
    console.log(`my name is ${this.name}`);
  }
};

// 프로토타입 배울만 할 가치가 있지는 않다.

class Lawyer {
  constructor(name,age,intro)
  {
    this.name=name;
    this.age=age;
    this.intro=intro;
  }
  introduce(){
    console.log(`
    이름: ${this.name}
    나이: ${this.age}
    자기소개: ${this.intro}
    `);
  }
};
const A=new Lawyer("우영우",27,"기러기 토마토 스위스 역삼역");
const B=new Lawyer("최수연",27,"봄날의 햇살");
A.introduce();
B.introduce();

class Hero{
  hp=100

  showHp(){
    console.log(this.hp);
  }
  run(){
    this.hp-=10;
  }
};

const batman=new Hero;

batman.showHp();
batman.run();
batman.run();
batman.showHp();

class Person{
  constructor(name,hp){
    this.name=name;
    this.hp=hp;
  }
  hello(){
    console.log(this.name);
  }
}
class Avangers extends Person{
  constructor(name,hp,power,skill){
    super(name,hp);
    this.power=power;
    this.skill=skill;
  }

  information(){
    console.log(`
    이름: ${this.name}
    체력: ${this.hp}
    파워: ${this.power}
    스킬: ${this.skill}
    `)
  }
  fly(){
    console.log("비행중");
  }
}

const C=new Avangers("Lee",100,50,"fly");
C.information();
C.fly();