#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
/*
 1. Handling input
 2. bfs
*/
#define coord pair<int, int>
int T, M, N, K;
vector<int> results;
int G[50][50];
int move_x[4] = {1, -1, 0, 0};
int move_y[4] = {0, 0, 1, -1};

void bfs(coord start) {
  queue<coord> q;
  q.push(start);

  coord curr;
  while (!q.empty()) {
    curr = q.front();
    q.pop();
    G[curr.second][curr.first] = 0;

    int next_x, next_y;
    for (int i = 0; i < 4; i++) {
      next_x = curr.first + move_x[i];
      next_y = curr.second + move_y[i];
      if (next_x >= 0 && next_x < M && next_y >= 0 && next_y < N &&
          G[next_y][next_x]) {
        q.push(make_pair(next_x, next_y));
        G[next_y][next_x] = 0;
      }
    }
  }
}

int calNumWorm() {
  int num_worm = 0;
  bool is_completed = false;
  bool is_found;
  while (!is_completed) {
    is_found = false;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (G[i][j]) {
          bfs(make_pair(j, i));
          is_found = true;
          break;
        }
      }
      if (is_found) break;
    }
    if (!is_found) break;
    num_worm++;
  }
  return num_worm;
}

void initG() {
  for (int i = 0; i < 50; i++)
    for (int j = 0; j < 50; j++) G[i][j] = 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> M >> N >> K;
    int x, y;
    for (int i = 0; i < K; i++) {
      cin >> x >> y;
      G[y][x] = 1;
    }
    int result = calNumWorm();
    results.push_back(result);
    initG();
  }

  for (const auto& ret : results) {
    cout << ret << "\n";
  }
}
