#include <iostream>
#include <algorithm> // <== 정렬 기능이 포함된 라이브러리(min,max)
using namespace std;

// 정렬
// -> 특정 집합의 요소들을 특정 기준으로 나열하는 것

// 정렬 알고리즘
// STL의 정렬 기능을 그냥 가져다가 쓸 것이다.
// --> STL에서 구현된 정렬 알고리즘 = 굉장히 "안정적"
// --> STL에서 만들어진 정렬의 시간복잡도는 "항상" 0(NlogN) 보장
// --> C++ >> Intro Sort
// --> 힙정렬 + 삽입정렬 + 퀵정렬 ==>하이브리드 정렬

bool cmp(int left, int right)
{
  // return left > right;

  // left > right : true
  // left < right : false

  if (left < right)
    return false;
  if (left > right)
    return true;
  // 모든 조건들이 같을 때
  return false;
}

struct Student
{
  string name;
  int age;
  int grade;
};

bool ssafycmp(Student left, Student right)
{ // 1. 시험 점수 높은 사람 중,
  if (left.grade > right.grade)
    return true;
  if (left.grade < right.grade)
    return false;
  // 2. 나이가 많은 사람,
  if (left.age > right.age)
    return true;
  if (left.age < right.age)
    return false;
  // 3. 이름이 사전순으로 빠른 사람
  if (left.name < right.name)
    return true;
  if (left.name > right.name)
    return false;
  return false;
}

int main()
{
  int arr[] = {1, 3, 3, 4, 2, 6};
  // 정렬방법
  // sort(RandomAccessIterator,RandomAccessIterator)
  // Iterator : 포인터
  // 배열 자체 = 포이터
  // cout << arr;// arr[0]번이 존재하는 메모리의 주소
  // 정렬이 되는 구간 : first부터 "last 전"의 주소까지
  // sort(배열의 시작 주소 (정렬을 하려고하는 시작 위치, 배열의 끝 주소

  // 오름차순 정렬
  /*sort(arr, arr + 6);

  for (int i = 0; i < 6; i++)
    cout << arr[i];*/

  // 내림차순 정렬        sort(시작 주소, 배열 끝 주소, 함수)
  sort(arr, arr + 6, cmp);
  for (int i = 0; i < 6; i++)
    cout << arr[i];

  // 사용자 정의 정렬

  Student ssafy[5];
  // 시험 점수 높은 사람 중, 나이가 많은 사람, 이름이 사전순으로 빠른 사람
  ssafy[0] = {"송유빈", 3, 100};
  ssafy[1] = {"박준형", 4, 100};
  ssafy[2] = {"김택우", 2, 100};
  ssafy[3] = {"김기덕", 4, 100};
  ssafy[4] = {"이득화", 7, 25};

  sort(ssafy, ssafy + 5, ssafycmp);

  for (int i = 0; i < 5; i++)
    cout << ssafy[i].name << endl;

  return 0;
}
