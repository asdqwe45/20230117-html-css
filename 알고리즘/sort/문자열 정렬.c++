#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;


bool cmp(string& left, string& right)
{
	// 부등호 쓰지말기 ex) >=
	
	if (left.length() < right.length())
		return true;
	if (left.length() > right.length())
		return false;
	if (left < right)
		return true;
	if (left > right)
		return false;
	return false;
}


int main()
{

	string names[100];
	int N; cin >> N;

	for (int i = 0; i < N; i++)
		cin >> names[i];

	sort(names, names + N,cmp);

	for (int i = 0; i < N; i++)
		cout << names[i] << '\n';

	return 9;

}