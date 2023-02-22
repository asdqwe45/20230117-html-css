#include <iostream>

using namespace std;

// 비트 연산
// Bit = 가장 작은 데이터 단위
// tb gb mb kb byte -> bit
// 1byte = 8bit
// 2진수로 표현 0과 1로 구성

// 비트연산자
// A & B (AND) : A와 B가 모두 1이면 아니면 0
// A | B (OR)  : A와 B 중 하나만 1이여도 1
// A ^ B (XOR) : 둘이 다르면 1 같은면 0
// A ~ B (NOT) : 0이면 1, 1이면 0 (*Complement) 
// << N (left shift) : 모든 비트를 N칸 왼쪽으로 이동
// >> N (right shift) : 모든 비트를 N칸 오른쪽으로 이동


int main()
{
	int A = 3; // 0011
	int B = 5; // 0101

	// &
	// 0011
	// 0101
	// 0001
	// => 1
	int C = A & B;
	cout << C << '\n';

	// |
	// 0011
	// 0101
	// 0111
	// =>7
	int D = A | B;
	cout << D << '\n';

	//^
	// 0011
	// 0101
	// 0110
	// => 6
	int E = A ^ B;
	cout << E << '\n';

	int original = 35;
	int a = 123456789;
	int b = 987654321;
	int c = original ^a^ b ^ b ^ a; // 답:35 => a와 a가 상쇄되고 b와 b가 상쇄된다.
	cout << c<<'\n';

	// ~
	//   0011  0101
	//=> 1100  1010
	int F = ~B;
	cout << F << '\n';

	// shift
	//    0011
	// => 0001
	int G = A >> 1;
	cout << G << '\n';

	int H = A << 2;
	cout << H << '\n';

	// 비트 연산 언제 쓰는데?
	// #1. 문제가 노골적인 비트연산 문제이다.
	// #2. (비트 관련문제) 비트마스킹 (bit masking)
	
	
	// Bit masking #1 
	// 특정 비트를 바꾸는 방법
	// B = 5 => 0101
	// 문제 : 특정비트를 1로 바꾸고 싶다.
	// N=1 => 0111
	int N = 1;
	int res = B | (1 << N);
	cout << res << '\n';

	int M = 1;
	res = B ^ (1 << M);
	cout << res << '\n';

	//Bit masking #2
	// 특정 bit를 삭제
	// B = 5 => 0101
	// N = 0 => 0100

	M = 2;
	res = B & ~(1 << M);
	cout << res << '\n';


	return 0;
}