#include <iostream>

using namespace std;

int N,M;
char map[100][100];
struct Node
{
	int row, col;
};

Node Blue;
Node Red;
Node Goal;
<<<<<<< HEAD
int cntA;
int cntB;
int dir[4][2] = { 1, 0, -1, 0, 0, 1, 0, -1 };

void dfs(int lev,int Ay,int Ax,int By,int Bx)
{


	if (lev == 10)
		return;

	int i; int p;
	for (i = 0; i < 4; i++) {
		int flag = 0;
		for (p = 1; p < N; p++) {

			int nAy = Ay + dir[i][0] * p, nAx = Ax + dir[i][1] * p;

			if (map[nAy][nAx] == '#')break;
			if (map[nAy][nAx] == 'O') {
				cntA = min(cntA, lev+1);
			}
			if (map[nAy][nAx] == 'B'&&flag==0) {
				for (p = 1; p < N; p++) {
					int nBy = By + dir[i][0] * p, nBx = Bx + dir[i][1] * p;

					
					if (map[nBy][nBx] == '#')break;
					if (map[nBy][nBx] == 'O') {
						flag = 1;
						cntB = min(cntB,lev+1);
					
					}
				}
			}
			
		}
		int g = p;
		if(flag==0)
		for (p = 1; p < N; p++) {
			int nBy = By + dir[i][0] * p, nBx = Bx + dir[i][1] * p;


			if (map[nBy][nBx] == '#')break;
			if(map[nBy][nBx]=='A')
			if (map[nBy][nBx] == 'O') {
				flag = 1;
				cntB = min(cntB, lev+1);

			}
		}
		if (g == 1 && p == 1)continue;
		dfs(lev + 1, Ay + dir[i][0] * (g - 1), Ax + dir[i][1] * (g - 1), By + dir[i][0] * (p - 1), By + dir[i][1] * (p - 1));
	}


=======
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
>>>>>>> 2af56c18ca3cd8543fa1ca9871aa8023198a15bb
}

int main()
{
	cin >> N>> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'B')
				Blue.row = i, Blue.col = j;
			if (map[i][j] == 'R')
				Red.row = i, Red.col = j;
			if (map[i][j] == 'O')
				Goal.row = i, Goal.col = j;
		}
	cntA = 2e8, cntB = 2e8;

	dfs(0, Red.row, Red.col, Blue.row, Blue.col);


	int d = 1;

	return 0;
}