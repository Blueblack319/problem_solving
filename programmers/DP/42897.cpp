#include <cmath>
#include <iostream>
#include <string>
#include <vector>

#define INF 1000001
#define MAX_MONEY 1000

using namespace std;
// DP - Tabulation, bottom-up

int dp[INF] = {-1};
int dp2[INF] = {-1};

int solution(vector<int> money) {
  int answer = 0;
  int N = money.size() - 1;

  dp[0] = money[0];
  dp[1] = max(money[0], money[1]);
  dp2[0] = 0;
  dp2[1] = money[1];
  dp2[2] = max(money[1], money[2]);

  for (int i = 2; i < N; i++) dp[i] = max(dp[i - 2] + money[i], dp[i - 1]);
  for (int i = 3; i <= N; i++) dp2[i] = max(dp2[i - 2] + money[i], dp2[i - 1]);

  // for(int i = 0; i < N; i++)
  //     cout << dp[i] << ", ";
  // cout << "\n";
  // for(int i = 0; i <= N; i++)
  //     cout << dp2[i] << ", ";
  // cout << "\n";

  return max(dp[N - 1], dp2[N]);
}