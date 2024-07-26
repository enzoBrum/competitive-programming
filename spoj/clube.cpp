#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int solve(vector<int> &boards, int w, int h, int l) {
  int divisions = w / l, cur_divisions = 0;

  if (divisions == 0 || w % l != 0)
    return 1e9;
  int ans = 0;
  vector<bool> used(boards.size(), false);
  for (int i = boards.size() - 1; i >= 0 && cur_divisions < divisions; --i) {
    if (used[i])
      continue;
    int b = boards[i];
    if (b > h)
      continue;
    if (b == h) {
      ans++;
      cur_divisions++;
      used[i] = true;
      continue;
    }

    int other = h - b;
    int b2 = -1;
    int i2 = 1e9;

    auto it = lower_bound(boards.begin(), boards.end(), other);
    if (*it != other)
      continue;

    i2 = it - boards.begin();
    while (i2 < boards.size() && boards[i2] == other && (used[i2] || i2 == i))
      i2++;

    if (i2 < boards.size() && boards[i2] == other) {
      used[i2] = used[i] = true;
      cur_divisions++;
      ans += 2;
    }
  }

  return cur_divisions == divisions && divisions > 0 ? ans : 1e9;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int w, h, l, k;
  while (cin >> w >> h && w && h) {
    cin >> l >> k;
    vector<int> boards(k);
    for (auto &b : boards) {
      cin >> b;
      b *= 100;
    }

    w *= 100;
    h *= 100;

    sort(boards.begin(), boards.end());

    int ans = min(solve(boards, w, h, l), solve(boards, h, w, l));
    cout << (ans == (int)1e9 ? "impossivel" : to_string(ans)) << '\n';
  }
}
