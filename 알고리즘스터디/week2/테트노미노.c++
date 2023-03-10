#include <iostream>

using namespace std;

int dir1[4][2] = {0, 0, 0, 1, 0, 2, 0, 3};
int dir2[4][2] = {0, 0, 1, 0, 2, 0, 2, 1};

int map[5][5] = {
    1, 2, 3, 4, 5,
    6, 7, 8, 9, 10,
    11, 12, 13, 14, 15};

int main()
{
  int N = 3, M = 5;

  int copy[5][5];
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      copy[j][i] = map[i][j];

  int turn1[5][5];
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      turn1[M - 1 - j][i] = map[i][j];

  int turn2[5][5];
  for (int i = 0; i < M; i++)
    for (int j = 0; j < N; j++)
      turn2[N - 1 - j][i] = turn1[i][j];

  int turn3[5][5];
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      turn3[M - 1 - j][i] = turn2[i][j];

  int d = 1;

  return 0;
}