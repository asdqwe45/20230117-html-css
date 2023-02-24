#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

// SWEA 등산로 조정
/*
2
5 1
9 3 2 3 2
6 3 1 7 5
3 4 8 9 9
2 3 7 7 7
7 6 5 5 8
3 2
1 2 1
2 1 2
1 2 1
*/

struct Node {
    int y;
    int x; 
    int canbreak; // 아직 깎을 수 있는가? 
};

int N; // 한 변의 길이
int K; // 최대 공사 가능 높이
int MAP[10][10];
vector<Node>v; // 가장 높은 봉우리의 위치를 담을 vector
int ydir[] = { -1, 1, 0, 0 };
int xdir[] = { 0, 0, -1, 1 }; 
int visited[10][10]; 
int cnt = 0; // 총 몇개의 칸을 이동했는지 확인할 정답
int ans = -21e8; 

void dfs(Node now) {
    // 어느 순간 now까지 왔을때 ans보다 더 많은 길을 왔다
    if (cnt > ans) 
        ans = cnt;

    // 재귀 구성 
    // 상하좌우 방향으로 갈수있는데까지 가본다
    for (int i = 0; i < 4; i++) {
        int ny = now.y + ydir[i];
        int nx = now.x + xdir[i];
        // 범위 체크
        if (ny < 0 || nx < 0 || ny >= N || nx >= N)
            continue;
        if (visited[ny][nx] == 1)
            continue;

        // 무작정 깊게 들어가는 것 X
        // #1. 만약 다음 갈려고 하는 위치가 지금 내 위치를 기준으로
        // 더 높거나 같다 -> 깎아보고 갈수 있으면 간다
        if (MAP[ny][nx] >= MAP[now.y][now.x]) {
            // #1. 아직 깎아볼 수 있으면 
            if (now.canbreak == 1) {
                // 만약 다음위치를 최대 K만큼 깎았을때
                // 지금 내 위치보다 작아질수만 있다면 
                // 우리는 이 다음 위치를 (내위치 -1)로 깎을수 있다. 
                // (내위치 -1) : 이래야 최대한 많이 흘러들어갈 수 있도록 만들 수 있기 때문 
                if (MAP[ny][nx] - K < MAP[now.y][now.x]) {
                    // 여기는 갈 수 있게 된다!
                    // 본래의 MAP[ny][nx] 값을 저장해두고
                    int temp = MAP[ny][nx]; 
                    // 실제로 깎은것을 반영해줘야 한다. 
                    MAP[ny][nx] = MAP[now.y][now.x] - 1;
                    visited[ny][nx] = 1;
                    // 깎았으니까 -> 이제는 더 깎을 수 없는 상태 
                    cnt++; 
                    dfs({ ny, nx, 0 });
                    cnt--; 
                    visited[ny][nx] = 0;
                    // 나올때 복구
                    MAP[ny][nx] = temp; 
                }
            }
            // #2. 내가 이미 깎은 상태로 여기 왔다
            // 무조건 못가는 것 (아무것도 안하면 된다)
        }
        // #2. 지금내가 가려고 하는 곳이 지금 내 위치를 기준으로
        // 더 낮다면 -> 그냥 가면 된다. 
        else {
            visited[ny][nx] = 1;
            // 지금 내가 어떤 상태로 여기까지 왔는가? 
            cnt++; 
            dfs({ ny, nx, now.canbreak});
            visited[ny][nx] = 0; 
            cnt--;
        }
    }
}

int main() {

    freopen("input.txt", "r", stdin);

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // reset 
        memset(MAP, 0, sizeof(MAP)); 
        v.clear(); 
        int MAX = -21e8; 
        ans = -21e8;

        // input
        cin >> N >> K;
        // 등산로 정보 입력
        // #1. 최대값만 찾아놓고 나중에 다시 빙 돌면서 -> 최대값인 위치일때 dfs
        // #2. 모든 가장 높은 봉우리의 위치를 저장해놓고 -> 그 위치들을 돌면서 dfs
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> MAP[i][j];
                // 이제 이 봉우리가 가장 높은 봉우리라면
                // 새로운 가장 높은 봉우리를 찾았다! 
                if (MAP[i][j] > MAX) {
                    // 새로운 가장 높은 봉우리를 찾았다면
                    // 기존의 저장되었던 봉우리의 위치들은 쓸모없다
                    v.clear();
                    v.push_back({ i, j , 1});
                    MAX = MAP[i][j];
                }
                // 만약 지금 가장 높은 봉우리와 같은 높이의 봉우리를 찾았다면
                else if (MAP[i][j] == MAX)
                    v.push_back({ i, j, 1 });
            }
        }

        // solve
        // #2. 모든 가장 높은 봉우리에서의 dfs
        for (int i = 0; i < v.size(); i++) {
            // * 특수하게 reset해야 하는 경우
            memset(visited, 0, sizeof(visited));
            // 내가 지금 들어가는 곳 방문 체크를 하고 시작
            cnt = 1; // 내가 지금 시작하는 위치도 포함
            visited[v[i].y][v[i].x] = 1;
            dfs(v[i]);
        }

        // output 
        cout << "#" << tc << " " << ans << '\n';
    }
}