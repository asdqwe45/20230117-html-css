#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> arr(5);


void run(int now)
{
	cout << now;
	// 다음 갈 곳을 찾아라
	for (int i = 0; i < arr[now].size(); i++) {
		int next = arr[now][i];
		run(next);
	}
}

int main()
{
	//// 특정 노드 번호를 입력받으면 
	//// 연결된 노드 모두 출력
	arr[0] = { 3 };
	arr[1] = { 2,0 };
	arr[3] = { 4,2 };
	arr[4] = { 2 };

	//int n; cin >> n;
	//for (int i = 0; i < arr[n].size(); i++)
	//	cout << arr[n][i] << ' '; // 인접행렬은 if문으로 모두 돌린다. 
	//                            // 인접리스트는 if문 없고 딱 그 갯수 만큼만 출력 그래서 효율적
	run(0);

	return 0;
}