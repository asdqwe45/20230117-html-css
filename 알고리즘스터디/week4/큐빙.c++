#include <iostream>

using namespace std;

// 0 : top , 1 : bottom , 2 : front , 3 : back , 4 : left , 5 : right
string cube[6][3];
string color[6] = { "www","yyy","rrr","ooo","ggg","bbb" };
int main()
{
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			cube[i][j] = color[i];
		}
	}

	int d = 1;

	return 0;
}

// top => back빼고 cube[0] 옮기기
// front => top : cube[2] , left : cube[i][2] , right : cube[i][0] , bottom : cube[0]
// bottom => top빼고 cube[2] 옮기기