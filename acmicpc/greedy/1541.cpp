#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

/*
 1. Handling the input
 2. Changing operator to minus(-) after minus occurs
*/
vector<int> nums;
vector<char> ops;
string input, num = "";

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> input;

  for (const auto &ch : input) {
    if (ch == '+' || ch == '-') {
      ops.push_back(ch);
      nums.push_back(stoi(num));
      num = "";
    } else {
      num += ch;
    }
  }
  nums.push_back(stoi(num));

  bool is_m = false;
  int result = nums[0];

  for (int i = 0; i < ops.size(); i++) {
    if (is_m) {
      result -= nums[i + 1];
    } else {
      if (ops[i] == '+') {
        result += nums[i + 1];
      } else {
        is_m = true;
        result -= nums[i + 1];
      }
    }
  }
  cout << result << "\n";
}
