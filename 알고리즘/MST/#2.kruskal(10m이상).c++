#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

/* 입력1
5 8
0 1 50
0 2 30
1 2 5
1 3 7
2 4 20
2 3 8
1 4 9
3 4 1
*/

/* 입력2
5 8
0 1 50
0 2 30
1 2 5
1 3 7
2 4 20
2 3 8
1 4 9
3 4 35
*/

int N, M;
int sum = 0;

struct Edge {
	int a, b;
	int cost;
};

vector<Edge>v;

bool cmp(Edge left, Edge right) {
	return left.cost < right.cost;
}
int parent[100];

int Find(int now) {
	if (parent[now] == now)
		return now;
	return parent[now] = Find(parent[now]);
}
void Union(int A, int B)
{
	int pa = Find(A);
	int pb = Find(B);
	if (pa == pb)return;
	parent[pb] = pa;
}
int cnt;
int kruskal() {
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++)
	{
		Edge now = v[i];

		if (Find(now.a) == Find(now.b))continue;
		if (now.cost < 10)continue;
		cnt++;
		sum += now.cost;
		Union(now.a, now.b);
	}
	if (cnt == N - 1)
		return sum;
	else
		return -1;
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		v.push_back({ from,to,cost });
	}
}



int main()
{

	input();
	for (int i = 0; i < N; i++)
		parent[i] = i;

	cout<<kruskal();

	

	return 0;

}