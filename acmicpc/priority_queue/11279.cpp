#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  priority_queue<int> pq;
  int N, input, max;
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> input;
    if (input == 0) {
      if (pq.empty()) {
        cout << 0 << "\n";
      } else {
        max = pq.top();
        pq.pop();
        cout << max << "\n";
      }
    } else {
      pq.push(input);
    }
  }
}
