#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	//1번 
	
	char str[100] = "string";
	string s = "string";

	// quiz # 1 : 문자열의 길이을 찾아라!
	// 구현
	int Len2 = 0;
	int i = 0;
	while (str[i] != NULL)
	{
		Len2++;
		i++;
	}

	cout << Len2;
	//cstring library
	cout << strlen(str);
	cout << '\n';

	// string class(자료형)
	// string.length() : 길이
	// cout << s.length();
	
	// quiz 2 : 두개의 문자열이 동일하면 1 아니면 0을 출력하는 프로그램
	// char a[100] = "abc";
	// char b[100] = "bcd";
	
	// 두개의 길이가 다르면 둘이 같은 문자열일 수 없다.
	/*if (strlen(a) != strlen(b))
		cout << 0;
	else {
		for (int i = 0; i < strlen(a); i++) {
			if (a[i] != b[i]) {
				cout << 0;
				return 0;
			}
		}
		cout << 1;
	}*/
	cout << '\n';

	// cstring -> strcmp
	// string compare
	// a == b : 0
	// a != b : -1 -> a가 b보다 사전순으로 앞에 온다.
	// a != b : 1 -> a가 b보다 사전순으로 뒤에 온다.

	// if (strcmp(a, b) == 0)
	// 	cout << 1;
	// else
	// 	cout << 0;

	//string class
	string c = "abc";// 97 98   :  아스키코드 숫자로 비교
	string d = "bcd";// 97 97
	cout << '\n';

	if (c < d)
		cout << 1;
	else
		cout << 0;
	cout << '\n';

	// 2번

	// quiz #3. 두개의 문자열을 결합 ->  a에다가 결합
	char e[100] = "str";
	char f[100] = "ing";

	int Len1 = strlen(e);
	int Len2 = strlen(f);

	for (int i = 0; i < Len2; i++)
		e[i+Len1] = f[i];// 비주얼스튜디오에 따라서 마지막 끝까지 널문자가 없을 수도??

	e[Len1 + Len2] = '\0';


	//strcat(e, f);

	// 작업
	cout << e; // <- string
	cout << '\n';
	// cstring
	// strcat -> string concatenate
	// strcat(a,b) => b가 a에 결합
	strcat(e, f);
	cout << e;
	cout << '\n';

	// string class
	// 연사잔 사용 가능 -> 
	// + = 결합      문자열은 + 연산만 가능 ( -,*,/ : 불가 )
	string c = "str";
	string d = "ing";
	c += d;
	cout << c;
	cout << '\n';

	// quiz #4. 복사하는 거
	// char a[100] = "string";
	// char b[100];
	/*int Length = strlen(a);
	for (int i = 0; i <= Length; i++)
		b[i] = a[i];*/

	//cout << b;

	// cstring 
	// strcpy -> string copy
	// strcpy(복사하고자 하는 문자열의 위치, 복사하려고 하는 문자열)
	// strcpy(b, a);
	// cout << b;
	// cout << '\n';

	// string class
	string a2 = "string2";
	string b2;
	b2 = a2;
	cout << b2;
	cout << '\n';

	// quiz #5. 부분을 찾아오는 것
	// 2개의 정수 입력 -> 2 6
	char a3[100] = "string3";
	char b3[100];
	int st, en,idx=0;
	cin >> st >> en;
	for (int i = 0; i <= en - st; i++)
		b3[i] = a3[st + i];
	b3[idx] = '\0';
	/*for (int i = st; i < en; i++)
	{
		b3[idx] = a3[i];
		idx++;
	}
	b3[idx] = '\0';*/
	cout << b3;

	// cstring 
	//  전체 본사 = strcpy
	//  일부분 복사 =>
	//  strncpy(복사를 해서 저장할 위치, 복사를 할 위치, 복사를 할 구간 크기)
	
// 3번
	
	char a4[100]="string";
	char b4[100];
	int st, en;
	cin >> st >> en;
	strncpy(b4, a4 + st, en - st);
	b4[en-st] = '\0';
	cout << b4 << '\n';

	// string class
	// 부분 문자열을 가져와라! substr()
	// substr(시작위치, 구간크기)
	string c = "string";
	string d;
	cin >> st >> en;
	d = c.substr(st, en); // 구간의 크기가 문자열을 넘어서도 문자열까지만 가져온다.
    cout<<	d<<'\n';



	// quiz #6. 문자열에서  특정 substring이 등장하는 위치

	// char a[100] = "string";
	// char b[100];
	// cin >> b;
	// int Len1 = strlen(a);
	// int Len2 = strlen(b);
	// int i, j,flag=0;
	// for (i = 0; i < Len1-Len2; i++) {
	// 	flag = 0;
	// 	for (j = 0; j < Len2; j++)
	// 		if (a[i + j] != b[j]) {
	// 			flag = 1;
	// 			break;
	// 		}
	// 	if (flag == 0)
	// 		break;
	// }
	// cout << i;

	// cstring
	// strst(A,B) ->
    // 찾으려고 하는 문자열이 A에 존재한다면, 처음 찾은 위치를 기준으로
    // 남은 문자열 전체를 반환
    //  cout << strstr(a,b);
    // char a[100] = "string";
    // char b[100];
    // cin >> b;
    // 	if (strstr(a, b) != NULL)
    // 		cout << 1<<'\n';
    // 	cout << strstr(a, b);
    
	
	// string class
    // 부분 문자열을 찾으려고 한다 -> find()
    // str.find(내가 찾으려고 하는 substring) -> substring을 찾은 첫 index를 return
// 1. string::npos return
// 2. -1로 인식해서 해결
string a = "stssst";
string b = "sst";
// 찾을 수 있다면 어떠한 값
int c = a.find(b);
cout << c << '\n';
if (a.find(b) == -1) // string::npos 문자열이 못찾았을 때의 NULL과 같다고 생각하세여.(-1과 같다)
cout << 0;
// 찾을 수 없다면
else
cout << 1;
	// 4. 문자열의 형태 변경








	return 0;
}