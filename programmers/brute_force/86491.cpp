#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
  int answer = 0;
  int temp;
  priority_queue<int> max_widths;
  priority_queue<int> max_heights;
  int max_width;
  int max_height;

  for (auto &size : sizes) {
    if (size[0] < size[1]) {
      temp = size[0];
      size[0] = size[1];
      size[1] = temp;
    }
  }

  for (const auto &size : sizes) {
    // cout << "[" << size[0] << ", " << size[1] << "]\n";
    max_widths.push(size[0]);
    max_heights.push(size[1]);
  }

  max_width = max_widths.top();
  max_height = max_heights.top();

  return max_width * max_height;
}