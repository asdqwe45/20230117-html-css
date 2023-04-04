#include <iostream>
#include <queue>
using namespace std;
#define WALL 2e8
#define BIN -2e8

struct Node {
	int y, x;
};

Node Virus[10];
int used[10];
int N, M;
int map[50][50];
int temp[50][50];
int t = 0;
int mini;

int getNum() {
	int max = -1;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			if (map[i][j] == BIN)
				return 2e8;	
			if (map[i][j] != 2e8&&map[i][j] > max)max = map[i][j];
		}
	return max;
}

int flood_fill() {
	queue<Node>q;
	int visited[50][50] = { 0 };
	int dir[4][2] = { 1,0,-1,0,0,1,0,-1 };
	for (int i = 0; i < t; i++) {
		if (used[i] == 1)
			q.push(Virus[i]);
	}

	while (!q.empty()) {
		Node now = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dir[i][0];
			int nx = now.x + dir[i][1];

			if (ny < 0 || nx < 0 || ny >= N || nx >= N)continue;
			if (visited[ny][nx] == 1)continue;
			if (map[ny][nx] == BIN) {
				visited[ny][nx] = 1;
				map[ny][nx] = map[now.y][now.x] + 1;
				q.push({ ny,nx });
			}			
		}
	}
	return getNum();
}

void dfs(int lev,int st) {
	if (lev == 3) {
		memcpy(temp, map, sizeof(map));
		flood_fill();
		int ret=getNum();
		if(ret!=2e8)
		mini = min(mini, ret);
		memcpy(map, temp, sizeof(map));
		return;
	}

	for (int i = st; i < t; i++) {
		if (used[i] == 1)continue;
		used[i] = 1;
		dfs(lev + 1, i + 1);
		used[i] = 0;
	}
}

void input() {
	cin >> N >> M;
	for(int i=0;i<N;i++)
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)map[i][j] = WALL;
			else if (map[i][j] == 2) {
				map[i][j] = 0;
				Virus[t++] = { i,j };
			}
			else if (map[i][j] == 0) {
				map[i][j] = BIN;
			}
		}
	mini = 2e8;
}

int main()
{
	input();

	dfs(0, 0);
	if (mini != 2e8)
		cout << mini << endl;
	else
		cout << -1 << endl;
	return 0;
}