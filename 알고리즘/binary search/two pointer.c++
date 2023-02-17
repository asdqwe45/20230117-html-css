#include <iostream>
using namespace std;
int main()
{
  // int arr[] = { 1, 2, 3, 1, 2, 3, 5, 6, 7, 8 };
  //// target
  // int target = 1;
  //// two pointer
  // int left = 0; // slow pointer
  // int right = 0; // fast pointer
  //// 내가 지금 left와 right포인터가 가리키고 있는 구간의 합
  // int sum = 0;
  // int cnt = 0;
  // while (left <= 10 && right <= 10) {
  //     if (sum == target) {
  //         cnt++;
  //         sum -= arr[left];
  //         left++;
  //     }
  //     else if (sum < target) {
  //         // sum에 fast pointer (right)가 가리키는 값을 더하고
  //         sum += arr[right];
  //         // right를 한 칸 이동
  //         right++;
  //     }
  //     else if(sum > target){
  //         // sum에서 left 포인터가 가리키는 값을 빼고
  //         sum -= arr[left];
  //         // left를 한칸 이동
  //         left++;
  //     }
  // }
  // cout << cnt;
  int arr[] = {1, 1, 8, 1, 2, 3, 5, 6, 7, 8};
  int N = 3; // 구간 크기

  // sliding window
  // 1. 초기 포인터 세팅
  int left = 0;
  int right = N - 1; // index가 0부터 시작하는 경우 -> 구간 크기 - 1
  // 2. 초기 공통 구간 세팅
  int sum = 0;
  for (int i = left; i < right; i++)
    sum += arr[i];
  // 3. sliding window
  int ans = 21e8;
  // right 포인터가 범위를 벗어나지 않을때까지
  while (right < 10)
  {
    // 구간 완성
    sum += arr[right];
    // 수행
    if (sum < ans)
      ans = sum;
    cout << "SUM : " << sum << '\n';
    // 다음 공통 구간 만들기
    sum -= arr[left];
    // left와 right 포인터 이동
    left++;
    right++;
  }
  cout << ans;
}