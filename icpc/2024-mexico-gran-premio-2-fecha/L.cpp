#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;


inline void swp(int i, vector<int>& vec, vector<int>& mp) {
  int ib = mp[i];
  int vb = vec[i];

  swap(vec[i], vec[ib]);
  mp[i] = i, mp[vb] = ib;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> right(n), left(n);
  vector<int> mpr(n), mpl(n);
  for (int i = 0; i < n; ++i) {
    cin >> right[i];
    right[i]--;
    mpr[right[i]] = i;
  }
  for (int i = 0; i < n; ++i) {
    cin >> left[i];
    left[i]--;
    mpl[left[i]] = i;
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (left[i] != i)
      swp(i, left, mpl), ans++;
    if (right[i] != i)
      swp(i, right, mpr), ans++;
  }

  cout << ans << '\n';
}
