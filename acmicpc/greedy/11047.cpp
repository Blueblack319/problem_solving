#include <algorithm>
#include <iostream>

using namespace std;
/*
1. Store types of coin
2. Execute divide and modular to the K recursively
*/
int N, K, A[10], result = 0;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> K;

  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for (int i = N - 1; i >= 0; i--) {
    result += K / A[i];
    K %= A[i];
  }
  cout << result;
}
