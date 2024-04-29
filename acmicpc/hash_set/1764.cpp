#include <algorithm>
#include <iostream>
#include <unordered_set>
using namespace std;
/*
1. Insert the value into set datastructure
2. When handling the second line, check if the value is in the set.
If it is, store the value into the result
*/
vector<string> result;
unordered_set<string> unknown;
int N, M;
string cur;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    cin >> cur;
    unknown.insert(cur);
  }
  for (int i = 0; i < M; i++) {
    cin >> cur;
    if (unknown.find(cur) != unknown.end()) {
      result.push_back(cur);
    }
  }
  sort(result.begin(), result.end());
  cout << result.size() << "\n";
  for (const auto name : result) {
    cout << name << "\n";
  }
}
