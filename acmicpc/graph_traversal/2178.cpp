#include <algorithm>
#include <iostream>
#include <queue>
/*
 1. Handle inputs
 2. BFs
  - Queue contains (x, y, depth)
*/
#define ppii pair<pair<int, int>, int>

using namespace std;

int N, M;
int maze[100][100];
bool visited[100][100];
int move_x[4] = {0, 0, -1, 1};
int move_y[4] = {1, -1, 0, 0};

int bfs() {
  int result = 0;
  queue<ppii> q;
  q.push(make_pair(make_pair(0, 0), 1));
  visited[0][0] = true;

  int curr_x, curr_y, next_x, next_y;
  while (!q.empty()) {
    ppii curr = q.front();
    q.pop();
    curr_x = curr.first.first;
    curr_y = curr.first.second;
    if (curr_x == M - 1 && curr_y == N - 1) {
      result = curr.second;
      break;
    }

    for (int i = 0; i < 4; i++) {
      next_x = curr_x + move_x[i];
      next_y = curr_y + move_y[i];
      if (next_x >= 0 && next_x < M && next_y >= 0 && next_y < N &&
          !visited[next_y][next_x] && maze[next_y][next_x]) {
        visited[next_y][next_x] = true;
        q.push(make_pair(make_pair(next_x, next_y), curr.second + 1));
      }
    }
  }
  return result;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  string input;
  for (int i = 0; i < N; i++) {
    cin >> input;
    for (int j = 0; j < M; j++) {
      maze[i][j] = input[j] - '0';
    }
  }

  int result = bfs();
  cout << result;
}
