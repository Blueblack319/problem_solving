#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
// Create a 2d array
/*
For each row

*/
int main() {
  int N, M;
  cin >> N >> M;

  int arr[50][50];
  string input;
  int ans = 0;
  int cur, distance, result;

  for (int i = 0; i < N; i++) {
    cin >> input;
    for (int j = 0; j < M; j++) {
      arr[i][j] = input[j] - '0';
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cur = arr[i][j];
      for (int k = j + 1; k < M; k++) {
        distance = k - j;
        if (i + distance >= N) break;
        if (cur == arr[i][k] && cur == arr[i + distance][j] &&
            cur == arr[i + distance][k])
          ans = max(ans, distance);
      }
    }
  }
  result = (ans + 1) * (ans + 1);
  cout << result;

  return 0;
}