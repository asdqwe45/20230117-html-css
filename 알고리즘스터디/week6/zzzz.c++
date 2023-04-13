#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct shark {
	int row, col;
	int d;
};

struct fish {
	int num;
	int d;
};

fish map[4][4];
shark S;
vector<fish>v;
int dir[8][2] = { -1,0,-1,-1,0,-1,1,-1,1,0,1,1,0,1,-1,1 };
int maxi;

void move() {

}

void input() {
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) {
			int a, b;
			cin >> a >> b;
			if (i == 0 and j == 0)
				S = { i,j,b - 1 };
			else
				map[i][j] = { a,b - 1 };
		}
}

void dfs(int total) {
	int cnt = 0;
	fish arr[4][4];
	memcpy(arr, map, sizeof(map));

	move();

	for (int p = 1; p <= 4; p++) {
		int ny = S.row + dir[S.d][0] * p;
		int nx = S.col + dir[S.d][1] * p;

		if (ny < 0 || nx < 0 || ny >= 4 || nx >= 4)continue;
		if (map[ny][nx].num == 0)continue;

		if (map[ny][nx].num >= 1) {
			cnt++;
			fish temp = map[ny][nx];
			shark sT = S;
			map[ny][nx] = { 0,0 };
			S = { ny,nx,temp.d };
			cout << ny << ' ' << nx << endl;
			dfs(total + temp.num);
			map[ny][nx] = temp;
			S = sT;
		}

	}
	if (cnt == 0) {
		maxi = max(maxi, total);
		return;
	}
	memcpy(map, arr, sizeof(map));
}

int main()
{
	input();

	dfs(map[0][0].num);

	cout << maxi << endl;

	return 0;
}