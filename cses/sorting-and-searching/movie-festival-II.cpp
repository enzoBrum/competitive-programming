#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, k;
  cin >> n >> k;

  int free_members = k;

  vector<pair<int, int>> movies(n);
  for (auto &v : movies)
    cin >> v.first >> v.second;

  sort(movies.begin(), movies.end(), [](pair<int, int> &a, pair<int, int> &b) {
    return a.second < b.second;
  });

  int ans = 0;
  multiset<int> members;
  for (int i = 0; i < k; ++i)
    members.insert(0);
  for (auto &[a, b] : movies) {
    auto it = members.upper_bound(a);
    if (it == members.begin())
      continue;

    ans++;
    members.erase(--it);
    members.insert(b);
  }

  cout << ans << '\n';
}
