#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

bool backtrack(vector<vector<int>>& walls_hit, int i, int k, int final_k, vector<bool>& found) {
  if (k == final_k && all_of(found.begin(), found.end(), identity()))
    return true;
  if (k == final_k)
    return false;
  if (i >= walls_hit.size())
    return false;
  
  auto old = found;
  for (auto& w : walls_hit[i])
    found[w] = true;
  if (backtrack(walls_hit, i+1, k+1, final_k, found))
    return true;
  
  found = old;
  if (backtrack(walls_hit, i+1, k, final_k, found))
    return true;
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int l, w, n, r;
  cin >> l >> w >> n >> r;

  vector<pair<double, double>> cranes(n);
  vector<pair<double, double>> centers = {
    {-l/2.0, 0},
    {l/2.0, 0},
    {0, -w/2.0},
    {0, w/2.0}
  };
  for (auto&[x, y] : cranes)
    cin >> x >> y;

  vector<vector<int>> circles_to_walls(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 4; ++j) {
      int xdist = cranes[i].first - centers[j].first;
      int ydist = cranes[i].second - centers[j].second;
      if ( sqrt(xdist*xdist + ydist * ydist) - r <= 1e-12 )
        circles_to_walls[i].push_back(j);
    }
  }
  
  int ans = 0;
  for (int k = 1; k < 5 && !ans; ++k) {
    vector<bool> found(4, false);
    if (backtrack(circles_to_walls, 0, 0, k, found))
      ans = k;
  }


  cout << (ans == 0 ? "Impossible" : to_string(ans)) << '\n';
}
