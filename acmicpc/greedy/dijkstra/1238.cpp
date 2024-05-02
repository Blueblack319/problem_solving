#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

#define MAX_D 1e9
using namespace std;

int N, M, X;
vector<int> dist[2];
vector<pair<int, int>> graph[2][1001];

void input() {
  cin >> N >> M >> X;
  int a, b, t;
  for (int i = 0; i < M; i++) {
    cin >> a >> b >> t;
    graph[0][a].push_back(make_pair(b, t));
    graph[1][b].push_back(make_pair(a, t));
  }
  dist[0].resize(N + 1, MAX_D);
  dist[1].resize(N + 1, MAX_D);
}

void dijkstra(int idx) {
  dist[idx][X] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  pq.push(make_pair(0, X));
  while (!pq.empty()) {
    int current = pq.top().second;
    int current_d = pq.top().first;
    pq.pop();

    if (current_d > dist[idx][current])
      continue;  // If the value of dist[idx][current] is already visited, then
                 // it is the optimal(smallest) value and we can skip this

    for (const auto &node : graph[idx][current]) {
      int next = node.first;
      int next_d = current_d + node.second;

      if (next_d < dist[idx][next]) {
        dist[idx][next] = next_d;
        pq.push({next_d, next});
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  input();
  dijkstra(0);
  dijkstra(1);

  int result = 0;
  for (int i = 1; i < N + 1; i++) {
    result = max(result, dist[0][i] + dist[1][i]);
  }
  cout << result;

  return 0;
}