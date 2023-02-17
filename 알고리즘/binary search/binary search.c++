#include <iostream>
#include <algorithm>
using namespace std;
// int arr[] = { 3, 99, 21, 33, 4, 1, 5, 55, 7, 10 };
//  binary search = 무조건 정렬이 필요하다.
//  binary search 언제 써야 효율적?
//  --> 내가 단순하게 하나의 값이 있는가? 체크할때 -> O(N)
//  --> 여러번 찾아야 할때
// void bs(int target) {
//     // #1. 내가 어떤 범위를 탐색하는가?
//     // --> 배열 내에만 존재하는 요소를 찾는다 : index
//     // --> 특정 정수 내의 범위이다 : 시작 끝
//     int left = 0;
//     int right = 9;
//     int flag = 0;
//
//     while (left <= right) {
//         // mid를 예측한다!
//         int mid = (left + right) / 2;
//         // 만약 mid가 내가 찾고자 하는 값이라면
//         if (arr[mid] == target) {
//             // 찾았다!
//             flag = 1;
//             // 이미 찾았으면 더 탐색해볼 필요 X
//             break;
//         }
//         else if (target < arr[mid]) {
//             right = mid - 1;
//         }
//         else if (target > arr[mid]) {
//             left = mid + 1;
//         }
//     }
//     // 찾앗으면 1, 아니면 0
//     cout << flag;
// }
int N;
int arr[4];
int MAX;
bool condition(int val)
{
  int sum = 0;
  for (int i = 0; i < N; i++)
  {
    if (arr[i] > val)
      sum += val; // 상한선만큼밖에 줄수 없어
    else
      sum += arr[i];
  }
  if (sum > MAX)
    return false;
  return true;
}
void psearch(int low, int high)
{
  int left = low;   // 상한선 범위의 가장 낮은값 = 0원
  int right = high; // 상한선 범위의 가장 큰 값 = 내가 가진 전부
  int ans = 0;
  while (left <= right)
  {
    // 가능성 -> 정답이라고 가정한 값
    int mid = (left + right) / 2;
    // 이 가능성이 정답이 될수 있어?
    if (condition(mid) == true)
    {
      // 정답이 될 가능성이 있는 값을 찾았다!
      ans = mid;
      // 더 많은 금액을 줄 수 있는가?
      // 더 상한선을 높게 잡아도 가능한가?
      left = mid + 1;
    }
    else
    {
      // 이 값이 정답이 될수 없어
      // 너무 상한선을 높게 잡았다
      // 상한선의 가장 큰 값의 범위를 낮춘다.
      right = mid - 1;
    }
  }
  cout << ans;
}
int main()
{
  // int target; // 찾고자 하는 숫자
  // cin >> target;
  //  arr안에 이 target이 있느냐?
  //  O(N)
  //  예) 1000개의 정수가 있는 배열 -> 1000번의 Query
  //  O(N) * O(Q) = O(N^2) = 100만
  // int flag = 0;
  // for (int i = 0; i < 10; i++) {
  //     if (arr[i] == target)
  //         flag = 1;
  // }
  // cout << flag;
  //  binary search
  //  target을 찾아가는 이분탐색
  //  예) 1000개의 정수가 있는 배열 -> 1000번의 Query
  //  O(Nlog(2)N) = 만번
  //  O(NlogN)
  // sort(arr, arr + 10);
  //// O(logN)
  // bs(target);
  //  parametric search
  //  내 회사 - 연봉 협상시기
  //  N명의 직원들이 있다
  //  내가 사장 -> 각 직원들이 얼마만큼의 인상을 원하는지를 알고 있다.
  //  총 연봉을 올려줄수 있는 금액은 정해져 있다.
  //  4
  //  100 200 300 400
  //  400
  //  모두 최대한 주고 싶은데, 어떤 상한선을 정해야 한다.
  //  상한선을 정했을때, 만약 상한선보다 적게 원하면 다 주고
  //  아니면, 정한 이 상한선 만큼
  //  상한선을 얼마로 조정해야 할까?
  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> arr[i];
  cin >> MAX;
  psearch(0, MAX);
}