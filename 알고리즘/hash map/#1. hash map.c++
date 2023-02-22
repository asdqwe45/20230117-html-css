#include <iostream>
#include <unordered_map>
using namespace std;

// hash map
// C++에서 쓸수있는 map의 종류는 두개가 있다. 
// #1. unordered_map // <-얘를 쓰세요 (정렬되지 않은 맵)
// -> hash-table 구조를 이용
// -> 만들고, 삭제, 탐색 O(1)~O(logN)
// string의 데이터를 전부 변환 

// #2. map <-- 정렬된 맵 
// -> red-black tree 
// -> 새로 만들고, 삭제, 탐색 -> O(logN)
// 비교적으로 양이 많은 경우 불리하다
// string을 key로 쓸때

int main() {
    // MAP = 고유의 키 값을 가진다.
    // 이미 존재하는게 있다면 -> 덮어씌워지는게 아니라
    // 무시하게 됩니다. 
    int arr[] = { 1, 200000000, 200000000, 1, 5 };
    // MAP 생성
    // unordered_map<key type, value type>
    unordered_map<int, int>um; 

    /*
    for (int i = 0; i < 5; i++) {
        um.insert({ arr[i], i});
    }
    
    cout << um[200000000];
    */

    for (int i = 0; i < 5; i++) {
        // 만약 이미 MAP에 키가 등록되어있다면
        // 해당 키값에 연결된 value + 1
        // find(값) -> 없으면 um.end()
        if (um.find(arr[i]) != um.end()) {
            um[arr[i]]++; 
        }
        // 만약 key가 없다면 
        // 새로 찾은 숫자 = value = 1 
        else {
            // inset(key, value); 
            um.insert({ arr[i], 1 });
        }
    }
    // 1. 뭐가 출력될까?
    // 2. map에 존재할까? 
    // um[key] -> key가 생성 됩니다. 
    // cout << um[3]; 
    
    // 기존에 3이라는 key가 없어도 만들어진다. 
    um[3] = 1; 
    int de = 1;
    cout << um[3] << '\n';

    // traversal / iteration 
    // 시간이 꽤 걸립니다
    for (auto it = um.begin(); it != um.end(); it++) {
        cout << it->first << " " << it->second << '\n';
    }
}