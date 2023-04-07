#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int num, dir, turn;
};

int N, M, T;
int map[50][50];
queue<Node>Turn;

void input() {
	cin >> N >> M >> T;

	for (int i= 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];

	for (int i = 0; i < T; i++)
	{
		int num, dir, turn;
		cin >> num >> dir >> turn;
		turn %= N;
		if (turn > N / 2) {
			turn = N - turn;
			dir = abs(dir - 1);
		}
		Turn.push({ num,dir,turn });
	}
}

void bfs() {
	int temp[50][50] = { 0 };
	int dir[4][2] = { 0,1,0,-1,1,0,-1,0 };
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			for (int k = 0; k < 4; k++) {
				int ny = i + dir[i][0];
				int nx = j + dir[i][1];

				if (ny < 0 || nx >= N)continue;
				if (nx < 0)
					nx = N - 1;
				else if (nx >= N)
					nx = 0;

				if (map[i][j] == map[ny][nx])
				{
					temp[i][j] = -1;
					temp[ny][nx] = -1;
				}
				else {
					if (temp[i][j] != -1)
						temp[i][j] = map[i][j];
					if (temp[ny][nx] != -1)
						temp[ny][nx] = map[ny][nx];
				}
			}
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			if(temp[i][j]==-1)
				map[i][j]=0;
}

void turnCircle(int n, int dir, int turn) {
	for (int i = 0; i < turn; i++) {
		if(dir==1)
			for (int j = 0; j < N-1; j++) {
				swap(map[n][j], map[n][j + 1]);
		}
		else if (dir == 0) {
			for (int j = N - 1; j >= 1; j--)
				swap(map[n][j], map[n][j - 1]);
		}
	}
}

int main()
{
	input();

	for (int i = 0; i < T; i++) {
		Node now = Turn.front(); Turn.pop();
		for (int j = 0; j < N; j++) {
			if (((j+1)%now.num) == 0) {
				turnCircle(j,now.dir,now.turn);
			}
		}
		bfs();
	}
	int total = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			total += map[i][j];

	cout << total << endl;

	return 0;
}