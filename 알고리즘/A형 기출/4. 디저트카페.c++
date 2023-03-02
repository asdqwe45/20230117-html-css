#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

/*
2
4
9 8 9 8
4 6 9 4
8 7 7 8
4 5 3 5
5
8 2 9 6 6
1 9 3 3 4
8 2 3 3 6
4 3 4 4 9
7 4 6 3 5
*/

int MAP[20][20];
int visited[20][20]; // 방문 기록
int DAT[101];        // index : 카페에서 제공하는 디저트 종류, value : 방문했는가?
int N;
int cnt;
int ans = -21e8; // -21억

// 방향 배열
// 오른쪽 아래 -> 왼쪽 아래 -> 왼쪽 위 -> 오른쪽 위
int ydir[] = {1, 1, -1, -1};
int xdir[] = {1, -1, -1, 1};

void dfs(int y, int x, int dir, int dy, int dx)
{

  // 기저 조건 (option) -> 내가 모든 루트를 돌아서 다시 내가 시작한 자리로 왔을때
  if (y == dy && x == dx)
  {
    // 최대값->내가 이 루트를 통해 거쳐 온 카페의 수 = 최대라면 갱신
    if (cnt > ans)
      ans = cnt;
    return;
  }

  // 들어간 이후 가지치기해서 빠져나오는 backtracking
  // #1. 벽 (범위체크) -> 방향 배열
  if (y < 0 || x < 0 || y >= N || x >= N)
    return;
  // #2. 방문체크
  if (visited[y][x] == 1)
    return;
  // #3. 같은 종류의 카페 이미 방문한적 있는가?
  if (DAT[MAP[y][x]] == 1)
    return;

  // 가지치기를 모두 통과했다면 -> 이 (y,x) 위치에 도달할 수 있다!-> 증명
  visited[y][x] = 1;
  DAT[MAP[y][x]] = 1;
  cnt++;

  // #1. 쭉 내려간다
  dfs(y + ydir[dir], x + xdir[dir], dir, dy, dx);

  // 따로 복구 필요 없음 -> (y,x) 기준으로 다음 루트도 내려갈것이기 때문

  // #2. 방향을 바꿔서 내려간다
  if (dir < 3)
  {
    dir++;
    dfs(y + ydir[dir], x + xdir[dir], dir, dy, dx);
    dir--;
  }

  visited[y][x] = 0;
  DAT[MAP[y][x]] = 0;
  cnt--;
}

int main()
{

  // freopen("input.txt", "r", stdin);

  int T; // test case
  cin >> T;
  for (int tc = 1; tc <= T; tc++)
  {
    // reset
    memset(MAP, 0, sizeof(MAP));
    memset(DAT, 0, sizeof(DAT));
    memset(visited, 0, sizeof(visited));
    ans = -21e8;
    cnt = 0;

    // input
    cin >> N;
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
        cin >> MAP[i][j];

    // solve -> 모든 위치를 출발점으로 두고 dfs 탐색
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {
        visited[i][j] = 1;
        DAT[MAP[i][j]] = 1; // (i,j) 위치의 카페 종류는 이미 방문했다!
        cnt++;
        // dfs(다음 y, 다음 x, 방향, 도착 y, 도착 x);
        dfs(i + 1, j + 1, 0, i, j);
        cnt--;
        visited[i][j] = 0;
        DAT[MAP[i][j]] = 0;
      }
    }

    // output
    // 만약 루트를 찾지 못했다면 -> ans = -21e8;
    if (ans == -21e8)
      ans = -1;
    cout << "#" << tc << " " << ans << '\n';
  }
}