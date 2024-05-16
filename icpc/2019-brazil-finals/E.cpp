#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;
using pii = pair<int, int>;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string s;
  cin >> s;

  int max_fruits;
  cin >> max_fruits;

  long long ans = 0;

  int og_size = s.size();

  vector<int> eggfruits;
  for (int i = 0; i < max_fruits - 1; ++i) {
    s.push_back(s[i]);
  }
  for (int i = 0; i < s.size(); ++i)
    if (s[i] == 'E')
      eggfruits.push_back(i);

  for (int i = 0; i < s.size(); ++i) {
    char c = s[i];
    // cout << "\nI: " << i << ',';
    if (c == 'E') {
      if (i < og_size) {
        ans++;
        ans += min(i, max_fruits - 1);
      } else {
        int remaining = i - og_size + 1;
        remaining = min(max_fruits, i + 1) - remaining;
        ans += remaining;
      }
    } else {
      auto it = lower_bound(eggfruits.begin(), eggfruits.end(), i);

      if (it == eggfruits.begin())
        continue;
      int idx = *(it - 1);

      // cout << "IDX: " << idx << ',';
      int size = i - idx + 1;
      int limit = min(i + 1, max_fruits);
      if (size > limit)
        continue;

      if (i >= og_size && idx >= og_size) {
        int remaining = i - og_size + 1;
        remaining = limit - remaining;
        ans += remaining;
      } else {
        ans += 1;

        int remaining = limit - size;
        if (remaining) {
          ans += remaining;
        }
      }
    }

    // cout << ",ANS=" << ans << '\n';
  }

  // int limit = min((int)s.size(), max_fruits - 1);
  // bool found_egg = s.back() == 'E';
  // for (int i = 0; i < limit; ++i) {
  //   if (s[i] == 'E')
  //     found_egg = true;
  //
  //   if (found_egg)
  //     ans++;
  // }
  //

  cout << ans << '\n';
}

