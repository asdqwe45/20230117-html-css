#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <vector>
#include <queue> 
using namespace std;

// SWEA : 탈주범 검거

/*
2
5 6 2 1 3
0 0 5 3 6 0
0 0 2 0 2 0
3 3 1 3 7 0
0 0 0 0 0 0
0 0 0 0 0 0
5 6 2 2 6
3 0 0 0 0 3
2 0 0 0 0 6
1 3 1 1 3 1
2 0 2 0 0 2
0 0 4 3 1 1
*/

int N; // 세로 크기
int M; // 가로 크기
int R; // 맨홀의 세로 위치 (y) 
int C; // 맨홀의 가로 위치 
int L; // 소요시간
int MAP[50][50]; 

// 파이프가 연결하는 방향에 대한 정보를 담는 dir
int pipedir[][4] = {
    // 상하좌우
    // 갈 수있으면 1, 아니면 0
    {0, 0, 0, 0},
    {1, 1, 1, 1}, // +
    {1, 1, 0, 0},
    {0, 0, 1, 1},
    {1, 0, 0,1 },
    {0, 1, 0, 1},
    {0, 1, 1, 0},
    {1, 0, 1, 0}
};

struct Node {
    int y;
    int x; 
};

// 무지성 flood fill 
// 이제 추가해야 되는 조건 
// #1. 파이프 
// --> 내가 지금 파이프에서 다음 파이프로 갈수 있는가? 
// #2. L만큼의 시간동안 퍼진다. 
// --> 단계별 flood fill

int bfs(int y, int x) {
    // queue 준비
    queue<Node>q; 
    q.push({ y, x });

    // visited 준비
    int visited[50][50] = { 0, };
    visited[y][x] = 1; 

    // 방향 배열
    int ydir[] = { -1, 1, 0, 0 };
    int xdir[] = { 0, 0, -1, 1 }; 

    int time = 0; 
    int cnt = 0; // 내가 방문한 파이프의 개수

    while (!q.empty()) {
        // 어느 순간 내가 L의 시간 만큼 지낸 때가 온다. 
        if (time == L)
            break; 

        // 여기 돌아오면 -> 하나의 단계가 완료
        // -> 1시간이 지났다 
        time++; 

        // 일단은 단계별로 -> 지금 queue에 들어있는 만큼만
        // 돌아갈 수 있도록 구성

        int cursize = q.size();
        for (int j = 0; j < cursize; j++) {

            // now -> 내가 지금 진입한 파이프 
            // now = 지금 내가 갈 수 있는 파이프
            // now가 나왔다는 것 = 내가 갈수 있는 파이프가 하나 늘었다!
            Node now = q.front();
            q.pop();

            cnt++; 

            for (int i = 0; i < 4; i++) {
                int ny = now.y + ydir[i];
                int nx = now.x + xdir[i];
                if (ny < 0 || nx < 0 || ny >= N || nx >= M)
                    continue;
                if (visited[ny][nx] == 1)
                    continue;

                // 갈수 있는지 판단
                // #1. 지금 내 파이프가 i번 방향으로 갈수있는가? 
                int curpipe = MAP[now.y][now.x]; // 지금 내 파이프 번호 
                // 만약 지금 내 파이프에서 i번째 방향으로 못간다면 continue
                if (pipedir[curpipe][i] == 0)
                    continue; 

                // #2. 벽이면 못간다
                if (MAP[ny][nx] == 0)
                    continue;

                // #3. 지금 내가 (ny, nx) 파이프로 가려고하는데
                // 여기까지 왔다는건 다음 위치가 벽도 아니고
                // 지금 나는 이 방향으로 갈 수 있다 
                // --> 다음 파이프가 내가 지금 행하는 방향에서
                // 왔을때 -> 들어갈수 있는가? 
                int nextpipe = MAP[ny][nx]; 
                // 다음 파이프가 지금 파이프에서 가는 방향의
                // 반대방향이 뚫려있는가? 
                // 내가 지금 가는 i방향의 반대방향을 확인
                int nextdir = -1;
                if (i % 2 == 0)
                    nextdir = i + 1;
                else
                    nextdir = i - 1; 
                if (pipedir[nextpipe][nextdir] == 0)
                    continue; 

                visited[ny][nx] = 1;
                q.push({ ny, nx });
            }
        }
    }
    return cnt; 
}

int main() {

    freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // reset
        memset(MAP, 0, sizeof(MAP));

        // input
        cin >> N >> M >> R >> C >> L; 
        for (int i = 0; i < N; i++) 
            for (int j = 0; j < M; j++)
                cin >> MAP[i][j]; 
        
        // solve
        int ans = bfs(R, C); 
        
        // output
        cout << "#" << tc << " " << ans << '\n';
    }
}