#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

// SWEA 홈방범 서비스

/*
1
8 3
0 0 0 0 0 1 0 0
0 1 0 1 0 0 0 1
0 0 0 0 0 0 0 0
0 0 0 1 0 1 0 0
0 0 1 1 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 1 0 1 0
1 0 0 0 0 0 0 0
*/

/*
1
5 1
1 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
*/

int N;// 도시의 크기
int M;// 집 하나가 지불할 비용
int MAP[20][20]; // 도시
int ydir[] = { -1, 1, 0, 0 };
int xdir[] = { 0, 0, -1, 1 }; 

struct Node {
    int y;
    int x; 
};

int calculate(int servicearea, int homecnt) {
    // #1. 지출
    int K = servicearea; 
    int expense = K * K + (K - 1) * (K - 1);
    
    // #2. 매출 = 집의 개수 x 집당 주는 값?
    int income = homecnt * M; 

    // #3. 수익 = 매출 - 지출
    return income - expense; 
}

int bfs(int y, int x) {
    // queue 세팅
    queue<Node>q;
    q.push({ y, x }); 

    // visited 세팅
    int visited[20][20] = { 0, };
    visited[y][x] = 1; 

    // 현재 서비스 영역
    // 지금 있는 위치는 이미 서비스를 개시 
    int K = 1; 

    // 집의 개수
    int cnt = 0; 

    // 중간 정답 -> 내가 지금 (y,x)에서 서비스를 시작했을때
    // 가장 처리를 많이 할 수 있는 집의 수 
    int temp = 0; 

    // 만약 내가 지금 서비스를 시작하는 위치가 = 집
    if (MAP[y][x] == 1)
        cnt++; 

    // 지금 처리가 가능한 집의 영역이 딱 여기만 처리 가능할때
    // 집의 수를 갱신할 수있는 코드가 필요하다. 

    if (calculate(K, cnt) >= 0)
        temp = cnt; // 내가 최대로 처리할 수 있는 집이
    // 딱 여기인 경우도 있을거야!

    // ff 코드 
    // 각 위치에서 K영역 만큼 단계적으로 퍼지는 ff의 구성
    while (!q.empty()) {
        // 지금 Queue에 대기하고 있는 노드의 개수 만큼만 
        // 단계적으로 서비스 영역을 확장시키고 있다. 
        K++; // 하나의 서비스 영역이 확장되었다!

        int cursize = q.size();
        for (int j = 0; j < cursize; j++) {
            Node now = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int ny = now.y + ydir[i];
                int nx = now.x + xdir[i];
                // 방향배열 사용시 -> 무조건 체크해야하는 범위 
                if (ny < 0 || nx < 0 || ny >= N || nx >= N)
                    continue;
                if (visited[ny][nx] == 1)
                    continue;
                // 만약 다음 위치가 집이라면 
                if (MAP[ny][nx] == 1)
                    cnt++; 
                visited[ny][nx] = 1;
                q.push({ ny, nx });
            }
        }
        // 하나의 단계적 서비스가 종료되었을때,
        // 이 면적에서는 #1. 손해를 보지 않는가? 
        // #2. 더 많은 집을 처리할 수 있었는가? 
        if (calculate(K, cnt) >= 0) {
            if (cnt > temp)
                temp = cnt; 
        }
    }
    // 지금 이 (y,x)위치에서 가장 많이 처리가 가능한 집의 수
    return temp; 
}

int main() {

    //freopen("input.txt", "r", stdin); 

    int T; 
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // reset
        memset(MAP, 0, sizeof(MAP)); 
        int ans = -1; 

        // input
        cin >> N >> M;
        // 도시 정보 입력
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> MAP[i][j]; 

        // solve ->모든 위치에서 그냥 일단 FF 
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int temp = bfs(i, j); 
                // 최종 정답 갱신 
                if (ans < temp)
                    ans = temp; 
            }
        }

        // output 
        cout << "#" << tc << " " << ans << '\n';
    }
}