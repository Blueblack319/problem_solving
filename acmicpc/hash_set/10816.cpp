#include <iostream>
#include <set>
#include <unordered_map>

using namespace std;
/*
1. Handing inputs
2. Create a map and store the number of cards_map into the corresponding card
index
*/
int N, M, num;
unordered_map<int, int> cards_map;
set<int> cards_set;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> num;
    auto card = cards_map.find(num);
    if (card != cards_map.end())
      cards_map[num] += 1;
    else
      cards_map[num] = 1;
  }

  cin >> M;
  for (int i = 0; i < M; i++) {
    cin >> num;
    auto card = cards_map.find(num);
    if (card != cards_map.end()) {
      cout << cards_map[num] << " ";
    } else
      cout << "0 ";
  }
}