#include <string>
#include <vector>

#define MAX_N 101
using namespace std;
// DP - Tabulation: Bottom-up
int DP[MAX_N][MAX_N] = {0};

int solution(int m, int n, vector<vector<int>> puddles) {
  int answer = 0;
  for (const auto &puds : puddles) DP[puds[1]][puds[0]] = -1;

  DP[1][1] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (DP[i][j] == -1) continue;
      int a = DP[i][j - 1] == -1 ? 0 : DP[i][j - 1];
      int b = DP[i - 1][j] == -1 ? 0 : DP[i - 1][j];
      DP[i][j] += (a + b) % 1000000007;
    }
  }
  answer = DP[n][m];
  return answer;
}