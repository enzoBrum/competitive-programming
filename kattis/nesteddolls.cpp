#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  while (t--) {
    int m;
    cin >> m;

    vector<pii> dolls(m);
    for (auto &[w, h] : dolls)
      cin >> w >> h;

    sort(rall(dolls));

    int ans = 0;
    multiset<int> active;
    queue<int> q;

    int last_w = -1;
    for (auto &[w, h] : dolls) {
      if (w != last_w)
        while (!q.empty()) {
          active.insert(q.front());
          q.pop();
        }

      auto it = active.upper_bound(h);
      if (it != active.end())
        active.erase(it);
      else
        ans++;
      q.push(h);
      last_w = w;
    }

    cout << ans << '\n';
  }
}
