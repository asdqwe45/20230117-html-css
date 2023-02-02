#include <iostream>
#include <vector>
using namespace std;

struct Node
{
  int n;
  int price;
};

vector<vector<Node>> v(4);
int used[10];

void run(int now, int sum)
{
  if (now == 3)
  {
    cout << sum << endl;
    return;
  }
  for (int i = 0; i < v[now].size(); i++)
  {
    Node next = v[now][i];
    if (used[next.n])
      continue;
    used[next.n] = 1;
    run(next.n, sum + next.price);
    used[next.n] = 0;
  }
}

int main()
{
  v[0] = {{1, 5}, {2, 7}, {3, 10}};
  v[1] = {{2, 2}, {3, 1}};
  v[2] = {{0, 90}, {3, 1}};

  used[0] = 1;
  run(0, 0);

  return 0;
}