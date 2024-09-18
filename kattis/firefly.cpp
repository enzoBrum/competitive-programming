#include <algorithm>
#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, h;
  cin >> n >> h;

  vector<int> up, down;

  for (int i = 0; i < n; ++i) {
    int tmp;
    cin >> tmp;
    if (i % 2 == 0)
      down.push_back(tmp);
    else
      up.push_back(h - tmp);
  }

  sort(all(up));
  sort(all(down));

  int best = 1e9, cnt_best = 0;
  for (int i = 0; i < h; ++i) {
    auto it = upper_bound(all(down), i);
    int hit_ground = it == down.end() ? 0 : down.size() - (it - down.begin());

    auto it2 = upper_bound(all(up), i);
    int hit_ceilling = it2 == up.end() ? up.size() : it2 - up.begin();

    int cur = hit_ceilling + hit_ground;
    // cout << "I: " << i << ", GROUND: " << hit_ground
    //      << ",CEIL: " << hit_ceilling << '\n';
    if (cur == best)
      cnt_best++;
    else if (cur < best)
      cnt_best = 1, best = cur;
  }

  cout << best << ' ' << cnt_best << '\n';
}
