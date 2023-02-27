#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int block[4][4] = {
    5,
    0,
    1,
    4,
    0,
    0,
    0,
    1,
    1,
    0,
    9,
    0,
    0,
    0,
    0,
    1,
};

int reuslt[4][4] = {
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    4,
    5,
    0,
    1,
    1,
    1,
    0,
    9,
    1,
};

void downdown(int index)
{
  vector<int> arr;
  for (int y = 3; y >= 0; y--)
  {
    int tar = block[y][index];
    if (tar == 0)
      continue;
    arr.push_back(tar);
  }

  // 삭제
  for (int y = 3; y >= 0; y--)
  {
    block[y][index] = 0;
  }

  // 깔끔하게 밑에서부터 적기
  for (int i = 0; i < arr.size(); i++)
  {
    block[3 - i][index] = arr[i];
  }
}

int main()
{

  downdown(0);
  downdown(1);
  downdown(2);
  downdown(3);

  return 0;
}