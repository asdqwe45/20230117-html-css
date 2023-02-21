#include <iostream>

using namespace std;

// 거스름돈
/*
1200 5
10 50 100 400 500
*/

// Memoization (Top-Down)
// - 정석적인 방법(재귀 동작에 대한 이해도가 있다.)
// - 아마 이 방법이 설계하기 더 쉽다.
// - 가지치기, backtracking, return 조건 이런것만 생각하고 구성
//  아주 조건이 까다로워도 생각보다 코드 짜는게 어렵지 않을 것
// - 재귀 호출 + return 취합 => tabulation보다는 비교적 느림
// - 모든 문제를 풀지 않음 ( 내가 풀어야 하는 문제만 푼다.)

// Tabulation (Bottom-Up)
// - 점화식 구성이 필요하므로 상대적으로 쉽게 구성 X
// - 점화식 구성에 조건이 까다로우면 점화식 만들기도 쉽지 않다.
// - 최하위 문제로부터 N까지 모든 문제를 푼다.
// -

// index : 특정 거스름돈 액수
// value : 그 거스름돈을 돌려주기 위한 최소 동전 개수

int dp[10001];
int target;
int N;
int coins[100];

// #1.  Top-Down
int func(int now)
{
  // 기저 조건
  if (now == 0) // 답을 찾았다.
  {
    return 0;
  }
  if (now < 0) // 오답이다.
    // now까지의 기록에 최소값이 저장될 수 있도록
    // 영향을 미칠 값 즉, 아주 큰 값을 return
    return 21e8;
  // 만약 now에 대한 답이 기억되고 있다면 그 값 리턴
  if (dp[now] != 0)
    return dp[now];

  // 재귀 구성
  //  now에서 모든 동전을 하나씩 빼가면서 쭉 쭉 내려가본다.
  int MIN = 21e8;
  for (int i = 0; i < N; i++)
  {
    // now로 다시 올라오면
    // func(now-coins[i])+1
    int temp = func(now - coins[i]) + 1;
    // 이 temp가 최소인가?
    if (temp < MIN)
      MIN = temp;
  }
  // now까지 올라왔을 때, 하위 문제의 답을 모두 췹하여
  // 그  중 가장 작은 값을 dp[now]에 기록
  return dp[now] = MIN;
}

int main()
{
  cin >> target >> N;
  for (int i = 0; i < N; i++)
    cin >> coins[i];

  // cout << func(target);

  // Bottom-Up
  //  #0. 최소값
  for (int i = 0; i <= target; i++)
    dp[i] = 21e8;
  // #1. 찾을 수 있는 가장 작은 문제에 대한 해답
  dp[0] = 0;

  for (int i = 0; i < N; i++)
  {
    int now = coins[i];
    for (int j = now; j <= target; j++)
    {
      // 지금 위치에서 내 동전의 값만큼을 뺀 공간에서
      // 동전을 하나 더 추가했을 때 => 지금 now를 만들 수 있는 값이 나온다.
      // 이미 dp에 기록된 값보다 많은 개수로 만들게 된다면 -> 갱신 X
      if (dp[j - now] + 1 < dp[j])
        dp[j] = dp[j - now] + 1;
    }
  }

  /*for (int i = 0; i <= target; i+=100)
    cout <<i<<" : "<< dp[i] << '\n';*/

  cout << dp[target];
  return 0;
}