#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;
// song: idx, genre, play
// 장르별 재생된 횟수의 합
// 각 장르마다 play로 내림차순 정렬

struct comp {
  bool operator()(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
      return a.second > b.second;
    } else
      return a.first < b.first;
  }
};

vector<int> solution(vector<string> genres, vector<int> plays) {
  vector<int> answer;

  map<string, priority_queue<pair<int, int>, vector<pair<int, int>>, comp>>
      categories;

  int N = genres.size();
  for (int i = 0; i < N; i++) {
    auto search = categories.find(genres[i]);
    if (search == categories.end()) {
      priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
      pq.push({plays[i], i});
      categories.insert({genres[i], pq});
    } else {
      cout << search->first;
    }
  }

  for (const auto &category : categories) {
    cout << category.first << "\n";
  }

  return answer;
}