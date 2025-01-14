#include <algorithm>
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

  string s;
  cin >> s;

  vector<int> lis(s.size());
  int k = 0;

  for (int i = 0; i < s.size(); ++i) {
    char c = s[i];
    int pos = lower_bound(lis.begin(), lis.begin() + k, c) - lis.begin();

    lis[pos] = c;
    if (pos == k)
      k++;
  }
  cout << 26 - k << '\n';
}
