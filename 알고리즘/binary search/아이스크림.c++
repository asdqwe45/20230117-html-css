#include <iostream>
#include <algorithm>
using namespace std;

int iceCream[6] = {120, 50, 70, 90, 10, 30};
bool isOkay(int cupSize)
{
  // 해당 cupSize로 3개 이하로 수용가능한가?
  int cnt = 0;
  int sum = 0;
  for (int i = 0; i < 6; i++)
  {
    sum += iceCream[i];
    if (sum > cupSize) // 넘쳐흐름
    {
      cnt++;
      sum = iceCream[i];
    }
  }
  if (sum > 0)
    cnt++; // 잔여물
  return cnt <= 3;
}
int main()
{
  // O(N)
  for (int ml = 120; ml <= 400; ml++)
  {
    if (isOkay(ml))
    {
      cout << ml << "\n";
      break;
    }
  }

  // O(logN)
  int s = 120;
  int e = 400;
  int answer = 1e9;
  while (s <= e)
  {
    int mid = (s + e) / 2;
    if (isOkay(mid))
    {
      answer = min(answer, mid);
      e = mid - 1;
    }
    else
    {
      s = mid + 1;
    }
  }
  cout << answer;
  return 0;
}