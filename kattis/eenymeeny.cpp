#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int recurrence(vector<int> &vec, vector<int> &solution, int k, int n) {
  return solution[n - 1] =
             n > 1 ? (recurrence(vec, solution, k, n - 1) + k) % n + 1 : 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string line;
  getline(cin, line);

  int k = 1 + ranges::count(line, ' ');

  int n;
  cin >> n;

  unordered_map<string, int> mp;
  vector<int> vec;
  while (n--) {
    string name;
    cin >> name;
    mp[name] = mp.size();

    vec.push_back(mp[name]);
  }

  vector<vector<int>> teams(2);
  vector<int> solution(vec.size());
  recurrence(vec, solution, k, vec.size());
  ranges::for_each(solution, [](auto &obj) { cout << obj << '\n'; });
}
