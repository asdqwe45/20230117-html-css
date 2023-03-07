#include <iostream>

using namespace std;

int N;
char map[100][100];
struct Node
{
	int row, col;
};

Node Blue;
Node Red;
Node Goal;
int cnt;
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

void bfs()
{
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'B')
				Blue.row = i, Blue.col = j;
			if (map[i][j] == 'R')
				Red.row = i, Red.col = j;
			if (map[i][j] == 'O')
				Goal.row = i, Goal.col = j;
		}

	return 0;
}