#include <algorithm>
#include <iostream>

/*
1. Create an array to store the result
2. Generate a non-self number by using each number lower than 10000
*/
using namespace std;
bool result[10001];
int num;

int genNum(int num) {
  int temp = num;
  while (num != 0) {
    temp += num % 10;
    num /= 10;
  }
  return temp;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  for (int i = 1; i < 10001; i++) {
    result[i] = true;
  }

  for (int i = 1; i < 10001; i++) {
    num = genNum(i);
    if (num <= 10000) result[num] = false;
  }

  for (int i = 1; i <= 10000; i++) {
    // cout << result[i];
    if (result[i]) cout << i << "\n";
  }
}
