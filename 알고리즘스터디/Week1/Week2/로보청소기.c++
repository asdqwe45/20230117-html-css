#include <iostream>

using namespace std;

int dir[4][2] = { -1,0,0,-1,1,0,0,1 };
int map[100][100];
int N, M;
int r, c, d;




int main()
{
	cin >> N >> M;
	cin >> r >> c >> d;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	}

	int cnt = 0;
	map[r][c] = 2;
	cnt++;
	

	int nr, nc;
	while (1)
	{
		
		std::cout << r << ' ' << c << '\n';
		int flag = 0;

		for (int i = 0; i < 4; i++) {
			nr = r + dir[(d + i) % 4][0];
			nc = c + dir[(d + i) % 4][1];

			if (map[nr][nc] == 0) {
				d += i;
				flag = 1;
				break;
			}
			

		}
		if (flag == 1) {
			map[nr][nc] = 2;
			cnt++;
			r = nr, c = nc;
		}
		else {
			int direct = (d + 2) % 4;
			int tr = r + dir[direct][0];
			int tc = c + dir[direct][1];

			if (map[tr][tc] == 1)
				break;
			r = tr, c = tc;
		}
		

	}

	std::cout << cnt << endl;

	return 0;
}