#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

// SWEA 보물 상자 비밀번호
/*
2
12 10
1B3B3B81F75E
16 2
F53586D76286B2D8
*/

int N; // 총 문자의 개수 (길이)
int K; // K번째 큰 숫자
string s; 

bool cmp(long long left, long long right) {
    if (left > right)
        return true;
    if (left < right)
        return false;
    return false; 
}

long long hextodec(string s) {
    // 16진수를 10진수로 만들어야 합니다. 
    long long res = 0;
    for (int i = 0; i < s.length(); i++) {
        char now = s[i];
        int temp = 0; 
        // 0~9 
        if (now >= '0' && now <= '9')
            temp = now - '0';
        // 알파벳 대문자 A~f
        else
            temp = now - 55; 
        res = res * 16 + temp; 
    }
    return res; 
}

int main() {

    //freopen("input.txt", "r", stdin);

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // reset 
        unordered_map<long long, int>um; 
        vector<long long>v; 

        // input 
        cin >> N >> K; 
        cin >> s; 

        // 원형으로 돌수 있도록 s 뒤에 s를 추가
        s += s; 

        // solve -> sliding window로 구현
        // SW : two pointer의 일종 
        // #1. 포인터 세팅 
        int start = 0; // 시작 포인터
        int end = N/4 - 1; // 구간 크기 포인터
        // #2. 공통 구간 세팅
        string temp = "";
        for (int i = start; i < end; i++) 
            temp += s[i]; 
        
        // #3. sliding window 수행
        // s의 길이가 2배로 늘어났으니까
        // while(end < N*2) 
        while (end < N + N/4 - 1) {
            // #1. 구간 완성 -> end가 가리키는 값을 더한다 
            temp += s[end];

            // #2. 수행 
            // -> 완성된 구간 = 16진수 
            // -> 10진수로 만들고 
            long long num = hextodec(temp); 
            // -> 이 10진수가 중복이 아니라면 -> 후보로 등록
            // 2억 넘게 가니까 -> DAT 배열로 처리 못한다. 

            //cout << temp << " " << num <<'\n';

            if (um.find(num) == um.end()) {
                // 이 10진수를 찾았다! 기록
                um[num] = 1; 
                // 후보로 등록 
                v.push_back(num); 
            }

            // #3. 다음 공통 구간 완성 
            // "1B3" -> "B3" 
            //string newstr = "";
            //for (int i = 1; i < temp.length(); i++)
            //    newstr += temp[i]; 
            //temp = newstr; 
            temp = temp.substr(1, temp.length()); 

            // #4. 포인터 이동 
            start++;
            end++; 
        }

        // 후보들이 들어가있는 vector를 정렬
        // 큰거부터 나열했을때 K번째
        // 큰거 우선으로 정렬
        sort(v.begin(), v.end(), cmp); 

        // output
        cout << "#" << tc << " " << v[K - 1] << '\n';
    }
}