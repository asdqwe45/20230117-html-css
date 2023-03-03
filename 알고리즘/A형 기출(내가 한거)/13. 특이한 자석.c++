#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int flag[4];
int K;
int mag[4][8];
int datas[20][2];
struct MAG
{
	int pos, dir;
};

void input()
{
	cin >> K;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 8; j++)
			cin >> mag[i][j];
	for (int i = 0; i < K; i++)
		cin >> datas[i][0] >> datas[i][1];
}

void rotate(int pos, int dir)
{

	if (dir == 1)
		for (int i = 7; i >= 1; i--)
			swap(mag[pos][i], mag[pos][i - 1]);
	else
		for (int i = 0; i < 7; i++)
			swap(mag[pos][i], mag[pos][i + 1]);
}

void bfs(MAG First)
{
	queue<MAG> q;
	q.push(First);
	int used[4] = {0};
	used[First.pos] = 1;
	int addPos[2] = {1, -1};
	flag[First.pos] = 1;

	while (!q.empty())
	{
		MAG now = q.front();
		q.pop();

		for (int i = 0; i < 2; i++)
		{
			int newPos = now.pos + addPos[i];
			int newDir = -now.dir;

			if (newPos >= 4 || newPos < 0)
				continue;
			if (used[newPos] == 1)
				continue;
			used[newPos] = 1;
			if (newPos > now.pos)
			{
				if (mag[newPos][6] != mag[now.pos][2])
					flag[newPos] = 1;
				else
					continue;
			}
			if (newPos < now.pos)
			{
				if (mag[newPos][2] != mag[now.pos][6])
					flag[newPos] = 1;
				else
					continue;
			}
			q.push({newPos, newDir});
		}
	}

	int target = First.pos % 2;

	int dir = First.dir;

	for (int i = 0; i < 4; i++)
		if (flag[i] == 1)
		{
			if (i % 2 == target)
				rotate(i, dir);
			else
				rotate(i, -dir);
		}
}

int getTotal()
{
	int total = 0;
	for (int i = 0; i < 4; i++)
	{
		if (mag[i][0] == 1)
			total += pow(2, i);
	}
	return total;
}

int main()
{
	//	freopen_s(new FILE*, "input.txt", "r", stdin);

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		input();

		for (int i = 0; i < K; i++)
		{
			for (int j = 0; j < 4; j++)
				flag[j] = 0;
			bfs({datas[i][0] - 1, datas[i][1]});
		}
		cout << "#" << t << ' ' << getTotal() << '\n';
	}

	return 0;
}