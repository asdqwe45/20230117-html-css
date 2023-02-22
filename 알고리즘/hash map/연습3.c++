#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

unordered_map<string, string> d1, d2;

int main()
{    
    d1["jodan"] = 63;
    d2["63"] = "jodan";

    d1["park"] = "11";
    d2["11"] = "park";

    string str;
    cin >> str;

    if (d1.count(str) > 0) cout << d1[str];
    if (d2.count(str) > 0) cout << d2[str];


    return 0;
}