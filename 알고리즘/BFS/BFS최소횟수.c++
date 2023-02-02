#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Node
{
  int n;
  int lev;
};

vector<vector<int>> alist(5);
int used[5];
queue<Node> q;

int main()
{

  alist[0] = {1, 2, 3};
  alist[1] = {2, 3};
  alist[2] = {3};
  alist[3] = {4};

  q.push({0, 0});
  while (!q.empty())
  {
    Node now = q.front();
    q.pop();

    if (now.n == 4)
    {
      cout << now.lev;
      break;
    }

    for (int i = 0; i < alist[now.n].size(); i++)
    {
      int next = alist[now.n][i];
      if (used[next])
        continue;
      used[next] = 1;
      q.push({next, now.lev + 1});
    }
  }

  return 0;
}