
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, width, height;
int block[15][15];
int maxRemoveCnt;

struct Coord
{
  int y, x;
};

Coord getFirstDropAxis(int index)
{
  for (int y = 0; y < height; y++)
  {
    if (block[y][index] != 0)
    {
      return {y, index};
    }
  }
  return {-1, -1};
}

int RemoveBlock_BFS(Coord startPoint)
{
  int removeCnt = 1;

  queue<Coord> q;
  q.push(startPoint);
  int isReg[15][15] = {0};
  isReg[startPoint.y][startPoint.x] = 1;

  int directY[4] = {-1, 1, 0, 0};
  int directX[4] = {0, 0, 1, -1};

  while (!q.empty())
  {
    Coord now = q.front();
    q.pop();

    int power = block[now.y][now.x];
    block[now.y][now.x] = 0;

    for (int t = 0; t < 4; t++)
    {
      for (int p = 1; p < power; p++)
      {
        int ny = now.y + (directY[t] * p);
        int nx = now.x + (directX[t] * p);
        if (ny < 0 || nx < 0 || ny >= height || nx >= width)
          break;
          
        if (isReg[ny][nx])
          continue;

        if (block[ny][nx] == 0)
          continue;

        isReg[ny][nx] = 1;
        q.push({ny, nx});
        removeCnt++;
      }
    }
  }

  return removeCnt;
}

void applyGravity()
{
  for (int x = 0; x < width; x++)
  {
    // 한줄 읽기
    vector<int> scan;
    for (int y = height - 1; y >= 0; y--)
    {
      if (block[y][x] == 0)
        continue;
      scan.push_back(block[y][x]);
      block[y][x] = 0;
    }

    // 한줄 쓰기
    for (int i = 0; i < scan.size(); i++)
    {
      int y = height - 1 - i;
      block[y][x] = scan[i];
    }
  }
}

int shot(int index)
{
  // 폭탄이 닿는 첫번째 벽돌 좌표 구하기
  Coord startPoint = getFirstDropAxis(index);
  if (startPoint.y == -1)
    return 0;

  // 폭탄 터트리기
  int removeCnt = RemoveBlock_BFS(startPoint);
  if (removeCnt == 1)
    return 1;

  // 중력 적용하기
  applyGravity();
  return removeCnt;
}

void dfs(int lev, int removeCntSum)
{
  if (lev == n)
  {
    maxRemoveCnt = max(maxRemoveCnt, removeCntSum);
    return;
  }

  int backup[15][15];
  memcpy(backup, block, 15 * 15 * sizeof(int));

  for (int x = 0; x < width; x++)
  {
    int removeCnt = shot(x);
    dfs(lev + 1, removeCntSum + removeCnt);
    memcpy(block, backup, 15 * 15 * sizeof(int));
  }
}

int main()
{
  // freopen_s(new FILE*, "input.txt", "r", stdin);

  int tcCnt, totalBlockCnt;
  cin >> tcCnt;

  for (int tc = 1; tc <= tcCnt; tc++)
  {
    // 입력값 블럭 초기개수 세기
    totalBlockCnt = 0;
    cin >> n >> width >> height;
    for (int y = 0; y < height; y++)
    {
      for (int x = 0; x < width; x++)
      {
        cin >> block[y][x];
        if (block[y][x] > 0)
          totalBlockCnt++;
      }
    }

    maxRemoveCnt = 0;
    dfs(0, 0);
    cout << "#" << tc << " " << totalBlockCnt - maxRemoveCnt << "\n";
  }

  return 0;
}