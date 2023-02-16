#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
// 1. 모든 노드를 최소한의 비용 => 간선이 모든 노드에 1개씩 연결
// 2. 사이클이 없다.
// 3. 양방향 연결에서 유효


// #1. 가장 짧은거부터 순서대로 연결
// => 단, cycle이 생긴다면 이 간선은 연결 X
// => Union-Find 사용
// 간선 위주 알고리즘 => kruskal

/*
10 16
0 3 10
0 2 20
2 3 34
1 2 30
1 5 12
5 2 56
5 8 7
5 6 21
8 6 23
8 9 15
6 9 78
6 7 67
7 9 22
2 7 45
7 4 35
3 4 60
*/

struct Edge {
	int a;
	int b;
	int cost;
};
bool cmp(Edge left, Edge right) {
	return left.cost < right.cost;
}

vector<Edge>v;

int N, M; //  노드의 개수, 간선의 개수
int sum = 0;
int parent[100];

int Find(int  now) {
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

int kruskal() {
	// 짧은 간선부터 우선적으로 확인하기 위해 간선정보를 정렬
	sort(v.begin(), v.end(),cmp);
	// 앞에서부터 순차적으로 간선을 확인
	// 확인 => 이 간선을 MST의 일원으로 채택 가능?
	// 이게 판단되면 => 연결한다!( 즉, 비용을 누적한다 )
	// 연결할 수 없다면 -> 다음 간선 확인
	for (int i = 0; i < v.size(); i++)
	{
		// now번 간선을 연결할 수 있는지 확인
		Edge now = v[i]; // 연결 해볼까 비교하는 간선

		// cycle이ㅣ 발생하는가?
		if (Find(now.a)==Find(now.b))
			continue;

		//이제 이 간선은 연결을 시킬 것이다.
		sum += now.cost;
		// 이제 now의 A와 now의 B는 하나의 소속이 된다.
		Union(now.a, now.b);
	}
	return sum;
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		// 그래프 구성
		// 알아야 하는 정보는 A와 B가 cost의 간선
		v.push_back({ from,to,cost });
	}
	// MST를 만든다.
	for (int i = 0; i < N; i++)
		parent[i] = i;
	
	cout<<kruskal();




	return 0;
}