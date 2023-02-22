#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <string>

using namespace std;

struct Node {
	int y, x;
};

unordered_map<int, vector<Node>>um;


int main()
{
	int arr[3][3] = {
		15,11,-7,
		55,-7,11,
		-7,-55,-9
	};

	
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			um[arr[i][j]].push_back({ i,j });

	int a; cin >> a;

	if (um.count(a) > 0) {
		int n = um[a].size();
		for (int i = 0; i < n; i++) {
			//cout << um[a][i].y << " , " << um[a][i].x << '\n';
			Node ret = um[a][i];
			cout << ret.y << "," << ret.x << '\n';

		}
	}
	else
		cout << "없다";




	return 0;
}