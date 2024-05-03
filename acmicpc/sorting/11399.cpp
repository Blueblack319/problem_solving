#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
/*
1. Create a vector 'durations'
2. Sorting in ascending order
3. Accumulating using acc variable
*/
int N, dur, result, acc = 0;
int durations[1000] = {0};
int results[1000] = {0};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> dur;
    durations[i] = dur;
  }

  sort(durations, durations + N);

  for (int i = 0; i < N; i++) {
    acc += durations[i];
    result += acc;
  }
  cout << result;
}
