#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ull n, p, h;
  cin >> n >> p >> h;

  vector<pair<ull, ull>> folds(n+1);
  ull sz = (1ull << n);
  folds[n] = {sz, h};

  for (int i = n-1; i >= 0; --i) {
    ull sz = folds[i+1].first/2;
    ull pos = (folds[i+1].second > sz) ? folds[i+1].first - folds[i+1].second + 1 : folds[i+1].second;

    folds[i] = {sz, pos};
  }

  string ans;
  char side = p <= sz/2 ? 'L' : 'R';
  char otherside = side == 'L' ? 'R' : 'L';
  for (int i = 0; i < n; ++i) {
    auto[cur_sz, cur_pos] = folds[i];
    auto[next_sz, next_pos] = folds[i+1];

    side = p <= sz/2 ? 'L' : 'R';
    otherside = side == 'L' ? 'R' : 'L';

    if (cur_pos == next_pos) { 
      ans.push_back(otherside);
      if (otherside == 'L') {
        if (p > sz/2)
          p = p - sz/2;
        else
          p = (sz/2 + 1) - p;
      } else {
        if (p > sz/2)
          p = sz/2 - (p - sz/2 - 1);
      }
    }
    else {
      ans.push_back(side);
      if (side == 'L') {
        if (p > sz/2)
          p = p - sz/2;
        else
          p = (sz/2 + 1) - p;
      } else {
        if (p > sz/2)
          p = sz/2 - (p - sz/2 - 1);
      }
    }

    //cout << p << endl;
    sz /= 2;
  }

  cout << ans << '\n';
}
