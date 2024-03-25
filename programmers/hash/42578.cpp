#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;
// cateogry별로 map에 넣으면서 총 합 누적
// 각 누적값+1을 곱하고 빼기 1

int solution(vector<vector<string>> clothes) {
  int answer = 1;

  map<string, int> categories;
  for (const auto &cloth : clothes) {
    auto search = categories.find(cloth[1]);
    if (search == categories.end()) {
      categories.insert({cloth[1], 1});
    } else {
      search->second += 1;
    }
  }

  for (const auto category : categories) answer *= (category.second + 1);

  return answer - 1;
}