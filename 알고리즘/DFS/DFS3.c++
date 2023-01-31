#include <iostream>
#include <vector>
using namespace std;

// 문제. 
// 0번 노드에서 2번 노드로 가는데 다양한 길이 있다.
// 그 다양한 길들은 각각의 통행료가 (=가중치)있는데
// 0번에서 2번 노드로 가는데에 발생할 수 있는 통행료의 합들을 출력하라.

// 추가적으로 해보면 좋은 것
// 1단계 : 그래프 가중치값들을 바꿔보기
// 2단계 : 최종적으로 MAX 값 , MIN 값만을 출력하는 형태로 만들어보기
// 3단계 : 노드 개수, 간선 개수, 가중치 값
//         시작지점, 도착지점 등을 직접 입력 받는 형태로 만들어보기

int sum = 0; // 총합

int visited[4] = { 0, }; // 방문배열, 노드개수만큼

struct Edge // 구조체
{
    int to; // 가게 될 노드번호
    int price; // 가중치 값
};

vector<Edge> v[4]; // 구조체 이차원벡터 생성(얼마나? 노드 개수만큼) 
                   // 또는 vector<vector<Edge>> v(4); 라고 선언 해주셔도 됩니다.
                   

void dfs(int now, int sum)
{

if (now == 2) // 2번 노드에 도착했다면 
{
    cout << sum << endl; // 2번 노드로 오면서의 총합 출력
    return;
}


for (int i = 0; i < v[now].size(); i++) // 현재 탐색중인 벡터의 사이즈만큼 탐색
                                        // 아래 하드코딩으로 초기화 한 것을 예시로 들면
                                        // v[0] 의 사이즈는 3,  v[1]의 사이즈는 1 ....
{
    int next = v[now][i].to; // 다음에 갈 노드번호는 현재 탐색중인 v[now][i] 의 to 값인데
                             // 그것을 next 라는 변수에 받아옴.

    if (visited[next] == 1) continue; // 다음 방문 예정인 노드에 이미 방문한 적이 있다면 컨티뉴
    visited[next] = 1; // 그렇지 않다면, 방문 전 1을 체크

    dfs(next, sum + v[now][i].price); // next를 통해서 노드가 넘어갈 것이고
                                      // sum 값에는 v[now][i]의 price 값을 더해줌.
    
    visited[next] = 0;
}
};

int main()
{
         // 인접리스트 하드코딩 초기화

v[0] = { {1,7} , {2,20} , {3,8} }; // v[from] = { {to, price} , {to,price} , {to,price} };
                                                 // 예) v[0][0]는 to = 1, price = 7 값을 가지고 있음.
                                                 // 조사식으로 확인해보세요 !
v[1] = { {2,5} };
v[2] = { {0,15} };
v[3] = { {2,6} };



visited[0] = 1; // 시작노드인 0을 방문배열에 1을 체크하고 DFS고고
dfs(0, sum); // (시작노드번호, sum값)

return 0;
}