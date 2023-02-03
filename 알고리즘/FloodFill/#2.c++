#include <iostream>

#include <queue>
using namespace std;

int sy, sx;

string MAP[8] = {
    "####",
    "###_",
    "#___",
    "_###",
    "_###",
    "____",
    "##__",
    "#___"};

struct Node
{
  int y; // y좌표
  int x; // x좌표
};

// 단계별 floodfill
/*
void bfs(int y, int x) {
    // #1. queue 준비
    queue<Node>q;
    q.push({ y, x });

// #2. visited 준비
int visited[5][5] = { 0, };
visited[y][x] = 1; // 시작 노드 방문 기록

// #3. 방향 배열
int ydir[] = { -1, 1, 0, 0 };
int xdir[] = { 0, 0, -1, 1 };

int day = 1;
cout << "DAY #" << day << '\n';
for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
        cout << visited[i][j];
    }
    cout << '\n';
}

while (!q.empty()) {
    // 다음 날이 되었다!
    day++;

    // 지금 queue에서 오늘 날짜에 감염될 node 만큼만을 추출해서 기록
    int cursize = q.size();
    for (int j = 0; j < cursize; j++) {

        Node now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = now.y + ydir[i];
            int nx = now.x + xdir[i];

            if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5)
                continue; //

            if (visited[ny][nx] == 1)
                continue;

            visited[ny][nx] = 1;
            q.push({ ny, nx });
        }
    }

    cout << "DAY #" << day << '\n';
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << visited[i][j];
        }
        cout << '\n';
    }
    cout << '\n';
}
}
*/

int cnt = 0;
// visited를 여러번의 flood fill에서 공유할수 있도록 함
int visited[8][8] = {
    0,
};

void bfs(int y, int x)
{
  // #1. queue 준비
  queue<Node> q;
  q.push({y, x});

  // #2. visited 준비
  visited[y][x] = 1; // 시작 노드 방문 기록

  // #3. 방향 배열
  int ydir[] = {-1, 1, 0, 0};
  int xdir[] = {0, 0, -1, 1};

  while (!q.empty())
  {

    Node now = q.front();
    q.pop();

    for (int i = 0; i < 4; i++)
    {
      int ny = now.y + ydir[i];
      int nx = now.x + xdir[i];

      if (ny < 0 || nx < 0 || ny >= 8 || nx >= 8)
        continue; //

      if (visited[ny][nx] == 1)
        continue;

      // 연결된 섬이라면 -> 계속
      if (MAP[ny][nx] == '_')
        continue;

      visited[ny][nx] = 1;
      q.push({ny, nx});
    }
  }
}

int main()
{
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      // 만약 이 위치가 섬이라면 && 아직 확인하지 않은 섬이라면
      if (MAP[i][j] == '#' && visited[i][j] == 0)
      {
        bfs(i, j);
        // 한번의 플러드필이 종료된다면 -> 하나의 연결된 섬을 찾았다!
        cnt++;
      }
    }
  }
  cout << cnt;
}