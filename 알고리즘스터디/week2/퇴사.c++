#include <iostream>
using namespace std;

int T[15];
int P[15];
int N;
int maxi;

void dfs(int lev, int sum)
{

  if (lev <= N)
  {
    maxi = max(sum, maxi);
  }
  if (lev >= N)
    return;

  dfs(lev + T[lev], sum + P[lev]);
  dfs(lev + 1, sum);
}

int main()
{

  cin >> N;

  for (int i = 0; i < N; i++)
    cin >> T[i] >> P[i];

  dfs(0, 0);

  cout << maxi << endl;

  return 0;
}