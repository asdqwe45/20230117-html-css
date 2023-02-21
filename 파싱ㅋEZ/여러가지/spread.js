//  spread
// 객체 안을 분해해서 넣는다
const square={
  width:200,
  height:200,
}

const colorSquare={
  ...square,
  color:"red"
};

console.log(colorSquare);

// 객체 안에 객체가 생성된다 비추
const square={
  width:200,
  height:200,
}

const colorSquare={
  square,
  color:"red"
};

console.log(colorSquare);

//
const square={
  width:200,
  height:200,
}

const colorSquare={
  width:square.width,
  height:square.height,
  color:"red"
};

// 배열 spread
console.log(colorSquare);

const catTypeAnimals=["고양이","호랑이","사자"];
const dogTypeAnimals=["개","늑대","여우"];

const animals=[...catTypeAnimals,...dogTypeAnimals,"비버"];
console.log(animals);


// Rest

const chicken={
  type:"양념",
  drumsticks:2, // 닭다리
  wing:2,
}

const {type,...another}=chicken;

console.log(type);  // 양념
console.log(another); // {drumsticks:2,wing:2}


