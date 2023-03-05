#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m, c;
int arr[11][11];
int vis[11][11];
int ans = -21e8;
int Select[5];
int mx_val[2];

/*
2중 for문을 돌면서 arr[i][j] ~ arr[i][j + m] 까지가 유효한 범위인지 확인
유효하면 1번째 일꾼으로 vis 체크 후 dfs 시작
기저조건 일꾼 번호가 2번째 일꾼일 때 최대값 지속 갱신
*/

bool check(int i, int j)
{
  for (int k = j; k < j + m; k++)
  {
    if (vis[i][k] > 0 || k >= n)
      return false;
  }
  return true;
}

void make_vis(int i, int j, int person)
{
  for (int k = j; k < j + m; k++)
  {
    vis[i][k] = person;
  }
}

int tot(vector<int> cal)
{
  int sum = 0;
  for (int i = 0; i < cal.size(); i++)
  {
    sum += cal[i];
  }
  return sum;
}

int cal(vector<int> cal)
{
  int sum = 0;
  for (int i = 0; i < cal.size(); i++)
  {
    sum = sum + (cal[i] * cal[i]);
  }
  return sum;
}

void dfs_cal(vector<int> per, int idx, int ii, int total, int bef)
{
  if (total > c)
    return;
  if (mx_val[idx] < bef)
    mx_val[idx] = bef;

  for (int i = ii; i < m; i++)
  {
    if (Select[i] == true)
      continue;
    Select[i] = true;
    dfs_cal(per, idx, i, total + per[i], bef + (per[i] * per[i]));
    Select[i] = false;
  }
}

void dfs(int i, int j, int person)
{
  if (person == 2)
  {
    mx_val[0] = 0, mx_val[1] = 0;
    vector<int> p1, p2;
    memset(Select, 0, sizeof(Select));
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (vis[i][j] == 0)
          continue;
        if (vis[i][j] == 1)
          p1.push_back(arr[i][j]);
        else if (vis[i][j] == 2)
          p2.push_back(arr[i][j]);
      }
    }

    if (tot(p1) <= c)
      mx_val[0] = max(mx_val[0], cal(p1));
    else
      dfs_cal(p1, 0, 0, 0, 0);

    if (tot(p2) <= c)
      mx_val[1] = max(mx_val[1], cal(p2));
    else
      dfs_cal(p2, 1, 0, 0, 0);

    int tmp_ans = mx_val[0] + mx_val[1];
    ans = max(ans, tmp_ans);

    return;
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (check(i, j))
      {
        make_vis(i, j, 2);
        dfs(i, j, 2);
        make_vis(i, j, 0);
      }
    }
  }
}

int main()
{
  int T;
  cin >> T;
  for (int tc = 1; tc <= T; tc++)
  {
    memset(arr, 0, sizeof(arr));
    memset(vis, 0, sizeof(vis));
    memset(Select, 0, sizeof(Select));
    memset(mx_val, 0, sizeof(mx_val));
    ans = -21e8;

    cin >> n >> m >> c;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        cin >> arr[i][j];
      }
    }

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (check(i, j))
        {
          make_vis(i, j, 1);
          dfs(i, j, 1);
          make_vis(i, j, 0);
        }
      }
    }

    cout << "#" << tc << " " << ans << "\n";
  }

  return 0;
}