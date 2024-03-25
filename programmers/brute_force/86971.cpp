#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
// graph 만들기
// dfs를 통해서 각 node에서 연결된 node 수의 합 구하기
vector<vector<int>> graph;
vector<int> size_from;
void dfs(int curr, int prev) {
  for (const auto next : graph[curr]) {
    if (next == prev) continue;
    dfs(next, curr);
    size_from[curr] += size_from[next];
  }
}

int solution(int n, vector<vector<int>> wires) {
  int answer = 100;

  graph.resize(n + 1, {});
  size_from.resize(n + 1, 1);

  for (const auto &wire : wires) {
    graph[wire[0]].push_back(wire[1]);
    graph[wire[1]].push_back(wire[0]);
  }
  dfs(1, -1);

  for (const auto size : size_from) {
    int other = n - size;
    answer = min(answer, abs(size - other));
  }

  return answer;
}