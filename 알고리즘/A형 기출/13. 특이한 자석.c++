#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

/*
10
2
1 0 0 1 0 0 0 0
0 1 1 1 1 1 1 1
0 1 0 1 0 0 1 0
0 1 0 0 1 1 0 1
3 1
1 1
*/
int k;
string s[4];
int Query[20][2]; // Query[회전 번호][0 : pos, 1 : dir]
void input()
{
  cin >> k;
  for (int i = 0; i < 4; i++)
  {
    s[i] = "";
    for (int j = 0; j < 8; j++)
    {
      char a;
      cin >> a;
      s[i] += a;
    }
  }
  for (int i = 0; i < k; i++)
    cin >> Query[i][0] >> Query[i][1];
}

/*
*
1. 붙어있는 자성이 같은가?
   arr[2][오른쪽 자성 위치 : 2] == arr[3][왼쪽 자성 위치 : 6]
2. 회전방향 결정 <- 1번의 연장선

3. 자석을 회전
실제로 돌린다, 인덱스 번호 이동

*/

int direct[4]; // 각 자석별 회전 방향
void calc_dir(int pos, int dir)
{ // 회전 방향을 결정
  // pos위치의 자석을 dir방향으로 돌릴 때, 다른 자석들은 어느 방향으로 돌아는가?
  memset(direct, 0, sizeof(direct));
  direct[pos] = dir;

  // pos기준 왼쪽들 확인
  for (int i = pos - 1; i >= 0; i--)
    if (s[i][2] == s[i + 1][6]) // 붙어 있는 자성이 같으면 ?
      break;                    // 더 이상 왼쪽방향으론 회전이 X
    else
      direct[i] = -direct[i + 1]; // 내 방향은 내 오른쪽의 반대 방향

  // pos기준 오른쪽들 확인
  for (int i = pos + 1; i < 4; i++)
    if (s[i - 1][2] == s[i][6])
      break; // 더 이상 오른쪽방향으론 회전이 X
    else
      direct[i] = -direct[i - 1];
}

void rotate()
{ // direct라는 회전 방향에 맞게 회전시키기!
  for (int i = 0; i < 4; i++)
  {
    if (direct[i] == 1)
      s[i] = s[i][7] + s[i].substr(0, 7);
    else if (direct[i] == -1)
      s[i] = s[i].substr(1, 7) + s[i][0];
  }
}
void printMag()
{
  // 디버깅용 출력
  for (int j = 0; j < 4; j++)
    cout << s[j] << "\n";
  cout << "\n";
}

int calc_score()
{
  int score = 0;
  // int temp = 1;
  for (int i = 0; i < 4; i++)
  {
    if (s[i][0] == '1')
      score += 1 << i; // 0번 : 1점(2^0), 1번 : 2점(2^1), 2번 : 4점(2^2), 3번 : 8점(2^3)
                       // temp *= 2;
  }
  return score;
}

int solution()
{
  // printMag();
  for (int i = 0; i < k; i++)
  {
    // 입력되는 자석 번호 - 1 == 우리가 사용하는 자석 번호
    calc_dir(Query[i][0] - 1, Query[i][1]);
    rotate();
    // printMag();
  }
  return calc_score();
}

int main()
{
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++)
  {
    input();
    cout << "#" << tc << " " << solution() << "\n";
  }
}