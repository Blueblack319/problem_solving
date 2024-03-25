#include <iostream>
#include <string>
#include <vector>

using namespace std;
// DP, Tabluation: Bottom-up

int solution(vector<vector<int>> triangle) {
  int answer = 0;
  int N = triangle.size();

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < triangle[i].size(); j++) {
      int a = 0, b = 0;
      if (i - 1 >= 0) {
        if (j - 1 >= 0) a = triangle[i - 1][j - 1];
        if (j < triangle[i - 1].size()) b = triangle[i - 1][j];
      }
      int cur = triangle[i][j];
      triangle[i][j] = max(a + cur, b + cur);
    }
  }
  for (int i = 0; i < N; i++) {
    answer = max(answer, triangle[N - 1][i]);
  }

  return answer;
}