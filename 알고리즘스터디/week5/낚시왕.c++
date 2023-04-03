#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


int R, C, M;
int dir[4][2] = { -1,0,1,0,0,1,0,-1 };
int rowCnt, colCnt;

struct Node {
	int row;
	int sp;
	int dir;
	int size;
	int hp;
};
struct Nude {
	int row;
	int col;
	int sp;
	int dir;
	int size;
	int hp;
};

vector<vector<Node>>v;

struct cmt {
	bool operator()(Node left, Node right) {
		if (left.size < right.size)return true;
		return false;
	}
};

bool cmp(Node left, Node right) {
	if (left.row > right.row)return true;
	return false;
}

vector<vector<Node>> run() {
	int used[100][100] = { 0 };
	vector<vector<Node>>v2;
	for (int i = 0; i < C; i++) {
		int s = v[i].size();
		for (int j = 0; j < s; j++) {
			Node now = v[i][j];
			now.sp%= colCnt;
			int col = i;
			for (int k = 0; k < now.sp; k++) {
				now.row += dir[now.dir][0];
				col += dir[now.dir][1];

				if (now.row < 0 || col < 0) {
					if (now.dir % 2 == 0)
						now.dir--;
					else
						now.dir++;
					now.row += 2 * dir[now.dir][0];
					col += 2 * dir[now.dir][1];
				}
			}
			if (used[now.row][col] == 1)
				continue;
			v2[col].push_back({ now.row,now.sp,now.dir,now.size,now.hp });
		}
	}
	return v2;
}

int main()
{
	cin >> R >> C >> M;

	for (int i = 0; i < M; i++) {
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		v[b-1].push_back({ a-1,c,d,e,1 });
	}
	int total = 0;
	rowCnt = 2 * R - 2;
	colCnt = 2 * C - 2;
	priority_queue<Nude,vector<Nude>,cmt>q;
	for (int i = 0; i < C; i++) {
		for (int j = 0; j < R; j++) {
			if (v[i].size()) {
				total += v[i][j].size;
				v[i].erase(v[i].begin());
				break;
			}
		}
		for (int j = 0; j < C; j++) {
			int s = v[j].size();
			for (int k = 0; k < s; k++) {
				Node now = v[j][k];
				q.push({ now.row,j,now.sp,now.dir,now.size,now.hp });
			}
		}
		v=run();

	}

	int d = 1;
	return 0;
}
