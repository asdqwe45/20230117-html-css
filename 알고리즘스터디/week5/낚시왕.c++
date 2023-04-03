#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int R, C, M;
int dir[4][2] = { -1,0,1,0,0,1,0,-1 };

struct Node{
	int row;
	int sp;
	int dir;
	int size;
	int hp;
};

vector<vector<Node>>v(100);

bool cmp(Node left, Node right) {
	if (left.size > right.size)return true;
	return false;
}

void run() {
	int used[100][100] = { 0 };


}

int main()
{
	cin >> R >> C >> M;

	for (int i = 0; i < M; i++) {
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		v[a].push_back({ b,c,d,e,1 });
	}
	int total = 0;
	for (int i = 0; i < C; i++) {
		for (int j = 0; j < R; j++) {
			
		}
		run();
		
	}

	int d = 1;
	return 0;
}
