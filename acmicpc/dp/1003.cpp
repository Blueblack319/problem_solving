#include <algorithm>
#include <iostream>

using namespace std;
/*
dp[i] = dp[i - 1] + dp[i - 2]
*/
#define MAX_N 41

int dp[MAX_N][2];
int T, n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> T;

  dp[0][0] = 1;
  dp[0][1] = 0;

  dp[1][0] = 0;
  dp[1][1] = 1;

  for (int i = 2; i < MAX_N; i++) {
    dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
    dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
  }

  for (int i = 0; i < T; i++) {
    cin >> n;
    cout << dp[n][0] << " " << dp[n][1] << "\n";
  }
}
