#include <iostream>
#include <cstring>
using namespace std;

int N;
int map[20][20];
int maxi = 2;

void gravity(int dir) {
    if (dir == 0) { // 상
        for (int i = 0; i < N; i++) {
            int now = 0;
            for (int j = 0; j < N; j++) {
                int temp = map[j][i];
                if (temp == 0) continue;
                map[j][i] = 0;
                map[now++][i] = temp;
            }
        }
    }

    else if (dir == 1) { // 하
        for (int i = 0; i < N; i++) {
            int now = N - 1;
            for (int j = N-1; j >= 0; j--) {
                int temp = map[j][i];
                if (temp == 0) continue;
                map[j][i] = 0;
                map[now--][i] = temp;
            }
        }
    }

    else if (dir == 2) { // 좌
        for (int i = 0; i < N; i++) {
            int now = 0;
            for (int j = 0; j < N; j++) {
                int temp = map[i][j];
                if (temp == 0) continue;
                map[i][j] = 0;
                map[i][now++] = temp;
            }
        }
    }

    else if (dir == 3) { // 우
        for (int i = 0; i < N; i++) {
            int now = N - 1;
            for (int j = N - 1; j >= 0; j--) {
                int temp = map[i][j];
                if (temp == 0) continue;
                map[i][j] = 0;
                map[i][now--] = temp;
            }
        }
    }
}


void run(int dir) {

    gravity(dir);

    if (dir == 0) { // 상
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N - 1; j++) {
                if (map[j][i] == 0) continue;
                if (map[j][i] == map[j + 1][i]) {
                    map[j][i] *= 2;
                    map[j + 1][i] = 0;
                }
            }
        }
    }

    else if (dir == 1) { // 하
        for (int i = 0; i < N; i++) {
            for (int j = N-1; j > 0; j--) {
                if (map[j][i] == 0) continue;
                if (map[j][i] == map[j - 1][i]) {
                    map[j][i] *= 2;
                    map[j - 1][i] = 0;
                }
            }
        }
    }

    else if (dir == 2) { // 좌
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N-1; j++) {
                if (map[i][j] == 0) continue;
                if (map[i][j] == map[i][j+1]) {
                    map[i][j] *= 2;
                    map[i][j+1] = 0;
                }
            }
        }
    }

    else if (dir == 3) { // 우
        for (int i = 0; i < N; i++) {
            for (int j = N-1; j > 0; j--) {
                if (map[i][j] == 0) continue;
                if (map[i][j] == map[i][j-1]) {
                    map[i][j] *= 2;
                    map[i][j-1] = 0;
                }
            }
        }
    }

    gravity(dir);
}

void dfs(int lev) {
    if (lev == 5) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (map[i][j] > maxi) maxi = map[i][j];
            }
        }

        return;
    }

    int cpy[20][20] = { 0, };
    for (int i = 0; i < 4; i++) {
        memcpy(cpy, map, sizeof(map));
        run(i);
        dfs(lev + 1);
        /*
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                cout << map[y][x] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
        */
        memcpy(map, cpy, sizeof(map));
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    dfs(0);

    cout << maxi;

    return 0;
}