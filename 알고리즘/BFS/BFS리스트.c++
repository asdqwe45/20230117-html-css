#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> alist = {
    {1, 4},
    {2, 3},
    {},
    {},
    {},
};

char name[6] = "ACTSB";
queue<int> q;

int main()
{

  q.push(0);

  while (!q.empty())
  {
    int now = q.front();
    q.pop();

    cout << now;

    for (int i = 0; i < alist[now].size(); i++)
    {
      int next = alist[now][i];
      q.push(next);
    }
  }

  return 0;
}