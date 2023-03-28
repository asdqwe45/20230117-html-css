#include <iostream>

using namespace std;

// 0 : top , 1 : bottom , 2 : front , 3 : left , 4 : back , 5 : right
string cube[6][3];
string color[6] = { "www","yyy","rrr","ggg","ooo","bbb" };
struct Node {
	int y, x;
};
Node outside[8] = { 0,0,0,1,0,2,1,2,2,2,2,1,2,0,1,0 };


void cubeTurn(char position, char direction) {
	if (position == 'U') {
		if (direction == '-') {
			for (int j = 0; j < 2; j++)
				for (int i = 0; i < 7; i++)
					swap(cube[0][outside[i].y][outside[i].x], cube[0][outside[i + 1].y][outside[i + 1].x]);
			string temp;
			temp = cube[2][0];
			for (int i = 2; i <= 4; i++)
				cube[i][0] = cube[i + 1][0];
			cube[5][0] = temp;
		}
		else {
			for (int j = 0; j < 2; j++)
				for (int i = 7; i >0; i--)
					swap(cube[0][outside[i].y][outside[i].x], cube[0][outside[i -1].y][outside[i -1].x]);
			string temp;
			temp = cube[5][0];
			for (int i = 5; i >=3; i--)
				cube[i][0] = cube[i -1][0];
			cube[2][0] = temp;
		}
	}
	else if (position == 'F') {
		if (direction == '-') {
			for (int j = 0; j < 2; j++)
				for (int i = 0; i < 7; i++)
					swap(cube[2][outside[i].y][outside[i].x], cube[2][outside[i + 1].y][outside[i + 1].x]);
			string leftTemp="";
			string rightTemp="";
			for (int i = 0; i < 3; i++) {
				leftTemp += cube[3][i][2];
				rightTemp += cube[5][i][0];
			}
			string temp = cube[0][2];
			cube[0][2] = rightTemp;
			for (int i = 0; i < 3; i++)
				cube[5][i][0] = cube[1][0][2-i];
			cube[1][0] = leftTemp;
			for (int i = 0; i < 3; i++)
				cube[3][i][2] = temp[2 - i];
		}
		else {
			for (int j = 0; j < 2; j++)
				for (int i = 7; i > 0; i--)
					swap(cube[2][outside[i].y][outside[i].x], cube[2][outside[i - 1].y][outside[i - 1].x]);
			
		}
	}
	else if (position == 'L') {
		if (direction == '-') {

		}
		else {

		}
	}
	else if (position == 'R') {
		if (direction == '-') {

		}
		else {

		}
	}
	else if (position == 'B') {
		if (direction == '-') {

		}
		else {

		}
	}
	else if (position == 'D') {
		if (direction == '-') {

		}
		else {

		}
	}
}

int main()
{
	int T; cin >> T;
	for (int t = 0; t < T; t++) {
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 3; j++) {
				cube[i][j] = color[i];
			}
		}
		cube[0][0] = "123";
		cube[0][1] = "456";
		cube[0][2] = "789";
		int a; cin >> a;
		for (int i = 0; i < a; i++) {
			char ch[3];
			cin >> ch;
			cubeTurn(ch[0], ch[1]);
		}
		for (int i = 0; i < 3; i++)
			cout << cube[2][i];
	}

	int d = 1;

	return 0;
}

// top => back빼고 cube[0] 옮기기
// front => top : cube[2] , left : cube[i][2] , right : cube[i][0] , bottom : cube[0]
// bottom => top빼고 cube[2] 옮기기