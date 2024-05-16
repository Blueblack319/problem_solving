#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
/*
1. Handling input data
 - Store pairs of start and end time into vector
 - Sort by the end time
2. Cut off pairs whose start time is smaller than the end time of the
previous pair.
*/
#define puu pair<unsigned, unsigned>

int N;
unsigned time_start, time_end, current, result;
vector<puu> schedules;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> time_start >> time_end;
    schedules.push_back(make_pair(time_start, time_end));
  }
  sort(schedules.begin(), schedules.end(), [](puu a, puu b) {
    if (a.second == b.second) {
      return a.first < b.first;
    } else {
      return a.second < b.second;
    }
  });

  current = schedules[0].second;
  result = 1;
  for (auto iter = schedules.begin() + 1; iter < schedules.end(); iter++) {
    if (iter->first >= current) {
      // cout << iter->first << " " << iter->second << "\n";
      current = iter->second;
      result++;
    }
  }
  cout << result;
}
