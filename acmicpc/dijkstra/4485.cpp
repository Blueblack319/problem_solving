#include <iostream>
#include <queue>
#include <sstream>
#include <vector>

#define MAX_N 125

using namespace std;

int dist[MAX_N][MAX_N];
int costs[MAX_N][MAX_N];
int visied[MAX_N][MAX_N];
int x_move[4] = {0, 0, -1, 1};
int y_move[4] = {1, -1, 0, 0};
int N;

void dijkstra() {
  priority_queue<pair<int, pair<int, int>>> pq;
  pq.push(make_pair(-1 * costs[0][0], make_pair(0, 0)));  // -cost, x, y
  dist[0][0] = costs[0][0];

  while (!pq.empty()) {
    pair<int, int> curr_pos = pq.top().second;
    pq.pop();

    for (int i = 0; i < 4; i++) {
      int next_x = curr_pos.first + x_move[i];
      int next_y = curr_pos.second + y_move[i];
      int next_node_cost = costs[next_x][next_y];

      if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N) {
        int next_dist = dist[curr_pos.first][curr_pos.second] + next_node_cost;
        if (dist[next_x][next_y] > next_dist) {
          dist[next_x][next_y] = next_dist;
          pq.push(make_pair(next_dist * (-1), make_pair(next_x, next_y)));
        }
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int pro_cnt = 1;

  while (1) {
    cin >> N;
    if (N == 0) break;

    int cost;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        cin >> costs[i][j];

        dist[i][j] = 200000;
      }
    }
    dijkstra();
    cout << "Problem " << pro_cnt << ": " << dist[N - 1][N - 1] << "\n";

    pro_cnt++;
  }
  return 0;
}