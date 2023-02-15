#include <iostream>
#include <queue>
using namespace std;

char parent[200]; // 'A'(65) ~ 'Z'(90)
int memCnt[200];
void init()
{
  parent['A'] = 'A';
  parent['B'] = 'A';
  parent['C'] = 'A';
  memCnt['A'] = 3;
  parent['D'] = 'D';
  parent['E'] = 'D';
  parent['F'] = 'D';
  memCnt['D'] = 3;
  parent['G'] = 'G';
  parent['H'] = 'G';
  memCnt['G'] = 2;
  parent['I'] = 'I';
  parent['J'] = 'I';
  memCnt['I'] = 2;
}

char Find(char now)
{
  if (now == parent[now])
    return now;
  char ret = Find(now);
  parent[now] = ret;
  return ret;
}

int total = 4;
void Union(char a, char b)
{
  char pa = Find(a);
  char pb = Find(b);
  if (pa == pb)
    return;
  memCnt[pa] += memCnt[pb];
  memCnt[pb] = 0;
  total--;
  parent[pb] = pa;
}
int main()
{
  init();
  int N;
  cin >> N;

  for (int i = 0; i < N; i++)
  {
    char a, b;
    cin >> a >> b;
    Union(a, b);
  }
  cout << total << "개";
  // 제일 큰 그룹의 멤버 수
  int maxCnt = -1;
  for (char ch = 'A'; ch <= 'J'; ch++)
  {
    if (parent[ch] != ch)
      continue;
    if (memCnt[ch] > maxCnt)
    {
      maxCnt = memCnt[ch];
    }
  }
  cout << maxCnt;
  return 0;
}