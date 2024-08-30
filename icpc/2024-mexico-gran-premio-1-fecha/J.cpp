#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;

  string s;
  cin >> s;

  vector<pair<int, set<int>>> st(26);

  for (int i = 0; i < s.size(); ++i) {
    int idx = s[i] - 'a';
    if (st[idx].first == -1)
      st[idx].first = i;
    else
      st[idx].second.insert(i);
  }


}
