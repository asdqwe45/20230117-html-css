#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
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
struct Edge {
    int to;
    int cost; 
    bool operator < (Edge next) const {
        if (cost < next.cost)
            return false;
        if (cost > next.cost)
            return true;
        return false; 
    }
};
int N, M;
vector<Edge>al[101]; 
int prim(int start) {
    // #1. priority queue 준비
    priority_queue<Edge>pq;
    pq.push({ start, 0 }); 
    // #2. connected DAT를 준비
    // 지금 내가 start부터 시작한 MST의 일원으로 연결이 되어있는가? 
    int connected[101] = { 0, }; 
    
    // 비용
    int sum = 0; 
    int cnt = 0;
    // prim 동작
    while (!pq.empty()) {
        // 간선이 가장 작은 것부터 뺴옵니다. 
        Edge now = pq.top();
        pq.pop(); 
        // 이미 now가 MST의 일원이야? 
        if (connected[now.to] == 1)
            continue;
        // MST의 일원으로 새로 확보가 되는 노드
        connected[now.to] = 1; 
        // 지금 이 노드까지 오는 길 = MST의 일원
        // 이 길의 비용을 누적
        sum += now.cost; 
        cnt++; 
        // now에서 갈수 있는 노드를 priority queue에 삽입
        for (int i = 0; i < al[now.to].size(); i++) {
            Edge next = al[now.to][i];
            // 만약 이미 다음갈려고 하는 노드 = MST의 일원 = 다시 안봐도 된다
            if (connected[next.to] == 1)
                continue;
            pq.push(next); 
        }
    }
    if(cnt == N)
        return sum; 
    return -1; 
}
int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int from, to, cost; 
        cin >> from >> to >> cost; 
        al[from].push_back({ to, cost });
        al[to].push_back({ from, cost }); 
    }
    // prim - MST 
    cout << prim(2);
}



