#include <iostream>
#include <queue>
using namespace std;

int N, W, H;
int maxRemoveCnt;
int map[20][20];

struct Node {
	int y, x;
};

Node getFirstNode(int index) {
	for (int i = 0; i < H; i++)
		if (map[i][index] != 0)
			return{ i,index };
	return { -1,-1 };
}

int Bfs(Node First) {
	queue<Node>q;
	q.push(First);
	int used[20][20] = { 0 };
	used[First.y][First.x] = 1;
	int removeCnt = 1;
	int dir[4][2] = { 0,1,0,-1,1,0,-1,0 };

	while (!q.empty()) {

		Node now = q.front(); q.pop();

		int power = map[now.y][now.x];

		map[now.y][now.x] = 0;

		for (int i = 0; i < 4; i++) {
			for (int p = 1; p < power; p++) {
				int ny = now.y + dir[i][0] * p;
				int nx = now.x + dir[i][1] * p;

				if (ny < 0 || nx < 0 || ny >= H || nx >= W)break;
				if (map[ny][nx] == 0)continue;
				if (used[ny][nx] == 1)continue;

				used[ny][nx] = 1;
				q.push({ ny,nx });
				removeCnt++;

			}
		}
	}
	return removeCnt;

}

void goDown() {
	for (int i = 0; i < W; i++) {
		vector<int>v;
		for (int j = H - 1; j >= 0; j--)
			if (map[j][i] != 0) {
				v.push_back(map[j][i]);
				map[j][i] = 0;
			}
		for (int j = 0; j < v.size(); j++)
		{
			map[H - 1 - j][i] = v[j];
		}

	}


}

int getRemoveCnt(int index) {
	Node First = getFirstNode(index);
	if (First.y == -1)
		return 0;

	int removeCnt = Bfs(First);
	if (removeCnt == 1)
		return 1;

	goDown();
	return removeCnt;
}

void dfs(int lev,int removeCntSum) {
	if (lev == N) {
		maxRemoveCnt = max(maxRemoveCnt, removeCntSum);
		return;
	}
	int backup[20][20];
	memcpy(backup, map, sizeof(map));

	for (int i = 0; i < W; i++) {
		int removeCnt = getRemoveCnt(i);
		
		dfs(lev + 1, removeCntSum + removeCnt);

		memcpy(map, backup, sizeof(map));
	}


}

void input() {
	cin >> N >> W >> H;
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			cin >> map[i][j];

	maxRemoveCnt = 0;
}


int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		input();

		dfs(0, 0);

		cout << "#" << t << ' ' << maxRemoveCnt << '\n';
	}
	





	int d = 1;
	return 0;
}