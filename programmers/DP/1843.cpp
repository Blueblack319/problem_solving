#include <cstring>
#include <string>
#include <vector>
using namespace std;
int dp[101][101][2], inf = 9e8;
vector<string> arr;
int sol(int l, int r, int k) {
  int result = dp[l][r][k];
  if (result != -1) return result;
  if (k) {
    result = -inf;
    for (int i = l; i <= r; i++) {
      int lval, rval;
      lval = l > i - 1 ? stoi(arr[2 * l]) : sol(l, i - 1, 1);
      if (r < i + 1)
        rval = stoi(arr[2 * r + 2]);
      else if (arr[2 * i + 1].compare("+") == 0)
        rval = sol(i + 1, r, 1);
      else
        rval = sol(i + 1, r, 0);
      if (arr[2 * i + 1].compare("+") == 0)
        result = max(result, lval + rval);
      else
        result = max(result, lval - rval);
    }
  } else {
    result = inf;
    for (int i = l; i <= r; i++) {
      int lval, rval;
      lval = l > i - 1 ? stoi(arr[2 * l]) : sol(l, i - 1, 0);
      if (r < i + 1)
        rval = stoi(arr[2 * i + 2]);
      else if (arr[2 * i + 1].compare("+") == 0)
        rval = sol(i + 1, r, 0);
      else
        rval = sol(i + 1, r, 1);
      if (arr[2 * i + 1].compare("+") == 0)
        result = min(result, lval + rval);
      else
        result = min(result, lval - rval);
    }
  }
  dp[l][r][k] = result;
  return result;
}

int solution(vector<string> _arr) {
  memset(dp, -1, sizeof(dp));
  arr = _arr;
  return sol(0, arr.size() / 2 - 1, 1);
}