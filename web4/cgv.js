console.log("TEST");

const title1=document.querySelector("#contents > div.wrap-movie-chart > div.sect-movie-chart > ol:nth-child(2) > li:nth-child(1) > div.box-contents > a > strong")
console.log(title1.textContent);

const percent1=document.querySelector("#contents > div.wrap-movie-chart > div.sect-movie-chart > ol:nth-child(2) > li:nth-child(1) > div.box-contents > div > strong > span")
console.log(percent1.textContent);

const date1=document.querySelector("#contents > div.wrap-movie-chart > div.sect-movie-chart > ol:nth-child(2) > li:nth-child(1) > div.box-contents > div > strong > span")
console.log(date1.textContent.trim());

const title2=document.querySelector("#contents > div.wrap-movie-chart > div.sect-movie-chart > ol:nth-child(2) > li:nth-child(2) > div.box-contents > a > strong")
title2.textContent="삼겹살과 그대라면";

const percent2=document.querySelector("#contents > div.wrap-movie-chart > div.sect-movie-chart > ol:nth-child(2) > li:nth-child(2) > div.box-contents > div > strong > span")
percent2.textContent="5%";

const date2=document.querySelector("#contents > div.wrap-movie-chart > div.sect-movie-chart > ol:nth-child(2) > li:nth-child(2) > div.box-contents > span.txt-info > strong")
date2.textContent=" 1985.07.27 ";

// const image1=document.querySelector("#contents > div.wrap-movie-chart > div.sect-movie-chart > ol:nth-child(2) > li:nth-child(1) > div.box-image > a > span > img")
// const image2=document.querySelector("#contents > div.wrap-movie-chart > div.sect-movie-chart > ol:nth-child(2) > li:nth-child(3) > div.box-image > a > span > img")
// const image3=document.querySelector("#contents > div.wrap-movie-chart > div.sect-movie-chart > ol:nth-child(2) > li:nth-child(1) > div.box-image > a > span > img")

// image1.src="https://img.cgv.co.kr/Movie/Thumbnail/Poster/000086/86728/86728_320.jpg";
// image2.src="https://img.cgv.co.kr/Movie/Thumbnail/Poster/000086/86072/86072_320.jpg";

// image1.url="http://www.cgv.co.kr/movies/detail-view/?midx=86072";
// image2.url="http://www.cgv.co.kr/movies/detail-view/?midx=86728";

//이미지 title swap;
//


const title3=document.querySelector("#contents > div.wrap-movie-chart > div.sect-movie-chart > ol:nth-child(2) > li:nth-child(3) > div.box-contents > a > strong")
let temp=title.textContent;
title.textContent=title3.textContent;
title3.textContent=temp;

//이미지바꿔치기
const onePoster=document.querySelector("#contents > div.wrap-movie-chart > div.sect-movie-chart > ol:nth-child(2) > li:nth-child(1) > div.box-image > a > span > img")

const threePoster=document.querySelector("#contents > div.wrap-movie-chart > div.sect-movie-chart > ol:nth-child(2) > li:nth-child(3) > div.box-image > a > span > img")
let srcTemp=onePoster.src;
onePoster.src=threePoster.src;
threePoster.src=srcTemp;

