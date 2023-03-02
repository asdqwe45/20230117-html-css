#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
char leftOper[4];
int nums[20];

int maxi;
int mini;

void dfs(int lev, int result) {

    if (lev == n - 1) {
        maxi = max(maxi, result);
        mini = min(mini, result);
        return;
    }

    char backup[4];
    //backup 에다가 처음 시작 상태 저장
    memcpy(backup, leftOper, 4);

    for (int i = 0; i < 4; i++) {
        if (leftOper[i] == '0') continue;
        leftOper[i]--;
        if (i == 0) dfs(lev + 1, result + nums[lev + 1]);
        if (i == 1) dfs(lev + 1, result - nums[lev + 1]);
        if (i == 2) dfs(lev + 1, result * nums[lev + 1]);
        if (i == 3) dfs(lev + 1, result / nums[lev + 1]);
        leftOper[i]++;
        //memcpy(leftOper, backup, 4);
    }
}

int main() {

    //freopen_s(new FILE*, "input.txt", "r", stdin);

    int tcCnt = 0;
    cin >> tcCnt;

    for (int tc = 1; tc <= tcCnt; tc++) {
        memset(leftOper, 0, 4);
        memset(nums, 0, 20 * 4);
        n = 0;
        maxi = -21e8;
        mini = 21e8;

        cin >> n;
        for (int i = 0; i < 4; i++) cin >> leftOper[i];
        for (int i = 0; i < n; i++) cin >> nums[i];

        dfs(0, nums[0]);

        cout << "#" << tc << " " << maxi - mini << "\n";
        break;
    }

    return 0;
}