#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;

  while (t--) {
    string m;
    cin >> m;

    string ans = m;

    // UP
    int i = m.size() - 1;
    while (i && m[i] != 's' && m[i] != 'r')
      i--;
    if (!i) {
      cout << "<none> ";
    } else {
      ans[i] = m[i] == 's' ? 'p' : 'q';
      i++;
      for (; i < m.size(); ++i)
        ans[i] = m[i] == 'p' || m[i] == 's' ? 's' : 'r';
      cout << ans << ' ';
    }
    ans = m;
    i = m.size() - 1;

    // DOWN
    while (i && m[i] != 'p' && m[i] != 'q')
      i--;
    if (!i) {
      cout << "<none> ";
    } else {
      ans[i] = m[i] == 'p' ? 's' : 'r';
      i++;
      for (; i < m.size(); ++i)
        ans[i] = m[i] == 'p' || m[i] == 's' ? 'p' : 'q';
      cout << ans << ' ';
    }
    ans = m;
    i = m.size() - 1;

    // LEFT
    while (i && m[i] != 'q' && m[i] != 'r')
      i--;
    if (!i) {
      cout << "<none> ";
    } else {
      ans[i] = m[i] == 'q' ? 'p' : 's';
      i++;
      for (; i < m.size(); ++i)
        ans[i] = m[i] == 'p' || m[i] == 'q' ? 'q' : 'r';
      cout << ans << ' ';
    }
    ans = m;
    i = m.size() - 1;

    // RIGHT
    while (i && m[i] != 'p' && m[i] != 's')
      i--;
    if (!i) {
      cout << "<none>\n";
    } else {
      ans[i] = m[i] == 'p' ? 'q' : 'r';
      i++;
      for (; i < m.size(); ++i)
        ans[i] = m[i] == 'p' || m[i] == 'q' ? 'p' : 's';
      cout << ans << '\n';
    }
  }
}
