#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;
// M1. Using two unordered_map variables
/*
Store a name as a key and index as a value for the first unordered_map
Store an index as a key and name as a value for the first unordered_map
*/
unordered_map<string, int> map1;
unordered_map<int, string> map2;
int N, M;
string input;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> input;
    map1[input] = i + 1;
    map2[i + 1] = input;
  }

  for (int i = 0; i < M; i++) {
    cin >> input;
    if (isdigit(input[0]))
      cout << map2[stoi(input)];
    else
      cout << map1[input];
    cout << "\n";
  }
}
