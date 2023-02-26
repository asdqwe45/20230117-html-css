#include <iostream>
#include <queue>
using namespace std;

// sort와 비교
// sort( first, last, cmp) default cmp : <
// --> 작은거부터 나온다
// left < right --> 작은거 우선순위 가짐

// pq
// priority_queue< ty, container, cmp> default cmp : <
// --> 큰 거부터 나온다.
// left < right --> 큰거 우선순위 가짐

struct Student {
	string name;
	int age;
	int grade;
};
struct cmp {
	// PQ -> < 쓰면 : MAX heap
	// sort 때와 동일한 생각을 기준을 잡느다?
	// 올바른 상황( 즉, 내가 원하는 상황) ==> false

	bool operator()(int left, int right) {
		// return left > right;

		if (left > right)
			return true;
		else 
			return false;

	}
};

struct ssafycmp {
	bool operator()(Student left, Student right) 
	{
	// 1. 시험 점수 높은 사람 중,
	if (left.grade > right.grade)
		return true;
	if(left.grade<right.grade)
		return false;
	// 2. 나이가 많은 사람, 
	if (left.age > right.age)
		return true;
	if (left.age < right.age)
		return false;
	// 3. 이름이 사전순으로 빠른 사람
	if (left.name < right.name)
		return true;
	if (left.name > right.name)
		return false;
	return false;
	}
};

bool qcmp(int left, int right)
{
	// 정렬: 짝수 우선, 홀수 나중, 짝수는 내림차순, 홀수는 오름차순

	if (left % 2 == 0 && right % 2 == 1)
		return true;
	if(left%2==1&&right%2==0)
		return false;

	if (left % 2 == 0 && right % 2 == 0 && left > right)
		return true;
	if (left % 2 == 0 && right % 2 == 0 && left < right)
		return false;
	if (left % 2 == 1 && right % 2 == 1 && left < right)
		return false;
	if (left % 2 == 1 && right % 2 == 1 && left < right)
		return true;
	return false;
}
int main()
{
	int arr[] = { 1,4,5,3,2 };

	// #1 default : MAX heap
	
	// 삽입 : push()
	// 삭제 : pop()
	// 맨 위 (우선순위가 가장 높은 값) return : q.top()
	// 비어있는가? q.empty()

	priority_queue<int>pq;

	for (int i = 0; i < 5; i++)
		pq.push(arr[i]);

	while (!pq.empty()) {
		cout << pq.top();
		pq.pop();
	}

	// #2 MIN heap

	// priority_queue< typename, conatiner, less>
	// typename : 자료형
	// container : vector
	// _Pr : less --> '<'
	// less : Compare cmp X --> 함수 구조체를 넣어야 됨
	// 함수를 넣어주면 안되고, 구조체 함수를 만들어서 넣어야 한다.
	// priority_queue<int, vector<int>, less<int>>


	/*priority_queue<int, vector<int>, cmp>pq;

	for (int i = 0; i < 5; i++)
		pq.push(arr[i]);

	while (!pq.empty()) {
		cout << pq.top();
		pq.pop();
	}*/


	// #3 사용자 정의 sort

	priority_queue<Student>pq;



	//	// 시험 점수 높은 사람 중, 나이가 많은 사람, 이름이 사전순으로 빠른 사람

	//pq.push({ "송유빈", 3, 100 });
	//pq.push({ "박준형",4,100 });
	//pq.push({ "김택우",2,100 });
	//pq.push({ "김기덕",4,100 });
	//pq.push({ "이득화",7,25 });

	//while (!pq.empty()) {
	//	cout << pq.top();
	//	pq.pop();
	//}

	// sort와 priority queue 언제 쓰는가?
	// sort : 0(NlogN)
	// PQ : 삽입과 추출 0(logN)

	// 예시 - N개의 정수를 입력 받고 가장 큰 수를 출력하라
	// sort : 입력받고 -> 정렬 -> arr[N-1] == 0(NlogN)
	// PQ : 입력받으면서 PQ 삽입(logN) -> heapify -> pq.top() // peek

	// 예시 2 - N개의 Query
	// 1 -> 삽입
	// 2 -> 현재 가장 큰값 삭제
	// 0 -> 현재 가장 큰 값을 출력
	// sort : Q * (NlogN)
	// PQ : Q * (logN)

	// sort : 딱 한번의 정렬로 해결이 가능할 때
	// --> binary search, greedy

	// PQ : 계속해서 새로운 값이 삽입 추출될 때, 즉 변환가 있을 때



	// Quiz
	// 정렬: 짝수 우선, 홀수 나중, 짝수는 내림차순, 홀수는 오름차순

	int arr2[] = { 1,3,4,5,2 };

	sort(arr2, arr2 + 5, qcmp);

	for (int i = 0; i < 5; i++)
		cout << arr2[i] << ' ';


	return 0;
}