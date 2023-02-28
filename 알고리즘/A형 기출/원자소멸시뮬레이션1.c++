#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

/*
2
4
-1000 0 3 5
1000 0 2 3
0 1000 1 7
0 -1000 0 9
4
-1 1 3 3
0 1 1 1
0 0 2 2
-1 0 0 9
*/

// vector -> O(1)시간에서 터지고 있다
// int arr[100]; -> arr[101] -> 동작 함
// vector<int>v -> v[101] -> 에러
// -> vector[index] -> 실행되는 overhead -> 범위체크
// v[i]

struct Atom
{
  int x;
  int y;
  int dir;     // 방향
  int energy;  // 에너지
  int isAlive; // 이 원소가 살아있는가?
};

// SWEA - 원자 소멸 시뮬레이션
int N;               // 원자의 수
int MAP[4001][4001]; // -1000~1000의 좌표를 양수화 -> 0~2000의 좌표
// 방향 배열
int xdir[] = {0, 0, -1, 1};
int ydir[] = {1, -1, 0, 0};

vector<Atom> v; // 원자들을 담을 백터

int main()
{
  int T;
  cin >> T;
  for (int tc = 1; tc <= T; tc++)
  {
    // reset
    memset(MAP, 0, sizeof(MAP));
    v.clear();
    int cnt = 0; // 저희의 원소의 수

    // input
    cin >> N;
    for (int i = 0; i < N; i++)
    {
      int x, y, dir, energy;
      cin >> x >> y >> dir >> energy;
      // 좌표체계가 바뀌었으니
      x = (x + 1000) * 2;
      y = (y + 1000) * 2;
      v.push_back({x, y, dir, energy, 1});
      // 이제 이 (x, y) 좌표에는 하나의 원소가 살고 있다!
      MAP[x][y] = 1;
      // 하나의 원소가 더 있다!
      cnt++;
    }

    // solve - 시뮬레이션
    // 언제 끝날까? ->
    // #1. 모든 원소가 터졌거나
    // #2. 모든 원소가 터지지 않는다면 -> 살아남은 원소들은 -> 무조건 좌표를 벗어난다.
    // -> 원소가 터지면 죽는거 counting
    // -> 원소가 좌표 밖을 벗어나면 -> 죽었다! -> counting
    // 모든 원소가 죽거나 밖으로 나갈때까지 반복
    int ans = 0;
    while (true)
    {

      // 만약 모든 원소가 죽었다면 -> 시뮬레이션 종료
      if (cnt == 0)
        break;

      // 각 원소들이 다음 갈 위치를 일단 확인
      for (int i = 0; i < v.size(); i++)
      {

        Atom now = v[i];

        // 모든 원소를 볼때, 이미 죽어있는 원소 = 체크할 필요 없음
        if (now.isAlive == 0)
          continue;

        int nx = now.x + xdir[now.dir];
        int ny = now.y + ydir[now.dir];

        // 방향 사용시 항상 체크 해야하는거
        // 만약 좌표를 벗어난다면
        if (nx < 0 || ny < 0 || nx >= 4001 || ny >= 4001)
        {
          // 이 원소는 죽는다!
          v[i].isAlive = 0;
          // 이제 이 원소가 있던 위치 = 아무것도 존재하지 않게 되겠죠.
          MAP[now.x][now.y] = 0;
          // 하나의 원소가 소멸했다!
          cnt--;
          continue; // 과정 skip
        }

        // 살아있는것을 움직일떄 동작하는 코드
        // 일단 움직이기
        // 지금 위치 (x, y) -> (nx, ny)로 이동
        MAP[nx][ny]++; // 이 다음 위치에 도착한 원소가 하나 늘었다!
        MAP[now.x][now.y]--;
        if (MAP[now.x][now.y] < 0)
          MAP[now.x][now.y] = 0;

        // 지금 이 원소의 위치도 변경
        v[i].x = nx;
        v[i].y = ny;
      }

      // ---- 움직임 끝 ----
      // MAP -> 원소가 존재하는 위치 = 0보다 큰 수가 적혀있겠죠
      // 그리고 여기에 만약 2이상인 값이 존재한다면 -> 여기는 충돌이 일어난것
      // 충돌 확인
      for (int i = 0; i < v.size(); i++)
      {
        Atom now = v[i];
        if (now.isAlive == 0)
          continue;
        // 원소가 2개 이상 모여있는 공간이 있다면
        if (MAP[now.x][now.y] >= 2)
        {
          // 터트려야죠 -> v[i]랑 동일한 위치에 있는 원소를 찾을것
          for (int j = 0; j < v.size(); j++)
          {
            if (v[j].isAlive == 0)
              continue;
            // j번 노드가 살아있고, i번 노드와 같은 위치에 있다면 =
            // 얘네들은 터짐
            if (now.x == v[j].x && now.y == v[j].y)
            {
              // j번 노드는 죽임
              v[j].isAlive = 0;
              // 이만큼의 에너지가 발생한다 !
              ans += v[j].energy;
              // 하나의 원소가 더 죽었다!
              cnt--;
            }
          }
        }
        // v[i]에 존재하는 모든 원소들이 터졌으니까
        // MAP 갱신 -> 이제 이 위치에는 아무것도 없습니다.
        MAP[now.x][now.y] = 0;
      }
    }

    // output
    cout << "#" << tc << " " << ans << '\n';
  }
}