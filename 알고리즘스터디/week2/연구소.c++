#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

struct Node {
	int row, col;
};

int map[8][8];
int N, M;
int cnt;
vector<Node>zeroV;
vector<Node>virusV;
int Size;
queue<Node>virusQ;

int bfs() {
	for (int i = 0; i < virusV.size(); i++)
		virusQ.push(virusV[i]);
	int dir[4][2] = { 0,1,0,-1,1,0,-1,0 };
	int used[8][8] = { 0 };

	while (!virusQ.empty()) {
		Node now = virusQ.front(); virusQ.pop();
		for (int i = 0; i < 4; i++) {
			int ny = now.row + dir[i][0];
			int nx = now.col + dir[i][1];

			if (ny < 0 || nx < 0 || nx >= M || ny >= N)continue;
			if (used[ny][nx] == 1)continue;
			if (map[ny][nx] == 1 || map[ny][nx] == 2)continue;

			used[ny][nx] = 1;
			map[ny][nx] = 3;

			virusQ.push({ ny,nx });

		}
	}
	int bfsCnt = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (map[i][j] == 0)
				bfsCnt++;
	return bfsCnt;
}

void dfs(int lev, int st)
{

	if (lev == 3) {
		int temp[8][8];
		memcpy(temp, map, sizeof(map));
		int tempCnt = bfs();
		cnt = max(tempCnt, cnt);
		memcpy(map, temp, sizeof(map));
		return;
	}


	for (int i = st; i < Size; i++) {
		Node now = zeroV[i];
		map[now.row][now.col] = 1;
		dfs(lev + 1, i+1);
		map[now.row][now.col] = 0;
	}
}


int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) 
				zeroV.push_back({ i,j });
			
			if (map[i][j] == 2)
				virusV.push_back({ i,j });
		}
	}
	Size = zeroV.size();

	dfs(0, 0);

	cout << cnt << '\n';

	return 0;
}

