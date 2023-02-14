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
int main()
{
  freopen_s(new FILE *, "input.txt", "r", stdin);
  input();
  // 가짜 dijkstra
  priority_queue<Node, vector<Node>, cmp> pq;
  int processed[8] = {0};
  int start = 1;
  pq.push({start, 0}); // start, start~~>start비용
  int dist[8] = {0};
  while (!pq.empty())
  {
    Node now = pq.top();
    pq.pop();
    if (processed[now.node] == 1)
      continue;
    processed[now.node] = 1;
    dist[now.node] = now.accCost;
    // proccess
    for (Edge &next : adj[now.node])
    {
      int newCost = now.accCost + next.cost; // start~~~~>now + 간선비용
      pq.push({next.node, newCost});
    }
  }
  for (int node = 1; node <= 7; node++)
  {
    cout << start << "~~~~~~>" << node << "의 최소비용 : " << dist[node] << endl;
  }
  return 0;
}
