#include <iostream>
#include <cstring>
using namespace std;

int dir1[4][2] = { 0,0,0,1,0,2,0,3 };
int dir2[4][2] = { 0,0,1,0,2,0,2,1 };
int dir3[4][2] = { 0,0,1,0,1,1,2,1 };
int dir4[4][2] = { 0,0,0,1,1,0,1,1 };
int dir5[4][2] = { 0,0,0,1,0,2,1,1 };
int maxi = -2e8;
int N, M;

int map[500][500];
int mapCopy[500][500];

void test(int temp[500][500], int row,int col) {
    for (int i = 0; i <= row - 1; i++)
        for (int j = 0; j <= col - 4; j++)
        {
            int total = 0;
            for (int k = 0; k < 4; k++) {
                int ny = i + dir1[k][0];
                int nx = j + dir1[k][1];

                total += map[ny][nx];

            }
            if (total > maxi)maxi = total;
        }

    for (int i = 0; i <= row - 3; i++)
        for (int j = 0; j <= col - 2; j++)
        {
            int total = 0;
            for (int k = 0; k < 4; k++) {
                int ny = i + dir2[k][0];
                int nx = j + dir2[k][1];

                total += map[ny][nx];

            }
            if (total > maxi)maxi = total;
        }

    for (int i = 0; i <= row - 3; i++)
        for (int j = 0; j <= col- 2; j++)
        {
            int total = 0;
            for (int k = 0; k < 4; k++) {
                int ny = i + dir3[k][0];
                int nx = j + dir3[k][1];

                total += map[ny][nx];

            }
            if (total > maxi)maxi = total;
        }


    for (int i = 0; i <= row - 2; i++)
        for (int j = 0; j <= col - 2; j++)
        {
            int total = 0;
            for (int k = 0; k < 4; k++) {
                int ny = i + dir4[k][0];
                int nx = j + dir4[k][1];

                total += map[ny][nx];

            }
            if (total > maxi)maxi = total;
        }

    for (int i = 0; i <= row - 2; i++)
        for (int j = 0; j <= col - 3; j++)
        {
            int total = 0;
            for (int k = 0; k < 4; k++) {
                int ny = i + dir5[k][0];
                int nx = j + dir5[k][1];

                total += map[ny][nx];

            }
            if (total > maxi)maxi = total;
        }
}
void turn(int row, int col) {
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            mapCopy[col - 1 - j][i] = map[i][j];
}

void moveDecal(int row, int col) {
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            mapCopy[j][i] = map[i][j];
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> map[i][j];

    // map
    test(map, N, M);

    turn(N, M);
    memcpy(map, mapCopy, sizeof(map));
    test(map, M, N);

    turn(M, N);
    memcpy(map, mapCopy, sizeof(map));
    test(map, N, M);

    turn(N, M);
    memcpy(map, mapCopy, sizeof(map));
    test(map, M, N);

    // 대칭이동
    moveDecal(M, N);
  
    memcpy(map, mapCopy, sizeof(map));
    test(map,N, M);

    turn(N, M);
    memcpy(map, mapCopy, sizeof(map));
    test(map, M, N);

    turn(M, N);
    memcpy(map, mapCopy, sizeof(map));
    test(map, N, M);

    turn(N, M);
    memcpy(map, mapCopy, sizeof(map));
    test(map, M, N);


    cout << maxi << '\n';
    int d = 1;  

    return 0;
}