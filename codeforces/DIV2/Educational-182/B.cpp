#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int INF = 1e9;
ll INFL = 1e18;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin  >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> vec(n);
    vector<bool> shown(n+1, false);
    for (auto& v : vec) {
      cin >> v;
      shown[v] = 1;
    }

    set<int> not_shown;
    for (int i = 1; i <= n; ++i)
      if (!shown[i])
        not_shown.insert(i);

    for (int i = 0; i < n; ++i)
      if (!vec[i]) {
        auto it = prev(not_shown.end());
        if (*it == i+1 && next(it) != not_shown.begin())
          it = prev(it);
        vec[i] = *it;
        not_shown.erase(it);
      }

    int ans = 0;
    int begin = -1;
    int end = -1;
    for (int i = 0; i < n; ++i) {
      if (vec[i] != i+1 &&  begin == -1)
        begin = end = i;
      if (vec[i] != i+1)
        end = i;
    }
    if (begin != -1)
      cout << end - begin + 1 << endl;
    else
      cout << "0\n";
  }
}
