#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct Node {
	int y, x;
	int isAlive;
};
struct fish {
	int num;
	int d;
};
struct shark {
	int y, x;
	int d;
};

int st;
shark S;
Node A[17];
fish map[4][4];
int dir[8][2] = { -1,0,-1,-1,0,-1,1,-1,1,0,1,1,0,1,-1,1 };
int maxi;

void move() {
	for (int i = 1; i <= 16; i++) {
		if (A[i].isAlive == 1) {
			fish now = map[A[i].y][A[i].x];
			for (int j = 0; j < 8; j++) {
				int ny = A[i].y + dir[(now.d + j) % 8][0];
				int nx = A[i].x + dir[(now.d + j) % 8][1];

				if (ny < 0 || nx < 0 || ny >= 4 || nx >= 4)continue;
				if (ny == S.y&&nx == S.x)continue;
				map[A[i].y][A[i].x].d = (now.d + j) % 8;
				swap(map[A[i].y][A[i].x], map[ny][nx]);
				swap(A[i], A[map[A[i].y][A[i].x].num]);
				break;
			}
		}
	}
}

void dfs(int total) {
	int cnt = 0;
	fish temp[4][4];
	memcpy(temp, map, sizeof(map));
	move();
	for (int p = 1; p <= 3; p++) {
		int ny = S.y + dir[S.d][0] * p;
		int nx = S.x + dir[S.d][1] * p;
		if (ny < 0 || nx < 0 || nx >= 4 || ny >= 4)continue;
		int sum = map[ny][nx].num;
		if (A[sum].isAlive == 0)
			continue;
		shark t = S;
		S = { ny,nx,map[ny][nx].d };
		cnt++;
		A[sum].isAlive = 0;

		dfs(total + sum);

		A[sum].isAlive = 1;
		S = t;
	}

	memcpy(map, temp, sizeof(map));

	if (cnt == 0) {
		maxi = max(maxi, total);
		return;
	}
}

void input() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int a, b;
			cin >> a >> b;
			A[a] = { i,j,1 };
			map[i][j] = { a,b - 1 };
			if (i == 0 && j == 0) {
				st = map[i][j].num;
				A[a] = { i,j,0 };
				S = { i,j,b - 1 };
			}
		}
	}
}

int main()
{
	input();

	dfs(st);

	cout << maxi << endl;



	return 0;
}