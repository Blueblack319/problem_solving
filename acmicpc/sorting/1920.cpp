#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M, n;
vector<int> numbers;

// set<int> numbers;
// int main() {
//   ios::sync_with_stdio(false);
//   cin.tie(0);

//   cin >> N;
//   for (int i = 0; i < N; i++) {
//     cin >> n;
//     numbers.insert(n);
//   }
//   cin >> M;
//   for (int i = 0; i < M; i++) {
//     cin >> n;
//     if (numbers.find(n) != numbers.end())
//       cout << 1;
//     else
//       cout << 0;
//     cout << "\n";
//   }
// }
bool binary_search(int num, int lower, int upper) {
  int mid = (upper + lower) / 2;
  //   cout << lower << ", " << upper << "\n";
  if (num == numbers[mid]) return true;
  if (lower >= upper) return false;
  //   if (lower == 3) return false;

  if (num < numbers[mid]) {
    return binary_search(num, lower, mid - 1);
  } else {
    return binary_search(num, mid + 1, upper);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  numbers.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> n;
    numbers[i] = n;
  }
  sort(numbers.begin(), numbers.end());

  cin >> M;
  for (int i = 0; i < M; i++) {
    cin >> n;
    if (binary_search(n, 0, N - 1)) {
      cout << 1;
    } else
      cout << 0;
    cout << "\n";
  }
}