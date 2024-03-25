#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// 두 수를 붙였을 때 더 큰 수를 앞으로

bool compare(int a, int b) {
  string ab = to_string(a) + to_string(b);
  string ba = to_string(b) + to_string(a);
  return stoi(ab) > stoi(ba);
}

string solution(vector<int> numbers) {
  string answer = "";

  sort(numbers.begin(), numbers.end(), compare);
  for (int number : numbers) answer += to_string(number);

  return answer;
}