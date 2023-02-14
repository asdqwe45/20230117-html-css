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
int N, T;
vector<Edge> adj[8];
void input()
{
  cin >> N >> T;
  for (int i = 0; i < T; i++)
  {
    int a, b, cost;
    cin >> a >> b >> cost;
    adj[a].push_back({b, cost});
  }
}
const int INF = 1e9; // 10억
int main()
{
  freopen_s(new FILE *, "input.txt", "r", stdin);
  input();
  priority_queue<Node, vector<Node>, cmp> pq;
  int dist[8]; // dist[A] : PQ에 있는 A의 제일 작은 누적비용
  for (int i = 1; i <= 7; i++)
    dist[i] = INF;
  int start = 1;
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
  for (int node = 1; node <= 7; node++)
  {
    cout << start << "~~~~~~>" << node << "의 최소비용 : " << dist[node] << endl;
  }

  return 0;
}
