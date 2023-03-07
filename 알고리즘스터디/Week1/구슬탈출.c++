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
int minCnt=2e8;

int isOut(int y, int x)
{
	return (y < 1 || x < 1 || y >= N - 1 || x >= N - 1);
}

void dfs(int lev, int Ay, int Ax, int By, int Bx)
{
	int tAy = Ay, tAx = Ax;
	int tBy = By, tBx = Bx;

	int p;
	int i;
	int j;
	int h;
	int flag = 0;
	for (i = 0; i < 4; i++)
	{
		for (p = 1; p < N; p++)
		{
			Ay += dir[i][0] * p;
			Ax += dir[i][0] * p;
			if (isOut(Ay, Ax))
				break;
				if(map[Ay][Ax]=='O')
				minCnt=min(minCnt,lev);
			if (map[Ay][Ax] == 'B')
			{
				flag = 1;
				for (j = 0; j < 4; j++)
				{
					for (h = 1; h < N; h++)
					{
						By += dir[i][0] * h;
						Bx += dir[i][0] * h;

						if (isOut(By, Bx))
							break;
						if (map[By][Bx] == '#')
							break;
					}
				}
			}
			if (flag == 0)
			{
				for (j = 0; j < 4; j++)
				{
					for (h = 1; h < N; h++)
					{
						int nBy = By + dir[i][0] * h;
						int nBx = Bx + dir[i][0] * h;

						if (isOut(nBy, nBx))
							break;
						if (map[By][Bx] == '#')
						break;
					}
				}
			}
		}
	}
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