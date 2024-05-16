#include <algorithm>
#include <iostream>

using namespace std;
/*
 1. Handling input: Store A and B
 2. Sort the A in the ascending order and B in the descending order
*/
int N, a, b;
int A[50], B[50];
int result = 0;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < N; i++) cin >> B[i];

  sort(A, A + N);
  sort(B, B + N, greater<int>());

  for (int i = 0; i < N; i++) {
    result += A[i] * B[i];
  }
  cout << result << "\n";
}
