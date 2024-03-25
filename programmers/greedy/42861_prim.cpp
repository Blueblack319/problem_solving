#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> costs) {
  int answer = 0;

  // Prim's Alogrithm
  // Make the priority queue containing the candidate nodes
  // Insert the first node into the prioriy queue
  // Take out the node which has the smallest weight from the priority queue
  // Add nodes adjecent to the current node into the priority queue
  // repeat
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      PQ;
  vector<bool> visited(n, false);
  int l, r, w;
  for (const auto &cost : costs) {
    l = cost[0];
    r = cost[1];
    w = cost[2];
    if (l == 0) {
      visited[0] = true;
      PQ.push(make_pair(w, r));
    }
    if (r == 0) {
      visited[0] = true;
      PQ.push(make_pair(w, l));
    }
  }

  while (!PQ.empty()) {
    int current_node = PQ.top().second;
    int current_weight = PQ.top().first;
    PQ.pop();

    if (!visited[current_node]) {
      visited[current_node] = true;
      answer += current_weight;

      for (const auto &cost : costs) {
        int next_left = cost[0];
        int next_right = cost[1];
        int next_weight = cost[2];
        if (current_node == next_left && !visited[next_right])
          PQ.push(make_pair(next_weight, next_right));
        else if (current_node == next_right && !visited[next_left])
          PQ.push(make_pair(next_weight, next_left));
      }
    }
  }

  return answer;
}