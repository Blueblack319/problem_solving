#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
// brute force로 rock을 뺄 생각하지 말고 최소 거리를 찾아가기
// mid만큼의 간격을 만들어 나가기 & cnt++
// If cnt <= n, 최소거리 mid를 더 키울 수 있음 => left = mid
// else, 최소거리 mid를 더 줄여야 해 => right = mid - 1

int solution(int distance, vector<int> rocks, int n) {
  int answer = 0;

  sort(rocks.begin(), rocks.end());
  int left = 0;
  int right = distance;
  while (left <= right) {
    cout << left << " " << right << "\n";
    int mid = (left + right) / 2;
    int cnt = 0;
    int prev = 0;
    for (const auto &rock : rocks) {
      if (rock - prev < mid) {
        cnt++;
      } else {
        prev = rock;
      }
    }
    if (distance - prev < mid) cnt++;
    if (cnt <= n) {
      answer = max(mid, answer);
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return answer;
}