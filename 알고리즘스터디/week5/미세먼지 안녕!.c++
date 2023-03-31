#include <iostream>
#include <cstring>
using namespace std;

int map[50][50];
int R, C, T;
int total;
int dir[4][2] = { 0,1,0,-1,1,0,-1,0 };
int st;

void run() {
	int temp[50][50] = { 0 };

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++) {
			int cnt = 0;
			if (map[i][j] >= 1) {
				for (int k = 0; k < 4; k++) {
					int ny = i + dir[k][0];
					int nx = j + dir[k][1];

					if (ny < 0 || nx < 0 || ny >= R || nx >= C)continue;
					if (map[ny][nx] == -1)continue;
					cnt++;
					temp[ny][nx] += map[i][j] / 5;
				}
				temp[i][j] += map[i][j] - map[i][j] / 5 * cnt;
			}
		}
	if (temp[st - 1][0] >= 1) {
		total -= temp[st - 1][0];
		temp[st - 1][0] = 0;
	}
	for (int i = st - 2; i >= 0; i--) {
		if (temp[i][0] >= 1)
			swap(temp[i][0], temp[i + 1][0]);
	}
	for (int i = 1; i < C; i++) {
		if (temp[0][i] >= 1) {
			swap(temp[0][i], temp[0][i - 1]);
		}
	}
	for (int i = 1; i <= st; i++)
		if (temp[i][C - 1] >= 1)
			swap(temp[i][C - 1], temp[i - 1][C - 1]);
	for (int i = C - 2; i >= 1; i--)
		if (temp[st][i] >= 1)
			swap(temp[st][i], temp[st][i + 1]);

	if (temp[st + 2][0] >= 1)
	{
		total -= temp[st + 2][0];
		temp[st + 2][0] = 0;
	}

	for (int i = st+3; i <R; i++) {
		if (temp[i][0] >= 1)
			swap(temp[i][0], temp[i - 1][0]);
	}

	for (int i = 1; i < C; i++) {
		if (temp[R - 1][i] >= 1) {
			swap(temp[R - 1][i], temp[R - 1][i - 1]);
		}
	}

	for (int i = R - 2; i >= st + 1; i--) {
		if (temp[i][C - 1] >= 1) {
			swap(temp[i][C - 1], temp[i + 1][C - 1]);
		}
	}

	for (int i = C - 2; i >= 1; i--) {
		if (temp[st + 1][i] >= 1) {
			swap(temp[st + 1][i], temp[st + 1][i + 1]);
		}
	}
	memcpy(map, temp, sizeof(int)*R*C);


}


int main()
{
	int en;
	cin >> R >> C >> T;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] >= 1)
				total += map[i][j];
			if (map[i][j] == -1)
				en = i;
		}
	st = en - 1;
	for (int t = 0; t < T; t++) {
		run();
	}
	cout << total << endl;

	return 0;
}
