#include <iostream>
using namespace std;
/*
// 9개의 노드, 6개의 결합 정보
9 7
0 3
3 6
6 8
3 7
1 4
2 5
4 3
*/
// Find : 소속을 찾아가는 알고리즘
// #1. 정보 (부모 정보)를 저장할 parent가 필요
int parent[101];
int N, M;
// 개발자 수 정보
int pop[101];
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
  // 만약 A와 B가 이미 같은 소속이라면 아래 합병을 거치지 마라!
  if (pa == pb)
    return; // 함수 종료
  // #2. B의 소속을 A의 소속의 산하로 만든다!
  parent[pb] = pa;
  // 합병이 되면서, A회사가 B회사의 개발자를 10명 데려온다!
  pop[A] += 10;
  pop[B] -= 10;
}
int main()
{
  // cin >> N >> M;
  //// parent는 항상 자기 자신이 대장이다!
  //// 즉, 본인은, 개별적인 노드이다! 라는 상태에서 시작
  // for (int i = 0; i < N; i++)
  //     parent[i] = i; // 나의 부모는 나다!
  //// 소속 결합 정보
  // for (int i = 0; i < M; i++) {
  //     // A와 B가 결합된다!
  //     int A, B;
  //     cin >> A >> B;
  //     Union(A, B);
  // }
  // int a, b;
  // cin >> a >> b;
  //// a와 b가 같은 그룹인가?
  //// --> 절대 현재 parent의 상황으로 비교 X
  //// --> 한번 더 업데이트
  //// if (parent[a] == parent[b])
  //// -> A의 대표를 다시 한번 찾아가면서 parent를 update
  //// --> A의 상위 노드에 대한 path compression
  // if(Find(a) == Find(b))
  //     cout << "같은 그룹";
  // else
  //     cout << "다른 그룹";
  //  문제
  //  N개의 회사가 있습니다 (IT 회사)
  //  회사들이 경제가 안좋아서 망하면서 M개의 인수합병 과정을 밟아요
  //  A가 B를 인수할때, A회사가 대표회사가 되고,
  //  B회사로부터 10명의 개발자들을 빼올겁니다.
  //  M개의 인수합병 과정을 거친 후, 각 회사에 몇 명의 개발자가 남아있는지를 출력
  //  input
  /*
  6 5
  10 20 30 40 50 60
  0 1
  3 0
  3 4
  4 3
  2 5
  */
  // output : 10 10 40 60 40 50
  cin >> N >> M;

  // parent 구성
  for (int i = 0; i < N; i++)
  {
    parent[i] = i;
    int temp;
    cin >> temp;
    pop[i] = temp;
  }
  // 합병 정보
  for (int i = 0; i < M; i++)
  {
    // A와 B가 합병한다!
    int A, B;
    cin >> A >> B;
    // Union을 하기 전에, 이런 문제에서는, 이미 결합된 소속을 다시 결합하면 문제가 생길 수 있다!
    // #1. Union을 하기 전에 결합 여부 확인
    if (Find(A) == Find(B))
      continue; // 이미 같은 소속이라면 결합하지 않아!
    Union(A, B);
  }
  for (int i = 0; i < N; i++)
  {
    cout << i << " : " << pop[i] << '\n';
  }
}