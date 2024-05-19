#include <algorithm>
#include <iostream>
#include <queue>
/*
 1. BFS
  - Think of 3 direction: X-1, X+1, 2*X
*/
#define pi pair<int, int>

using namespace std;
unsigned N, K;
unsigned line[100001];
bool visited[100001];

unsigned bfs() {
  unsigned result = 0;
  queue<pi> q;
  q.push(make_pair(N, 0));
  visited[N] = true;

  unsigned next;
  while (!q.empty()) {
    pi curr = q.front();
    q.pop();
    if (curr.first == K) {
      result = curr.second;
      break;
    }

    next = curr.first + 1;
    if (next >= 0 && next <= 100000 && !visited[next]) {
      visited[next] = true;
      q.push(make_pair(next, curr.second + 1));
    }
    next = curr.first - 1;
    if (next >= 0 && next <= 100000 && !visited[next]) {
      visited[next] = true;
      q.push(make_pair(next, curr.second + 1));
    }
    next = curr.first * 2;
    if (next >= 0 && next <= 100000 && !visited[next]) {
      visited[next] = true;
      q.push(make_pair(next, curr.second + 1));
    }
  }
  return result;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> K;

  unsigned result = bfs();
  cout << result;
}
