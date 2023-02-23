#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int price[4];
int plan[13];
int mini;

int getCost(int month, int type) {
    if (type == 0) return plan[month] * price[0];
    if (type == 1) return price[1];
    if (type == 2) return price[2];
    return -1;
}

int getNextMonth(int month, int type) {
    if (type == 2) return month + 3;
    return month + 1;
}

void dfs(int month, int sum) {
    if (month >= 12 + 1) {
        mini = min(mini, sum);
        return;
    }

    for (int type = 0; type < 3; type++) {
        int cost = getCost(month, type);
        int nextMonth = getNextMonth(month, type);
        dfs(nextMonth, sum + cost);
    }
}

int main() {

    //freopen_s(new FILE*, "input.txt", "r", stdin);

    int tcCnt;
    cin >> tcCnt;

    for (int tc = 1; tc <= tcCnt; tc++) {
        memset(price, 0, 4 * sizeof(int));
        memset(plan, 0, 13 * sizeof(int));
        mini = 21e8;

        for (int i = 0; i < 4; i++) cin >> price[i];
        for (int i = 1; i <= 12; i++) cin >> plan[i];

        dfs(1, 0);
        mini = min(mini, price[3]);

        cout << "#" << tc << " " << mini << '\n';
    }

    return 0;
}