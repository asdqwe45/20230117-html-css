#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
/*
1
5 5 19
3 2 0 3 0
0 3 0 0 0
0 0 0 0 0
0 0 1 0 0
0 0 0 0 2
*/

struct Cell
{
  int row, col; // 좌표
  int life, hp; // life : 앞으로 얼마나 살 수 있을까?, hp : 생명력 수치
  bool operator<(Cell right) const
  {
    // right를 꺼내고 싶으면 true
    // left를 꺼내고 싶으면 false
    if (hp < right.hp)
      return true;
    if (hp > right.hp)
      return false;

    // 이 밑은 사실 필요 없음(운좋게 얻어 걸리는 경우들이 간혹 있음)
    // 다른 것도 해주는게 좋음
    if (life < right.life)
      return true;
    if (life > right.life)
      return false;

    // 다른 것도 해주는게 좋음
    if (row < right.row)
      return true;
    if (row > right.row)
      return false;

    // 다른 것도 해주는게 좋음
    if (col < right.col)
      return true;
    if (col > right.col)
      return false;
    return false;
  }
};

priority_queue<Cell> pq;

int N, M, K;
int MAP[1000][1000];

void input()
{
  cin >> N >> M >> K;
  memset(MAP, 0, sizeof(MAP));
  pq = priority_queue<Cell>();
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
    {
      cin >> MAP[500 + i][500 + j];
      if (MAP[500 + i][500 + j])
      {
        pq.push({
            500 + i, 500 + j,                                // 좌표
            MAP[500 + i][500 + j] * 2, MAP[500 + i][500 + j] // life, hp
        });
      }
    }
}
// 1시간동안 증식
priority_queue<Cell> flood_fill(priority_queue<Cell> nowPQ)
{                              // nowPQ : 이번 시간에 살아있는 세포들
  priority_queue<Cell> nextPQ; // nextPQ : 다음 시간에 살아있는 세포들
  while (!nowPQ.empty())
  {
    // 살아있는 세포 하나 꺼내기
    Cell now = nowPQ.top();
    nowPQ.pop();
    now.life--; // 세포의 생명 하나 깎기

    // 살아만 있으면 다음 시간에도 증식 작용
    if (now.life) // 죽음 판단
      nextPQ.push(now);

    // 살아있는 세포 상태 판단(비활성화 or 활성화)
    if (now.life >= now.hp) // 비활성화 판단
      continue;             // 실제 증식할 필요 없음

    // 활성화 상태 <- 실제로 증식
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    for (int i = 0; i < 4; i++)
    {
      int nr = now.row + dr[i];
      int nc = now.col + dc[i];
      if (MAP[nr][nc])
        continue; // 증식하려는 곳에 어떤 세포가 있다면 무시
      MAP[nr][nc] = MAP[now.row][now.col];
      nextPQ.push({
          nr, nc,                      // 좌표
          2 * MAP[nr][nc], MAP[nr][nc] // life, hp
      });
    }
  }

  // 가장 중요한 결과값 ?
  return nextPQ; //<- 1시간동안 증식한 결과, 다음에 진행할 PQ
}

int solution()
{
  for (int i = 0; i < K; i++)
  {
    // 다음pq = flood_fill(이번pq);
    pq = flood_fill(pq); // upgrade가능성 있음 : '활성화가 안되는상태도 진행하고 있음' -> 활성화 되는 시간에만 돌아가도록 구성 가능
  }
  // pq : K라는 시간이 지났을 때 살아있는 세포들
  return pq.size();
}

int main()
{
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++)
  {
    input();
    cout << "#" << tc << " " << solution() << "\n";
  }

  return 0;
}