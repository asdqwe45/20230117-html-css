#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct Data {
	int st;
	int en;
};

bool cmp(Data left, Data right)
{
	if (left.en < right.en)
		return true;
	if (left.en > right.en)
		return false;
	/*if (left.st > right.st)
		return true;
	if (left.st < right.st)
		return false;*/
	return false;

}


int main()
{
	int N; cin >> N;

	Data Time[100000];

	for (int i = 0; i < N; i++)
		cin >> Time[i].st >> Time[i].en;

	sort(Time, Time + N, cmp);

	int endTime = 0;
	int cnt = 0;
	for (int i = 0; i < N; i++)
		if (Time[i].st >= endTime) {
			cnt++;
			endTime = Time[i].en;
		}
	
	cout << cnt;

	return 0;

}