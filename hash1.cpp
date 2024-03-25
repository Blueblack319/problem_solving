#include <algorithm>
#include <map>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
  vector<int> answer;
  // key: genre, value: (play, index)

  unordered_set<string> genres_set(genres.begin(), genres.end());
  multimap<string, pair<int, int>> result;
  vector<pair<string, int>> genres_and_total_plays;

  unsigned total = genres.size();

  for (int i = 0; i < total; i++) {
    auto iter =
        find_if(genres_and_total_plays.begin(), genres_and_total_plays.end(),
                [genres, i](pair<string, int> item) -> bool {
                  return item.first == genres[i];
                });
    if (iter == genres_and_total_plays.end()) {
      genres_and_total_plays.push_back(make_pair(genres[i], plays[i]));
    } else {
      iter->second += plays[i];
    }
    result.insert(make_pair(genres[i], make_pair(plays[i], i)));
  }

  sort(genres_and_total_plays.begin(), genres_and_total_plays.end(),
       [](const pair<string, int> i1, const pair<string, int> i2) -> bool {
         return i1.second > i2.second;
       });

  for (auto item : genres_and_total_plays) {
    auto range = result.equal_range(item.first);
    pair<int, int> first_music{0, 0};
    pair<int, int> second_music{0, 0};
    for (auto iter = range.first; iter != range.second; iter++) {
      if (iter->second.first > first_music.first) {
        first_music.first = iter->second.first;
        first_music.second = iter->second.second;
      } else if (iter->second.first > second_music.first) {
        second_music.first = iter->second.first;
        second_music.second = iter->second.second;
      }
    }
    answer.push_back(first_music.second);
    if (second_music.first != 0) {
      answer.push_back(second_music.second);
    }
  }

  //     multimap<string, int> genres_plays_map;
  //     map<int, string> ordered_by_plays;

  //     for(int i = 0; i < genres.size(); i++)
  //         genres_plays_map.insert(make_pair(genres[i], plays[i]));

  //     for(auto genre: genres_set){
  //         int plays_acc = 0;
  //         auto range = genres_plays_map.equal_range(genre);
  //         for(auto iter = range.first; iter != range.second; iter++){
  //             plays_acc += iter->second;
  //         }
  //         ordered_by_plays.insert(make_pairs(plays_acc, genre));
  //     }

  //     for(auto iter = ordered_by_plays.rbegin(); iter !=
  //     ordered_by_plays.rend(); iter++){

  //     }

  return answer;
}