#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool compare(int a, int b) {
  string ab = to_string(a) + to_string(b);
  string ba = to_string(b) + to_string(a);
  return stoi(ab) > stoi(ba);
}

string solution(vector<int> numbers) {
  string answer = "";

  sort(numbers.begin(), numbers.end(), [](const int &a, const int &b) {
    return stoi(to_string(a) + to_string(b)) >
           stoi(to_string(b) + to_string(a));
  });

  for (auto iter = numbers.begin(); iter != numbers.end(); iter++) {
    answer.append(to_string(*iter));
  }
  if (answer[0] == '0') return "0";

  return answer;
}