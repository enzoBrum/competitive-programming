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

  int n;
  cin >> n;

  int ox, oy, dx, dy;
  cin >> ox >> oy >> dx >> dy;

  vector<pii> vec(n);
  for (auto &[x, y] : vec)
    cin >> x >> y;

  bool asc = ox < dx;
  bool ascy = oy < dy;
  sort(all(vec), [&asc, &ascy](pii &a, pii &b) {
    if (a.first != b.first && asc)
      return a.first < b.first;
    else if (a.first != b.first)
      return a.first > b.first;
    else if (ascy)
      return a.second < b.second;
    return a.second > b.second;
  });

  auto cmp_func = ascy ? [](int a, int b) { return a < b; }
                       : [](int a, int b) { return a > b; };

  //cout << "VEC: ";
  //for (auto &[x, y] : vec) {
  //  cout << '(' << x << ", " << y << ") - ";
  //}
  //cout << endl;

  vector<int> lis(n);
  vector<int> lis_sz(n);
  vector<int> max_lis_sz(n);
  vector<int> cnt(n);
  int k = 0;

  for (int i = 0; i < n; ++i) {
    auto [x, y] = vec[i];

    bool x_valid = (ox < dx && x >= ox && x <= dx) || (x <= ox && x >= dx);
    bool y_valid = (oy < dy && y >= oy && y <= dy) || (y <= oy && y >= dy);

    if (!x_valid || !y_valid)
      continue;

    int pos =
        upper_bound(lis.begin(), lis.begin() + k, y, cmp_func) - lis.begin();

    lis[pos] = y;
    if (pos == k)
      k++;
    lis_sz[pos] = pos ? lis_sz[pos-1] + 1 : 1;
    //lis_sz[pos] += cnt[pos];
    //lis_sz[pos+1] = 0;
    max_lis_sz[pos] = max(max_lis_sz[pos], lis_sz[pos]);
    cnt[pos]++;
  }

  int ans = 0;
  for (auto &sz : max_lis_sz)
    ans = max(ans, sz);

  cout << ans << '\n';
}
