#include <algorithm>
#include <iostream>
#include <queue>
#include <set>

using namespace std;
/*
 1. Handlig inputs
    Create a graph
 2. DFS
 3. BFS
*/

set<int> graph[1001];
bool is_visited[1001];
int N, M, V;

void input() {
  cin >> N >> M >> V;
  int v1, v2;
  for (int i = 0; i < M; i++) {
    cin >> v1 >> v2;
    graph[v1].insert(v2);
    graph[v2].insert(v1);
  }
}

void initVisited() {
  for (int i = 0; i < 1001; i++) is_visited[i] = false;
}

// Using recursion
void dfs(int curr) {
  if (is_visited[curr]) return;
  cout << curr << " ";
  is_visited[curr] = true;
  for (const auto &next : graph[curr]) {
    dfs(next);
  }
}

void bfs(int start) {
  queue<int> q;
  q.push(start);

  int curr;
  while (!q.empty()) {
    curr = q.front();
    q.pop();
    if (!is_visited[curr]) cout << curr << " ";
    is_visited[curr] = true;
    for (const auto &next : graph[curr]) {
      if (!is_visited[next]) q.push(next);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  input();
  dfs(V);
  initVisited();
  cout << "\n";
  bfs(V);
}
