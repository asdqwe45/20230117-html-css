#include <iostream>

using namespace std;

int N, M;
int r, c, d;
int map[100][100];

int dir[4][2] = {-1, 0, 0, -1, 1, 0, 0, 1};

int main()
{
	cin >> N >> M;
	cin >> r >> c >> d;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	int cnt = 1;
	int nr, nc;
	map[r][c] = 2;

	if (d == 1)
		d = 3;
	else if (d == 3)
		d = 1;

	while (1)
	{
		int nr, nc;
		int flag = 0;
		int i;
		for (i = 1; i < 5; i++)
		{

			nr = r + dir[(d + i) % 4][0];
			nc = c + dir[(d + i) % 4][1];

			if (map[nr][nc] == 0)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
		{
			cnt++;
			map[nr][nc] = 2;
			d = (d + i) % 4;
			r = nr, c = nc;
		}
		else
		{
			int direct = (d + 2) % 4;
			r = r + dir[direct][0];
			c = c + dir[direct][1];

			if (map[r][c] == 1)
				break;
		}
	}

	cout << cnt << endl;

	return 0;
}