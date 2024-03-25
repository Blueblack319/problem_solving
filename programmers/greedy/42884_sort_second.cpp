#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define MIN_POINT -30001
using namespace std;

int solution(vector<vector<int>> routes) {
  int answer = 0;

  // Greedy
  // Sort by the second point
  sort(routes.begin(), routes.end(),
       [](const vector<int> a, const vector<int> b) -> bool {
         return a[1] < b[1];
       });
  int current_end = routes[0][1];
  answer++;
  for (const auto &route : routes) {
    if (route[0] > current_end) {
      answer++;
      current_end = route[1];
    }
  }

  return answer;
}