// 백틱
//  ``
const myName="이온유";

//문자열 자바스크립트 혼합 OK
const introduce="제 이름은" +myName+"입니다";

const introduce2=`제 이름은 ${myName} 입니다.`;


// 백틱은 enter를 허용한다.

// 오류 발생
const hello="안녕하세요"+
"저는"
+"치킨입니다.";

const hello2=`
안뇽하세요
저는
치킨입니다.
`;

//adjectHtmlElement 문자열로 된 html 태그를 집어넣기

const a=`
<div class="a">
안녕하세요
</div>
`

const bb=(hello)=>`
<div class="a">
${hello}
</div>
`;
bb();

document.querySelector('body').insertAdjacentHTML('beforeend',b);


//원시타입 stack
// Number,string,Boolean,null,undefined


//객체타입 heap(참조형)
// Array
// function
// object