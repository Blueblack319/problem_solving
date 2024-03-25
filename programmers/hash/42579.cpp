#include <algorithm>
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
  vector<pair<string, int>> sum_category;

  int N = genres.size();
  for (int i = 0; i < N; i++) {
    auto search = categories.find(genres[i]);
    if (search == categories.end()) {
      priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
      pq.push({plays[i], i});
      categories.insert({genres[i], pq});
      sum_category.push_back({genres[i], plays[i]});
    } else {
      categories[genres[i]].push({plays[i], i});
      auto found = find_if(sum_category.begin(), sum_category.end(),
                           [&genres, i](pair<string, int> a) -> bool {
                             return genres[i].compare(a.first) == 0;
                           });
      found->second += plays[i];
    }
  }

  sort(sum_category.begin(), sum_category.end(),
       [](pair<string, int> a, pair<string, int> b) -> bool {
         return a.second > b.second;
       });
  for (const auto &category : sum_category) {
    for (int i = 0; i < 2; i++) {
      if (categories[category.first].empty()) break;
      const auto song = categories[category.first].top();
      answer.push_back(song.second);
      categories[category.first].pop();
    }
  }

  // for(const auto &category: categories){
  //     auto max_val = category.second.top();
  //     cout << category.first << " " << max_val.first << "\n";
  // }
  // for(const auto &sum: sum_category){
  //     cout << sum.first << " " << sum.second << "\n";
  // }

  return answer;
}