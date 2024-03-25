#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define MIN_POINT -30000
using namespace std;

int solution(vector<vector<int>> routes) {
  int answer = 0;

  // Greedy
  // Sort by the first point
  sort(routes.begin(), routes.end(),
       [](const vector<int> a, const vector<int> b) -> bool {
         if (a[0] == b[0])
           return a[1] > b[1];
         else
           return a[0] < b[0];
       });
  int current_end = routes[0][1];
  answer++;
  for (const auto &route : routes) {
    if (route[0] > current_end) {
      answer++;
      current_end = route[1];
      continue;
    }
    if (route[1] < current_end) {
      current_end = route[1];
    }
  }

  return answer;
}