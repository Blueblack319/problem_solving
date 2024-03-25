#include <algorithm>
#include <set>
#include <string>
#include <vector>

using namespace std;

bool is_prime(int num) {
  if (num < 2) return false;
  for (int i = 2; i * i <= num; i++)
    if (num % i == 0) return false;
  return true;
}

int solution(string numbers) {
  int answer = 0;

  set<int> primes;
  sort(numbers.begin(), numbers.end());

  do {
    string tmp;
    int tmp_num;
    for (const auto c : numbers) {
      tmp += c;
      tmp_num = stoi(tmp);
      if (is_prime(tmp_num)) primes.insert(tmp_num);
    }
  } while (next_permutation(numbers.begin(), numbers.end()));

  answer = primes.size();

  return answer;
}