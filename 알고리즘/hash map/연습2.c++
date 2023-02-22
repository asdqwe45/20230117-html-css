#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;



string arr[] = { "HI","HI","GGG","HI","GGG" };
unordered_map<string, int>um;
int main()
{
	// 문자열 하나 입력받고, 그 문자여링 배열에 몇 개 있는지 출력하는
	// 프로그램 작성하기
	// 입력 받기 전 사저 ㄴ세팅( 빠른 검색을 위한 최기화)
	for (int i = 0; i < 5; i++) {
		um[arr[i]] += 1;
	}

	/*string str;
	cin >> str;

	cout << um[str];*/

	string str;
	str = "BBQ";

	if (um.count(str) == 0) { // 있는지 없는지 물어보려면 무조건  count
		cout << "없네?"; // 출력 : "없네?"
	}

	if (um[str] == 0) // 물어보기만 해도 ["BBQ"] = {"BBQ",0} 생성
		cout << "없넹?"; // 출력 : 없넹?

	if (um.count(str) == 0) {
		cout << "없네?"; // 출력 안됨 => 위에서 생성이 되었기 때문
	}

	return 0;

}