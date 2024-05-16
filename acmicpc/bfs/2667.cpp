#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
#define coord pair<int, int>
/*
 1. Handling inputs
 2. Declare variables for bfs
 3. bfs
*/
int N;
int map[25][25];
vector<int> complex;
int move_x[4] = {1, -1, 0, 0};
int move_y[4] = {0, 0, 1, -1};

int bfs(int row, int col) {
  int result = 0;
  queue<coord> q;
  q.push(make_pair(row, col));
  coord curr;
  while (!q.empty()) {
    curr = q.front();
    q.pop();
    result++;
    map[curr.first][curr.second] = 0;

    int next_x, next_y;
    for (int i = 0; i < 4; i++) {
      next_y = curr.first + move_y[i];
      next_x = curr.second + move_x[i];
      if (next_x >= 0 && next_x < 25 && next_y >= 0 && next_y < 25 &&
          map[next_y][next_x]) {
        q.push(make_pair(next_y, next_x));
        map[next_y][next_x] = 0;
      }
    }
  }
  return result;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  string line;
  for (int i = 0; i < N; i++) {
    cin >> line;
    for (int j = 0; j < line.length(); j++) {
      map[i][j] = line[j] - '0';
    }
  }

  bool is_completed = false;
  bool is_found = false;
  while (!is_completed) {
    is_found = false;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (map[i][j]) {
          int ret = bfs(i, j);
          complex.push_back(ret);
          is_found = true;
          break;
        }
      }
      if (is_found) break;
    }
    if (!is_found) is_completed = true;
  }
  sort(complex.begin(), complex.end());
  cout << complex.size() << "\n";
  for (const auto &ret : complex) cout << ret << "\n";
}
