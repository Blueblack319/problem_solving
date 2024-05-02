#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
// Backtracking
// Find all solutions meeting the conditions
// Traverse the state space tree by using DFS and a recursive function
vector<int> people;
vector<int> real;
int max_height;
int target_height;
int people_size;

void backtracking(int depth, int current_height) {
  if (depth > people_size || current_height < target_height) {
    return;
  }
  if (real.size() == 7 && current_height == target_height) {
    sort(real.begin(), real.end());
    for (const auto &r : real) cout << r << "\n";
    exit(0);
    return;
  }
  const int h_curr = people[depth];
  real.push_back(h_curr);
  backtracking(depth + 1, current_height - h_curr);

  real.pop_back();
  backtracking(depth + 1, current_height);
}

int main() {
  int c;
  for (size_t i = 0; i < 9; i++) {
    cin >> c;
    people.push_back(c);
  }

  people_size = people.size();
  max_height = accumulate(people.begin(), people.end(), 0);
  target_height = max_height - 100;

  backtracking(0, max_height);
  return 0;
}
