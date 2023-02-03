#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int arr[5][5] = {
    0,1,0,0,1,
    0,0,1,1,0,
    0,0,0,0,0,
    0,0,0,0,0,
    0,0,0,0,0,
};

char name[6] = "ACTSB";

queue<int> q;

int main()
{

  // 1. 초기세팅
  q.push(0);

  while (!q.empty())
  {

    // 1. 큐에서 하나 뺀다.
    int now = q.front();
    q.pop();

    cout << name[now];

    // 2. 연결된거 찾아 큐에 넣기
    for (int i = 0; i < 5; i++)
    {
      if (arr[now][i] == 0)
        continue;
      q.push(i);
    }
  }

  return 0;
}