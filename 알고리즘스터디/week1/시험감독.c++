#include <iostream>

using namespace std;

int A[1000000];

int main()
{
	int B, C;
	int  long long total = 0;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> A[i];

	cin >> B >> C;

	for (int i = 0; i < N; i++)
	{
		A[i] = A[i] - B;
		if (A[i] <= 0)continue;
		int  n = A[i] / C;
		int  remain = A[i] % C;
		if (remain != 0 && n != 0)
			total += n + 1;
		else if (remain != 0 && n == 0)
			total += 1;
		else if (remain == 0 && n != 0)
			total += n;
	}
	total += N;

	cout << total;


	return 0;
}