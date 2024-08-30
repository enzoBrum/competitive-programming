#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  cin >> n;
  vector<pii> vec(n);
  for (int i = 0; i < n; ++i)
    cin >> vec[i].first, vec[i].second = i+1;

  sort(vec.begin(), vec.end());
  
  for (int i = 0; i < vec.size(); ++i)
    if (i+1 < vec[i].first) {
      cout << "-1\n";
      return 0;
    }
  
  vector<pii> edges;
  for (int i = 0; i < vec.size(); ++i)
    for (int j = 0; j < vec[i].first - 1; ++j)
      edges.push_back({vec[i].second, vec[j].second});
  cout << edges.size() << '\n';
  for (auto&[u, v] : edges)
    cout << u << ' ' << v << '\n';
  
}
