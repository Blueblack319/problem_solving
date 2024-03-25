#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;
// Binary Search
// n명을 다 심시하기 위해 걸릴 수 있는 최소시간 & 최대시간
// By using binary search, mid일 때 n명을 다 심사할 수 있는지 check
// 할 수 있다면 answer를 update하고 아니면 pass
// Repeat until l > h
int curr_n = 0;

ll solution(int n, vector<int> times) {
  ll answer = 0;

  sort(times.begin(), times.end());
  ll left = 1;
  ll right = (ll)times.back() * n;
  while (left <= right) {
    // cout << "left: " << left << ", right: " << right << "\n";
    ll mid = (left + right) / 2;
    ll passed = 0;
    for (const auto time : times) {
      passed += (mid / (ll)time);
    }
    if (passed >= n) {
      right = mid - 1;
      answer = mid;
    } else
      left = mid + 1;
  }

  return answer;
}