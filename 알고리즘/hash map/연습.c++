#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;


map<int, string>kkk;
unordered_map<int, string>ggg;

string ccc[200];

int main()
{
	ccc[100] = "DJS";
	//1. index에 음수 사용 불가
	//2. index에 아주 큰 수 사용 불가
	//3. index에 문자열 사용 불가

	kkk[100] = "HUHUHU";

	ggg[100] = "HAHAHA";



	return 0;

}