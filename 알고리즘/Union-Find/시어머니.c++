#include <iostream>
#include <queue>
using namespace std;

struct Node
{
  int row, col;
  int accCost;
};

const int MAXN = 10;
int N;
int MAP[MAXN][MAXN];
Node start;

void input()
{
  cin >> start.row >> start.col;
  cin >> N;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      cin >> MAP[i][j];
  start.accCost = MAP[start.row][start.col];
}
int dist[MAXN][MAXN];

struct cmp
{
  bool operator()(Node left, Node right)
  {
    return left.accCost > right.accCost;
  }
};

int dr[4] = {0, 0, -1, 1};
int dc[4] = {-1, 1, 0, 0};

void dijkstra()
{
  const int INF = 1e9;
  for (int row = 0; row < N; row++)
    for (int col = 0; col < N; col++)
      dist[row][col] = INF;
  priority_queue<Node, vector<Node>, cmp> pq;
  dist[start.row][start.col] = start.accCost;
  pq.push(start);

  while (!pq.empty())
  {
    Node now = pq.top();
    pq.pop();
    if (dist[now.row][now.col] < now.accCost)
      continue;

    for (int t = 0; t < 4; t++)
    {
      int nr = now.row + dr[t];
      int nc = now.col + dc[t];
      if (MAP[nr][nc] == -1)
        continue;
      if (nr < 0 || nc < 0 || nr >= N || nc >= N)
        continue;

      int newCost = MAP[nr][nc] + now.accCost;
      if (dist[nr][nc] > newCost)
      {
        dist[nr][nc] = newCost;
        pq.push({nr, nc, newCost});
      }
    }
  }
}

int main()
{
  input();

  dijkstra();

  int maxvalue = -1;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      if (maxvalue < dist[i][j] && MAP[i][j] != -1)
        maxvalue = dist[i][j];

  cout << maxvalue;

  return 0;
}