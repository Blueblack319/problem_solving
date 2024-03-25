#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// DP
// Tabulization: Bottom-up

int solution(int N, int number) {
  int answer = -1;
  // DP[i]: the numbers which can be calculated by using i number of N
  unordered_set<int> DP[9];

  int n = 0;
  for (int i = 1; i < 9; i++) {
    n = n * 10 + N;
    DP[i].insert(n);
  }

  for (int i = 1; i < 9; i++) {
    for (int j = 1; j < i; j++) {
      for (const int a : DP[j]) {
        for (const int b : DP[i - j]) {
          DP[i].insert(a + b);
          DP[i].insert(a - b);
          DP[i].insert(a * b);
          if (b > 0) {
            DP[i].insert(a / b);
          }
        }
      }
    }
  }

  for (int i = 1; i < 9; i++) {
    if (DP[i].find(number) == DP[i].end()) continue;
    answer = i;
    break;
  }

  return answer;
}