#include <algorithm>
#include <iostream>

using namespace std;
/*
Determine if the number is han
1. arr[4]
2.
*/
int N, cnt = 0;

bool determineHan(int num) {
  int arr[4] = {0};
  int len = 0, temp, diff;

  while (num != 0) {
    temp = num % 10;
    arr[len] = temp;
    len += 1;
    num /= 10;
  }

  diff = arr[1] - arr[0];

  for (int i = 1; i < len - 1; i++) {
    if (diff != arr[i + 1] - arr[i]) {
      return false;
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;

  for (int i = 1; i <= N; i++)
    if (determineHan(i)) cnt++;
  cout << cnt;
}
