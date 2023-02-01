#include <iostream>
using namespace std;

int arr[5][5] = {
    0,0,1,0,1,
    1,0,0,0,0,
    0,0,0,1,1,
    0,0,0,0,1,
    0,0,0,0,0,
};
int age[5] = { 8, 9, 15, 4, 22 };

int main() {

    int maxi = 0;
    int maxIndex = 0;
    for (int x = 0; x < 5; x++) {
        int cnt = 0;
        for (int y = 0; y < 5; y++) {
            cnt += arr[y][x];
        }
        if (maxi < cnt) {
            maxi = cnt;
            maxIndex = x;
        }
    }
    cout << age[maxIndex];


    return 0;
}