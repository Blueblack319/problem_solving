#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#define MAX 101

using namespace std;

struct cmp {
  bool operator()(vector<int> a, vector<int> b) { return a[2] > b[2]; }
};

int getParent(int num, vector<int> &parent) {
  if (num == parent[num]) return num;
  return parent[num] = getParent(parent[num], parent);
}

bool checkCycle(int a, int b, vector<int> &parent) {
  return getParent(a, parent) == getParent(b, parent);
}

void unionParent(int a, int b, vector<int> &parent) {
  int a_parent = getParent(a, parent);
  int b_parent = getParent(b, parent);
  if (a_parent > b_parent)
    parent[a_parent] = b_parent;
  else
    parent[b_parent] = a_parent;
}

int solution(int n, vector<vector<int>> costs) {
  int answer = 0;

  // Kruskal's Alogrithm
  // To speed up, use min heap => O(nlogn)
  // # of edges = n - 1
  // If including an edge makes a cycle, do not select that
  vector<int> parent(MAX);
  for (int i = 0; i < MAX; i++) parent[i] = i;

  sort(costs.begin(), costs.end(),
       [](const vector<int> &a, const vector<int> &b) -> bool {
         return a[2] < b[2];
       });

  int cnt_edge = 0;
  for (auto &cost : costs) {
    if (cnt_edge == n - 1) break;
    if (!checkCycle(cost[0], cost[1], parent)) {
      unionParent(cost[0], cost[1], parent);
      answer += cost[2];
      cnt_edge++;
    }
  }

  return answer;
}