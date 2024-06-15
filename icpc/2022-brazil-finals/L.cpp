#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string s;
  int d;

  cin >> s >> d;

  string curr = s.substr(0, d);
  int ans = 1;

  int curr_idx = 0;
  int i = d;
  while ( i < s.size() ) {
    if (s[i] == curr[curr_idx]) {
      curr_idx = (curr_idx + 1) % d;
      i++;
      continue;
    } 

    curr = s.substr(i, d);
    i += d;
    ans++;
    curr_idx = 0;
  }
  cout << ans << '\n';
}
