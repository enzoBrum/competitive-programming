#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  vector<int> vb(m);
  unordered_set<int> sa, sb;
  for (int i = 0; i < n; ++i) {
    int num;
    cin >> num;
    sa.insert(num);
  }
  for (auto &v : vb) {
    cin >> v;
  }

  for (int i = 0; i < vb.size(); ++i) {
    if (sa.find(vb[i]) != sa.end()) {
      sb.insert(vb[i]);
      continue;
    }

    bool found = false;
    for (int j = 0; j < i; ++j) {
      if (sb.find(vb[i] - vb[j]) != sb.end()) {
        found = true;
        break;
      }
    }
    if (found) {
      sb.insert(vb[i]);
      continue;
    }

    cout << vb[i] << '\n';
    return 0;
  }

  cout << "sim\n";
}
