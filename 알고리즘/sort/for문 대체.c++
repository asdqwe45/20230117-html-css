#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;





int main()
{
	vector<int> arr = { 5,3,1,6,8,9,2,4,10,7 };
	// 작은값부터 순서대로 출력하기

	sort(arr.begin(), arr.end());  //  [ begin, end )  begin : 포함    end : 미포함

	// value에 arr값을 복사해서 사용하기 때문에 value만 바뀌는 것이지 arr에는 영향 X
	// 복사비용이 발생
	// 참조연산자 & 사용하면 해결... 하지만 arr원본배열에 영향이 간다.
	// const 사용 시 값 변화 X
	for (const int& value : arr) 
	{
		cout << value << ' ';
		//value = 3;
	}

	cout << endl;
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i]<<' ';

	return 9;

}