#include <iostream>
#include <cmath>
using namespace std;

int nums[100];
int N;
int oper[4];
int mini, maxi;

void dfs(int lev, int plus, int minus, int mul, int sub, int sum)
{
  if (lev == N)
  {
    mini = min(mini, sum);
    maxi = max(maxi, sum);
    return;
  }

  if (plus >= 1)
    dfs(lev + 1, plus - 1, minus, mul, sub, sum + nums[lev]);
  if (minus >= 1)
    dfs(lev + 1, plus, minus - 1, mul, sub, sum - nums[lev]);
  if (mul >= 1)
    dfs(lev + 1, plus, minus, mul - 1, sub, sum * nums[lev]);
  if (sub >= 1)
  {
    dfs(lev + 1, plus, minus, mul, sub - 1, sum / nums[lev]);
  }
}

int main()
{
  cin >> N;

  maxi = -2e8;
  mini = 2e8;

  for (int i = 0; i < N; i++)
    cin >> nums[i];

  for (int i = 0; i < 4; i++)
    cin >> oper[i];

  dfs(1, oper[0], oper[1], oper[2], oper[3], nums[0]);

  cout << maxi << endl;
  cout << mini << endl;

  return 0;
}