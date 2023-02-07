const array=[3,5,4,2];

const filterArray=array.filter(data=>data>3);

const bucketList=[
  {
    id:1,
    text:"여행 가기",
    done:false,
  },
  {
    id:2,
    text:"치킨 먹기",
    done:true,
  },
  {
    id:3,
    text:"코딩 하기",
    done:true,
  },
  {
    id:4,
    text:"요리 하기",
    done:false,
  },
]

const filterBucketList1=bucketList.filter(data=>data.done===false);
console.log(filterBucketList1);

// const filterBucketList2=bucketList.filter(data=>!data.done);





