#include <algorithm>
#include <iostream>
#include <unordered_set>

using namespace std;
unordered_set<int> cards;
int N, M, num;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> num;
    cards.insert(num);
  }

  cin >> M;
  for (int i = 0; i < M; i++) {
    cin >> num;
    auto card = cards.find(num);
    if (card != cards.end())
      cout << 1;
    else
      cout << 0;
    cout << " ";
  }
}
