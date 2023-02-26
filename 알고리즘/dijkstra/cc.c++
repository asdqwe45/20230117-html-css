#include <iostream>
#include <queue>
#include <string>
using namespace std;
struct Edge
{
  int node;
  int cost;
};
struct Node
{
  int node;    // start ~~~~ > node
  int accCost; // start~~~>node 까지의 누적비용
};
struct cmp
{
  bool operator()(Node &left, Node &right)
  {
    return left.accCost > right.accCost;
  }
};
int N, T, K;
int st, en;
vector<Edge> adj[20];
void input()
{
  cin >> N >> T >> K >> st >> en;
  for (int i = 0; i < N; i++)
  {
    int a, b, cost;
    cin >> a >> b >> cost;
    adj[a].push_back({b, cost});
    adj[b].push_back({a, cost});
  }
}
const int INF = 1e9; // 10억
int main()
{
  input();
  priority_queue<Node, vector<Node>, cmp> pq;
  int dist[20]; // dist[A] : PQ에 있는 A의 제일 작은 누적비용
  for (int i = 1; i <= T; i++)
    dist[i] = INF;
  int start = K;
  pq.push({start, 0}); // start, start~~>start비용
  dist[start] = 0;
  while (!pq.empty())
  {
    Node now = pq.top();
    pq.pop();
    if (now.accCost > dist[now.node])
      continue;
    // proccess
    for (Edge &next : adj[now.node])
    {
      int newCost = now.accCost + next.cost; // start~~~~>now + 간선비용
      if (newCost < dist[next.node])
      {
        dist[next.node] = newCost;
        pq.push({next.node, dist[next.node]});
      }
    }
  }

  cout << start << "~~~~~~>" << st << "의 최소비용 : " << dist[st] << endl;
  cout << start << "~~~~~~>" << en << "의 최소비용 : " << dist[en] << endl;

  return 0;
}
