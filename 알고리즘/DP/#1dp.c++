#include <iostream>

using namespace std;

// 다이나믹 프로그래밍 = 기억하기 프로그래밍(기록)
int dp[101];

// Top-Down
//  피보나치 수열
//  1 1 2 3 5 8 13 21
//  N번째 피보나치 수열을 구해라

int fibo(int n)
{
  if (n <= 2)
    return 1;

  if (dp[n] != 0)
    return dp[n];

  // 다시 여기까지 돌아오는 순간
  // =now까지의 정답을 찾았다.
  // now번째의 정답을 아니까 -> 잊지 않도록 기억(기록)
  else
    return dp[n] = fibo(n - 1) + fibo(n - 2);
}

int main()
{

  int x;
  cin >> x;
  // cout<<fibo(x);

  // Bottom-Up (Tabulation)
  //  아래의 (가장 하위의 문제)부터 순차적으로 더 상위 문제를
  //  * 점화식을 생성할 수 있어야 한다.
  //  가장 작은 문제에 대한 해답을 구해야 한다.

  dp[1] = 1;
  dp[2] = 1;
  for (int i = 3; i <= x; i++)
  {
    dp[i] = dp[i - 2] + dp[i - 1];
  }
  cout << dp[x];
  return 0;
}