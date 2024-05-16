#include <algorithm>
#include <iostream>
#include <set>

using namespace std;
/*
 1. Handling inputs
 2. DFS
*/
int N, M;
set<int> graph[101];
bool is_visited[101];
int result = 0;

void dfs(int curr) {
  if (!is_visited[curr]) {
    result++;
    is_visited[curr] = true;
    for (const auto &n : graph[curr]) {
      dfs(n);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> M;
  int v, w;
  for (int i = 0; i < M; i++) {
    cin >> v >> w;
    graph[v].insert(w);
    graph[w].insert(v);
  }
  dfs(1);
  cout << result - 1 << "\n";

  //   cout << "\n";
  //   for (int i = 1; i <= N; i++) {
  //     for (const auto &n : graph[i]) cout << n << " ";
  //     cout << "\n";
  //   }
}
