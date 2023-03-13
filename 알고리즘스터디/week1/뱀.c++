#include <iostream>
#include <vector>
using namespace std;

struct Node { int y, x; };

int mapSize, appleCnt, changeCnt;
int moveDir[10000];
int map[100][100];

int snake()
{
    // snake
    vector<Node> snake;
    snake.push_back({ 0, 0 });

    map[0][0] = 2;

    // direction Array
    int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

    // move
    int dirIndex = 0;
    for (int time = 0; time < 10000; time++)
    {
        Node now = snake.back();

        dirIndex += moveDir[time];
        if (dirIndex < 0) dirIndex = 3;
        if (dirIndex >= 4) dirIndex = 0;

        int ny = now.y + dir[dirIndex][0];
        int nx = now.x + dir[dirIndex][1];

        if (ny < 0 || ny >= mapSize || nx < 0 || nx >= mapSize) return time + 1;
        if (map[ny][nx] == 2) return time + 1;

        if (map[ny][nx] == 0)
        {
            snake.push_back({ ny, nx });
            map[ny][nx] = 2;
            Node tail = snake.front();
            map[tail.y][tail.x] = 0;
            snake.erase(snake.begin());
        }
        if (map[ny][nx] == 1)
        {
            snake.push_back({ ny, nx });
            map[ny][nx] = 2;
        }
    }
}

int main()
{
    // input
    cin >> mapSize >> appleCnt;
    for (int i = 0; i < appleCnt; i++)
    {
        int y, x;
        cin >> y >> x;
        map[y - 1][x - 1] = 1;
    }
    cin >> changeCnt;
    for (int i = 0; i < changeCnt; i++)
    {
        int time;
        char turn;
        cin >> time >> turn;
        if (turn == 'D') moveDir[time] = 1;
        if (turn == 'L') moveDir[time] = -1;
    }

    // solve
    int leadTime = snake();

    // output
    cout << leadTime;

    return 0;
}