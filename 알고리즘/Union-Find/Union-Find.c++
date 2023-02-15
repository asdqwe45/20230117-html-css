#include <iostream>

using namespace std;
/* 9개의 노드, 6개의 결합 정보
9 7
0 3
3 6
6 8
3 7
1 4
2 5
4 3
*/

int parent[20];
int N, M;

// Find의 시간복잡도 O(N)
//  경로 압축 후의 시간복잡도 O(1) ~ O(logN)
//  장점 : 시간의 효율성이 대폭 상승
//  단점 : 돌이킬 수 없음

int Find(int now)
{

  if (now == parent[now])
    return now;

  return parent[now] = Find(parent[now]);
}

void Union(int A, int B)
{
  // #1. 각 A와 B의 소속을 확인
  int pa = Find(A);
  int pb = Find(B);

  // #2. B의 소속을 A 소속의 산하로 만든다.
  parent[pb] = pa;
}

int main()
{
  // Union Find  ==  Disjoint Set  분리집합
  // 소속/그룹을 만들고 유지/관리하는 알고리즘
  // Union : 서로 두개의 다른 집합을 결합하는 작업
  // Find  : 특정 소속에 속한 멤버가 "어떤 소속에 포함되어있는가?를 찾아가고, 판단하는 작업
  // Find ->소속을 찾아가는 작업

  // Find + 최적화 => path compression(=경로 압축)

  cin >> N >> M;

  for (int i = 0; i < N; i++)
    parent[i] = i;

  for (int i = 0; i < M; i++)
  {
    int A, B;
    cin >> A >> B;
    Union(A, B);
  }

  int a, b;
  cin >> a >> b;
  // a와 b가 같은 그룹인가?
  // --> 절대 현재 parent의 상황으로 비교 X
  // --> 한번 더 업데이트
  // A의 대표를 다시 한번 찾아가면서 parent를 업데이트
  // --> A
  if (Find(a) == Find(b))
    cout << "같은 그룹";
  else
    cout << "다른 그룹";

  // 문제
  // N개의 회사가 있습니다. (IT 회사)
  // 회사들이 경제가 안 좋아서 망하면서 M개의 인수합병 과정을 밟는다.
  // A가 B를 인수할 때, A회사가 대표회사가 되고
  // B회사로부터 10명의 개발자들을 빼올겁니다.
  // M개의 인수합병 과정을 거친 후 각 회사에 몇 몇의 개발자가 남아있는지를 출력

  /*
  6 5
  10 20 30 40 50
  0 1
  3 0
  3 4
  4 3
  2 5
  */
  // output : 10 10 40 60 40 50
  return 0;
}