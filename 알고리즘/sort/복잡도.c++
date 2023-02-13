#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int A(int n)
{
	int res = 0;
	for (int i = 1; i <= n; i++)
		res += i;

	return res;
}
int B(int n)
{
	return n * (n + 1) / 2;
}


int main()
{
	
	int n; cin >> n;

	//cout << A(n) << '\n'; // O(n)

	//cout << B(n) << '\n'; // O(1)
	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) // O(n^2)
			cnt++;
	// c++기준 1억개가 될 때 1초정도 나온다.

	return 0;

}