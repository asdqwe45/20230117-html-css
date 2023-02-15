#include <iostream>

using namespace std;
/*
18 15
3 0
6 3
9 6
10 6
11 6
4 1
7 4
12 4
13 4
14 7
5 2
8 5
15 8
16 8
17 8
*/

int parent[20];
int N, M;

// Find의 시간복잡도 O(N)
//  경로 압축 후의 시간복잡도 O(1) ~ O(logN)
//  장점 : 시간의 효율성이 대폭 상승
//  단점 : 돌이킬 수 없음

int Find(int now)
{
  // 종료 조건
  // now의 부모가 나랑 같다면 : => 소속을 찾았다!
  if (now == parent[now])
    return now;

  // 재귀 구성
  // 내가 대장이 아니면 -> 나의 부모를 찾아가라!
  // path compression
  // 돌아왔을 때-> 소속을 "아는 상태"로 가지고 돌아오니까
  // 나의 부모(소속)은 = 돌아올 때 가지고 있던 값이다.
  return parent[now] = Find(parent[now]);
}

int main()
{
  // Union Find  ==  Disjoint Set  분리집합
  // 소속/그룹을 만들고 유지/관리하는 알고리즘
  // Union : 서로 두개의 다른 집합을 결합하는 작업
  // Find  : 특정 소속에 속한 멤버가 "어떤 소속에 포함되어있는가?를 찾아가고, 판단하는 작업
  // Find ->소속을 찾아가는 작업
  // Find + 최적화 => path compression(=경로 압축)

  // parent는 항상 자기 자신이 대장이다!
  //  즉 본인은 개별적인 노드이다 라는 상태에서 시작

  for (int i = 0; i < 3; i++)
    parent[i] = i;

  // cin >> N >> M;
  // for (int i = 0; i < M; i++)
  //{
  //	int A, B;
  //	cin >> A >> B;
  //	// A의  부모는 B다
  //	parent[A] = B;
  // }
  for (int i = 0; i < 100; i++)
    parent[i + 1] = i;

  int num;
  cin >> num;
  cout << num << "의 소속은 : " << Find(num) << '\n';

  cout << num << "의 소속은 : " << Find(num) << '\n';

  for (int i = 0; i < 100; i++)
  {
    cout << parent[i] << ' ';
  }

  return 0;
}