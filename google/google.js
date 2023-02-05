const btn=document.querySelector(".toggle-button");
const backGround=document.querySelector("body");
const bookmarkText=document.querySelectorAll(".bookmark-item");
const anotherText=document.querySelector(".header-nav-list-wrapper");

btn.addEventListener("click",function(){
  btn.textContent="다크모드";
  btn.classList.toggle("btn-dark-mode");
  backGround.classList.toggle("body-dark");
  anotherText.classList.toggle("another-Text");

  for(let i=0;i<bookmarkText.length;i++)
  {
  bookmarkText[i].classList.toggle("bookmark-Text");
  }

  if(btn.classList.contains("btn-dark-mode")===true)
  {
    btn.textContent="일반모드";
  }


});
